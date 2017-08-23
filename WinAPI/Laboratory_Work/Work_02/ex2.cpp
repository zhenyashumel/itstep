#include<windows.h>
#include<ctime>
#include<tchar.h>
#include<string>
#define ButtonStart 228


LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);


HWND Create(LPWSTR name, LPWSTR title, HINSTANCE hInstance)
{
	WNDCLASSEX wndclass;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.lpszClassName = name;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WinProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	srand((unsigned)time(0));
	wndclass.hbrBackground = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wndclass))
		return false;

	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);

	srand((unsigned)time(0));
	HWND hWnd = CreateWindowEx
	(
		WS_EX_TOPMOST,
		name,
		title,
		WS_OVERLAPPEDWINDOW,
		(rect.right / 2) - 640 , (rect.bottom / 2) - 360  , 1280, 720,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd)
		return false;

	return hWnd;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
	HWND hWnd = Create(L"MyClass", L"Guess number", hInstance);
	
	

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

	HDC hdc;
	std::wstring str;
	setlocale(0, "");
	bool game = true;

	HWND hWndBut;
	switch (iMsg)
	{
	
		case WM_CREATE:

			ShowWindow(hWnd, true);
			hWndBut = CreateWindowEx(NULL,
				L"BUTTON",
				L"Начать игру",
				WS_CHILD | WS_VISIBLE,
				520, 310, 160, 60,
				hWnd,
				(HMENU)ButtonStart,
				GetModuleHandle(NULL),
				NULL);
			break;
		
		
		case WM_COMMAND:
			if (LOWORD(wParam) == ButtonStart )
			{
				static int key = rand() % 100 + 1;
				static int left = 1;
				static int right = 101;
				while (game)
				{

						str = _TEXT("Ваше число это ");
						str += std::to_wstring(key);
						if (MessageBox(hWnd, str.c_str(), _TEXT("Информация"), MB_YESNO) == IDYES)
						{
							game = false;
							MessageBox(hWnd, L"Я угадал!!!", L"Информация", NULL);

						}

						else
						{
							if (MessageBox(hWnd, L"Ваше число больше ?", L"Информация", MB_YESNO) == IDYES)
							{
								left = key;
								if (left >= right)
								{
									MessageBox(hWnd, L"Что-то пошло не так!!!", L"Информация", NULL);
									game = false;
								}
								else
									key = (left + right) / 2;
								
							}
							else
							{
								right = key ;
								if (right <= left)
								{
									MessageBox(hWnd, L"Что-то пошло не так!!!", L"Информация", NULL);
									game = false;
								}
								else
									key = (left + right) / 2;
							}
						}
				   }
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
