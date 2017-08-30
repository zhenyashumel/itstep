#include<Windows.h>
#include<vector>
#include<string>
#include<ctime>
#include<CommCtrl.h>
#pragma comment (lib, "comctl32")
#include"resource.h"
#define GameOver 876
#define ProgressTimer 228

void sort(std::vector<int> A, int size)
{
	for (int d = size / 2; d > 0; d /= 2)
	{
		for (int i = d, j; i < size; i++)
		{
			int temp = A[i];
			for (j = i; j >= d; j -= d)
			{
				if (temp < A[j - d])
					A[j] = A[j - d];
				else break;
			}
			A[j] = temp;
		}
	}
}
BOOL CALLBACK DlgProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

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
	static int timer;
	static std::vector<int> numb;
	static HWND list, edit, spin, prog;
	static HWND but1, but2, but3, but4, but5, but6, but7, but8,
		but9, but10, but11, but12, but13, but14, but15, but16;

	switch (iMsg)
	{
	case WM_INITDIALOG:	
		prog = GetDlgItem(hWnd, Progress);
		but1 = GetDlgItem(hWnd, Button1);
		but2 = GetDlgItem(hWnd, Button2);
		but3 = GetDlgItem(hWnd, Button3);
		but4 = GetDlgItem(hWnd, Button4);
		but5 = GetDlgItem(hWnd, Button5);
		but6 = GetDlgItem(hWnd, Button6);
		but7 = GetDlgItem(hWnd, Button7);
		but8 = GetDlgItem(hWnd, Button8);
		but9 = GetDlgItem(hWnd, Button9);
		but10 = GetDlgItem(hWnd, Button10);
		but11 = GetDlgItem(hWnd, Button11);
		but12 = GetDlgItem(hWnd, Button12);
		but13 = GetDlgItem(hWnd, Button13);
		but14 = GetDlgItem(hWnd, Button14);
		but15 = GetDlgItem(hWnd, Button15);
		but16 = GetDlgItem(hWnd, Button16);
		
		list = GetDlgItem(hWnd, List);
		edit = GetDlgItem(hWnd, Edit);
		spin = GetDlgItem(hWnd, Spin);
		return true;

	case WM_COMMAND:
		if (LOWORD(wParam) == ButtonStart)
		{
			numb.clear();
			
			
			srand((unsigned)time(0));
			for (int i = 0; i < 16; ++i)
			{
				numb.push_back(rand() % 100);						
				
			}
			int index = 0;
			std::wstring tmp = std::to_wstring(numb[index++]);
			SetWindowText(but1, tmp.c_str());
			
			tmp = std::to_wstring(numb[index++]);
			SetWindowText(but2, tmp.c_str());

			tmp = std::to_wstring(numb[index++]);
			SetWindowText(but3, tmp.c_str());

			tmp = std::to_wstring(numb[index++]);
			SetWindowText(but4, tmp.c_str());

			tmp = std::to_wstring(numb[index++]);
			SetWindowText(but5, tmp.c_str());

			tmp = std::to_wstring(numb[index++]);
			SetWindowText(but6, tmp.c_str());

			tmp = std::to_wstring(numb[index++]);
			SetWindowText(but7, tmp.c_str());

			tmp = std::to_wstring(numb[index++]);
			SetWindowText(but8, tmp.c_str());

			tmp = std::to_wstring(numb[index++]);
			SetWindowText(but9, tmp.c_str());

			tmp = std::to_wstring(numb[index++]);
			SetWindowText(but10, tmp.c_str());

			tmp = std::to_wstring(numb[index++]);
			SetWindowText(but11, tmp.c_str());

			tmp = std::to_wstring(numb[index++]);
			SetWindowText(but12, tmp.c_str());

			tmp = std::to_wstring(numb[index++]);
			SetWindowText(but13, tmp.c_str());

			tmp = std::to_wstring(numb[index++]);
			SetWindowText(but14, tmp.c_str());

			tmp = std::to_wstring(numb[index++]);
			SetWindowText(but15, tmp.c_str());

			tmp = std::to_wstring(numb[index]);
			SetWindowText(but16, tmp.c_str());

			wchar_t buf[5];
			GetWindowText(edit, buf, 5);
			std::wstring temp = buf;
			timer = stoi(temp);

			SendMessage(prog, PBM_SETRANGE, 0, MAKELPARAM(0, timer));
			SendMessage(prog, PBM_SETPOS, 0, 0);
			SetTimer(hWnd, ProgressTimer, 1000, NULL);
			SetTimer(hWnd, GameOver, timer * 1000 + 1, NULL);
		
		}

		return true;
	case WM_TIMER:
		if (wParam == ProgressTimer)
		{
			SendMessage(prog, PBM_DELTAPOS, 1, 0);
		}
		else if (wParam == GameOver)
		{
			KillTimer(hWnd, ProgressTimer);
			KillTimer(hWnd, GameOver);
			MessageBox(hWnd, L"Игра проиграна", L"Конец игры", NULL);
		}
		return true;

	case WM_VSCROLL:
		
		if (LOWORD(wParam) == SB_THUMBPOSITION)
		{
			wchar_t buf1[5];
			GetWindowText(edit, buf1, 5);
			std::wstring temp = buf1;
			int x = stoi(temp);
			++x;
			temp = std::to_wstring(x);
			SetWindowText(edit, temp.c_str());
		}
		return true;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;
	}
	return false;
}
