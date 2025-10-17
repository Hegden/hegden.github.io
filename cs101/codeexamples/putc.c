/* CS101C: Code to demonstrate the use of putc function with hello.txt that contains the string Hello (no newline).
* Author: Nikhil Hegde*/
#include<stdio.h>

int main(){
	FILE* filehandle;
	filehandle=fopen("hello.txt","r+"); //open the file in read/update mode. Change this to "r" and observe that you see "Error upon calling putc".
	if(filehandle != NULL){
		//write character Y. Overwrites the first character of the file.  
		int x='Y';
		int charwritten=putc(x,filehandle);
		if(charwritten != EOF)
			printf("char written: %c\n",charwritten); //File now contains Yello
		else
			printf("Error upon calling putc\n");
		//write character H. Overwrites the second character of the file. File now contains 
		int y;
		y='H';
		int charwritten2=putc(y,filehandle);
		if(charwritten2 != EOF)
			printf("char written: %c\n",charwritten2); //File now contains YHllo
		else
			printf("Error upon calling putc\n");
		fclose(filehandle);
		filehandle=fopen("hello.txt","r+");
		int z;
		z='H';
		int charwritten3=putc(z,filehandle);
		if(charwritten3 != EOF)
			printf("char written: %c\n",charwritten3);//File now contains HHllo
		else
			printf("Error upon calling putc\n");
	} else
		printf("Error upon calling fopen\n");
}
