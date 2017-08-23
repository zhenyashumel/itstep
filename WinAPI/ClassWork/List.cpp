#include<windows.h>
#include"resource.h"
#include <string>

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);


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
	static HWND  ed, list, stat, com, te;
	static std::wstring text;
	switch (iMsg)
	{
	
	case WM_INITDIALOG:
		
		ed = GetDlgItem(hWnd, Edit);
		list = GetDlgItem(hWnd, MyList);
		stat = GetDlgItem(hWnd, Counter);
		com = GetDlgItem(hWnd, ComboBox);
		te = GetDlgItem(hWnd, ButtonTest);
		
		return true;
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;
	

	case WM_COMMAND:

		/*if (LOWORD(wParam) == ButtonTest)
		{
			DWORD rec = SendMessage(com, CB_GETEDITSEL, 0, 0);
			wchar_t buf[50];
			wsprintf(buf, L"%d, %d", LOWORD(rec), HIWORD(rec));
			MessageBox(hWnd, buf, L"Info", NULL);
		}
*/
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

		else if (LOWORD(wParam) == ButtonDel)
		{
			SendMessage(list, LB_RESETCONTENT, 0, 0);
			int count = SendMessage(list, LB_GETCOUNT, 0, 0);
			text = L"Elements: ";
			text += std::to_wstring(count);
			SetWindowText(stat, text.c_str());
		}


		else if (LOWORD(wParam) == ButtonAdd)
		{

			wchar_t buf[50];
			GetWindowText(ed, buf, sizeof(buf));

			if (wcscmp(buf, L"") != 0)
			{
				bool check = true;
				int index = SendMessage(list, LB_FINDSTRING, 0, LPARAM(buf));
				if(index == LB_ERR)
					SendMessage(list, LB_ADDSTRING, 0, LPARAM(buf));
				else
				{
					wchar_t buf1[50];
					for (int i = 0; i < SendMessage(list, LB_GETCOUNT, 0, 0); ++i)
					{
						wchar_t buf1[50];
						SendMessage(list, LB_GETTEXT, index, LPARAM(buf1));
						if (wcsstr(buf, buf1))
							check = false;					 
					}
					if(check)
						SendMessage(list, LB_ADDSTRING, 0, LPARAM(buf));

				}
				
			}


			SetWindowText(ed, L"");
			SetFocus(ed);
			int count = SendMessage(list, LB_GETCOUNT, 0, 0);
			text = L"Elements: ";
			text += std::to_wstring(count);			
			SetWindowText(stat, text.c_str());
		}
		

		else if (LOWORD(wParam) == ButtonClear)
		{
			int index = SendMessage(list, LB_GETCURSEL, 0, 0);
			SendMessage(list, LB_DELETESTRING, 0, LPARAM(index));
			int count = SendMessage(list, LB_GETCOUNT, 0, 0);
			text = L"Elements: ";
			text += std::to_wstring(count);
			SetWindowText(stat, text.c_str());			
		}

		else if (LOWORD(wParam) == ButtonX)
		{
			wchar_t buf[50];
			int index = SendMessage(list, LB_GETCURSEL, 0, 0);
			SendMessage(list, LB_GETTEXT, index, LPARAM(buf));
			SendMessage(com, CB_ADDSTRING, 0, LPARAM(buf));
		}
				
	
		return true;
	}
	return false;
}


