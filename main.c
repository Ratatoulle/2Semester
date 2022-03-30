#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* book;
	errno_t err;
	char* filename = (char*)malloc(13 * sizeof(char));
	printf_s("Please, enter the name of file needed to get sorted (max 13 characters): ");
	gets_s(filename, 12);
	err = fopen_s(&book, filename, "r");

	if (err == 0)
		printf("File was successfully opened.\n");
	else
	{
		printf("Couldn't open file.\n");
		exit(1);
	}
		
	_fcloseall();
	return 0;

}