/* CS101C: Code to demonstrate the use of fscanf function 
 * Author: Nikhil Hegde */
#include<stdio.h>

int main(){
	FILE* filehandle;
	filehandle=fopen("book.txt","w+");
	if(filehandle != NULL){
		//some data to dump into the file.
		char book[50]="Harry Potter";
		char author[50]="J K Rowling";
		float price=320.3;
		int year=2003;

		int ret;
		ret = fprintf(filehandle,"%s %s %f %d",book, author, price, year); //write the previosly mentioned data into file.
		printf("number of bytes written: %d\n",ret); //print number of bytes written.
	} else
		printf("Error upon calling fopen\n");
}

/*TODO: 
 * replace the line which defines price as : char price[50]="320.3"; 
 * replace the line with fprintf as: 
		ret = fprintf(filehandle,"%s %s %s %d",book, author, price, year);
 * compile and run.
 * what do you observe when you open the file book.txt?
 */
