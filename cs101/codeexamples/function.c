/*CS101C: This code example is used to demonstrate the use of functions (swap2-call-by-reference) and global variables.
 * Author: Nikhil Hegde*/
#include<stdio.h>
void swap2(int *a, int *b); //this is function declaration.
void swap(int a, int b); //this is function declaration.

int myVar=1234; //this is a global variable.

int main(){
	int x=10;
	int y=20;
	swap(x,y); //this is function call site. We are calling the function using call-by-value
	printf("Value of x and y after calling swap function\n");
	printf("x=%d, y=%d\n",x,y);
	swap2(&x,&y); //this is function call site. We are calling the function using call-by-reference
	printf("Value of x and y after calling swap2 function\n");
	printf("x=%d, y=%d\n",x,y);
	printf("calling swap multiple times to see the effect on static and normal variables..\n");
	swap(x,y); 
	swap(x,y); 
	swap(x,y); 
	return 0;
}

void swap(int a, int b){
	static int count; //this is a static variable.
	int normalVar=0; //this is a normal variable.
	/* two differences between static and normal variables:
	 * a) static variables get initialized to zero if not initialized explicitly.
	 * b) they retain their old values when the function is called next. */
	int tmp=a;
	a=b;
	b=tmp;
	normalVar++;
	count++;
	printf("Inside swap: normalVar=%d static var count=%d\n",normalVar, count);
	return;
}

void swap2(int *a, int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
	return;
}

