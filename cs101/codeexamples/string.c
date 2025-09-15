#include<stdio.h>
int main(){
	char *str="HELLO";
	char arr[6]={'H','E','L','L','O'};

	printf("string before: %s\n",str);
	//iterating over every character of the string constant using a pointer.
	for(int i=0;i<6;i++){
		printf("address of cell number:%d = %p\n",i,str);
		printf("content at cell number:%d = %c\n",i,*str);
		str = str+1;
	}
	*(str-6)='Y'; //cant do this. Notice that str-6 is valid as per pointer arithmetic.
	printf("string after: %s\n",str);

	//print the entire content of the character array by using format specifier %s. 
	printf("array arr before: %s",arr);
	str=arr; //overwriting the content of str with a different address. Now str points to the first element of arr.
	*str='Y'; //modify the content of the array using str, a pointer to an element of the array.
	//print the array after modification.
	printf("array arr after: %s",arr);

}
	
