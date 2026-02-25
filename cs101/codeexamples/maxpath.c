/* CS101: A naive solution approach to Lab Test problem: compute the maximum path sum from top-left corner to bottom-right corner of a matrix.
 * Rules: can only move to right or down. Expected output: print maximum sum. print path which yields the maximum sum if a macro DEBUG is defined.
 * Author: Nikhil Hegde
 */

#include<stdio.h>
#include<assert.h>
#define MAX 100

#ifdef DEBUG
#define RIGHT 1
#define DOWN 2
int path[MAX][MAX];
#endif

int maxPathSum(int matrix[MAX][MAX], int rowIndex, int colIndex, int numRows, int numCols){
	if((rowIndex == numRows-1) && (colIndex==numCols-1)){
		return matrix[rowIndex][colIndex];
	}
	else if(rowIndex == numRows-1){
#ifdef DEBUG
		path[rowIndex][colIndex]=RIGHT;
#endif
		int maxsumMoveRight=maxPathSum(matrix, rowIndex, colIndex+1, numRows, numCols);
		return matrix[rowIndex][colIndex]+maxsumMoveRight; 
	}
	else if(colIndex == numCols-1){
#ifdef DEBUG
		path[rowIndex][colIndex]=DOWN;
#endif
		int maxsumMoveDown=maxPathSum(matrix, rowIndex+1, colIndex, numRows, numCols);
		return matrix[rowIndex][colIndex]+maxsumMoveDown; 
	
	}
	int maxsumMoveRight=maxPathSum(matrix, rowIndex, colIndex+1, numRows, numCols);
	int maxsumMoveDown=maxPathSum(matrix, rowIndex+1, colIndex, numRows, numCols);
	int max;
	if(maxsumMoveRight > maxsumMoveDown){
#ifdef DEBUG
		path[rowIndex][colIndex]=RIGHT;
#endif
		max = maxsumMoveRight;
	} else {
#ifdef DEBUG
		path[rowIndex][colIndex]=DOWN;
#endif
		max = maxsumMoveDown;
	}
	return max+matrix[rowIndex][colIndex];
}

int main(){
	int m, n;
	int matrix[MAX][MAX];
	printf("Enter number of rows and columns of matrix\n");
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&matrix[i][j]);	
		}
	}
	int maxsum=maxPathSum(matrix, 0, 0, m, n);
	printf("max sum:%d\n",maxsum);
#ifdef DEBUG
	int xCoord = 0;
	int yCoord = 0;
	printf("path:");
	while(1){
		printf("(%d %d)",xCoord, yCoord);
		if((xCoord == m-1) && (yCoord == n-1))
			break;
		if(path[xCoord][yCoord] == DOWN)
			xCoord = xCoord+1;
		else if(path[xCoord][yCoord] == RIGHT)
			yCoord = yCoord+1;
		printf("->");
	}
#endif
}
