#pragma once
#ifndef DX12_INDEX_BUFFER_H_
#define DX12_INDEX_BUFFER_H_

#include "dx12_header.h"
#include "dx12_resourceBuffer.h"

namespace ko
{
	namespace dx12
	{
		class IndexBuffer : public ResourceBuffer
		{
		public:
			IndexBuffer();
			~IndexBuffer()override;

			HRESULT Create(unsigned short* indices, size_t indexNum);
			void SetResourceView(void)override;
			void Map(void)override;
			void Unmap(void)override;

			const D3D12_INDEX_BUFFER_VIEW& Get(void)const;

		private:
			unsigned short* _indices = nullptr;
			size_t _indexNum = 0;
			D3D12_INDEX_BUFFER_VIEW _ibView = {};
		};
	}
}
#endif // DX12_INDEX_BUFFER_H_