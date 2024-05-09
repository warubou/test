#include "dx12_texture.h"
#include "dx12_device.h"
#include "dx12_fence.h"

namespace ko
{
	namespace dx12
	{
		void Texture::LoadTexture(const std::wstring& filePath)
		{
			DirectX::ScratchImage scratchImg = {};

			HRESULT h;
			h = DirectX::LoadFromWICFile(L"../data/TEXTURE/airou.png", DirectX::WIC_FLAGS_NONE, &_texMetaData, scratchImg);
			//if (FAILED(DirectX::LoadFromWICFile(filePath.c_str(), DirectX::WIC_FLAGS_NONE, &_texMetaData, scrImage)))
			if (FAILED(h))
			{
				MessageBox(NULL, "テクスチャ読み込み失敗", "Failed", MB_OK);
				return;
			}

			auto img = scratchImg.GetImage(0, 0, 0);//生データ抽出

			//まずは中間バッファとしてのUploadヒープ設定
			D3D12_HEAP_PROPERTIES uploadHeapProp = {};
			uploadHeapProp.Type = D3D12_HEAP_TYPE_UPLOAD;//Upload用
			uploadHeapProp.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
			uploadHeapProp.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
			uploadHeapProp.CreationNodeMask = 0;//単一アダプタのため0
			uploadHeapProp.VisibleNodeMask = 0;//単一アダプタのため0

			D3D12_RESOURCE_DESC resDesc = {};
			resDesc.Format = DXGI_FORMAT_UNKNOWN;
			resDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;//単なるバッファとして
			auto pixelsize = scratchImg.GetPixelsSize();
			resDesc.Width = alignmentedSize(img->rowPitch, D3D12_TEXTURE_DATA_PITCH_ALIGNMENT) * img->height;//データサイズ

			resDesc.Height = 1;//
			resDesc.DepthOrArraySize = 1;//
			resDesc.MipLevels = 1;
			resDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;//連続したデータですよ
			resDesc.Flags = D3D12_RESOURCE_FLAG_NONE;//とくにフラグなし
			resDesc.SampleDesc.Count = 1;//通常テクスチャなのでアンチェリしない
			resDesc.SampleDesc.Quality = 0;//


			//中間バッファ作成
			HRESULT hr = DX12Device::getInstance().Get()->CreateCommittedResource(
				&uploadHeapProp,
				D3D12_HEAP_FLAG_NONE,//特に指定なし
				&resDesc,
				D3D12_RESOURCE_STATE_GENERIC_READ,//CPUから書き込み可能
				nullptr,
				IID_PPV_ARGS(&uploadbuff)
			);

			//次にテクスチャのためのヒープ設定
			D3D12_HEAP_PROPERTIES texHeapProp = {};
			texHeapProp.Type = D3D12_HEAP_TYPE_DEFAULT;//テクスチャ用
			texHeapProp.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
			texHeapProp.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
			texHeapProp.CreationNodeMask = 0;//単一アダプタのため0
			texHeapProp.VisibleNodeMask = 0;//単一アダプタのため0

			//リソース設定(変数は使いまわし)
			resDesc.Format = _texMetaData.format;
			resDesc.Width = _texMetaData.width;//幅
			resDesc.Height = _texMetaData.height;//高さ
			resDesc.DepthOrArraySize = _texMetaData.arraySize;//2Dで配列でもないので１
			resDesc.MipLevels = _texMetaData.mipLevels;//ミップマップしないのでミップ数は１つ
			resDesc.Dimension = static_cast<D3D12_RESOURCE_DIMENSION>(_texMetaData.dimension);//2Dテクスチャ用
			resDesc.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;

			//テクスチャバッファ作成
			hr = DX12Device::getInstance().Get()->CreateCommittedResource(
				&texHeapProp,
				D3D12_HEAP_FLAG_NONE,//特に指定なし
				&resDesc,
				D3D12_RESOURCE_STATE_COPY_DEST,//コピー先
				nullptr,
				IID_PPV_ARGS(&texbuff)
			);
			uint8_t* mapforImg = nullptr;//image->pixelsと同じ型にする
			hr = uploadbuff->Map(0, nullptr, (void**)&mapforImg);//マップ
			auto srcAddress = img->pixels;
			auto rowPitch = alignmentedSize(img->rowPitch, D3D12_TEXTURE_DATA_PITCH_ALIGNMENT);
			for (int y = 0; y < img->height; ++y) {
				std::copy_n(srcAddress,
					rowPitch,
					mapforImg);//コピー
				//1行ごとの辻褄を合わせてやる
				srcAddress += img->rowPitch;
				mapforImg += rowPitch;
			}
			uploadbuff->Unmap(0, nullptr);//アンマップ

			dst.pResource = texbuff;
			dst.Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
			dst.SubresourceIndex = 0;

			src.pResource = uploadbuff;//中間バッファ
			src.Type = D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT;//フットプリント指定
			D3D12_PLACED_SUBRESOURCE_FOOTPRINT footprint = {};
			UINT nrow;
			UINT64 rowsize, size;
			auto desc = texbuff->GetDesc();
			DX12Device::getInstance().Get()->GetCopyableFootprints(&desc, 0, 1, 0, &footprint, &nrow, &rowsize, &size);
			src.PlacedFootprint = footprint;
			src.PlacedFootprint.Offset = 0;
			src.PlacedFootprint.Footprint.Width = _texMetaData.width;
			src.PlacedFootprint.Footprint.Height = _texMetaData.height;
			src.PlacedFootprint.Footprint.Depth = _texMetaData.depth;
			src.PlacedFootprint.Footprint.RowPitch = alignmentedSize(img->rowPitch, D3D12_TEXTURE_DATA_PITCH_ALIGNMENT);
			src.PlacedFootprint.Footprint.Format = img->format;
		}

		void Texture::MapGPUMemomry(ID3D12CommandAllocator* cmdAllocator, ID3D12GraphicsCommandList* cmdList, ID3D12CommandQueue* cmdQueue)
		{
			Fence fence;
			HRESULT hr = fence.Create();

			cmdList->CopyTextureRegion(&dst, 0, 0, 0, &src, nullptr);

			D3D12_RESOURCE_BARRIER BarrierDesc = {};
			BarrierDesc.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
			BarrierDesc.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
			BarrierDesc.Transition.pResource = texbuff;
			BarrierDesc.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
			BarrierDesc.Transition.StateBefore = D3D12_RESOURCE_STATE_COPY_DEST;
			BarrierDesc.Transition.StateAfter = D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE;

			cmdList->ResourceBarrier(1, &BarrierDesc);
			hr = cmdList->Close();
			//コマンドリストの実行
			ID3D12CommandList* cmdlists[] = { cmdList };
			cmdQueue->ExecuteCommandLists(1, cmdlists);
			////待ち
			fence.IncrementFenceValue();
			cmdQueue->Signal(fence.Get(), fence.GetFenceValue());

			if (fence.Get()->GetCompletedValue() != fence.GetFenceValue()) {
				auto event = CreateEvent(nullptr, false, false, nullptr);
				fence.Get()->SetEventOnCompletion(fence.GetFenceValue(), event);
				WaitForSingleObject(event, INFINITE);
				CloseHandle(event);
			}
			hr = cmdAllocator->Reset();//キューをクリア
			hr = cmdList->Reset(cmdAllocator, nullptr);
		}

		void Texture::CreateSRV(D3D12_CPU_DESCRIPTOR_HANDLE descHandle)
		{
			//通常テクスチャビュー作成
			D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
			srvDesc.Format = _texMetaData.format;//DXGI_FORMAT_R8G8B8A8_UNORM;//RGBA(0.0f～1.0fに正規化)
			srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;//後述
			srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;//2Dテクスチャ
			srvDesc.Texture2D.MipLevels = 1;//ミップマップは使用しないので1

			DX12Device::getInstance().Get()->CreateShaderResourceView(texbuff, //ビューと関連付けるバッファ
				&srvDesc, //先ほど設定したテクスチャ設定情報
				descHandle//ヒープのどこに割り当てるか
			);
		}

		size_t Texture::alignmentedSize(size_t size, size_t alignment) {
			{
				return size + alignment - size % alignment;
			}
		}
	}
}