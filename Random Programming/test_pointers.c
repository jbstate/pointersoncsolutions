
#include <stdio.h>

int main()
{
	int a = 112, b = -1;
	float c = 3.14;
	int *d = &a;
	float *e = &c;
	
	printf("With HEX values %d %d %f %x %x\n", a, b, c, d, e);
	
	printf("Dereferencing %d %d %f %d %f\n", a, b, c, *d, *e);
	
	return 0;
}//end main
