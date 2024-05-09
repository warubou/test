#include "dx12_inputLayout.h"

namespace ko
{
	namespace dx12
	{
		InputLayout::InputLayout() {}
		InputLayout::~InputLayout() {}

		void InputLayout::Set(D3D12_INPUT_ELEMENT_DESC* newInputLayout, size_t size)
		{
			_inputLayout = newInputLayout;
			_ilSize = size;
		}

		D3D12_INPUT_ELEMENT_DESC* InputLayout::Get(void)const
		{
			return _inputLayout;
		}

		size_t InputLayout::GetSize(void)const
		{
			return _ilSize;
		}
	}
}