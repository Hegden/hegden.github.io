/* Lab5 Test Program to print a diamond of stars given the number of rows to print 
 * Author: Nikhil Hegde */

#include<stdio.h>
int main(){
	char star='*';
	int numRows, numStarsToPrint;
	int maxBlankSpacesToInsert, numBlankSpacesToInsert;
	printf("Enter number of rows to print\n");
	scanf("%d",&numRows);
	maxBlankSpacesToInsert=numRows/2;
	for(int i=0;i<numRows;i++){
		numStarsToPrint=2*i+1;
		numBlankSpacesToInsert = maxBlankSpacesToInsert - i;   
		if(i>numRows/2){
			numStarsToPrint=2*(numRows-i)-1;
			numBlankSpacesToInsert = i - numRows/2;	
		}
		for(int j=0;j<numBlankSpacesToInsert;j++)
			printf(" ");
		for(int j=0;j<numStarsToPrint;j++)
			printf("%c",star);
		printf("\n");
	}
}
