#include "dx12_indexBuffer.h"
#include "dx12_device.h"
#include "dx12_helperStruct.h"

namespace ko
{
	namespace dx12
	{
		IndexBuffer::IndexBuffer() {}
		IndexBuffer::~IndexBuffer() {}

		HRESULT IndexBuffer::Create(unsigned short* indices, size_t indexNum)
		{
			_indexNum = indexNum;
			_indices = new unsigned short[_indexNum];
			_indices = indices;

			return ResourceBuffer::Create(_INDEX_HEAP, sizeof(unsigned short) * _indexNum);
		}

		void IndexBuffer::SetResourceView(void)
		{
			_ibView.BufferLocation = _resource->GetGPUVirtualAddress();
			_ibView.Format = DXGI_FORMAT_R16_UINT;
			_ibView.SizeInBytes = sizeof(unsigned short) * _indexNum;
		}

		void IndexBuffer::Map(void)
		{
			//作ったバッファにインデックスデータをコピー
			unsigned short* mappedIdx = nullptr;
			HRESULT hr = _resource->Map(0, nullptr, (void**)&mappedIdx);

			for (int index = 0; index < _indexNum; index++)
			{
				mappedIdx[index] = _indices[index];
			}
			//memcpy(mappedIdx, _indices, _indexNum);
		}

		void IndexBuffer::Unmap(void)
		{
			_resource->Unmap(0, nullptr);
		}

		const D3D12_INDEX_BUFFER_VIEW& IndexBuffer::Get(void)const
		{
			return _ibView;
		}
	}
}