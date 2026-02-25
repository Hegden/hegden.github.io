/* CS101: An incomplete solution approach to Lab Test problem: solve josephus problem for a given n and k.
 * Expected output: print the position of the survivor (positions with 0 as the start index). print the details of who is eliminated in which round and who all remain after elimination if a macro DEBUG is defined.
 * Author: Nikhil Hegde
 */
#include<stdio.h>
#define MAX 100
#define DEBUG

int josephus(int n, int k){
	if(n == 1)
		return 0;
	int survivor_n_minus_1=josephus(n-1,k);
	int plus_k = survivor_n_minus_1+k;
	int plus_k_mod_n = plus_k % n;
	return plus_k_mod_n;
}

int main(){
	int removed[MAX];
	int n, k;
	printf("Enter n and k\n");
	scanf("%d %d",&n, &k);

	int survivor=josephus(n,k);
	printf("survivor: %d\n",survivor);

	//This part of the code is incomplete. TODO: complete the code based on ideas discussed in class.
#ifdef DEBUG
	int currentIndex=0;
	int removedCount=0;
	int nextPositionRemoved;
	
	nextPositionRemoved = currentIndex+k-1;
	removedCount++;
	printf("%d elimination -> remove %d ->[",removedCount,nextPositionRemoved);
	for(int i=0;i<n;i++){
		if(i==nextPositionRemoved)
			continue;
		printf("%d",i);
		if(i!=n-1)
			printf(",");
			
	}
	printf("]");

	int nextPositionRemoved2;
	currentIndex = nextPositionRemoved+1;
	nextPositionRemoved2 = currentIndex+k-1;
	removedCount++;
	printf("%d elimination -> remove %d ->[",removedCount,nextPositionRemoved2);
	for(int i=0;i<n;i++){
		if((i==nextPositionRemoved) || (i==nextPositionRemoved2))
			continue;
		printf("%d",i);
		if(i!=n-1)
			printf(",");
			
	}
	printf("]");
#endif
}
