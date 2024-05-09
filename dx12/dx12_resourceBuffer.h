#pragma once
#ifndef DX12_RESOURCE_BUFFER_H_
#define DX12_RESOURCE_BUFFER_H_

#include "dx12_header.h"
#include "dx12_device.h"
#include "dx12_helperStruct.h"

namespace ko
{
	namespace dx12
	{
        class ResourceBuffer
        {
        public:
            ResourceBuffer() : _resource(nullptr) {}
            virtual ~ResourceBuffer() { Release(); }

            virtual void SetResourceView(void) {};
            virtual void Map(void) {}
            virtual void Unmap(void) {}

            ID3D12Resource* GetResource(void)const { return _resource; }
            void Release(void) { if (_resource) _resource->Release(); }
        protected:
            ID3D12Resource* _resource;

            HRESULT Create(HeapType type, size_t size) {
                D3D12_HEAP_PROPERTIES heapprop = {};
                heapprop = HELPER_D3D12_HEAP_PROPATIES(type);
                D3D12_RESOURCE_DESC resdesc = {};
                resdesc = HELPER_D3D12_RESOURCE_DESC(size);

                return DX12Device::getInstance().Get()->CreateCommittedResource(
                    &heapprop,
                    D3D12_HEAP_FLAG_NONE,
                    &resdesc,
                    D3D12_RESOURCE_STATE_GENERIC_READ,
                    nullptr,
                    IID_PPV_ARGS(&_resource)
                );
            }
        };
	}
}

#endif // DX12_RESOURCE_BUFFER_H_