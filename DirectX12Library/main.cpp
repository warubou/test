// ==============================================
// �C���N���[�h
// ==============================================
#include "main.h"
#include <Windows.h>

#include "../window/windowSystem.h"
#include "../dx12/dx12_main.h"
#include "../dx12/dx12_debugLayer.h"
#include "../dx12/dx12_sprite.h"

// ==============================================
// �}�N����`
// ==============================================
#define ENABLE_DEBUG_CONSOLE			// �R���\�[���̗L����

// ==============================================
// ���O��Ԃ̎g�p
// ==============================================
using namespace ko;

// ==============================================
// �O���[�o���ϐ�
// ==============================================
HWND g_hWnd;
long g_MouseX = 0;
long g_MouseY = 0;
float g_WindowSizeX = 0.0f;
float g_WindowSizeY = 0.0f;

#ifdef ENABLE_DEBUG_CONSOLE
int main()
#else
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#endif
{
#ifdef ENABLE_DEBUG_CONSOLE
	HINSTANCE hInstance = GetModuleHandle(nullptr);
	int nCmdShow;
#else
	UNREFERENCED_PARAMETER(hPrevInstance);	// �����Ă��ǂ����ǁA�x�����o��i���g�p�錾�j
	UNREFERENCED_PARAMETER(lpCmdLine);		// �����Ă��ǂ����ǁA�x�����o��i���g�p�錾�j
#endif

	// COM���C�u�����̏�����
	CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

	WindowsSystem ws;

	//g_WindowSizeX = SCREEN_WIDTH * 0.5;
	//g_WindowSizeY = SCREEN_HEIGHT * 0.5;
	g_WindowSizeX = SCREEN_WIDTH;
	g_WindowSizeY = SCREEN_HEIGHT;

	if (!ws.InitWindow(
		&g_hWnd,
		hInstance,
		"DiretctX12Test",
		g_WindowSizeX,
		g_WindowSizeY))
		return -1;

	ko::dx12::EnableDebugLayer();

	ko::dx12::DX12Main dx12Main;
	if (FAILED(dx12Main.MainInitialize(
		&g_hWnd,
		g_WindowSizeX,
		g_WindowSizeY)))
		return -1;

	ws.Show(&g_hWnd);

	ko::dx12::Sprite sprite;
	sprite.Init(L"../data/TEXTURE/airou.png");


	// ���C�����[�v
	while (ws.DispatchWindowMessage())
	{
		dx12Main.BeginDraw();
		sprite.Draw();
		dx12Main.EndDraw();
	}

	return 1;
}