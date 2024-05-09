#pragma once
#ifndef DX12_SINGLETON_GRAPHICS_PIPELINE_H_
#define DX12_SINGLETON_GRAPHICS_PIPELINE_H_

#include "dx12_header.h"
#include <map>

namespace ko
{
	namespace dx12
	{
		class SingletonGraphicsPipeline
		{
		public:
			enum USES_PIPELINE_TYPE
			{
				_SPRITE2D = 0,
				_SPRITE3D,
				_MODEL,
			};

			static SingletonGraphicsPipeline* getInstance(void);

			HRESULT Init(void);
			void Add(USES_PIPELINE_TYPE type, ID3D12PipelineState* pipelineState);
			ID3D12PipelineState* Get(USES_PIPELINE_TYPE type);

		private:
			SingletonGraphicsPipeline() {}
			~SingletonGraphicsPipeline() {}

			static SingletonGraphicsPipeline* instance;

			std::map<USES_PIPELINE_TYPE, ID3D12PipelineState*> _pipelineStatus = {
				{_SPRITE2D, nullptr},
				{_SPRITE3D, nullptr},
				{_MODEL, nullptr}
			};
			std::map<USES_PIPELINE_TYPE, ID3D12RootSignature*> _rootSignature = {
				{_SPRITE2D, nullptr},
				{_SPRITE3D, nullptr},
				{_MODEL, nullptr}
			};

			void createSprite2D(void);
			void createSprite3D(void);
			void createModel(void);
		};
	}
}

#endif // DX12_SINGLETON_GRAPHICS_PIPELINE_H_