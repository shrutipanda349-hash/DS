// represntation of sparse matrix in triplet form
#include<stdio.h>
void main()
{
	int a[10][10],triplet[10][3],i,j,r,c,nzero,k=1;
	printf("enter row and column:");
	scanf("%d %d",&r,&c);
	printf("enter matrix:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<r;i++)
        {
                for(j=0;j<c;j++)
                {
                        printf("%d\t",a[i][j]);
                }
		printf("\n");
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
}





