#include "dx12_viewPort.h"

namespace ko
{
	namespace dx12
	{
		ViewPort::ViewPort() {}
		ViewPort::~ViewPort() {}

		void ViewPort::Set(const D3D12_VIEWPORT& viewPort)
		{
			_viewPort = viewPort;
		}

		const D3D12_VIEWPORT& ViewPort::Get(void)const
		{
			return _viewPort;
		}
	}
}