#include<windows.h>
#include"resource.h"
#include<CommCtrl.h>
#include<commdlg.h>
#pragma comment (lib, "comctl32")

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	LoadLibrary(L"Riched20.dll");
	HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(WindowMain), NULL, DlgProc);
	ShowWindow(hWnd, true);
	HACCEL acc = LoadAccelerators(hInstance, MAKEINTRESOURCE(ID_ACC));

	MSG iMsg;
	while (GetMessage(&iMsg, NULL, NULL, 0))
	{
		if (!TranslateAccelerator(hWnd, acc, &iMsg))
		{
			TranslateMessage(&iMsg);
			DispatchMessage(&iMsg);
		}
		
	}
	return iMsg.wParam;

}

BOOL CALLBACK DlgProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND edit;
	static HWND Status;
	static OPENFILENAME openFile;
	static wchar_t fileName[256];
	static wchar_t fileTitle[256];
	RECT rect;
	static HMENU hMenu;
	
	switch (iMsg)
	{

	case WM_INITDIALOG:
		GetClientRect(hWnd, &rect);
		Status = CreateWindowEx(NULL,
			STATUSCLASSNAME,
			NULL,
			WS_CHILD | WS_VISIBLE |
			SBARS_TOOLTIPS | SBARS_SIZEGRIP  | CCS_BOTTOM,
			0, rect.bottom - 10,
			rect.right, 10,
			hWnd,
			(HMENU)NULL,
			GetModuleHandle(NULL),
			NULL);
		edit = GetDlgItem(hWnd, Edit);
		hMenu = LoadMenu(GetModuleHandle(NULL), MAKEINTRESOURCE(ID_MENU));
		SetMenu(hWnd, hMenu);
		SendMessage(Status, SB_SIMPLE, true, 0);
		SendMessage(Status, SB_SETTEXT, 255, (LPARAM)L"Hello");
		EnableMenuItem(hMenu, ID_FONT, MF_BYCOMMAND |MF_GRAYED);
		CheckMenuItem(hMenu, ID_STATUS, MF_BYCOMMAND | MF_CHECKED);


		ZeroMemory(&openFile, sizeof(OPENFILENAME));
		openFile.lStructSize = sizeof(OPENFILENAME);
		openFile.hInstance = GetModuleHandle(NULL);
		openFile.hwndOwner = hWnd;
		openFile.lpstrFilter = L"Левый Документ(*.txt)\0*.txt\0\0";
		openFile.nMaxFile = 256;
		openFile.lpstrDefExt = L"txt";
		openFile.lpstrFileTitle = fileTitle;
		openFile.lpstrFile = fileName;

		return true;
		
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{

		case ID_OPEN:
			GetOpenFileName(&openFile);
			break;


		case ID_ABOUT:
			MessageBox(hWnd, L"ZhenyaProduction, Inc.", L"About", NULL);
			break;


		case ID_CUT:
			SendMessage(edit, WM_CUT, 0, 0);
			break;


		case ID_COPY:
			SendMessage(edit, WM_COPY, 0, 0);
			break;


		case ID_INSERT:
			SendMessage(edit, WM_PASTE, 0, 0);
			break;


		case ID_DELETE:
			SetWindowText(edit, L"");
			break;


		case ID_EXIT:
			SendMessage(hWnd, WM_CLOSE, 0, 0);
			break;
		}
		
	
		return true;
	case WM_SIZE:
		GetClientRect(hWnd, &rect);
		MoveWindow(edit, 0, 0, rect.right, rect.bottom, true);
		MoveWindow(Status, 0, rect.bottom, rect.right, 10, true);
		return true;


	case WM_CLOSE:
		KillTimer(hWnd, 228);
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;



	}
	return false;
}