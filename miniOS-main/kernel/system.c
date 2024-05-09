#include <stdio.h>
#include <stdlib.h>

void minisystem()
{
	printf("minisystem\n");
}

void add(char *x, char *y) {
	printf("%d + %d = %d\n", *x - '0', *y - '0', (*x - '0') + (*y - '0'));
}

