// ------------------------------------------------------------------------------------------------
// windowsSystem.cpp								�E�C���h�E�쐬
// Date 2023/09/22
// Author Keigo Onari
// ------------------------------------------------------------------------------------------------
#include "windowSystem.h"
#include "../dx12/dx12_header.h"
#include <windowsx.h>

//extern HWND g_hWnd;

extern long g_MouseX;
extern long g_MouseY;
extern float g_WindowSizeX;
extern float g_WindowSizeY;

namespace ko {

	// ================================================================
	// ���b�Z�[�W�v���V�[�W���B
	// hWnd�����b�Z�[�W�𑗂��Ă����E�B���h�E�̃n���h���B
	// msg�����b�Z�[�W�̎�ށB
	// wParam��lParam�͈����B
	// ================================================================
	LRESULT CALLBACK MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		case WM_KEYDOWN:
			switch (wParam)
			{
			case VK_ESCAPE:					// [ESC]�L�[�������ꂽ
				DestroyWindow(hWnd);		// �E�B���h�E��j������悤�w������
				break;
			}

			break;
		case WM_MOUSEMOVE:
			//g_MouseX = LOWORD(lParam);
			//g_MouseY = HIWORD(lParam);

			g_MouseX = GET_X_LPARAM(lParam) * SCREEN_WIDTH / g_WindowSizeX;
			g_MouseY = GET_Y_LPARAM(lParam) * SCREEN_HEIGHT / g_WindowSizeY;
			break;
		case WM_SIZE:
			g_WindowSizeX = static_cast<float>(LOWORD(lParam));
			g_WindowSizeY = static_cast<float>(HIWORD(lParam));
			break;
		//case WM_SYSCOMMAND: // alt�L�[�𖳌���
		//	switch (wParam)
		//	{
		//	case SC_KEYMENU:
		//		SetActiveWindow(hWnd);
		//		return 0;
		//	}

		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}

		return 0;
	}

	// ================================================================
	// �E�B���h�E�̏�����
	// ================================================================
	bool WindowsSystem::InitWindow(HWND* hWnd, HINSTANCE hInstance, const TCHAR* appName, int width, int height)
	{
		//�E�B���h�E�N���X�̃p�����[�^��ݒ�(�P�Ȃ�\���̂̕ϐ��̏������ł��B)
		WNDCLASSEX wc =
		{
			sizeof(WNDCLASSEX),		//�\���̂̃T�C�Y�B
			CS_CLASSDC,				//�E�B���h�E�̃X�^�C���B
			//�����̎w��ŃX�N���[���o�[��������ł��邪�A�Q�[���ł͕s�v�Ȃ̂�CS_CLASSDC�ł悢�B
			MsgProc,				//���b�Z�[�W�v���V�[�W��(��q)
			0,						//0�ł����B
			0,						//0�ł����B
			GetModuleHandle(NULL),	//���̃N���X�̂��߂̃E�C���h�E�v���V�[�W��������C���X�^���X�n���h���B
			//�����C�ɂ��Ȃ��Ă悢�B
			NULL,					//�A�C�R���̃n���h���B�A�C�R����ς������ꍇ������ύX����B�Ƃ肠��������ł����B
			LoadCursor(NULL, IDC_ARROW),					//�}�E�X�J�[�\���̃n���h���BNULL�̏ꍇ�̓f�t�H���g�B
			(HBRUSH)(COLOR_WINDOW + 1),					//�E�B���h�E�̔w�i�F�BNULL�̏ꍇ�̓f�t�H���g�B
			NULL,					//���j���[���BNULL�ł����B
			appName,				//�E�B���h�E�N���X�ɕt���閼�O�B
			NULL					//NULL�ł����B
		};

		wc.hInstance = hInstance;

		//�E�B���h�E�N���X�̓o�^�B
		RegisterClassEx(&wc);

		// �E�B���h�E�̍쐬�B
		*hWnd = CreateWindow(
			appName,				//�g�p����E�B���h�E�N���X�̖��O�B
			//��قǍ쐬�����E�B���h�E�N���X�Ɠ������O�ɂ���B
			appName,				//�E�B���h�E�̖��O�B�E�B���h�E�N���X�̖��O�ƕʖ��ł��悢�B
			WS_OVERLAPPEDWINDOW,	//�E�B���h�E�X�^�C���B�Q�[���ł͊�{�I��WS_OVERLAPPEDWINDOW�ł����A
			0,						//�E�B���h�E�̏���X���W�B
			0,						//�E�B���h�E�̏���Y���W�B
			width + GetSystemMetrics(SM_CXDLGFRAME) * 2,
			height + GetSystemMetrics(SM_CXDLGFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION),
			NULL,					//�e�E�B���h�E�B�Q�[���ł͊�{�I��NULL�ł����B
			NULL,					//���j���[�B����NULL�ł����B
			hInstance,				//�A�v���P�[�V�����̃C���X�^���X�B
			NULL
		);

		return true;
	}

	void WindowsSystem::Show(HWND* hWnd)
	{
		ShowWindow(*hWnd, SW_SHOW);
	}

	// ================================================================
	// ���[�v
	// ================================================================
	bool WindowsSystem::DispatchWindowMessage()
	{
		MSG msg = { 0 };
		while (WM_QUIT != msg.message) {
			//�E�B���h�E����̃��b�Z�[�W���󂯎��B
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else {
				//�E�B���h�E���b�Z�[�W����ɂȂ����B
				break;
			}
		}
		return msg.message != WM_QUIT;
	}
}