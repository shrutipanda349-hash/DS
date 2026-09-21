//TRANSPOSE OF A SPARSE MATRIX

#include<stdio.h>
void main()
{
	int a[10][10],triplet[10][10],transpose[10][10];
		int i,j,r,c,nzero,k=1,temp=1;
	printf("enter row and column:");
	scanf("%d %d",&r,&c);
	printf("enter matrix element:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
		}
}
	// sparse matrix in triplet form


	triplet[0][0]=r;
	triplet[0][1]=c;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(a[i][j]!=0)
			{
				triplet[k][0]=i;
				triplet[k][1]=j;
				triplet[k][2]=a[i][j];
				k++;
			}
		}
	}
	nzero=k;
	triplet[0][2]=nzero;
	printf("Triplet form of matrix:\n");
	printf("row=%d\tcolumn=%d\tnon-zero=%d\n",r,c,k-1);
	for(i=1;i<nzero;i++)
	{
	
		for(j=0;j<3;j++)
		{
			printf("%d\t",triplet[i][j]);
		}
		printf("\n");
	}

//transpose
transpose[0][0]=c;
transpose[0][1]=r;
transpose[0][2]=nzero;
for(j=0;j<c;j++)
{
	for(i=1;i<nzero+1;i++)
	{
		if(triplet[i][1]==j)
		{
			transpose[temp][0]=triplet[i][1];
			transpose[temp][1]=triplet[i][0];
			transpose[temp][2]=triplet[i][2];

		}temp++;
	}
}
 printf("Transpose form of matrix:\n");
        printf("coloumn=%d\t row=%d\tnon-zero=%d\n",c,r,k-1);
        for(j=1;j<nzero;j++)
        {

                for(i=0;i<r;j++)
                {
                        printf("%d\t",transpose[i][j]);
                }
                printf("\n");
        }

}










