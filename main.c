#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test0();
void test1();

int main()
{
	test1();
	return 0;

}

int compare(const void* str1_void, const void* str2_void)
{
	char *const str1 = str1_void;
	char *const str2 = str2_void;
	return strcmp(*str1,*str2);
}

void test0()
{
	FILE* book;
	errno_t err;
	char* filename = (char*)malloc(13 * sizeof(char));
	printf_s("Please, enter the name of file needed to get sorted (max 12 characters): ");
	gets_s(filename, 12);
	err = fopen_s(&book, filename, "r");
	if (err == 0)
		printf("File was successfully opened.\n");
	else
	{
		printf("Couldn't open file.\n");
		exit(1);
	}
	int close = _fcloseall();
}

void test1()
{
	char* s1 = "Goes after every morning";
	int len1 = strlen(s1);
	char* s2 = "Easy as could be";
	int len2 = strlen(s2);
	char* s3 = "Be careful with him";
	int len3 = strlen(s3);
	char* s4 = "Don't worry";
	int len4 = strlen(s4);
	int total = len1 + len2 + len3 + len4;
	char** mass = (char**)malloc(total * sizeof(char*));
	for (int i = 0; i < total; i++)
	{
		mass[i] = (char*)malloc(len1 * sizeof(char));
	}
	qsort(mass, total, sizeof(char*), compare);
	for (int i = 0; i < total; i++)
	{
		printf(mass[i]);
		printf("\n");
	}
}