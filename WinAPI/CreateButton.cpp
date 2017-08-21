 hWndBut = CreateWindowEx(NULL,
			L"BUTTON",
			L"Click me",
			WS_CHILD | WS_VISIBLE,
			320, 200, 80, 30,
			hWnd,
			(HMENU)buttonTest,
			GetModuleHandle(NULL),
			NULL);
