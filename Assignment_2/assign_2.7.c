//Add two matrices.(Intially check the condition whether the matrix addition is possible or not).//
#include<stdio.h>
int main(){
	int m[2][2],n[2][2],sum[2][2];
	int i,j,r2,c2,r1,c1;
         printf("Enter the value of r1,r2,c1,and c2 \n");
	 scanf("%d %d %d %d",&r1,&r2,&c1,&c2);
	 if(r1==r2&&c1==c2)
	 {
		 printf("Enter the elements of matrix 1:\n");
		 for(i=0;i<r1;i++){
			 for(j=0;j<c1;j++){
				 printf("element[%d][%d]:\n",i,j);
				 scanf("%d",&m[i][j]);
			 }
		 }
		 printf("MATRIX 1:\n");
		for(i=0;i<r1;i++){
                for(j=0;j<c1;j++){

                                printf("%d",m[i][j]);
                                printf("\t");

                }printf("\n");
        }
		printf("Enter the elements of matrix 2:\n");
                 for(i=0;i<r2;i++){
                         for(j=0;j<c2;j++){
                                 printf("element[%d][%d]:\n",i,j);
                                 scanf("%d",&n[i][j]);
                         }
                 }
                 printf("MATRIX 2:\n");
                for(i=0;i<r2;i++){
                for(j=0;j<c2;j++){

                                printf("%d",n[i][j]);
                                printf("\t");

                }printf("\n");
        }
		printf("Addition:\n");
		for(i=0;i<r1;i++){
			for(j=0;j<c1;j++){
				sum[i][j]=m[i][j]+n[i][j];
			}
		}

		for(i=0;i<r1;i++){
			for(j=0;j<c1;j++){
				printf("%d",sum[i][j]);
				printf("\t");

			}
			printf("\n");
		}
	 
}
return 0;
}

