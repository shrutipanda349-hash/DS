//Double linked list implementation
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
 struct node *start=NULL;
//main function
 int main()
{
	int ch;
	while(1)
	{
		printf("\n__________________DOUBLE LINKED LIST_____________________\n");
		printf("1.INSERT AT BEGNING\n");
		printf("2.INSERT AT END\n");
		printf("3.INSERT AT ANY POSITION\n");
		printf("4.DELETE FROM BEGNING \n");
		printf("5.DELETE FROM END\n");
		printf("6.DELETE FROM ANY POSITION\n");
		printf("7.TRAVERSE\n");
		printf("8. EXIT \n");
		printf("enter your option:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insertbegin();
				break;
			case 2:
				insertend();
				break;
			case 3:
				 insertany();
				break;	
			case 4:
				deletebegin();
				break;
			case 5:
				deleteend();
				break;
			case 6:
				deleteany();
				break;
			case 7:
				traverse();
				break;
			case 8:
				printf("program ended \n");
				exit(0);
			default:
				printf("invalid choice \n");
		}
	}
	return 0;
}
//INSERT AT BEGINING

void insertbegin()
{
	struct node*ptr;
	ptr =(struct node*)malloc(sizeof(struct node));
	printf("enter value:");
	scanf("%d",&ptr->data);
        ptr->prev=NULL;
	ptr->next=start;

	if(start!=NULL)
		start->prev=ptr;
	       start= ptr;
	       printf("node inserted at the begin\n");
}

//INSERT AT END

void insertend()
{
	struct node*ptr,*temp;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter Data:");
	scanf("%d",&ptr->data);
	ptr->next=NULL;
	if(start==NULL)
	{
		ptr->prev =NULL;
		start=ptr;
	}
	temp=start;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=ptr;
	ptr->prev=temp;
	printf("Node inserted at the end\n");
}
//DELETE FROM BEGIN

void deletebegin()
{
	struct node*temp;
	if(start==NULL)
	{
		printf("list is empty \n");
		return;
	}
	temp=start;
	start=start-> next;
	if(start!= NULL)
	start->prev=NULL;
	free(temp);
}
//DELETE FROM END
void deleteend()
{
	struct node* temp;
	if(start== NULL)
	{
		printf("list is empty \n");
		return;
	}
	temp=start;
	if(start-> next == NULL);
	{
		start=NULL;
		free(temp);
		return ;
	}
	while(temp ->next != NULL)
		temp=temp->next;
	temp->prev->next=NULL;
	free(temp);
}
//Traverse
void traverse()
{
	struct node*temp=start;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

//INSERT AT ANY POSITION
 void insertany()
{
	struct node *ptr,*loc;
	int p,i;
	printf("Enter position:");
	scanf("%d",&p);
	if(p<1)
	{
		printf("Invalid postion");
	}
	ptr=(struct node *)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&ptr->data);
	if(p==1)
	{
		ptr->prev=NULL;
		ptr->next=start;
		if(start!=NULL)
		{
			start->prev=ptr;
		}
		start=ptr;
	}
		else{
			loc=start;
			for(i=1;i<p-1 && loc!=NULL;i++)
			{
				loc=loc->next;
			}
			if(loc==NULL)
			{
			printf("INVALID POSITION");
		         free(ptr);
		 	}
			else
			{ptr->next=loc->next;
				ptr->prev=loc;
				if(ptr->next!=NULL){
					loc->next->prev=ptr;
				}
				loc->next=ptr;
			}
		}
	}

//DELETE AT ANY POSITION
  void deleteany()
{
	struct node *loc;
	int p,i;
	printf("Enter position:");
	scanf("%d",&p);
	if(start==NULL||p<1)
	{printf("INVALID POSITION\n");
	}
	loc=start;
                        for(i=1;i<p-1 && loc!=NULL;i++)
                        {
                                loc=loc->next;
                        }
                        if(loc==NULL)
                        {
                        printf("INVALID POSITION");
			}
	else
	{
		if(loc->prev!=NULL)
		{
			loc->prev->next=loc->next;
		}
		else
		{
			start=loc->next;
		}
		if(loc->next!=NULL){
			loc->next->prev=loc->prev;
		}
		free(loc);
		printf("NODE DELETED");
	}
}































