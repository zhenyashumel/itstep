#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstring>
#include<stdlib.h>

struct message
{
	char author[20];
	char text[266];
};
bool correct(FILE*f)
{
	if (!f)
	{
		printf("Error!!!");
		return 0;
	}
	return 1;
}
int main(int argc,char* argv[])
{

	FILE *f;
	message ms;
	char file_name[20];
	strcpy(file_name, argv[1]);
	f = fopen(file_name, "a+b");
	int amount = atoi(argv[2]);
	char command[20];
	int counter_read = 0;
	bool zhenya=false;
	int counter_write = 0;
	bool flag = true;
	while (flag)
	{
		printf("Hello, enter the command:");
		scanf("%s", command);
		if (strcmp(command, "read") == 0)
		{
			if (zhenya){
				f = fopen(file_name, "a+b");
				if (correct(f) == 0) return 0;
				fseek(f, counter_read*sizeof(message), SEEK_SET);
				fread(&ms, sizeof(message), 1, f);
				printf("%s\n%s", ms.author, ms.text);
				if (counter_read < amount)
					counter_read++;
				else counter_read = 0;
				fclose(f);
			}
			else printf("File is empty\n");
		}
		else if (strcmp(command, "write") == 0)
		{
			zhenya = true;

			f = fopen(file_name, "a+b");
			if (correct(f) == 0) return 0;
			fseek(f, counter_write*sizeof(message), SEEK_SET);
			printf("Enter author and text: ");
			scanf("%s %s", ms.author, ms.text);

			fwrite(&ms, sizeof(message), 1, f);

			if (counter_write < amount)
				counter_write++;
			else counter_write = 0;
			fclose(f);
		}
		else flag = false;
		

	}



	return 0;
}
