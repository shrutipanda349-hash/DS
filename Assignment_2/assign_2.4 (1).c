//Read a matrix and replace all its diagonal elements as zero//
#include<stdio.h>
int main()
{
	int mat[3][3];
	int i,j;
	printf("Enter the elements of the matrix:\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("element[%d][%d]:",i,j);
			scanf("%d",&mat[i][j]);
		}
	}
	printf("obtained matrix:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++){
			printf("%d",mat[i][j]);
		printf("\t");
		}
		printf("\n");
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(i==j){
				mat[i][j]=0;
			}
		}}
	printf("Enter the updated matrix:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++){
			printf("%d",mat[i][j]);
		printf("\t");
		}printf("\n");
	}
	return 0;
}

