#include<fstream>
#include<string>
#include<iostream>

void function();


int main()
{
	function();
	return 0;
}
void function()
{
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	int counter=0;
	std::string temp;
	while (in >> temp)
	{
		if (temp.length() == 3)
		{
			out << temp;
			out << " ";
		}
	}		
	in.close();
	out.close();

}
