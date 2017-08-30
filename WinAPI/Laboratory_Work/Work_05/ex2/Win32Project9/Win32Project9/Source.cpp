#include<windows.h>
#include"resource.h"
#include<vector>
#include<string>
#define CatTimer 228
#define DogTimer 882
#define AllTimer 567

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

void InitCat(std::vector<HBITMAP> &cat)
{

	HBITMAP  cur = LoadBitmap (GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP1));
	cat.push_back(cur);

	cur = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP2));
	cat.push_back(cur);

	cur = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP3));
	cat.push_back(cur);

	cur = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP4));
	cat.push_back(cur);

	cur = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP5));
	cat.push_back(cur);

}


void InitDog(std::vector<HBITMAP> &dog)
{

	HBITMAP  cur = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP6));
	dog.push_back(cur);

	cur = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP6));
	dog.push_back(cur);

	cur = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP7));
	dog.push_back(cur);

	cur = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP8));
	dog.push_back(cur);

	cur = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP9));
	dog.push_back(cur);

	cur = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP10));
	dog.push_back(cur);

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
	static HWND butCat, butDog, butSlow, butFast, butStart, butStop, im;
	static std::vector <HBITMAP> dog;
	static std::vector <HBITMAP> cat;
	static std::vector<HBITMAP> allpic;
	static HBITMAP prev, cur;

	

	switch (iMsg)
	{

	case WM_INITDIALOG:
		InitDog(dog);
		InitCat(cat);
		butCat = GetDlgItem(hWnd, ButtonCat);
		butDog = GetDlgItem(hWnd, ButtonDog);
		butSlow = GetDlgItem(hWnd, ButtonSlow);
		butFast = GetDlgItem(hWnd, ButtonFast);
		butStart = GetDlgItem(hWnd, ButtonStart);
		butStop = GetDlgItem(hWnd, ButtonStop);
		im = GetDlgItem(hWnd, Image);	
		SendMessage(butFast, BM_SETCHECK, BST_CHECKED, 0);
		for (int i = 0; i < 5; ++i)
		{
			allpic.push_back(dog[i]);
			allpic.push_back(cat[i]);
		}
		return true;
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;


	case WM_COMMAND:

		if (LOWORD(wParam) == ButtonStart)
		{
			if (!SendMessage(butCat, BM_GETCHECK, 0, 0) && !SendMessage(butDog, BM_GETCHECK, 0, 0))
				MessageBox(hWnd, L"Выберите тип картинок!!!", L"Информация", NULL);
			else if (SendMessage(butCat, BM_GETCHECK, 0, 0) && !SendMessage(butDog, BM_GETCHECK, 0, 0))
			{
				int speed;
				if (SendMessage(butSlow, BM_GETCHECK, 0, 0))
					speed = 3000;
				else
					speed = 1000;
				cur = cat[rand() % cat.size()];
				SendMessage(im, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)cur);
				prev = cur;
				SetTimer(hWnd, CatTimer, speed, NULL);
				
			}

			else if (!SendMessage(butCat, BM_GETCHECK, 0, 0) && SendMessage(butDog, BM_GETCHECK, 0, 0))
			{
				int speed;
				if (SendMessage(butSlow, BM_GETCHECK, 0, 0))
					speed = 3000;
				else
					speed = 1000;
				cur = dog[rand() % dog.size()];
				SendMessage(im, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)cur);
				prev = cur;
				SetTimer(hWnd, DogTimer, speed, NULL);
			}

			else
			{
				
					int speed;
					if (SendMessage(butSlow, BM_GETCHECK, 0, 0))
						speed = 3000;
					else
						speed = 1000;

					cur = allpic[rand() % allpic.size()];
					SendMessage(im, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)cur);
					prev = cur;
					SetTimer(hWnd,AllTimer, speed, NULL);
				}
			}
		

		else if (LOWORD(wParam) == ButtonStop)
		{
			KillTimer(hWnd, DogTimer);
			KillTimer(hWnd, CatTimer);
			KillTimer(hWnd, AllTimer);
		}

	case WM_TIMER:
		if (wParam == CatTimer)
		{
			while (cur == prev)
				cur = cat[rand() % cat.size()];
			SendMessage(im, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)cur);
			prev = cur;
			
		}

		else if (wParam == DogTimer)
		{

			while (cur == prev)
				cur = dog[rand() % dog.size()];
			SendMessage(im, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)cur);
			prev = cur;

		}

		if (wParam == AllTimer)
		{

			while (cur == prev)
				cur = allpic[rand() % allpic.size()];
			SendMessage(im, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)cur);
			prev = cur;

		}


		return true;
	}
	return false;
}

