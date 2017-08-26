#include<windows.h>
#include<vector>
#include<ctime>
#define Height 720
#define Width 1280


LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);

bool checkClick(int x, int y, RECT rt)
{
	if ((x >= rt.left && x <= rt.right) && (y >= rt.top && y <= rt.bottom))
		return true;
	
	return false;
}


bool checkMove(int x, int y, RECT rt)
{
	if ((rt.left - x < 30 && x - rt.right < 30) && (rt.top - y < 30  && y - rt.bottom < 30))
		return true;
	
	return false;	
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	LPWSTR szClassName = L"MyWIndowsClass";
	LPWSTR szTitleName = L"Escaping static";
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
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
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
		(rect.right / 2) - 640, (rect.bottom / 2) - 360, Width, Height,
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
	static HWND stat;
	static WINDOWPLACEMENT st;
	static RECT rt;
	
	static int x, y;

	switch (iMsg)
	{

	case WM_CREATE:
		stat = CreateWindowEx(WS_EX_TOPMOST,
			L"STATIC",
			L"Catch me",
			WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE,
			560, 300, 100, 50,
			hWnd,
			(HMENU)NULL,
			GetModuleHandle(NULL),
			NULL);
	
		break;
	case WM_MOUSEMOVE:
		x = LOWORD(lParam);
		y = HIWORD(lParam);

		GetWindowPlacement(stat, &st);
		rt = st.rcNormalPosition;


		srand((unsigned)time(0));
		if (checkMove(x, y, rt))
		{
			std::vector<int> corX;
			std::vector<int> corY;
			
			for (int i = 0; i < 100; ++i)
			{
				int z = rand() % 1180 ;
				if ((z - x) > 400 || (z - x) < -400)
					corX.push_back(z);

				int q = rand() % 650;

				if ((q - y) > 200 || (q - y) < -200)
					corY.push_back(q);
				
			}		
			MoveWindow(stat, corX[rand() % corX.size()], corY[rand() % corY.size()], 100, 50, true);		

		}
		if (checkClick(x, y, rt))
			MessageBox(hWnd, L"Ты догнал статик!!!", L"Поздравление", NULL);

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, iMsg, wParam, lParam);

	}

	return 0;
}
