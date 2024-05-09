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
				MessageBox(NULL, "�e�N�X�`���ǂݍ��ݎ��s", "Failed", MB_OK);
				return;
			}

			auto img = scratchImg.GetImage(0, 0, 0);//���f�[�^���o

			//�܂��͒��ԃo�b�t�@�Ƃ��Ă�Upload�q�[�v�ݒ�
			D3D12_HEAP_PROPERTIES uploadHeapProp = {};
			uploadHeapProp.Type = D3D12_HEAP_TYPE_UPLOAD;//Upload�p
			uploadHeapProp.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
			uploadHeapProp.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
			uploadHeapProp.CreationNodeMask = 0;//�P��A�_�v�^�̂���0
			uploadHeapProp.VisibleNodeMask = 0;//�P��A�_�v�^�̂���0

			D3D12_RESOURCE_DESC resDesc = {};
			resDesc.Format = DXGI_FORMAT_UNKNOWN;
			resDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;//�P�Ȃ�o�b�t�@�Ƃ���
			auto pixelsize = scratchImg.GetPixelsSize();
			resDesc.Width = alignmentedSize(img->rowPitch, D3D12_TEXTURE_DATA_PITCH_ALIGNMENT) * img->height;//�f�[�^�T�C�Y

			resDesc.Height = 1;//
			resDesc.DepthOrArraySize = 1;//
			resDesc.MipLevels = 1;
			resDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;//�A�������f�[�^�ł���
			resDesc.Flags = D3D12_RESOURCE_FLAG_NONE;//�Ƃ��Ƀt���O�Ȃ�
			resDesc.SampleDesc.Count = 1;//�ʏ�e�N�X�`���Ȃ̂ŃA���`�F�����Ȃ�
			resDesc.SampleDesc.Quality = 0;//


			//���ԃo�b�t�@�쐬
			HRESULT hr = DX12Device::getInstance().Get()->CreateCommittedResource(
				&uploadHeapProp,
				D3D12_HEAP_FLAG_NONE,//���Ɏw��Ȃ�
				&resDesc,
				D3D12_RESOURCE_STATE_GENERIC_READ,//CPU���珑�����݉\
				nullptr,
				IID_PPV_ARGS(&uploadbuff)
			);

			//���Ƀe�N�X�`���̂��߂̃q�[�v�ݒ�
			D3D12_HEAP_PROPERTIES texHeapProp = {};
			texHeapProp.Type = D3D12_HEAP_TYPE_DEFAULT;//�e�N�X�`���p
			texHeapProp.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
			texHeapProp.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
			texHeapProp.CreationNodeMask = 0;//�P��A�_�v�^�̂���0
			texHeapProp.VisibleNodeMask = 0;//�P��A�_�v�^�̂���0

			//���\�[�X�ݒ�(�ϐ��͎g���܂킵)
			resDesc.Format = _texMetaData.format;
			resDesc.Width = _texMetaData.width;//��
			resDesc.Height = _texMetaData.height;//����
			resDesc.DepthOrArraySize = _texMetaData.arraySize;//2D�Ŕz��ł��Ȃ��̂łP
			resDesc.MipLevels = _texMetaData.mipLevels;//�~�b�v�}�b�v���Ȃ��̂Ń~�b�v���͂P��
			resDesc.Dimension = static_cast<D3D12_RESOURCE_DIMENSION>(_texMetaData.dimension);//2D�e�N�X�`���p
			resDesc.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;

			//�e�N�X�`���o�b�t�@�쐬
			hr = DX12Device::getInstance().Get()->CreateCommittedResource(
				&texHeapProp,
				D3D12_HEAP_FLAG_NONE,//���Ɏw��Ȃ�
				&resDesc,
				D3D12_RESOURCE_STATE_COPY_DEST,//�R�s�[��
				nullptr,
				IID_PPV_ARGS(&texbuff)
			);
			uint8_t* mapforImg = nullptr;//image->pixels�Ɠ����^�ɂ���
			hr = uploadbuff->Map(0, nullptr, (void**)&mapforImg);//�}�b�v
			auto srcAddress = img->pixels;
			auto rowPitch = alignmentedSize(img->rowPitch, D3D12_TEXTURE_DATA_PITCH_ALIGNMENT);
			for (int y = 0; y < img->height; ++y) {
				std::copy_n(srcAddress,
					rowPitch,
					mapforImg);//�R�s�[
				//1�s���Ƃ̒�������킹�Ă��
				srcAddress += img->rowPitch;
				mapforImg += rowPitch;
			}
			uploadbuff->Unmap(0, nullptr);//�A���}�b�v

			dst.pResource = texbuff;
			dst.Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
			dst.SubresourceIndex = 0;

			src.pResource = uploadbuff;//���ԃo�b�t�@
			src.Type = D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT;//�t�b�g�v�����g�w��
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
			//�R�}���h���X�g�̎��s
			ID3D12CommandList* cmdlists[] = { cmdList };
			cmdQueue->ExecuteCommandLists(1, cmdlists);
			////�҂�
			fence.IncrementFenceValue();
			cmdQueue->Signal(fence.Get(), fence.GetFenceValue());

			if (fence.Get()->GetCompletedValue() != fence.GetFenceValue()) {
				auto event = CreateEvent(nullptr, false, false, nullptr);
				fence.Get()->SetEventOnCompletion(fence.GetFenceValue(), event);
				WaitForSingleObject(event, INFINITE);
				CloseHandle(event);
			}
			hr = cmdAllocator->Reset();//�L���[���N���A
			hr = cmdList->Reset(cmdAllocator, nullptr);
		}

		void Texture::CreateSRV(D3D12_CPU_DESCRIPTOR_HANDLE descHandle)
		{
			//�ʏ�e�N�X�`���r���[�쐬
			D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
			srvDesc.Format = _texMetaData.format;//DXGI_FORMAT_R8G8B8A8_UNORM;//RGBA(0.0f�`1.0f�ɐ��K��)
			srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;//��q
			srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;//2D�e�N�X�`��
			srvDesc.Texture2D.MipLevels = 1;//�~�b�v�}�b�v�͎g�p���Ȃ��̂�1

			DX12Device::getInstance().Get()->CreateShaderResourceView(texbuff, //�r���[�Ɗ֘A�t����o�b�t�@
				&srvDesc, //��قǐݒ肵���e�N�X�`���ݒ���
				descHandle//�q�[�v�̂ǂ��Ɋ��蓖�Ă邩
			);
		}

		size_t Texture::alignmentedSize(size_t size, size_t alignment) {
			{
				return size + alignment - size % alignment;
			}
		}
	}
}