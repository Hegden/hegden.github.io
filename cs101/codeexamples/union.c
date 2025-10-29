/* CS101: code to demonstrate the use of unions in C.
 * Author: Nikhil Hegde
 */

#include<stdio.h>
union newtype{
	int i;
	char c;
	float f;
}newtype;

int main(){
	//define a variable of type newtype
	union newtype x;
	//assign value to the integer member of x
	x.i=100;
	//read the value from x's integer member
	printf("x's integer value is:%d\n",x.i);
	//assign value to char member of x
	x.c='C';
	printf("x's character value is:%c\n",x.c);
	//assign value to float member of x
	x.f=1.23;
	printf("x's float value is:%f\n",x.f);
	//print the size of x
	size_t xsize=sizeof(x);
	printf("x's size is:%zu\n",xsize);

	/*//Fun: assign integer member a value of 0x12345641
	x.i=0x12345641;
	//now print the value in character member of x.
	printf("x's character value is:%c\n",x.c);
	//why do you see the output that you see?*/

}

//TODO: 1)uncommend the Fun part of the code, recompile, and execute.
//2) how to you get the size of x without passing x as an argument to sizeof operator?
//3) if you were to type "newtype x"; instead of "union newtype x;" then what code changes would you have to make?
