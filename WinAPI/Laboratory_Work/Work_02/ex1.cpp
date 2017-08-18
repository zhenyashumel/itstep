#include<windows.h>
#include<ctime>
#define firstTimer 228
#define secondTimer 882
#define thirdTimer 5536
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

	srand((unsigned)time(0));
	HWND hWnd = CreateWindowEx
	(
		WS_EX_TOPMOST,
		name,
		title,
		WS_OVERLAPPEDWINDOW,
		rand() % 1000, rand() % 500, 1280, 720,
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
	
	HWND start = Create(L"MyClass", L"Start Window", hInstance);
	ShowWindow(start, true);
	

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;



}

LRESULT CALLBACK WinProc(HWND start, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	
	switch (iMsg)
	{
	
		case WM_CREATE:
			SetTimer(start, firstTimer, 4000, NULL);
			break;


		case WM_TIMER:
			if (wParam == firstTimer)
			{
				KillTimer(start, firstTimer);
				HWND first = Create(L"MyClass1", L"First Window", GetModuleHandle(NULL));
				ShowWindow(first, true);
				SetTimer(start, secondTimer, 4000, NULL);
			}
			else if (wParam ==secondTimer)
			{
				KillTimer(start, secondTimer);
				HWND second = Create(L"MyClass2", L"Second Window", GetModuleHandle(NULL));
				ShowWindow(second, true);
				SetTimer(start,thirdTimer, 4000, NULL);
			}

			else if (wParam ==thirdTimer)
			{
				KillTimer(start, thirdTimer);
				HWND third = Create(L"MyClass3", L"Third Window", GetModuleHandle(NULL));
				ShowWindow(third, true);
			}
			break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(start, iMsg, wParam, lParam);

	}

	return 0;
}
