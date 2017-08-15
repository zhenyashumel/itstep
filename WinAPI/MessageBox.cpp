int rec = MessageBoxW(NULL, L"Something went wrong!!!", L"Oops...", MB_OKCANCEL);  //создание окна

	if (rec == IDOK)     //обработка нажатий
	{
		PostQuitMessage(0);		
	}
