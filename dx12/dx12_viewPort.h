#pragma once
#ifndef DX12_VIEW_PORT_H_
#define DX12_VIEW_PORT_H_

#include "dx12_header.h"

namespace ko
{
	namespace dx12
	{
		class ViewPort
		{
		public:
			ViewPort();
			~ViewPort();

			void Set(const D3D12_VIEWPORT& viewPort);
			const D3D12_VIEWPORT& Get(void)const;

		private:
			D3D12_VIEWPORT _viewPort;
		};
	}
}

#endif // DX12_VIEW_PORT_H_