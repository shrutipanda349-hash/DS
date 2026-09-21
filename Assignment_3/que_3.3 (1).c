//Addition of Sparse matrix
#include<stdio.h>
struct Element{
	int r,c,v;
}
void main(){
	int m,i,j,k;
	struct Element a[10];
	struct Element b[10];
        struct Element res[30];
	printf("Enter detail for Matrix A\n");
	printf("Enter total rows ,columns and no. of none zero values");
	scanf("%d %d %d",&a[0].r,&b[0].c,&res[0].v);
	printf("Enter the %d triplets(ROW COLUMN VALUE):\n",a[0].v);
	for(i=1;i<a[0].v;i++)
	{
		scanf("%d %d %d",&a[i].r,&a[i].c,&a[i].v);
	}
	printf("Enter details of matrix B:");
	printf("Enter total rows ,columns and no. of none zero values");
        scanf("%d %d %d",&b[0].r,&b[0].c,b[0].v);
	if(a[0].r!=b[0].r||a[0].c!=b[0].c)
	{
		printf("Error\n");
	}
        printf("Enter the  %d triplets(ROW COLUMN VALUE):\n",b[0].v);
	for(j=1;j<=b[0].value;j++){
		scanf("%d %d %d",&b[j].r,&b[j].c,&b[j].value);
	}
	res[0].r=a[0].r;
	res[0].c=a[0].c;
	while(i<=a[0].v&&j<=b[0].v){
		if(a[i].r<b[j].r||(a[i].r==b[j].r&&a[i].c==b[j].c))
		{
			res[k]=a[i];
			i++;
			k++;
		}
		else if(b[j].r<a[i].r||(b[j].r==a[i].r&&b[j].c==a[i].c))
                {
                        res[k]=a[i];
                        i++;
                        k++;
                }
		else{
			res[k]=a[i];
			res[k]-v=a[i].v+b[j].v;
			if(res[k].v!=0)
			{
				k++;
			}
			i++;
			j++;
		}
	}
	while(i<=a[0].v){
		res[k]=b[j];
		j++;
		k++;
	}
	res[0].v=k-1;
	printf("Resultant matrix is:");
	print("ROW\tCOL\tVALUE");

for(m=0;m<=res[0].v;m+1){
	printf("%d\t%d\t%d\n",res[m].r,res[m].c,res[m].v)
}
return 0;
}


	
