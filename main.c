#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

void test0();

int main()
{
	test0();
	return 0;
}

int compare(const void* str1_void, const void* str2_void)
{
	unsigned char** str1 = (unsigned char**)str1_void;
	unsigned char** str2 = (unsigned char**)str2_void;
	return strcmp(*str1, *str2);
}

void test0()
{
	FILE* fp;
	int i = 0;
	int len = 0;
	errno_t open;
	setlocale(0, "rus");
	char* filename = (char*)calloc(13, sizeof(char));
	char** text = (char**)calloc(1, sizeof(char*));
	printf("Please, enter the name of file (max 12 characters): ");
	gets_s(filename, 13);
	open = fopen_s(&fp, filename, "r+");
	if (open == 0)
	{
		printf("File was successfully opened.\n");
		while (!feof(fp))
		{
			text[i] = (char*)malloc(250 * sizeof(char));
			fgets(text[i], 250, fp);
			i++;
			len++;
			text = (char**)realloc(text, (i + 1) * sizeof(char*));
		}
		qsort(text, 20, sizeof(char*), compare);
		for (int i = 0; i < 20; i++)
		{
			printf(text[i]);
			//fprintf_s(fp, text[i]);
			Sleep(75);
		}
		for (int i = 0; i < 20; i++)
			free(text[i]);
		free(text);
	}
	else
	{
		printf("Couldn't open file.\n");
		exit(1);
	}
	int close = _fcloseall();
}