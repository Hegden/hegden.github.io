/*CS101C: This code example is used to demonstrate the use scanf function 
 *author: Nikhil Hegde */

#include<stdio.h>
int main(){
	int a;
	float b;
	char n;
	/* you need to enter an integer, floating point value, and a single character */
	scanf("%d %f %c",&a, &b, &n);
	printf("you entered: %d %f %c",a, b, n);
}
