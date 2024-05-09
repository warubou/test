#pragma once
#ifndef DX12_VERTEX_BUFFER_H_
#define DX12_VERTEX_BUFFER_H_

#include "dx12_header.h"
#include "dx12_resourceBuffer.h"
#include "dx12_helperStruct.h"
#include "../vector/vector.h"

namespace ko
{
	namespace dx12
	{
		struct Vertex
		{
			Vector3 position;
			Vector2 uv;
		};

		class VertexBuffer : public ResourceBuffer
		{
		public:
			VertexBuffer();
			~VertexBuffer()override;
			
			HRESULT Create(size_t size);
			void SetResourceView(void)override;
			void SetResourceView(size_t, size_t);
			void Map(void)override;
			void Map(Vector3* buffer);
			void Unmap(void)override;

			void SetPoint(void) {

				Vertex* vert = nullptr;
				HRESULT hr = _resource->Map(0, nullptr, (void**)&vert);
				vert->position = _point.position;
				vert->uv = _point.uv;
				_resource->Unmap(0, nullptr);

				_vbView.BufferLocation = _resource->GetGPUVirtualAddress();
				_vbView.SizeInBytes = sizeof(_point);
				_vbView.StrideInBytes = sizeof(_point);
			};
			

			const D3D12_VERTEX_BUFFER_VIEW& Get(void)const;

		private:
			Vertex _vec[4] = {
				{{-0.4f,-0.7f,0.0f}, {0.0f,1.0f}}, // ç∂â∫
				{{-0.4f, 0.7f,0.0f}, {0.0f,0.0f}}, // ç∂è„
				{{ 0.4f,-0.7f,0.0f}, {1.0f,1.0f}}, // âEâ∫
				{{ 0.4f, 0.7f,0.0f}, {1.0f,0.0f}}, // âEè„
			};

			Vertex _point = { {0.0f,0.0f,0.0f}, {0.0f,0.0f} };

			D3D12_VERTEX_BUFFER_VIEW _vbView = {};
		};
	}
}

#endif // DX12_VERTEX_BUFFER_H_