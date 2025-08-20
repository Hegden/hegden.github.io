/*CS101C: This code example is used to demonstrate the use of if-else and else-if constructs (optional else part)
 *author: Nikhil Hegde */

#include<stdio.h>
int main(){
	int day;
	printf("enter day:");
	scanf("%d",&day);
	if(day == 0){
		printf("Sunday\n");
	} else if (day == 1){
		printf("Monday\n");
	} else if (day == 2){
		printf("Tuesday\n");
	} /*else 
		printf("Not a Sunday\n");*/
	
}
