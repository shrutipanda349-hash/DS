//Implementation of Queue using linkedlist 
# include<stdio.h>
#include<stdlib.h>
struct Node
{
	int info;
	struct Node*next;
};
 
struct Node*rear=NULL;
struct Node*front=NULL;

//enqueue
void Enqueue(int item)
{
	struct Node*ptr;
	ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->info=item;
	ptr->next=NULL;
	if(rear==NULL)
	{
		front=ptr;
		rear=ptr;
	}
	else
	{
		rear->next=ptr;
		rear=ptr;
	}
}
//Dequeue
 void Dequeue()
{
	struct Node *ptr;
	if (front==NULL)
	{
		printf("Queue is empty\n");
	
	}
	else
	{ if(front->next==NULL)
	{
		ptr=front;
		rear=front=NULL;
	free(ptr);
	}
	else
	{
		front=front->next;
		free(ptr);
	}
	printf("Element deleted successfully");
	}
}
//Traverse
void Traverse()
{
	struct Node*temp;
	if(temp==NULL)
	{
		printf("Queue is Empty\n");
	}
	temp=front;
	printf("Queue elements are:\n");
	while(temp!=NULL)
	{
		printf("%d\n",temp->info);
		temp=temp->next;
	}
}
//main function
int main()
{
	int choice,item;
	char ch;
	do
	{
		printf("\n___________IMPLEMENTATION OF QUEUE USING LINKED LIST____________\n");
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
				Enqueue(item);
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

