//Read and Display a two dimensional array, where the number of rows and columns are given as input by user//
#include<stdio.h>
 int main(){
	 int a,b;
	 int mat[a][b];
	 int i,j;
	 printf("Enter the number of rows and columns:");
	 scanf("%d %d",&a,&b);
	 printf("a=%d b=%d \n",a,b);
	 for(i=0;i<a;i++)
	 {
	 for(j=0;j<b;j++)
	 {
	 printf("Element[%d][%d] \n",i,j);
	 scanf("%d",&mat[i][j]);
	 }
	 }
for(i=0;i<a;i++){
	for(j=0;j<b;j++){
		printf("%d",mat[i][j]);
	}
}

	 return 0;
 }

