/*CS101: Code example to demonstrate the use of getchar function
 * Author: Nikhil Hegde */
#include<stdio.h>

int main(){
	int c;
	c=getchar();
	printf("entered character is %c\n",c);
	return 0;
}

/* In the class we discussed:
 * 1) what is printed when user enters: \t \n "he" 'h' hello ctrl+d
 * 2) why int c is preferred over char c
 */
