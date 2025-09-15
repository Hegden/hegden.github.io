/*CS101C: This code example is used to demonstrate the use of pointers with character arrays leading to a discussion on strings.
 *author: Nikhil Hegde */
#include<stdio.h>
int main(){
	char arr[5]={'H','E','L','L','O'}; //define an array of 5 characters and initialize
	char* ptrC=arr; //define a pointer to a char
	/*Notice the use of format specifier %s to print strings. Strings are sequence of characters and when you use the format specifier %s, every character in this sequence is printed until a special character, NULL character, is encountered. Above is a sequence of characters. Can we apply the format specifier, %s, and treat the array of characters as a string? No. because where is that NULL character in the above initialization? we have not initialized. So, the printing will take us beyond the last character of the array above and may lead to crash.*/  
	printf("%s",ptrC); 
	/* The correct way to print every character of the array*/
	for(int i=0;i<5;i++)
	{
		printf("%c",*ptrC);
		ptrC++;
	}
}
	
