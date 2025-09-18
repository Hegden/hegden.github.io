/*CS101C: This code example is used to demonstrate sorting using selection sort and also define our own function
 * Author: Nikhil Hegde*/
#include<stdio.h>

/* note that the swap function is returning an int. However, the return statement is missing. Compiler will insert a "return 0".*/
int swap(int *a, int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

/* our own function definition to print an integer array 
 * The function accepts two parameters: a) a pointer to an integer b) an integer
 * The first parameter, arr, a pointer to integer, will hold the address of the first element of input.
 * The second parameter, size, an integer, will hold the size of input, 5.
 * Note that we are allowed to use arr[i], when arr is a pointer. This is because arr[i] gets translated to *(arr+i)
 * and all we need is that arr is an address. */  
void printArray(int *arr, int size){
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}

int main(){
	int input[5]={3,7,-1,4,0};
	
	//selection sort code.
	for(int cursor=0;cursor<5;cursor++){
		for(int j=cursor;j<5;j++){
			if(input[cursor] > input[j]){
				//note that we call swap and we are not catching the return value returned by swap function. This is allowed. we are ignoring the return value. we could have chosen to define our swap function as returning void instead. 
				swap(&input[cursor], &input[j]);
			}
		}
	}
	//print the array using our own printArray function.
	printArray(input,5);
	//missing return statement
}	
