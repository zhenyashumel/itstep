template<typename T, typename...Args>
void myPrintf(const char *str, T value, Args...tail)
{
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] != '%')
			std::cout << str[i];
		else
		{
			std::cout << value;
			myPrintf((str+i+1), tail...);
			break;
		}
	}
}
