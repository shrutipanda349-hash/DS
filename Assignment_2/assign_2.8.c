//Multiply two square matrices.//
#include<stdio.h>
int main(){
	int m[2][2],n[2][2],r[2][2];
	int i,j,k;
     
		 printf("Enter the elements of matrix 1:\n");
		 for(i=0;i<2;i++){
			 for(k=0;k<2;k++){
				 printf("element[%d][%d]:\n",i,k);
				 scanf("%d",&m[i][k]);
			 }
		 }
		 printf("MATRIX 1:\n");
		for(i=0;i<2;i++){
                for(k=0;k<2;k++){

                                printf("%d",m[i][k]);
                                printf("\t");

                }printf("\n");
        }
		printf("Enter the elements of matrix 2:\n");
                 for(k=0;k<2;k++){
                         for(j=0;j<2;j++){
                                 printf("element[%d][%d]:\n",k,j);
                                 scanf("%d",&n[k][j]);
                         }
                 }
                 printf("MATRIX 2:\n");
                for(k=0;k<2;k++){
                for(j=0;j<2;j++){

                                printf("%d",n[k][j]);
                                printf("\t");

                }printf("\n");
        }
		printf("Multplication:\n");
		for(i=0;i<2;i++){
			for(j=0;j<2;j++){
				r[i][j]=0;

                              for(k=0;k<2;k++){
				r[i][j]+=m[i][j]*n[i][j];
			      }	}
		}
		for(i=0;i<2;i++){
                        for(j=0;j<2;j++){
                               
                                printf("%d",r[i][j]);
				printf("\t");

                              } printf("\n");
		}

		return 0;
}

                



