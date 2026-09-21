//Read a matrix and find its transpose//
#include<stdio.h>
int main(){
	int m[3][3];
	int i,j;
	printf("Enter the elements of the matrix:\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){

				printf("element[%d][%d]:\n",i,j);
			scanf("%d",&m[i][j]);
		}
	}
	printf("MATRIX:\n");
	for(i=0;i<3;i++){
                for(j=0;j<3;j++){

                                printf("%d",m[i][j]);
				printf("\t");
                        
                }printf("\n");
	}
	printf("TRANSPOSE:\n");
	 for(j=0;j<3;j++){
                for(i=0;i<3;i++){
                                 printf("%d",m[i][j]);
                                printf("\t");
                        
                }printf("\n");


                }
	return 0;
        }


