/*CS101C: This code example is used to demonstrate operator precedence and associativity  
 *author: Nikhil Hegde */

#include<stdio.h>
int main(){
	int a=10, b=20, c=5, d;
	d=a+b*c;
	printf("result of d=a+b*c: %d\n", d);
	d=a*b/c;
	printf("result of d=a*b/c: %d\n", d);
	d=b<a*c;
	printf("result of d=b<a*c: %d\n", d);
	d=0;
	d+=a?b:c;
	printf("result of d+=a?b:c %d\n", d);
	d=0;
	d+=a=b;
	printf("result of d+=a=b: %d. current value of a: %d\n", d, a);
	a=10;
	d=a+-b; 
	printf("result of d=a+-b: %d.\n", d); 
	/*exercise: our goal is to subtract negative b from a. change + to - in line 16.  what happens?*/
}
