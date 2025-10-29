/*CS101: Code example to demonstrate the use of putchar function
 * Author: Nikhil Hegde */
#include<stdio.h>
int main(){
	while(1){ //while(1) indicates that this loop executes forever.
		int c;
		c=getchar(); //read a character from the terminal
		if(c == EOF){ //if the read character is not EoF, print the character. otherwise, get out of the loop.
			printf("Exiting the infinite loop\n");
			break;
		} 
		int a;
		a=putchar(c);
	}
	return 0;
}

/* when we type two letters he and press enter we see that he is printed.
 * the reason is as follows:
 * when we press one or more keys they get stored in a buffer (terminal buffer). the buffer is consumed by getchar function, one character at a time. If the user typed two characters, the second character gets consumed by the next call to getchar function. The enter key, by default, triggers consumption from the buffer.
 if there were a third call to getchar, it would consume the enter key. In this program there is a third cal to getchar (because of infinite loop) hence enter key is consumed by getchar and the following putchar function prints the enter key. This is the reason why cursor moves to teh next line after displaying he on the terminal. 
 
 If you were to add the following code: if(c == '\n') continue;
 after the call to getchar function, then you would notice that 
 when you type he and press enter, he cursor would not move to the next line. */

/* In the class we also discussed:
 * what is the value of EoF
 * what keys to type on the terminal so that EoF is triggered: ctrl+D
 * how to convert lowercase to uppercase and vice-versa.
 */
