/*CS101C: This code example is used to demonstrate the use of if-else and else-if constructs
 *author: Nikhil Hegde */

#include<stdio.h>
int main(){
	int day;
	printf("enter day:");
	scanf("%d",&day);
	if(day < 7){
		if(day == 1)
			printf("Monday\n");
		else if( day == 2)
			printf("Tuesday\n");
	} else 
		printf("Not a valid integer for a day\n");
	/* exercise: remove the curly brace above and execute the program.
	 * what do you observe and why? */
}
