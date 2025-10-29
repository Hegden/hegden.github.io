/* CS101: code to demonstrate the use of macro substitution in C. Also, used to differentiate between macro definition and function definition.
 * Author: Nikhil Hegde
 */
#include<stdio.h>

//a macro to compute the abolute difference of two numbers (of any type) passed.
#define ABSDIFF(a, b)  ((a)>(b) ? (a)-(b) : (b)-(a))

//a function to compute the absolute difference of two integers. 
//If you were to compute the absolute difference of two floating point numbers using functions, the below function cannot be used. You have to define a separate function. However, if you were to use macros, you could still use the same macro defined above.
int absdiff_func(int a, int b){
	
	int result;
	if(a > b)
		result = a-b;
	else
		result = b-a;
	return result;
}

int main(){
	int x=10, y=20,z,w;
	z=ABSDIFF(x,y); //notice the use of macro defined.
	w=absdiff_func(x,y); //a function call.
	printf("%d\n",z);
	printf("%d\n",w);
}

/* Discussed in class:
 * 1) how does the control flow change in case of macro and in case of function?
 * i.e. which line gets executed after which line in case of macro and in case of function?
 * 2) which incurs more overhead macro vs. function call in the above example? why?
 * 3) what is an advantage of macro compared to function?
 * 4) What is a disadvantage of macro?
 */
