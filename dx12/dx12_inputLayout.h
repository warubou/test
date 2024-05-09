#pragma once
#ifndef DX12_INPUT_LAYOUT_H_
#define DX12_INPUT_LAYOUT_H_

#include "dx12_header.h"

namespace ko
{
	namespace dx12
	{
		class InputLayout
		{
		public:

			InputLayout();
			~InputLayout();

			void Set(D3D12_INPUT_ELEMENT_DESC* newInputLayout, size_t ilSize);
			D3D12_INPUT_ELEMENT_DESC* Get(void)const;
			size_t GetSize(void)const;

		private:
			D3D12_INPUT_ELEMENT_DESC* _inputLayout = nullptr;
			size_t _ilSize;
		};
	}
}

#endif // DX12_INPUT_LAYOUT_H_