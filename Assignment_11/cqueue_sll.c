//Implementation of circular linked list
#include<stdio.h>
#include<stdlib.h>
 struct Node{
	 int info;
	 struct Node* next;
 };

struct Node *front=NULL;
struct Node *rear=NULL;
 


//Enqueue
void Enqueue()
{
	struct Node*ptr;
	int item;
	ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->info=item;
	if(front==NULL)
	{
		front=rear=ptr;
		rear->next=front;
	}
	else
	{
		rear->next=ptr;
		rear=ptr;
		rear->next=front;
	}
	printf("Item inserted successfully\n");
}

//Dequeue
void Dequeue()
{
	struct Node*ptr;
	if(front==NULL)
	{
		printf("Circular queue is empty\n");
	}
	else
	{
		ptr=front;
		printf("Deueued element:%d\n",ptr->info);
		if(front==rear)
		{
			front=rear=NULL;
		}
	else
		{
			ptr=front;
			front=front->next;
			rear->next=front;
			printf("Deueued element:%d\n",ptr->info);
		}
			free(ptr);
		}
}
//Traverse
void Traverse()
{
	struct Node*ptr;
	if(front==NULL)
	{
		printf("CQUEUE is empty\n");
	}
	 printf("Circular queue elements are:\n");
	 ptr=front;
	 do
	 {
		 printf("%d->",ptr->info);
		 ptr=ptr->next;
	 }
	 while(ptr!=front);
	 printf("(Back to front %d)",front->info);
}

//main function
int main()
{
	int choice,item;
	char ch;
	do
	{
		printf("\n___________IMPLEMENTATION OF CIRCULAR QUEUE USING LINKED LIST____________\n");
		printf("\n");
		printf("1.ENQUEUE OPERATION\n");
		printf("2.DEQUEUE OPERATION\n");
		printf("3.TRAVERSE\n");
		printf("4. EXIT\n");
		printf("enter your choice: \n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter item:\n");
				scanf("%d",&item);
				Enqueue();
				break;
			case 2:
				Dequeue();
				break;
			case 3:
				Traverse();
				break;
			case 4:
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
