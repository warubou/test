#pragma once
#ifndef DX12_HEADER_H_
#define DX12_HEADER_H_

#include<d3d12.h>
#include<dxgi1_6.h>

#include <Windows.h>

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")

#define SCREEN_WIDTH (1920.0f)
#define SCREEN_HEIGHT (1080.0f)

#define ERROR_CHECK_HRESULT(hResult)\
{\
    if(FAILED(hResult))\
    {\
        (void)MessageBox(NULL, "Failed Create DirectX12 Resource", "Failed", MB_OK | MB_ICONERROR);\
        return hResult;\
    }\
}
#endif // DX12_HEADER_H_