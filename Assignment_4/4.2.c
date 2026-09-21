#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

/* Function for PUSH operation */
void push()
{
    int value;

    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        printf("Enter the element to push: ");
        scanf("%d", &value);

        top++;
        stack[top] = value;

        printf("%d is pushed into the stack.\n", value);
    }
}

/* Function for POP operation */
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("Deleted element: %d\n", stack[top]);
        top--;
    }
}

/* Function for Traversing the stack */
void traverse()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Elements of the stack are:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

/* Function to return precedence of an operator */
int precedence(char operator)
{
    if (operator == '^')
        return 3;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '+' || operator == '-')
        return 1;
    else
        return 0;
}

/* Function for Infix to Postfix conversion */
void infixToPostfix()
{
    char infix[MAX], postfix[MAX];
    char opStack[MAX];
    int topOp = -1;
    int i, j = 0;
    char ch;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        /* If operand, add it to postfix */
        if (isalnum(ch))
        {
            postfix[j] = ch;
            j++;
        }

        /* If opening bracket */
        else if (ch == '(')
        {
            topOp++;
            opStack[topOp] = ch;
        }

        /* If closing bracket */
        else if (ch == ')')
        {
            while (topOp != -1 && opStack[topOp] != '(')
            {
                postfix[j] = opStack[topOp];
                j++;
                topOp--;
            }

            if (topOp != -1)
                topOp--;
        }

        /* If operator */
        else
        {
            while (topOp != -1 &&
                   precedence(opStack[topOp]) >= precedence(ch))
            {
                postfix[j] = opStack[topOp];
                j++;
                topOp--;
            }

            topOp++;
            opStack[topOp] = ch;
        }
    }

    /* Pop remaining operators */
    while (topOp != -1)
    {
        postfix[j] = opStack[topOp];
        j++;
        topOp--;
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
}

/* Function for Postfix Evaluation */
void postfixEvaluation()
{
    char postfix[MAX];
    int evalStack[MAX];
    int evalTop = -1;
    int i;
    char ch;
    int a, b, result;
    int value;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        /* If operand */
        if (isdigit(ch))
        {
            value = ch - '0';
            evalTop++;
            evalStack[evalTop] = value;
        }

        /* If operator */
        else
        {
            b = evalStack[evalTop];
            evalTop--;

            a = evalStack[evalTop];
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

/* Main function */
int main()
{
    int choice;
    char continueChoice;

    do
    {
        printf("\n========== STACK MENU ==========\n");
        printf("1. PUSH OPERATION\n");
        printf("2. POP OPERATION\n");
        printf("3. TRAVERSING ELEMENTS OF A STACK\n");
        printf("4. EVALUATION OF POSTFIX EXPRESSION\n");
        printf("5. CONVERSION OF INFIX TO POSTFIX EXPRESSION\n");
        printf("6. EXIT\n");
        printf("================================\n");

        printf("Enter your option: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                traverse();
                break;

            case 4:
                postfixEvaluation();
                break;

            case 5:
                infixToPostfix();
                break;

            case 6:
                printf("Exiting the program...\n");
                return 0;

            default:
                printf("Invalid option! Please try again.\n");
        }

        printf("\nDo you want to continue (Y/N): ");
        scanf(" %c", &continueChoice);

    } while (continueChoice == 'Y' || continueChoice == 'y');

    printf("Program terminated.\n");

    return 0;
}
