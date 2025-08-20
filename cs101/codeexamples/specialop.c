/*CS101C: This code example is used to demonstrate the use of special operators: sizeof, comma, and ternary 
 *author: Nikhil Hegde */

#include<stdio.h>
int main() {
	int a=10, b=3;
	printf("Size of a: %zu\n", sizeof(a));
	int result = (a = b + 2, a * 2);
	printf("Comma operator result: %d\n", result);
	int max = (a > b) ? b : a;
	printf("max(a, b): %d\n", max);
}
