	x = 5;
		str = _TEXT("text");
		str += _T(' ');
		str += std::to_wstring(x);

		if (MessageBox(hWnd, str.c_str(), _TEXT("Информация"), MB_YESNO) == IDYES) {
			
			PostQuitMessage(0);
		}
