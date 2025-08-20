/*CS101C: This code example is used to demonstrate the use sizeof operator with different data types
 *author: Nikhil Hegde */

#include<stdio.h>
int main() {
	int a=10;
	float x=10.1;
	double d=10.123456768;
	char c='A';
	printf("Size of a: %zu\n", sizeof(a));
	printf("Size of x: %zu\n", sizeof(x));
	printf("Size of c: %zu\n", sizeof(c));
	printf("Size of d: %zu\n", sizeof(d));
}
