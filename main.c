#include <stdio.h>
#include <windows.h>
#include "tsort.h"

void test0();

int main()
{
	test0();
	return 0;
}

void test0(void)
{
	FILE* _Read;
	int i = 0;
	errno_t open;
	char* filename = (char*)calloc(13, sizeof(char));
	char** text = (char**)calloc(1, sizeof(char*));
	setlocale(0, "rus");
	printf("Please, enter the name of file (max 12 characters): ");
	gets_s(filename, 13);
	open = fopen_s(&_Read, filename, "r+");
	if (open == 0)
	{
		printf("File was successfully opened.\n");
		while (!feof(_Read))
		{
			text[i] = (char*)malloc(250 * sizeof(char));
			fgets(text[i], 250, _Read);
			int lastpos = strlen(text[i]) - 1;
			if (text[i][lastpos] == '\n')
				text[i][lastpos] = '\0';
			i++;
			text = (char**)realloc(text, (i + 1) * sizeof(char*));
		}
		qsort(text, 20, sizeof(char*), compare);
		for (int i = 0; i < 20; i++)
		{
			printf(text[i]);
			fprintf(_Read,text[i]);
			printf("\n");
			fprintf(_Read,"\n");
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