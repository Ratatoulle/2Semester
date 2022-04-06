#include <stdio.h>
#include "tsort.h"

int compare(const void* str1_void, const void* str2_void)
{
	unsigned char** str1 = (unsigned char**)str1_void;
	unsigned char** str2 = (unsigned char**)str2_void;
	if (strlen(*str1) < strlen(*str2))
		return -1;
	else if (strlen(*str1) > strlen(*str2))
		return 1;
	else
		return 0;
}