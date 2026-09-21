//Find the sum of all the elements of the each row of the matrix//
#include<stdio.h>

	int main(){
		int mat[3][3];
		int i,j,sum=0;
		printf("Enter the elements:\n");
		for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("element[%d][%d]:\n",i,j);
			scanf("%d",&mat[i][j]);
		}
		}
		printf("Row addition:\n");
		for(i=0;i<3;i++){
			for(j=0;j<3;j++)
			{
				sum +=mat[i][j];
			}
			printf("sum of rows %d = %d\n",i+1,sum);

		}
		return 0;}


