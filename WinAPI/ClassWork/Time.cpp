#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
#include<map>
#include"resource.h"
#include<CommCtrl.h>
#include<string>
#include<ctime>
#pragma comment (lib, "comctl32")

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

void init(std::map< std::wstring, std::pair<int, std::wstring>> &mp)
{
	mp.insert({ L"C++", {10, L"Ну он же создатель"} });
	mp.insert({ L"WinAPI",{ 9, L"Здесь может быть ваша реклама" } });
	mp.insert({ L"Python",{ 2, L"Oops..." } });
}

std::wstring times()
{
	struct tm *tim;
	time_t tt;
	std::wstring str;
	tt = time(NULL);
	tim = localtime(&tt);
	str = L"";
	if (tim->tm_hour >= 10)
		str += std::to_wstring(tim->tm_hour);
	else
	{
		str += '0';
		str += std::to_wstring(tim->tm_hour);
	}

	str += ':';

	if (tim->tm_min >= 10)
		str += std::to_wstring(tim->tm_min);
	else
	{
		str += '0';
		str += std::to_wstring(tim->tm_min);
	}
	str += ':';

	if (tim->tm_sec >= 10)
		str += std::to_wstring(tim->tm_sec);
	else
	{
		str += '0';
		str += std::to_wstring(tim->tm_sec);
	}
	return str;

}

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

BOOL CALLBACK DlgProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	
	static std::wstring str, str2;
	static HWND Status, com, statMark, statInfo;
	static std::map< std::wstring, std::pair<int, std::wstring>> marks;
	auto it = marks.begin();
	static int parts[4] = { 50, 100, 160, -1 };
	static	HMENU hMenu;
	switch (iMsg)
	{
	
	case WM_INITDIALOG:
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
		hMenu = GetMenu(hWnd);
	EnableMenuItem(hMenu, ID_OPEN, MF_BYCOMMAND | MF_DISABLED);
		str = times();

		
		
		SendMessage(Status, SB_SIMPLE, false, 0);
		SendMessage(Status, SB_SETPARTS, 4, LPARAM(parts));
		SendMessage(Status, SB_SETTEXT, 0, (LPARAM)L"It Step");
		SendMessage(Status, SB_SETTEXT, 1, (LPARAM)str.c_str());
	
		SendMessage(Status, SB_SETTEXT, 3, (LPARAM)L"© ZhenyaProduction, Inc.");
		SetTimer(hWnd, 228, 1000, NULL);
		
		com = GetDlgItem(hWnd, Combo);
		statMark = GetDlgItem(hWnd, StatMark);
		statInfo = GetDlgItem(hWnd, StatInfo);
		init(marks);
		
		it = marks.begin();
		for (int i = 0; i < marks.size(); ++i, ++it)
			SendMessage(com, CB_ADDSTRING, 0, LPARAM(it->first.c_str()));
		
	case WM_TIMER:
		if (wParam == 228)
		{
			
			str = times();			
			SendMessage(Status, SB_SETTEXT, 1, (LPARAM)str.c_str());
			
		
			RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_UPDATENOW);
		}
		return true;
	case WM_COMMAND:

		if (LOWORD(wParam) == ButtonShow)
		{
			wchar_t buf[50];
			GetWindowText(com, buf, sizeof(buf));
			std::wstring str = L"Оценка: ";
			int mark = marks[buf].first;
			str += std::to_wstring(mark);
			std::wstring str1 = marks[buf].second;
			SetWindowText(statMark, str.c_str());
			SetWindowText(statInfo, str1.c_str());
		}
		return true;

	case WM_CLOSE:
		KillTimer(hWnd, 228);
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		
		return true;


	}
	return false;
}
