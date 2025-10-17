/* CS101C: Code to demonstrate the use of putc function with hello.txt that contains the string Hello (no newline).
* Author: Nikhil Hegde*/
#include<stdio.h>

int main(){
	FILE* filehandle;
	filehandle=fopen("hello.txt","r");
	if(filehandle != NULL){
		int x;
		x=getc(filehandle); //reads the character H from file.
		printf("%c\n",x);
	} else
		printf("Error upon calling fopen\n");
}