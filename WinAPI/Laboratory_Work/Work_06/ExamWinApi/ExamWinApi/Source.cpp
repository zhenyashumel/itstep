#include<windows.h>
#include"resource.h"
#include<fstream>
#include<string>
#include<map>
#include<codecvt>


struct Data
{
private:

	std::wstring login = L"ZhenyaIsGod";
	std::wstring password = L"Pa$$w0rd";
public:

	bool log = false;
	std::wstring getLogin() const
	{
		return login;
	}

	std::wstring getPassword() const
	{
		return password;
	}
};

static Data dat;
BOOL CALLBACK DlgProc2(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	setlocale(LC_ALL, "rus");
	HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAINDLG), NULL, DlgProc);
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
	static HWND log, pas;
	switch (iMsg)
	{


	case WM_INITDIALOG:
		log = GetDlgItem(hWnd, LogEdit);
		pas = GetDlgItem(hWnd, PassEdit);
		return true;

	case WM_COMMAND:
		if (LOWORD(wParam) == ButtonCancel)
			SendMessage(hWnd, WM_CLOSE, 0, 0);

		else if (LOWORD(wParam) == ButtonLogin)
		{
			wchar_t login[256];
			wchar_t password[256];
			
			GetWindowText(log, login, sizeof(login));
			GetWindowText(pas, password, sizeof(password));
			std::wstring str1 = login;
			std::wstring str2 = password;
			if (str1 == L"" || str2 == L"")
				MessageBox(hWnd, L"Заполните все поля!!!", L"Информация", NULL);

			else if (str1 == dat.getLogin() && str2 == dat.getPassword())
			{
				dat.log = true;
				SendMessage(hWnd, WM_CLOSE, 0, 0);
			}
			else 
				MessageBox(hWnd, L"Неверные логин или пароль!!!", L"Информация", NULL);


				
		}
		return true;

	case WM_CLOSE:
		EndDialog(hWnd, 0);

		return true;
	}
	return false;
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND edFirst, butOpen, butClear, edSecond, list, statCount, com, edInf;
	static int counter = 0;
	static std::map<std::wstring, std::map<std::wstring, std::wstring>> information;
	static  std::map<std::wstring, std::wstring> templ = {
	{ L"Значение", L"" },{ L"Перевод", L"" },{ L"Синоним", L"" },{ L"Антоним", L"" } };
	static auto it = templ.begin();

	switch (iMsg)
	{

	case WM_INITDIALOG:
	
		edFirst = GetDlgItem(hWnd, EDIT_START);
		com = GetDlgItem(hWnd, Combo);
		edInf = GetDlgItem(hWnd, EditInfo);
		edSecond = GetDlgItem(hWnd, EditSecond);
		butOpen = GetDlgItem(hWnd, ButtonOpen);
		butClear = GetDlgItem(hWnd, ButtonClear);
		statCount = GetDlgItem(hWnd, text);
		list = GetDlgItem(hWnd, List);
	    EnableWindow(butOpen, false);
		EnableWindow(butClear, false);
		EnableWindow(edFirst, false);

		
		for (int i = 0; i < templ.size(); ++i, ++it)
		{
			SendMessage(com, CB_ADDSTRING, 0, LPARAM(it->first.c_str()));
		}
		return true;

	case WM_COMMAND:
		if (LOWORD(wParam) == ButtonAuto)
		{
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(Authorization), hWnd, DlgProc2);
			if (dat.log)
			{
				EnableWindow(butOpen, true);
				EnableWindow(butClear, true);
				EnableWindow(edFirst, true);
			}
				
		}
		else if (LOWORD(wParam) == ButtonClear)
		{
			SetWindowText(edFirst, L"");
			EnableWindow(edFirst, true);
			SendMessage(edFirst, EM_SETREADONLY, false, 0);
		}

		else if (LOWORD(wParam) == ButtonCopy)
		{
			SendMessage(edFirst, WM_COPY, 0, 0);
			SendMessage(edSecond, WM_PASTE, 0, 0);
		}

		else if (LOWORD(wParam) == ButtonOpen)
		{
			EnableWindow(edFirst, true);
			SetWindowText(edFirst, L"Это новая строчка\r\nЗдесь ничего нет\r\nЗдесь может быть ваша реклама\r\nСтрока №4");
			SendMessage(edFirst, EM_SETREADONLY, true, 0);
		}
		else if (LOWORD(wParam) == ButtonCopyAll)
		{
		
			int size = SendMessage(edFirst, WM_GETTEXTLENGTH, 0, 0);
			SendMessage(edFirst, EM_SETSEL, 0, LPARAM(size));
			SendMessage(edFirst, WM_COPY, 0, 0);
			SendMessage(edSecond, WM_PASTE, 0, 0);
		}

		if (LOWORD(wParam) == List)
		{
			if (HIWORD(wParam) == LBN_SELCHANGE)
			{
				int pos = SendMessage(list, LB_GETCURSEL, 0, 0);
				wchar_t buf[56];
				SendMessage(list, LB_GETTEXT, pos, LPARAM(buf));

				if (information.count(buf) == 0)
				{
					SetWindowText(edInf, L"not found");
				}
				else
				{
					int pos1 = SendMessage(com, CB_GETCURSEL, 0, 0);
					wchar_t buf2[56];

					SendMessage(com, CB_GETLBTEXT, pos1, LPARAM(buf2));

					std::wstring str = information[buf][buf2];
					SetWindowText(edInf, str.c_str());
				}

			}
		}
		if (LOWORD(wParam) == Combo)
		{
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				int pos = SendMessage(list, LB_GETCURSEL, 0, 0);
				wchar_t buf[56];
				SendMessage(list, LB_GETTEXT, pos, LPARAM(buf));

				if (information.count(buf) == 0)
				{
					SetWindowText(edInf, L"not found");
				}
				else
				{
					int pos1 = SendMessage(com, CB_GETCURSEL, 0, 0);
					wchar_t buf2[56];

					SendMessage(com, CB_GETLBTEXT, pos1, LPARAM(buf2));

					std::wstring str = information[buf][buf2];
					SetWindowText(edInf, str.c_str());
				}

			}
		}
		else if (LOWORD(wParam) == ButtonAddList)
		{
			int length = SendMessage(edSecond, WM_GETTEXTLENGTH, 0, 0);

			if (length)
			{
				wchar_t* buff = new wchar_t[length + 1];
				DWORD start = 0;
				DWORD end = 0;
				SendMessage(edSecond, WM_GETTEXT, -1, (LPARAM)buff);
				SendMessage(edSecond, EM_GETSEL, (WPARAM)&start, (LPARAM)&end);
				std::wstring temp = L"";
				for (int i = start; i < end; ++i)
				{
					temp += buff[i];
				}
				
				if (end - start)
				{
					bool check = true;
					int index = SendMessage(list, LB_FINDSTRING, 0, LPARAM(temp.c_str()));
					if (index == LB_ERR)
					{
						SendMessage(list, LB_ADDSTRING, 0, LPARAM(temp.c_str()));
						++counter;
						std::wstring str = std::to_wstring(counter);
						SetWindowText(statCount, str.c_str());

					}
					else
					{
						wchar_t buf1[50];
						for (int i = 0; i < SendMessage(list, LB_GETCOUNT, 0, 0); ++i)
						{
							wchar_t buf1[50];
							SendMessage(list, LB_GETTEXT, index, LPARAM(buf1));
							if (wcsstr(temp.c_str(), buf1))
								check = false;
						}
						if (check)
						{
							SendMessage(list, LB_ADDSTRING, 0, LPARAM(temp.c_str()));
							++counter;
							std::wstring str = std::to_wstring(counter);
							SetWindowText(statCount, str.c_str());

						}

					}

				}
			}			
		}
		
		else if (LOWORD(wParam) == ClearList)
		{
			if (counter != 0)
			{
			SendMessage(list, LB_RESETCONTENT, 0, 0);
			counter = 0;
			std::wstring str = std::to_wstring(counter);
			SetWindowText(statCount, str.c_str());
			}
			else
				MessageBox(hWnd, L"Список уже пустой!!!", NULL, NULL);
		}

		else if (LOWORD(wParam) == DeleteList)
		{
			if (counter != 0)
			{
				int pos = SendMessage(list, LB_GETCURSEL, 0, 0);
				SendMessage(list, LB_DELETESTRING, pos, 0);
				--counter;
				std::wstring str = std::to_wstring(counter);
				SetWindowText(statCount, str.c_str());
			}
			else
				MessageBox(hWnd, L"Список пуст!!!", NULL, NULL);
		}
		
		if (LOWORD(wParam) == ButtonSave)
		{
			wchar_t buf[50];
			int pos = SendMessage(list, LB_GETCURSEL, 0, 0);
			SendMessage(list, LB_GETTEXT, pos, LPARAM(buf));
			if (pos == -1)
			{
				MessageBox(hWnd, L"Выберете слово из списка!!!", NULL, NULL);
				return true;
			}
			int index = SendMessage(com, CB_GETCURSEL, 0, 0);
			if (index == -1)
			{
				MessageBox(hWnd, L"Выберете отношение из списка!!!", NULL, NULL);
				return true;
			}
			
			wchar_t buf1[10];
			SendMessage(com, CB_GETLBTEXT, pos, LPARAM(buf1));
			wchar_t buf2[300];
			GetWindowText(edInf, buf2, sizeof(buf2));
			if (information.count(buf) == 0)
			{
				information[buf] = templ;					
				information[buf][buf1] = buf2;		
			}
			else
			{
				information[buf][buf1] = buf2;
			}
			
		}

		else if (LOWORD(wParam) == ButtonClear2)
		{
			SetWindowText(edSecond, L"");			
		}

		else if (LOWORD(wParam) == ButtonWrite)
		{
		
			std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
			std::wofstream out("new_text.txt");
			if (!out.is_open())
				MessageBox(hWnd, L"Не удалось записать текст в файл!!!", L"Информация", NULL);
			out.imbue(loc);
			
			wchar_t buf[2000];
			GetWindowText(edSecond, buf, 2000);
			out << buf;
			out.close();
			MessageBox(hWnd, L"Текст успешно записан!!!", L"Информация", NULL);
		}

		else if (LOWORD(wParam) == WriteList)
		{

			std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
			std::wofstream out("list.txt");
			if (!out.is_open())
				MessageBox(hWnd, L"Не удалось записать текст в файл!!!", L"Информация", NULL);
			out.imbue(loc);

			wchar_t buf[256];
			for (int i = 0; i < SendMessage(list, LB_GETCOUNT, 0, 0); ++i)
			{
				SendMessage(list, LB_GETTEXT, i, LPARAM(buf));
				out << buf;
				out << std::endl;
			}
		out.close();
		MessageBox(hWnd, L"Список успешно записан!!!", L"Информация", NULL);
		}

	
		return true;
	case WM_CLOSE:

		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;
		
	}
	return false;
}