#include "dx12_vertexBuffer.h"
#include "dx12_device.h"

namespace ko
{
	namespace dx12
	{
		VertexBuffer::VertexBuffer() {}
		VertexBuffer::~VertexBuffer() {}
		
		HRESULT VertexBuffer::Create(size_t size)
		{
			return ResourceBuffer::Create(_VERTEX_HEAP, size);
		}

		void VertexBuffer::SetResourceView(void)
		{
			_vbView.BufferLocation = _resource->GetGPUVirtualAddress();
			_vbView.SizeInBytes = sizeof(_vec);
			_vbView.StrideInBytes = sizeof(_vec[0]);
		}

		void VertexBuffer::SetResourceView(size_t sizeofBuffer, size_t sizeofIndexPerOne)
		{
			_vbView.BufferLocation = _resource->GetGPUVirtualAddress();
			_vbView.SizeInBytes = sizeofBuffer;
			_vbView.StrideInBytes = sizeofIndexPerOne;
		}

		void VertexBuffer::Map(void)
		{
			Vertex* vec = nullptr;
			HRESULT hr = _resource->Map(0, nullptr, (void**)&vec);
			vec[0] = _vec[0];
			vec[1] = _vec[1];
			vec[2] = _vec[2];
			vec[3] = _vec[3];
		}

		void VertexBuffer::Map(Vector3* buffer)
		{
			HRESULT hr = _resource->Map(0, nullptr, (void**)&buffer);
		}

		void VertexBuffer::Unmap(void)
		{
			_resource->Unmap(0, nullptr);
		}
		
		const D3D12_VERTEX_BUFFER_VIEW& VertexBuffer::Get(void)const
		{
			return _vbView;
		}
	}
}