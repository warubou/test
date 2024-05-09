#include "dx12_scissorRect.h"

namespace ko
{
	namespace dx12
	{
		ScissorRect::ScissorRect() {}
		ScissorRect::~ScissorRect(){}

		void ScissorRect::Set(const D3D12_RECT& scissorRect)
		{
			_scissorRect = scissorRect;
		}

		const D3D12_RECT& ScissorRect::Get(void)const
		{
			return _scissorRect;
		}
	}
}