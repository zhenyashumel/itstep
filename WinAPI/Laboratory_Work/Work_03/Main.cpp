#include <windows.h>
#include <tchar.h>
#include"resource.h"
#include<ctime>
#define width  200
#define height  100
#define closeTimer 1
#define DestroyTimer 2
#define setColor 228
#define move 288

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{

	WNDCLASSEX wnd;
	wnd.cbSize = sizeof(wnd);
	wnd.lpfnWndProc = WndProc;
	wnd.cbClsExtra = 0;
	wnd.cbWndExtra = 0;
	wnd.hInstance = hInstance;
	wnd.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(101));
	wnd.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(103));
	wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wnd.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wnd.lpszMenuName = NULL;
	wnd.lpszClassName = _TEXT("Window");
	wnd.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(101));

	if (!RegisterClassEx(&wnd)) {
		MessageBox(NULL, _TEXT("Sorry... :("), _TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}

	HWND hWnd = CreateWindowEx(
		WS_EX_WINDOWEDGE,
		_TEXT("Window"),
		_TEXT("Hello"),
		WS_OVERLAPPEDWINDOW ^ WS_MAXIMIZEBOX ^ WS_MINIMIZEBOX,

		CW_USEDEFAULT, CW_USEDEFAULT, width, height,
		HWND_DESKTOP, NULL, hInstance, NULL);

	if (!hWnd) {
		MessageBox(NULL, _TEXT("Sorry... :("), _TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}

	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);


	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	RECT rect;
	HDC hdc;
	PAINTSTRUCT ps;
	HWND hWndStat;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
	int x, y;
	switch (uMessage)
	{


	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &rect);
		SetTextColor(hdc, RGB(50, 205, 50));
		SetBkMode(hdc, TRANSPARENT);
		DrawText(hdc, L"Sample Text!!!", -1, &rect, DT_CENTER);
		EndPaint(hWnd, &ps);
		break;

	case WM_LBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		MoveWindow(hWnd, x, y, 300, 300, true);
		break;




	case WM_CREATE:
		SetTimer(hWnd, closeTimer, 1500, NULL);
		srand((unsigned)time(0));
		SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256)));
		InvalidateRect(hWnd, NULL, true);
		SetTimer(hWnd, setColor, 1000, NULL);

		hWndStat = CreateWindowEx(WS_EX_TOPMOST, L"Static", L"Element", WS_CHILD | WS_VISIBLE,
			10, 20, 55,20, hWnd, NULL, GetModuleHandle(NULL), NULL);		
		break;

	
	case WM_SYSKEYDOWN:

		if (wParam == VK_DOWN)
			ShowWindow(hWnd, SW_SHOWMINIMIZED);

		else if (wParam == VK_UP)
			ShowWindow(hWnd, SW_MAXIMIZE);

		else if (wParam == VK_LEFT || wParam == VK_RIGHT)
			ShowWindow(hWnd, SW_NORMAL);

		else if (wParam == VK_F4)
			PostMessage(hWnd, WM_CLOSE, 0, 0);			
		break;




	case WM_KEYDOWN:
				
		if (wParam == VK_RETURN)
		{
			
			MoveWindow(hWnd, rect.right - width , 0, width, height, true);
			SetTimer(hWnd, move, 1, NULL);
		}		
		break;



	case WM_CHAR:
		if (wParam == 't')
		{
			SetWindowText(hWnd, L"New Text");
			InvalidateRect(hWnd, NULL, true);
		}
		break;



	case WM_TIMER:
		
		if (wParam == move)
		{
			//if()
		}

		if (wParam == closeTimer)
		{
			KillTimer(hWnd, closeTimer);
			SetTimer(hWnd, DestroyTimer, 10000, NULL);
		}

		else if (wParam == DestroyTimer)
		{
			KillTimer(hWnd, DestroyTimer);
			if (MessageBox(hWnd, _TEXT("Xотите завершить работу приложения?"), _TEXT("Информация"), MB_YESNO) == IDYES) {

				PostQuitMessage(0);
			}
		}

		if (wParam == setColor)
		{			
			SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256)));
			InvalidateRect(hWnd, NULL, true);
		}
		break;



	case WM_CLOSE:
		if (MessageBox(hWnd, _TEXT("Вы действительно хотите завершить работу приложения?"), _TEXT("Информация"), MB_YESNO) == IDYES) {
			
			PostQuitMessage(0);
		}
		break;

	
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}
