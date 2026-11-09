//Sorting techinques
#include<stdio.h>

 int i,j,n, a[100];

  //main function
int main()
{
	int choice,item;
	char ch;
	do
	{
		printf("\n___________Sorting Techinques____________\n");
		printf("\n");
		printf("1.INSERTION\n");
		printf("2.BUBBLE SORT\n");
		printf("3.SELECTION SORT\n");
		printf("4.INSERTION SORT\n");
		printf("5. EXIT\n");
		printf("enter your choice: \n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				bubble_sort();
				break;
			case 3:
				selection_sort();
				break;
			case 4:
				insertion_sort();
				break;

			case 5:
				exit(0);
				break;
			default:
				printf("invalid choice\n");
		}
	printf("do you want to continue?(Y/N):");
	scanf(" %c",&ch);
	}
	while(choice=='Y' || choice =='y');
	printf("program ended \n");
	return 0;
}

//array element insertion
void insert()
{
	int n;
	printf("Enter size of an array:");
	scanf("%d",&n);
	printf("Enter array element\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");

	printf("Element inserted successfully\n");
}

//Bubble sorting
void bubble_sort()
{ int j;
	printf("Bubble sorted:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
		 {
			 int temp=a[j];
			 a[j]=a[j+1];
			 a[j+1]=temp;
		
		 }

		}
		printf("%d\t",a[i]);
	}
}

//Selection sorting
int selection_sort(int a[], int n)
{ int temp;
 printf("Selection sorted:\n");
  for(i=0;i<n;i++)
  {
	  int min=i;
	  for(j=i+1;j<n;j++)
	  {
		if(a[j]<a[min])
		{
			min=j;

		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	  }
	  printf("%d\t",a[i]);
  }
}

//Insertion Sorting
int insertion_sort(int a[],int n)
{
	printf("Insertion sorted:\n");
	for(i=1;i<n-1;i++)
	{
		int temp=a[i];
		int j=i-1;
		while((temp,a[j])&&(j>=0))
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=temp;
		printf("%d\t",a[i]);
	}
}


