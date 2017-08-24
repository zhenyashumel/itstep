#include<windows.h>
#include"resource.h"
#include<CommCtrl.h>
#include<string>
#pragma comment (lib, "comctl32")
#include <string>
#define time 228

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	INITCOMMONCONTROLSEX cc;
	cc.dwSize = sizeof(cc);
	cc.dwICC == ICC_WIN95_CLASSES;
	InitCommonControlsEx(&cc);
	HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(WindowMain), NULL, DlgProc);
	ShowWindow(hWnd, true);

	MSG iMsg;
	while (GetMessage(&iMsg, NULL, NULL, 0))
	{
		TranslateMessage(&iMsg);
		DispatchMessage(&iMsg);
		if (iMsg.message == WM_SYSKEYDOWN || iMsg.message == WM_CHAR)
		{
			SendMessage(hWnd, iMsg.message, iMsg.wParam, iMsg.lParam);
		}
	}
	return iMsg.wParam;

}

BOOL CALLBACK DlgProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HWND prog, slide;
	static HWND Status;
	prog = GetDlgItem(hWnd, Progress);
	slide = GetDlgItem(hWnd, Slider);
	switch (iMsg)
	{

	case WM_INITDIALOG:

		SendMessage(prog, PBM_SETBKCOLOR, 0, (LPARAM)RGB(5, 233, 188));
		SendMessage(prog, PBM_SETBARCOLOR, 0, (LPARAM)RGB(5, 5, 233));
		SendMessage(prog, PBM_SETRANGE, 0, MAKELPARAM(0, 100));
		SendMessage(prog, PBM_SETSTEP, 1,0);

		SendMessage(slide, TBM_SETRANGE, 0, MAKELPARAM(0, 100));
		SendMessage(slide, TBM_SETPOS, true, 50);
		SendMessage(slide, TBM_SETLINESIZE, 0, 20);

		Status = CreateWindowEx(NULL,
			STATUSCLASSNAME,
			NULL,
			WS_CHILD | WS_VISIBLE |
			SBARS_TOOLTIPS | SBARS_SIZEGRIP,
			CW_USEDEFAULT, CW_USEDEFAULT,
			CW_USEDEFAULT, CW_USEDEFAULT,
			hWnd,
			(HMENU)NULL,
			GetModuleHandle(NULL),
			NULL);

		SendMessage(slide, SB_SIMPLE, true, 0);
		SendMessage(Status, SB_SETTEXT, 0, (LPARAM)L"Hello");
		return true;
		break;
	case WM_COMMAND:
	
		if (LOWORD(wParam) == IDOK)
		{
			DestroyWindow(hWnd);
			PostQuitMessage(0);
		}

		else if (LOWORD(wParam) == IDCANCEL)
		{
			if (MessageBox(hWnd, L"Хотите выйти ?", L"Информация", MB_YESNO) == IDYES)
			{
				DestroyWindow(hWnd);
				PostQuitMessage(0);
			}
		}
		else if (LOWORD(wParam) == Button)
		{
			SetTimer(hWnd, time, 20, NULL);
		}
		return true;

	case WM_HSCROLL:
		if (LOWORD(wParam) == TB_THUMBTRACK || LOWORD(wParam) == TB_LINEDOWN ||
			LOWORD(wParam) == TB_LINEUP || LOWORD(wParam) == TB_PAGEUP || LOWORD(wParam) == TB_PAGEDOWN
			|| LOWORD(wParam) == TB_BOTTOM || LOWORD(wParam) == TB_TOP)
		{
			int pos = SendMessage(slide, TBM_GETPOS, 0, 0);
			SendMessage(prog, PBM_SETPOS, pos, 0);
		}
		return true;
	case WM_TIMER:
		SendMessage(prog, PBM_DELTAPOS, 1, 0);
		//SendMessage(prog, PBM_STEPIT, 0, 0);

			return true;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		KillTimer(hWnd, time);
		return true;

			
	}
	return false;
}
