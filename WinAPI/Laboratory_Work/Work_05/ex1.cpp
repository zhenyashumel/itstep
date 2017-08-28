#include<windows.h>
#include<string>

#define Height 310
#define Width 320

#define FirstStat 228
#define SecondStat 882
#define StatAnswer 465

#define Edit1 55
#define Edit2 886

#define Button1 435
#define Button2 765

#define ButtonCheck 123
#define ButtonClear 321


LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	LPWSTR szClassName = L"MyWIndowsClass";
	LPWSTR szTitleName = L"Окошко";
	WNDCLASSEX wndclass;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.lpszClassName = szClassName;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WinProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wndclass))
		return false;

	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);

	HWND hWnd = CreateWindowEx
	(
		WS_EX_TOPMOST,
		szClassName,
		szTitleName,
		WS_OVERLAPPEDWINDOW,
		(rect.right / 2) - 160, (rect.bottom / 2) - 155, Width, Height,
		NULL,
		NULL,
		hInstance,
		NULL

	);

	if (!hWnd)
		return false;

	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;



}

LRESULT CALLBACK WinProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND stat1, stat2, stat3;
	static HWND edit1, edit2;
	static HWND but1, but2, but3, but4;
	
	HDC hdcStatic;
	static HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));

	wchar_t str1[256], str2[256];

	switch (iMsg)
	{

	case WM_CREATE:
		stat1 = CreateWindowEx(WS_EX_TOPMOST,
			L"STATIC",
			L"Первое слово",
			WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE,
			10, 10, 100, 50,
			hWnd,
			(HMENU)FirstStat,
			GetModuleHandle(NULL),
			NULL);

		stat2 = CreateWindowEx(WS_EX_TOPMOST,
			L"STATIC",
			L"Второе слово",
			WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE,
			10, 50, 100, 50,
			hWnd,
			(HMENU)SecondStat,
			GetModuleHandle(NULL),
			NULL);



		edit1 = CreateWindowEx(WS_EX_TOPMOST,
			L"EDIT",
			L"",
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			120, 25, 170, 23,
			hWnd,
			(HMENU) Edit1,
			GetModuleHandle(NULL),
			NULL); 

		edit2 = CreateWindowEx(WS_EX_TOPMOST,
			L"EDIT",
			L"",
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			120, 63, 170, 23,
			hWnd,
			(HMENU)Edit1,
			GetModuleHandle(NULL),
			NULL);



		but1 = CreateWindowEx(WS_EX_TOPMOST,
			L"BUTTON",
			L"Анаграмма",
			WS_CHILD | WS_VISIBLE  | BS_RADIOBUTTON,
			10, 100, 100, 50,
			hWnd,
			(HMENU)Button1,
			GetModuleHandle(NULL),
			NULL);

		but2 = CreateWindowEx(WS_EX_TOPMOST,
			L"BUTTON",
			L"Палиндром",
			WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON ,
			193, 100, 100, 50,
			hWnd,
			(HMENU)Button2,
			GetModuleHandle(NULL),
			NULL);




		but3 = CreateWindowEx(WS_EX_TOPMOST,
			L"BUTTON",
			L"Проверить",
			WS_CHILD | WS_VISIBLE,
			40, 160, 100, 25,
			hWnd,
			(HMENU)ButtonCheck,
			GetModuleHandle(NULL),
			NULL);

		but4 = CreateWindowEx(WS_EX_TOPMOST,
			L"BUTTON",
			L"Очистить",
			WS_CHILD | WS_VISIBLE ,
			170, 160, 100, 25,
			hWnd,
			(HMENU)ButtonClear,
			GetModuleHandle(NULL),
			NULL);


		stat3 = CreateWindowEx(WS_EX_TOPMOST,
			L"STATIC",
			L"Здесь появится ответ",
			WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE,
			15, 210, 280, 40,
			hWnd,
			(HMENU)StatAnswer,
			GetModuleHandle(NULL),
			NULL);

		SendMessage(but1, BM_SETCHECK, BST_CHECKED, 0);
	break;



	case WM_CTLCOLORSTATIC:
	    hdcStatic = (HDC)wParam;			
		SetBkColor(hdcStatic, RGB(255, 255, 255));
		return (INT_PTR)hBrush;		
		break;



	case WM_COMMAND:
		if (LOWORD(wParam) == Button1)
		{
			SendMessage(but1, BM_SETCHECK, BST_CHECKED, 0);
			SendMessage(but2, BM_SETCHECK, BST_UNCHECKED, 0);
			EnableWindow(edit2, true);
		}

		else if (LOWORD(wParam) == Button2)
		{
			SendMessage(but2, BM_SETCHECK, BST_CHECKED, 0);
			SendMessage(but1, BM_SETCHECK, BST_UNCHECKED, 0);
			EnableWindow(edit2, false);
			SetWindowText(edit2, L"");
		
		}
		
		else if (LOWORD(wParam) == ButtonCheck)
		{
			if (SendMessage(but1, BM_GETCHECK, 0, 0))
			{
				GetWindowText(edit1, str1, sizeof(str1));
				GetWindowText(edit2, str2, sizeof(str2));

				std::wstring x = str1;
				std::wstring y = str2;

				if ((x == L"" || x == L" ") && (y == L"" || y == L" "))
				{
					SetWindowText(stat3, L"Вы забыли заполнить поля!!");
					break;
				}

				else if (x == L"" || x == L" ")
				{
					SetWindowText(stat3, L"Вы забыли ввести первое слово!!!");
					break;
				}

				

				else if (y == L"" || y == L" ")
				{
					SetWindowText(stat3, L"Вы забыли ввести второе слово!!!");
					break;
				}
					

				bool check = true;
				for (int i = 0; str1[i] != '\0'; ++i)
				{
					bool flag = false;
					for (int j = 0; str2[j] != '\0'; ++j)
					{
						if (str1[i] == str2[j])
							flag = true;
					}
					if (!flag)
					{
						check = false;
						break;
					}
				}

				for (int i = 0; str2[i] != '\0'; ++i)
				{
					bool flag = false;
					for (int j = 0; str1[j] != '\0'; ++j)
					{
						if (str2[i] == str1[j])
							flag = true;
					}
					if (!flag)
					{
						check = false;
						break;
					}
				}
				if (check)
					SetWindowText(stat3, L"Эти слова являются анаграммами");
				else 
					SetWindowText(stat3, L"Эти слова  не являются анаграммами");
			}

			else
			{
				bool flag = true;
				GetWindowText(edit1, str1, sizeof(str1));
				std::wstring str = str1;
				if (str == L"" || str == L" ")
				{
					SetWindowText(stat3, L"Вы забыли ввести слово!!!");
					break;
				}
				for (auto it = str.begin(); it != str.end(); ++it)
				{
					if (*it == ' ' || *it == '.' || *it == ',' || *it == '!' || *it == '?' || *it == ';')
					{
						str.erase(it);
						--it;
					}
						
				}
				for (int i = 0, j = str.size() - 1 ; i != str.size() / 2  ; ++i, --j)
				{
					if (str[i] != str[j])
						flag = false;
				}
				if (flag)
					SetWindowText(stat3, L"Эта строчка является палиндромом");
				else
					SetWindowText(stat3, L"Эта строчка не является палиндромом");

			}
		}

		else if (LOWORD(wParam) == ButtonClear)
		{
			SetWindowText(stat3, L"Здесь появится ответ");
			SetWindowText(edit1, L"");
			SetWindowText(edit2, L"");

		}

			

	break;

		

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, iMsg, wParam, lParam);

	}

	return 0;
}
