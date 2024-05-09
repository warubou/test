// ------------------------------------------------------------------------------------------------
// windowsSystem.cpp								ウインドウ作成
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
	// メッセージプロシージャ。
	// hWndがメッセージを送ってきたウィンドウのハンドル。
	// msgがメッセージの種類。
	// wParamとlParamは引数。
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
			case VK_ESCAPE:					// [ESC]キーが押された
				DestroyWindow(hWnd);		// ウィンドウを破棄するよう指示する
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
		//case WM_SYSCOMMAND: // altキーを無効化
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
	// ウィンドウの初期化
	// ================================================================
	bool WindowsSystem::InitWindow(HWND* hWnd, HINSTANCE hInstance, const TCHAR* appName, int width, int height)
	{
		//ウィンドウクラスのパラメータを設定(単なる構造体の変数の初期化です。)
		WNDCLASSEX wc =
		{
			sizeof(WNDCLASSEX),		//構造体のサイズ。
			CS_CLASSDC,				//ウィンドウのスタイル。
			//ここの指定でスクロールバーをつけたりできるが、ゲームでは不要なのでCS_CLASSDCでよい。
			MsgProc,				//メッセージプロシージャ(後述)
			0,						//0でいい。
			0,						//0でいい。
			GetModuleHandle(NULL),	//このクラスのためのウインドウプロシージャがあるインスタンスハンドル。
			//何も気にしなくてよい。
			NULL,					//アイコンのハンドル。アイコンを変えたい場合ここを変更する。とりあえずこれでいい。
			LoadCursor(NULL, IDC_ARROW),					//マウスカーソルのハンドル。NULLの場合はデフォルト。
			(HBRUSH)(COLOR_WINDOW + 1),					//ウィンドウの背景色。NULLの場合はデフォルト。
			NULL,					//メニュー名。NULLでいい。
			appName,				//ウィンドウクラスに付ける名前。
			NULL					//NULLでいい。
		};

		wc.hInstance = hInstance;

		//ウィンドウクラスの登録。
		RegisterClassEx(&wc);

		// ウィンドウの作成。
		*hWnd = CreateWindow(
			appName,				//使用するウィンドウクラスの名前。
			//先ほど作成したウィンドウクラスと同じ名前にする。
			appName,				//ウィンドウの名前。ウィンドウクラスの名前と別名でもよい。
			WS_OVERLAPPEDWINDOW,	//ウィンドウスタイル。ゲームでは基本的にWS_OVERLAPPEDWINDOWでいい、
			0,						//ウィンドウの初期X座標。
			0,						//ウィンドウの初期Y座標。
			width + GetSystemMetrics(SM_CXDLGFRAME) * 2,
			height + GetSystemMetrics(SM_CXDLGFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION),
			NULL,					//親ウィンドウ。ゲームでは基本的にNULLでいい。
			NULL,					//メニュー。今はNULLでいい。
			hInstance,				//アプリケーションのインスタンス。
			NULL
		);

		return true;
	}

	void WindowsSystem::Show(HWND* hWnd)
	{
		ShowWindow(*hWnd, SW_SHOW);
	}

	// ================================================================
	// ループ
	// ================================================================
	bool WindowsSystem::DispatchWindowMessage()
	{
		MSG msg = { 0 };
		while (WM_QUIT != msg.message) {
			//ウィンドウからのメッセージを受け取る。
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else {
				//ウィンドウメッセージが空になった。
				break;
			}
		}
		return msg.message != WM_QUIT;
	}
}