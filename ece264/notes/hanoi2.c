#include<stdio.h>
void TOH(int n, char src, char destn, char aux)
{
	if(n == 0)
		return;
	TOH(n-1,src,aux,destn);
	printf("Move disk %d from %c to %c\n",n,src,destn);
	TOH(n-1,aux,destn,src); 
}

int main()
{
	TOH(5,'A','B','C');
}
