// ------------------------------------------------------------------------------------------------
// windowsSystem.h								�E�C���h�E�쐬
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
	// �E�C���h�E�쐬�N���X
	// ================================================================
	class WindowsSystem {	
	public:
		// ================================================================
		// �E�C���h�E�̏�����
		// �����F�E�C���h�E�̃n���h���A�A�v���P�[�V�����n���h���A�A�v���̖��O�A���A����
		// �����F���̖��̒ʂ�
		// ================================================================
		bool InitWindow(HWND* hWnd, HINSTANCE hInstance, const TCHAR* appName, int width, int height);

		void Show(HWND* hWnd);

		// ================================================================
		//�E�B���h�E���b�Z�[�W���f�B�X�p�b�`�Bfalse���Ԃ��Ă�����A�Q�[���I���B
		// ================================================================
		bool DispatchWindowMessage();

	private:
	};
}

#endif	// W2_WINDOES_SYSTEM_H_
