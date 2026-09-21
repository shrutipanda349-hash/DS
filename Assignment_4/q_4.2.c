//POSTFIX EVALUATION
#include<stdio.h>
#define SIZE 5

//void PUSH(void);
//int POP(void);
//void TRANSVERSE();

int stack[SIZE];
        int top=-1;
        int option;
        char a;

 void main()
{
/*	int stack[SIZE];
	int top=-1;
	int option;
	char a;*/

	do{
		printf("\n------------STACK OPERATION------------\n");
		printf("1.PUSH\n");
		printf("2.POP\n");
		printf("3.TRANSVERSE\n");
		printf("4.postfix evaluation\n");
		printf("5.EXIT\n");
		printf("ENTER YOUR OPTION:__\n");
	        scanf("%d",&option);
		switch(option)
		{
			case 1:
				PUSH();
				break;
			case 2:
			       printf("Deleted item is %d",POP());
		       	       break;
			case 3:
			      TRANSVERSE();
		              break;
		        case 4:
                              evaluation_postfix();
                              break;

			case 5:
			     printf("EXIT");
		       	     break;
			default:
			      printf("\nINVALID OPTION\n");
		}
		printf("\nDO YOU WANT TO CONTINUE(y/n):\n");
		scanf(" %c",&a);
	} while(a!='n');

}
//push function
void PUSH()
{
int element;
if(top==SIZE-1)
{
 printf("\nStack is overflow\n");
}
else
{
	printf("Enter Elements:");
	scanf("%d",&element);
	top++;
	stack[top]=element;
	printf("Elements pushed successfully\n");
}
}

//pop function
int POP()
{
	if(top==-1)
	{
		printf("Stack is underflow");
	}
	else
	{
		//printf("Delete item:%d\n",stack[top]);
		top--;
	}
	return stack[top];
}

//Transverse function
void TRANSVERSE()
{
	int i;
	if(top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Stack elements are:\n");
		for(i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}
//postfix evaluation
void evaluation_postfix()
{
	char postfix[SIZE];
	int evalStack[SIZE];
	int evalTop=-1;
	int i;
	char ch;
	int a,b,result;
	int value;
	printf("Enter postfix expression:");
	scanf("%s",postfix);
	for(i=0;postfix[i]!='\0';i++)
	{
		ch=postfix[i];
		//if operand
		if(isdigit(ch))
		{
			value=ch-'0';
			evalTop++;
			evalStack[evalTop]=value;
		}
		//if operator
		else
		{
			b=evalStack[evalTop];
			evalTop--;

			a=evalStack[evalTop];
			evalTop--;

		

	     if (ch == '+')
                result = a + b;
            else if (ch == '-')
                result = a - b;
            else if (ch == '*')
                result = a * b;
            else if (ch == '/')
                result = a / b;
            else if (ch == '%')
                result = a % b;
            else
            {
                printf("Invalid operator!\n");
                return;
            }

            evalTop++;
            evalStack[evalTop] = result;
        }
    }

    printf("Result = %d\n", evalStack[evalTop]);
}

























