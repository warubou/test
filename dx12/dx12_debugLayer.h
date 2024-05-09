#pragma once
#ifndef DX12_DEBUG_LAYER_H_
#define DX12_DEBUG_LAYER_H_

#include "dx12_header.h"

namespace ko
{
	namespace dx12
	{
		// デバッグレイヤーの有効化
		void EnableDebugLayer() {
			ID3D12Debug* debugLayer = nullptr;
			if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugLayer)))) {
				debugLayer->EnableDebugLayer();
				debugLayer->Release();
			}
		}
	}
}

#endif // DX12_DEBuG_LAYER_H_