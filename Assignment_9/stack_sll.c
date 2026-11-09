//Implementation of stack using single linked list
#include<stdio.h>

 struct Node{
	 int info;
	 struct Node *next;
 };
struct Node *top= NULL;
//push operation
void push(int item)
{
	struct Node *ptr;
	ptr=(struct Node *)malloc(sizeof(struct Node));
//	printf("Enter item:");
//	scanf("%d",&item);
	ptr->info=item;
	if(top==NULL)
	{
		ptr->next=NULL;
		top=ptr;
	}
	else
	{
		ptr->next=top;
		top=ptr;
	}
	printf("Inserted successfully\n");
}
//pop operation
void pop()
{
	struct Node*ptr;
	if(top==NULL)
	{
		printf("underflow condition\n");
	}
	else
	{
		ptr=top;
		top=top->next;
		free(ptr);
		printf("Item deleted successfully\n");

	}
	
}
//Traverse
void traverse()
{
	struct Node *temp;
	temp=top;
	while(temp->next!=NULL)
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
		printf("\n___________IMPLEMENTATION OF STACK USING LINKED LIST____________\n");
		printf("\n");
		printf("1.PUSH  OPERATION\n");
		printf("2.POP OPERATION\n");
		printf("3.TRAVERSE\n");
		printf("4. EXIT\n");
		printf("enter your choice: \n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter item:\n");
				scanf("%d",&item);
				push( item);
				break;
			case 2:
				pop();
				break;
			case 3:
				traverse();
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
