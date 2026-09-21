//Find the largest element present in the matrix//
#include<stdio.h>
int main(){
        int m[3][3];
        int i,j;
	int la;
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
        la=m[0][0];
         for(j=0;j<3;j++){
                for(i=0;i<3;i++){
			if(m[i][j]>la){
			la=m[i][j];}
                                 

                }


                }
	  printf("largest element:%d\n",la);

        return 0;
        }


