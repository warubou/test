#pragma once
#ifndef DX12_HELPER_STRUCT_H_
#define DX12_HELPER_STRUCT_H_

#include "dx12_header.h"
#include "dx12_shader.h"

namespace ko
{
	namespace dx12
	{
		enum DescriptorHeapDescType
		{
			_RTV = 0,
			_CBV_SRV_UAV,
			_DSV,
		};

		enum HeapType
		{
			_VERTEX_HEAP = 0,
			_INDEX_HEAP,
			_CONSTANT_HEAP,
		};

		enum ViewType
		{
			_SRV = 0,
			_CBV,
			_UAV,
		};

		struct HELPER_D3D12_DESCRIPTOR_HEAP_DESC : public D3D12_DESCRIPTOR_HEAP_DESC
		{
			HELPER_D3D12_DESCRIPTOR_HEAP_DESC(DescriptorHeapDescType descriptorHeapType, UINT descriptorNum)
			{
				switch (descriptorHeapType)
				{
				case _RTV:
					Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;		// RTV
					Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;	// 特に指定なし
					NodeMask = 0;
					break;
				case _CBV_SRV_UAV:
					Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;//シェーダリソースビュー(および定数、UAVも)
					Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;//シェーダから見えるように
					NodeMask = 0;//マスクは0
					break;
				case _DSV:
					break;
				}

				NumDescriptors = descriptorNum;				// 表裏の2つ
			}
		};

		struct HELPER_D3D12_HEAP_PROPATIES : public D3D12_HEAP_PROPERTIES
		{
			HELPER_D3D12_HEAP_PROPATIES(HeapType heapType, UINT creationNodeMask = 1, UINT visibleNodeMask = 1)
			{
				switch (heapType)
				{
				case _VERTEX_HEAP:
				case _INDEX_HEAP:
				case _CONSTANT_HEAP:
					Type = D3D12_HEAP_TYPE_UPLOAD;
					CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
					MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
					CreationNodeMask = creationNodeMask;
					VisibleNodeMask = visibleNodeMask;
					break;
				}
			}
		};
		
		struct HELPER_D3D12_RESOURCE_DESC : public D3D12_RESOURCE_DESC
		{
			HELPER_D3D12_RESOURCE_DESC(size_t bufferSize, D3D12_RESOURCE_FLAGS flags = D3D12_RESOURCE_FLAG_NONE, UINT64 alignment = 0)
			{
				Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
				Width = bufferSize;
				Height = 1;
				DepthOrArraySize = 1;
				MipLevels = 1;
				Format = DXGI_FORMAT_UNKNOWN;
				SampleDesc.Count = 1;
				SampleDesc.Quality = 0;
				Flags = flags;
				Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
				Alignment = alignment;
			}
		};

		struct HELPER_D3D12_DESCRIPTOR_RANGE : public D3D12_DESCRIPTOR_RANGE
		{
			HELPER_D3D12_DESCRIPTOR_RANGE(ViewType type,UINT baseShaderRegister = 0U, UINT numDescriptors = 1U)
			{
				switch (type) {
				case _SRV:
					RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
					break;
				case _CBV:
					RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_CBV;
					break;
				case _UAV:
					RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_UAV;
					break;
				default:
					break;
				}

				RegisterSpace = 0;
				NumDescriptors = numDescriptors;
				BaseShaderRegister = baseShaderRegister;
				OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
			}
		};

		struct HELPER_D3D12_ROOT_PARAMETER : public D3D12_ROOT_PARAMETER
		{
			HELPER_D3D12_ROOT_PARAMETER(ShaderType type, D3D12_DESCRIPTOR_RANGE* range, UINT numDescriptorRange)
			{
				switch (type) {
				case _VS:
					ShaderVisibility = D3D12_SHADER_VISIBILITY_VERTEX;
					break;
				case _PS:
					ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;
					break;
				case _HS:
					ShaderVisibility = D3D12_SHADER_VISIBILITY_HULL;
					break;
				case _DS:
					ShaderVisibility = D3D12_SHADER_VISIBILITY_DOMAIN;
					break;
				case _GS:
					ShaderVisibility = D3D12_SHADER_VISIBILITY_GEOMETRY;
					break;
				case _ALL:
					ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;
					break;
				default:
					break;
				}

				Descriptor.RegisterSpace = 0;
				Constants.RegisterSpace = 0;
				ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
				DescriptorTable.pDescriptorRanges = range;
				DescriptorTable.NumDescriptorRanges = numDescriptorRange;
			}
		};

		enum BLEND_MODE
		{
			_MODE_NONE = 0,		// 通常(上書き)
			_MODE_ADD,			// 加算合成
			_MODE_MULTIPLE,		// 乗算合成
			_MODE_SUBTRACT,		// 減算合成
			_MODE_ALFABLEND,	// αブレンド
		};

		struct HELPER_D3D12_BLEND_DESC : public D3D12_BLEND_DESC
		{
			HELPER_D3D12_BLEND_DESC(BLEND_MODE bm)
			{
				AlphaToCoverageEnable = false;
				IndependentBlendEnable = false;

				D3D12_RENDER_TARGET_BLEND_DESC rtbDesc = {};

				switch (bm)
				{
				case _MODE_NONE:
					rtbDesc.BlendEnable = false;
					rtbDesc.LogicOpEnable = false;
					rtbDesc.RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
					break;
				case _MODE_ADD:
					rtbDesc.BlendEnable = true;
					rtbDesc.LogicOpEnable = false;
					rtbDesc.BlendOp = D3D12_BLEND_OP_ADD;
					rtbDesc.SrcBlend = D3D12_BLEND_ONE;
					rtbDesc.DestBlend = D3D12_BLEND_ONE;
					break;
				case _MODE_MULTIPLE:
					rtbDesc.BlendEnable = true;
					rtbDesc.LogicOpEnable = false;
					rtbDesc.BlendOp = D3D12_BLEND_OP_ADD;
					rtbDesc.SrcBlend = D3D12_BLEND_ZERO;
					rtbDesc.DestBlend = D3D12_BLEND_SRC_COLOR;
					break;
				case _MODE_SUBTRACT:
					rtbDesc.BlendEnable = true;
					rtbDesc.LogicOpEnable = false;
					rtbDesc.BlendOp = D3D12_BLEND_OP_SUBTRACT;
					rtbDesc.SrcBlend = D3D12_BLEND_SRC_ALPHA;
					rtbDesc.DestBlend = D3D12_BLEND_ONE;
					break;
				case _MODE_ALFABLEND:
					rtbDesc.BlendEnable = true;
					rtbDesc.LogicOpEnable = false;
					rtbDesc.BlendOp = D3D12_BLEND_OP_ADD;
					rtbDesc.SrcBlend = D3D12_BLEND_SRC_ALPHA;
					rtbDesc.DestBlend = D3D12_BLEND_INV_SRC_ALPHA;
					rtbDesc.RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
					rtbDesc.BlendOpAlpha = D3D12_BLEND_OP_ADD;
					rtbDesc.SrcBlendAlpha = D3D12_BLEND_ONE;
					rtbDesc.DestBlendAlpha = D3D12_BLEND_INV_SRC_ALPHA;
					rtbDesc.LogicOp = D3D12_LOGIC_OP_NOOP;
					break;
				}

				RenderTarget[0] = rtbDesc;
			}
		};

		struct HELPER_D3D12_VIEWPORT : public D3D12_VIEWPORT
		{
			HELPER_D3D12_VIEWPORT(const FLOAT& width, const FLOAT& height)
			{
				Width = width;
				Height = height;
				TopLeftX = 0.0f;
				TopLeftY = 0.0f;
				MaxDepth = 1.0f;
				MinDepth = 0.0f;
			}
		};

		struct HELPER_D3D12_RECT : public D3D12_RECT
		{
			HELPER_D3D12_RECT(LONG width, LONG height)
			{
				left = 0;
				right = left + width;
				top = 0;
				bottom = top + height;
			}
		};
	}
}

#endif // DX12_HELPER_STRUCT_H_