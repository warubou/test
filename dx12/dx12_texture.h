#pragma once
#ifndef DX12_TEXTURE_H_ 
#define DX12_TEXTURE_H_ 

#include <DirectXTex.h>
#include <string>
#include "dx12_fence.h"

#include "dx12_header.h"
#include "dx12_helperStruct.h"

#pragma comment(lib, "DirectXTex.lib")

namespace ko
{
	namespace dx12
	{
		class Texture
		{
		public:
			Texture(){}
			Texture(const std::wstring& filePath)
			{
				LoadTexture(filePath);
			}
			Texture(const std::wstring& filePath, ID3D12CommandAllocator* cmdAllcator, ID3D12GraphicsCommandList* cmdList, ID3D12CommandQueue* cmdQueue)
			{
				LoadTexture(filePath);
				MapGPUMemomry(cmdAllcator, cmdList, cmdQueue);
			}


			void LoadTexture(const std::wstring& filePath);
			void MapGPUMemomry(ID3D12CommandAllocator* pCommandAllocator, ID3D12GraphicsCommandList* pCommandList, ID3D12CommandQueue* pCommandQueue);
			void CreateSRV(D3D12_CPU_DESCRIPTOR_HANDLE descHandle);
			const DirectX::TexMetadata& GetTexMetaData(void)const { return _texMetaData; }
			const D3D12_DESCRIPTOR_RANGE& GetDescriptorRange(void) { 
				_descRange = HELPER_D3D12_DESCRIPTOR_RANGE(_SRV);
			return _descRange; }
			const D3D12_ROOT_PARAMETER& GetRootParameter(void) { return HELPER_D3D12_ROOT_PARAMETER(_PS, &_descRange, 1); }
		private:
			DirectX::TexMetadata _texMetaData = {};
			ID3D12Resource* uploadbuff = nullptr;
			ID3D12Resource* texbuff = nullptr;
			D3D12_TEXTURE_COPY_LOCATION src = {};
			D3D12_TEXTURE_COPY_LOCATION dst = {};
			D3D12_DESCRIPTOR_RANGE _descRange = {};

			size_t alignmentedSize(size_t size, size_t alignment);
		};
	}
}

#endif // DX12_TEXTURE_H_