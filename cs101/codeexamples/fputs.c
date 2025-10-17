/* CS101C: Code to demonstrate the use of fputs function 
 * Author: Nikhil Hegde */
#include<stdio.h>

int main(){
	FILE* filehandle;
	filehandle=fopen("hello.txt","r+"); //open the file hello.txt in read/update mode.
	if(filehandle != NULL){
		char str[50]="World";
		int ret;
		ret=fputs(str,filehandle); //Writes the string Hello at the beginning of the file.
		if(ret > 0)
			printf("String successfully written to file. returned val:%d\n",ret); //prints a non-negative number indicating success.
		else
			printf("Error upon calling fputs\n");
	} else
		printf("Error upon calling fopen\n");
}

/* TODO: Open hello.txt using your favourite editor and edit: Hello world long string 
 * In this file (fputs.c) replace World with ZZZ.
 * Compile and execute. What do you observe?
 *
 * Open hello.txt using your favourite editor. Delete everything. Add the following text: World 
 * In this file (fputs.c) replace ZZZ with Hello World long string.
 * Compile and execute. What do you observe?
 */
