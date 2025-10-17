/* CS101C: Code to demonstrate the use of fgets function with hello.txt that contains the string Hello (no newline).
* Author: Nikhil Hegde*/
#include<stdio.h>

int main(){
	FILE* filehandle;
	filehandle=fopen("hello.txt","r");
	if(filehandle != NULL){
		char str[5];
		char *ret;
		ret=fgets(str,5,filehandle); //reads 4 characters from file and puts a 0 for 5th character. change this to 6, recompile and rerun. Repeat with 7 as well.
		if(ret != NULL)
			printf("String read from file:%s\n",ret); //prints Hell when the second argument is 5. prints Hello when 6, prints Hello (with a newline) when 7.
		else
			printf("Error upon calling fgets\n");
	} else
		printf("Error upon calling fopen\n");
}

//in Unix like operating systems, when you use an editor like Vim to edit a file and type Hello, even though you see Hello in the text the count of characters will be 6 because of an invisible newline char.
//you can cross check this by typing the command: wc hello.txt 
//The above command prints the number of lines, words, and characters in hello.txt. You can see that the number of characters is 6. 