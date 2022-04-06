#include <stdio.h>
#include <windows.h>
#include "tsort.h"

int main(int argc, char* argv[])
{
	FILE* _Read = NULL;
	int i = 0;
	errno_t open = 0;
	int choice = 0;
	char* filename = (char*)calloc(13, sizeof(char));
	char** text = (char**)calloc(1, sizeof(char*));
	setlocale(0, "rus");
	if (argc < 2)
	{
		printf("Do you want to sort 1 file or you have a list of names of files need to be sorted?\n");
		printf("1) 1 file\n");
		printf("2) list of files\n");
		printf("Your choice: ");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Please, enter the name of file (max 12 characters): ");
			gets_s(filename, 13);
			open = openFile(filename, _Read);
			break;
		case 2:
			printf("Please, enter the name of file contains filenames (max 12 characters): ");
			gets_s(filename, 13);
			open = openFile(filename, _Read);
			break;
		default:
			printf("Wrong choice, try again.\n");
			break;
		}
	}
	else
		open = fopen_s(&_Read, argv[1], "r+");
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
			fprintf(_Read, text[i]);
			printf("\n");
			fprintf(_Read, "\n");
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
	return 0;
}