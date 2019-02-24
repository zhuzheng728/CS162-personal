#include <stdio.h>

int main(int argc, char *argv[]) 
{
	printf("argv: %p\n", argv);
	printf("argv[0]: %s\n", argv[0]);
	printf("address of function main: %p\n", &main);
	

	return 0;
}