//queue implimentation
#include<stdio.h>
#define SIZE 5
 
int queue[SIZE];
int front=-1;
int rear=-1;
int option;
char a;
int item;

void main()
{


	do{
		printf("\n------------	QUEUE OPERATION------------\n");
		printf("1.INSERT OPERATION\n");
		printf("2.DELETE OPERATION\n");
		printf("3.TRAVERSING ELEMENT OF QUEUE\n");
		printf("4.EXIT\n");
		printf("ENTER YOUR OPTION:__\n");
	        scanf("%d",&option);
		switch(option)
		{
			case 1:
				Enqueue();
				break;
			case 2:
			       Dequeue();
		       	       break;
			case 3:
			      TRAVERSE();
		              break;
			case 4:
			     printf("EXIT");
		       	     break;
			default:
			      printf("\nINVALID OPTION\n");
		}
		printf("\nDO YOU WANT TO CONTINUE(y/n):\n");
		scanf(" %c",&a);
	} while(a!='n');

}

//check overflow condition and perform insert operation
int Enqueue()
{
	if (rear==(SIZE-1))
	{
		printf("Queue overflow ");
	}
	else
	{
		printf("Enter element:");
		scanf("%d",&item);
		rear=rear+1;
		queue[rear]=item;
		printf("Element inserted succcessfully\n");
	}
	return 0;
}

//check underflow condition and perform deletion operation
int Dequeue()
{
	int ele=0;
	if((front==-1&&rear==-1)||(front==rear))
	{
		printf("UNDERFLOW CONDITION");
	}
	else
	{
		 
		ele=queue[++front];
		printf("Deleted item is %d",ele);

	}
	
}
//traversing a queue
void TRAVERSE()
{
	int i;
	if(front==-1&&rear==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("queue elements are:\n");
		for(i=front+1;i<=rear;i++)
		{
			printf("%d\n",queue[i]);
		}
	}
}
















