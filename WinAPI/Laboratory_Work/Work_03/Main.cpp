#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <tchar.h>
#include"resource.h"
#include<ctime>
#include<string>

#define width  200
#define height  100
#define TimerTime 555
#define DestroyTimer 2
#define move 5536


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
	wnd.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(102));
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
	RECT rect, rect1;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
	GetWindowRect(hWnd, &rect1);
	HDC hdc;
	PAINTSTRUCT ps;
	HWND hWndStat;
	static int pos = 0, pos1 = rect.right - width, pos2 = 0;
	static struct tm *tim;
	static time_t tt;
	std::wstring str;

	int x, y;
	switch (uMessage)
	{

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &rect);
		SetTextColor(hdc, RGB(50, 205, 50));
		SetBkMode(hdc, TRANSPARENT);

		tt = time(NULL);
		tim = localtime(&tt);

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


		DrawText(hdc, str.c_str(), -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		EndPaint(hWnd, &ps);
		break;



	case WM_CREATE:
		SetTimer(hWnd, DestroyTimer, 10000, NULL);
		SetTimer(hWnd, TimerTime, 1000, NULL);
		srand((unsigned)time(0));
		SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256)));
		InvalidateRect(hWnd, NULL, true);

		break;


	case WM_LBUTTONDOWN:
		HCURSOR hCurs;
		hCurs = LoadCursor(NULL, IDC_ARROW);
		SetCursor(hCurs);
		SetClassLong(hWnd, GCL_HCURSOR, (LONG)LoadCursor(NULL, IDC_ARROW));
		//SendMessage(hWnd, WM_SETCURSOR, wParam, LPARAM(IDC_ARROW));
		break;


	case WM_LBUTTONDBLCLK:
		HCURSOR hCurs1;
		
		SetClassLong(hWnd, GCL_HCURSOR, (LONG)LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(102)));
		//SetClassLong(hWnd, GCL_HCURSOR, (LONG)LoadCursor(NULL, IDC_CROSS));
				
		break;


	case WM_RBUTTONDOWN:
		SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256)));
		InvalidateRect(hWnd, NULL, true);
		break;


	case WM_RBUTTONDBLCLK:
		SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(255, 255, 255)));
		InvalidateRect(hWnd, NULL, true);
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

			MoveWindow(hWnd, rect.right - width, 0, width, height, true);
			SetTimer(hWnd, move, 10, NULL);
		}
		else if (wParam == VK_ESCAPE)
		{
			KillTimer(hWnd, move);
			pos = 0;
			pos1 = rect.right - width;
			pos2 = 0;
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

		if (wParam == DestroyTimer)
		{
			KillTimer(hWnd, DestroyTimer);
			if (MessageBox(hWnd, _TEXT("Xотите завершить работу приложения?"), _TEXT("Информация"), MB_YESNO) == IDYES) {

				PostQuitMessage(0);
			}
		}

		else if (wParam == TimerTime)
		{
			RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_UPDATENOW);

		}
		else if (wParam == move)
		{

			if (rect1.top == 0 && rect1.right != rect.right)
			{
				pos = 0;
				pos1 = rect.right - width;
				MoveWindow(hWnd, pos2++, 0, width, height, true);
			}

			else if (pos1 == 0)
			{
				MoveWindow(hWnd, pos1, pos--, width, height, true);
			}


			else if (pos == rect.bottom - height)
				MoveWindow(hWnd, pos1--, pos, width, height, true);

			else if (rect1.right == rect.right)
			{
				pos2 = 0;
				MoveWindow(hWnd, rect.right - width, pos++, width, height, true);
			}
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
