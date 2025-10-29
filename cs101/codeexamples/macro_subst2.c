/* CS101: code to demonstrate the use of macro substitution in C.
 * This code rewrites all magic numbers, numbers such as 100, 1.23, 'C' that we saw in Union.c, with macro definitions.
 * Author: Nikhil Hegde
 */
#include<stdio.h>
#define MAXLEN 10
#define INITIAL_INT_VAL 100
#define INITIAL_FLOAT_VAL 1.23
#define INITIAL_CHAR_VAL 'C'

typedef union newtype{
	int i;
	char c[MAXLEN]; //notice the size of the array is specified using a MACRO.
	float f;
}newtype;

int main(){
	newtype x;
	x.i=INITIAL_INT_VAL; //notice we use the macro to initialize integer.
	printf("x's integer value is:%d\n",x.i);
	x.c[0]=INITIAL_CHAR_VAL; //notice we use the macro to initialize character element of the array.
	printf("x's character value is:%c\n",x.c);
	x.f=INITIAL_FLOAT_VAL;//notice we use the macro to initialize float value.
	printf("x's float value is:%f\n",x.f);
	size_t xsize=sizeof(newtype);
	printf("x's size is:%zu\n",xsize);
}
