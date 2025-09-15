/*CS101C: This code example is used to demonstrate the use of pointers and basic pointer arithmetic
 *author: Nikhil Hegde */
#include<stdio.h>
int main(){
	int arr[5]={10,20,30,40,50}; //define an array of 5 intergers and initialize it.
	int *p; //define a pointer to an integer
	p=&arr[1]; //get the address of the second element of the array and assign it to the pointer variable.
	printf("arr[1]=%d\n",*p); //use the dereference or indirection operator applied to a pointer variable and print the value at address pointed to by the pointer.
	printf("address of arr[0]=%p\n",&arr[0]); //other way to fetch the address of first element of array, arr[0], is using pointer arithmetic expression: p-1. Notice the use of format specifier %p to print addresses.
	printf("address of arr[0]=%p\n",arr); //name of the array is synonymous with the location of the first element. Notice the use of arr to print the address/location of the first element.
	printf("address of arr[1]=%p\n",p); //print the value of pointer variable p.
	printf("%d\n",*p++); //the result of this expression is 20. Why? postincrement has higher precedence. So p++ is done first. Meaning of 'p++' is that it first returns you the value of p and then increments p. So, the value of p that is returned is that of the address of the second element. Now applying the indirection operator, *, on that address will get you 20.
	printf("Value of p after *p++=%p\n",p); //now if you print the value of variable p, it would be pointing to the third element of array (because of postincrement done previously).
	//arr++; //NOT ALLOWED because you are trying to redefine arr. When you defined arr[5], the system attached an address to arr under the hood. Now you are trying to change that address. This is not allowed as the array name arr, even though its type is int*, cannot be used like a pointer (i.e. cannot be used like a variable)
	//printf("Value of arr after arr++=%p\n",arr);
	printf("Value at arr+4 =%d\n",*(arr+4)); //pointer arithmetic. Gives you the fifth element of the array.
	printf("Address of arr+4 =%p\n",(arr+4)); //gives you the address of the fifth element of the array.
	return 0;
}
