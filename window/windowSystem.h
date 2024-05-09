// ------------------------------------------------------------------------------------------------
// windowsSystem.h								ウインドウ作成
// Date 2023/10/05
// Author Keigo Onari
// ------------------------------------------------------------------------------------------------
#pragma once
#ifndef KO_WINDOWS_SYSTEM_H_
#define KO_WINDOWS_SYSTEM_H_

#include <Windows.h>

//#ifndef HINST_THISCOMPONENT
//EXTERN_C IMAGE_DOS_HEADER __ImageBase;
//#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
//#endif

namespace ko {

	// ================================================================
	// ウインドウ作成クラス
	// ================================================================
	class WindowsSystem {	
	public:
		// ================================================================
		// ウインドウの初期化
		// 引数：ウインドウのハンドル、アプリケーションハンドル、アプリの名前、幅、高さ
		// 説明：その名の通り
		// ================================================================
		bool InitWindow(HWND* hWnd, HINSTANCE hInstance, const TCHAR* appName, int width, int height);

		void Show(HWND* hWnd);

		// ================================================================
		//ウィンドウメッセージをディスパッチ。falseが返ってきたら、ゲーム終了。
		// ================================================================
		bool DispatchWindowMessage();

	private:
	};
}

#endif	// W2_WINDOES_SYSTEM_H_
