#include<Windows.h>
#include"resource.h"

BOOL CALLBACK DlgProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DlgProc2(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow)
{

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

BOOL CALLBACK DlgProc2(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{

	case WM_INITDIALOG:
		return true;

	case WM_CLOSE:
		EndDialog(hWnd, 0);
		
		return true;
	}
	return false;
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	

	switch (iMsg)
	{

	case WM_INITDIALOG:
		return true;
	case WM_COMMAND:
		if (LOWORD(wParam) == Button)
		{
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(Dialog), hWnd, DlgProc2);
		}
		return true;

	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;
	}
	return false;
}
