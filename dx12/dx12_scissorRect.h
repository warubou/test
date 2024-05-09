#pragma once
#ifndef DX12_SCISSOR_RECT_H_
#define DX12_SCISSOR_RECT_H_

#include "dx12_header.h"

namespace ko
{
	namespace dx12
	{
		class ScissorRect
		{
		public:
			ScissorRect();
			~ScissorRect();

			void Set(const D3D12_RECT& scissorRect);
			const D3D12_RECT& Get(void)const;

		private:
			D3D12_RECT _scissorRect;
		};
	}
}

#endif // DX12_SCISSOR_RECT_H_