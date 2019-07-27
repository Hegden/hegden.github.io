#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

//Struct to hold arguments to pthread_create function call
typedef struct Args {
	int tid; //thread id
	int numThreads; //total number of threads
  long * arr; //pointer to array that we want to sum up
	int arrSize; //length of array
  long result; //result of summing sub-array
} Args;

long * generateArray(int arrSize) {
	//allocate array
	long * ret = malloc(sizeof(long) * arrSize);
	
	//initialize array
	for (int i = 0; i < arrSize; i++) {
		ret[i] = i;
	}
	
	return ret;
}

void * sumSubArray(void * args) {
	//Recover args:
	Args * myArgs = (Args *) args;
	
	//calculate range of the array this thread should cover:
	//Number of elements this thread should work on:
	//Note: intervalLength needs to be the ceiling!
	int intervalLength = (myArgs->arrSize + myArgs->numThreads - 1) / myArgs->numThreads;
	
	//low end of range:
	int lo = myArgs->tid * intervalLength;
	
	//top end of range:
	int hi = lo + intervalLength;
	//Adjust in case arrSize isn't multiple of numThreads
	//In this case, hi might reach past arrSize
	hi = (hi > myArgs->arrSize) ? myArgs->arrSize : hi;
	
	printf("Thread %d summing from arr[%d] to arr[%d]\n", myArgs->tid, lo, hi);
	
	//Compute sum:
	myArgs->result = 0;
	for (int i = lo; i < hi; i++) {
		myArgs->result += myArgs->arr[i];
	}
	
	return NULL;
}

int main(int argc, char ** argv) {
	
	const int numThreads = 3;
	const int arrSize = 10000;
	
	long * toSum = generateArray(arrSize);
	
	//Allocate an array of 4 pthread_ts.
	pthread_t * threads = malloc(sizeof(pthread_t) * numThreads);
	
	//Allocate argument structs
	Args * args = malloc(sizeof(Args) * numThreads);
	
	//Initialize argument structs
	for (int i = 0; i < numThreads; i++) {
		args[i].tid = i;
		args[i].numThreads = numThreads;
		args[i].arr = toSum;
		args[i].arrSize = arrSize;
		args[i].result = 0;
	}
	
	//Spawn numThreads threads to sum up array
	for (int i = 0; i < numThreads; i++) {
		pthread_create(&threads[i], NULL, sumSubArray, &args[i]);
	}
	
	//Wait for threads to complete
	//Something to try: comment out this loop and see what happens
	for (int i = 0; i < numThreads; i++) {
		pthread_join(threads[i], NULL);
	}

	//Calculate final sum:
	long final = 0;
	for (int i = 0; i < numThreads; i++) {
		final += args[i].result;
	}

	printf("Total sum of array: %ld\n", final);

	//clean up memory
	free(args);
	free(toSum);
	free(threads);

}