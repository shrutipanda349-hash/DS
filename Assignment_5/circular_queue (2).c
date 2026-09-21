//circular queue implimentation
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

void Enqueue();
int Dequeue();
void Traverse();
 
int cqueue[SIZE];
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
			      Traverse();
		         break;
			case 4:
			     printf("EXIT");
			     exit(0);
			     printf("\n");
		       	     break;
			default:
			      printf("\nINVALID OPTION\n");
		}
		printf("\nDO YOU WANT TO CONTINUE(y/n):\n");
		scanf(" %c",&a);
	} while(a!='n');

}

//check overflow condition and perform insert operation
void Enqueue()
{
	if (front==(rear+1)%SIZE)
	{
		printf("Queue overflow ");
	}
	else if(front==-1)
	{      
		

		front=0;
		rear=0;
	//	cqueue[rear]=item;
		printf("Enter element:");
                scanf("%d",&item);
		cqueue[rear]=item;
	}						

	else
	{
		printf("Enter element:");
		scanf("%d",&item);
		rear=rear+1%SIZE;
		cqueue[rear]=item;
		printf("Element inserted succcessfully\n");
	}

}

//check underflow condition and perform deletion operation
int Dequeue()
{
	int ele=0;
	if((front==-1))
	{
		printf("UNDERFLOW CONDITION");
	}
	else if(front==rear)
	{
		printf("Deleted item is %d",cqueue[front]);

		front=-1;
		rear=-1;
//		printf("Deleted item is %d",cqueue[front]);
	}

	else
	{
		ele=cqueue[front];
		front=(front+1)%SIZE;
	       printf("Deleted item is %d",ele);
       return 0;	       

	}
	
}
//traversing a queue
void Traverse()
{
	int i;
	if(front==-1&&rear==-1)
	{
		printf("CQueue is empty\n");
	}
	else
	{
		printf("queue elements are:\n");
		for(i=front;i<=rear;i++)
	{
			printf("%d\n",cqueue[i]);
	}	}
		}

















