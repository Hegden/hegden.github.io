/* CS101C: Code to demonstrate the use of fscanf function 
 * Assumption: there exists a file hello.txt that contains: Hello World long string
 * Author: Nikhil Hegde */
#include<stdio.h>

int main(){
	FILE* filehandle;
	filehandle=fopen("hello.txt","r"); 
	if(filehandle != NULL){
		char str[7]; //define a character array to store a string
		char str2[7]; //define a character array to store a string
		int ret; //define an ineteger to store the return value of fscanf
		float price; //define a float variable to store the decimal number (when you do the exercise as mentioned in TODO)
		ret=fscanf(filehandle,"%s%s",str,str2); //reads Hello into str array and World into str2 array
		printf("number of matched items: %d\n",ret); //prints 2.
		printf("item read from file (string):%s\n",str); //prints Hello
		printf("item2 read from file (string):%s\n",str2); //prints World
	} else
		printf("Error upon calling fopen\n");
}

/*TODO: 
 * 1. open a different file using your favourite editor, float.txt, instead of hello.txt and edit. The file float.txt should contain 320.3 and nothing else.
	replace the line with: filehandle=fopen("float.txt","r");
   2. replace the use of fscanf with: ret=fscanf(filehandle,"%f",&price);
   3. replace the following two printf statements (after fscanf) with: printf("item read from file (float):%f\n",price);
   4. Compile and execute. What do you observe?
   */
