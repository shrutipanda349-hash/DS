// Read a matrix and transpose it//
#include<stdio.h>
 int main(){
        int m[2][3],t[3][2];
	int i,j;
	 printf("Enter the elements of matrix\n");
          for(i=0;i<2;i++){
		  for(j=0;j<3;j++){
			  printf("element[%d][%d]",i,j);
			  scanf("%d",&m[i][j]);
		  }
	  }
	  for(i=0;i<2;i++){
		  for(j=0;j<3;j++){

		  printf("%d",m[i][j]);
	  }
	  }
	  
         printf("transpose matrix:\n");
	  for(i=0;i<2;i++){
		 for(j=0;j<3;j++){
			 t[j][i]=m[i][j];
		 }
	  }
	  for(i=0;i<3;i++){
		  for(j=0;j<2;j++){
	           printf("%d\n",t[i][j]); }
	  }
	  
 

	   return 0;
 }
