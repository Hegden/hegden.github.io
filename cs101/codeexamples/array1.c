/*CS101C: This code example is used to demonstrate the use of arrays (definition, read, write) and the typecast operator 
 * The code computes the average of 10 numbers initialized in an array of integers.
 *author: Nikhil Hegde */

#include<stdio.h>
int main(){

	int i;
	int arr[10];
	int sum=0;
	float average;
	int numberofelements=10;
	//one way of initilizing using initializer list.
	//int arr[10]={1,2,3,4,5,6,7,8,9, 10};
	
	//initialize the array
	for(i=0;i<10;i++){
		arr[i]=i+1;
	}

	for(i=0;i<10;i++){
		sum = sum + arr[i];
	}
	average=sum/(float)numberofelements;
	
	printf("average of the numbers inside arr = %f\n",average);

}
