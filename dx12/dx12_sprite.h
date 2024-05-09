#pragma once
#ifndef DX12_SPRITE_H_
#define DX12_SPRITE_H_

#include "dx12_texture.h"
#include "dx12_inputLayout.h"
#include "dx12_shader.h"
#include "dx12_graphicsPipeline.h"
#include "dx12_rootSignature.h"
#include "dx12_vertexBuffer.h"
#include "dx12_descriptorHeap.h"
#include "dx12_constantBuffer.h"
#include <string>

namespace ko
{
	namespace dx12
	{
		class Sprite
		{
		public:
			HRESULT Init(const std::wstring& filePath);
			void Update(void);
			void Draw(void);
			void Release(void);
		private:
			struct UtilitySpriteC
			{
				Vector2 texScale;
			};

			Texture* _pTexture = nullptr;
			InputLayout* _pInputLayout = nullptr;
			Shader* _pShader = nullptr;
			GraphicsPipeline* _pGpipeline = nullptr;
			RootSignature* _pRootSignature = nullptr;
			VertexBuffer* _pVertexBuffer = nullptr;
			ConstantBuffer* _pConstantBuffer = nullptr;

			DescriptorHeap* _descriptor = nullptr;

			const size_t _VERTEX_NUM = 4;
			const size_t _VIEW_NUM = 2;
			const size_t _VIEW_NUM_FOR_VS = 0;
			const size_t _VIEW_NUM_FOR_PS = 1;
			const size_t _VIEW_NUM_FOR_GS = 1;
		};
	}
}

#endif DX12_SPRITE_H_