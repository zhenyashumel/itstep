#include"Students.h"




int main()
{
	Student student[size];
	FILE *in, *out;
	if (!(in = fopen("Input.txt", "r")))
	{
		printf( "Error!!!");
		return 1;
	}
	if (!(out = fopen("Output.txt", "w")))
	{
		printf("Error!!!");
		return 1;
	}
	for (int i = 0; i < size; i++)
		student[i] = read(in);

	for (int i = 0; i < size; i++)
	{
		output(student[i],out);
		fprintf(out, "% 0.2f\n", avg(student[i]));

	}
