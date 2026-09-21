#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void Enqueue();
void Dequeue(); // Changed return type to void since main ignores the return
void Traverse();

int Pqueue[SIZE];
int priority[SIZE];
int n = 0; // Tracks the actual number of elements currently in the queue

int main() // Fixed main function signature
{
    int option;
    char a;

    do {
        printf("\n------------ QUEUE OPERATION ------------\n");
        printf("1. INSERT OPERATION\n");
        printf("2. DELETE OPERATION\n");
        printf("3. TRAVERSING ELEMENT OF QUEUE\n");
        printf("4. EXIT\n");
        printf("ENTER YOUR OPTION: ");
        
        if (scanf("%d", &option) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (option)
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
                printf("EXITING...\n");
                exit(0);
            default:
                printf("\nINVALID OPTION\n");
        }
        printf("\nDO YOU WANT TO CONTINUE (y/n): ");
        scanf(" %c", &a);
    } while (a != 'n' && a != 'N');

    return 0;
}

// Check overflow condition and perform insert operation
void Enqueue()
{
    int item, pri;

    if (n == SIZE)
    {
        printf("Queue Overflow! Cannot insert elements.\n");
    }
    else
    {      
        printf("Enter element: ");
        scanf("%d", &item);
        printf("Enter priority (lower number = higher priority): ");
        scanf("%d", &pri);

        // Store both elements at the exact same active index 'n'
        Pqueue[n] = item;
        priority[n] = pri;
        n++; // Fixed: Crucial step to step up array tracker position count

        printf("Element and its priority inserted successfully.\n");
    }
}

// Check underflow condition and perform deletion based on highest priority
void Dequeue()
{	
    int posn = 0;
    int i;

    if (n == 0)
    {
        printf("Queue Underflow! The queue is empty.\n");
    }
    else
    {
        // Find the index of the highest priority element (lowest integer value)
        for (i = 1; i < n; i++)
        {
            if (priority[i] < priority[posn])
            {
                posn = i;
            }
        }
        
        printf("Deleted item is: %d (with priority %d)\n", Pqueue[posn], priority[posn]);
        
        // Shift remaining array records down to fill the empty spot
        for (i = posn; i < n - 1; i++)
        {
            Pqueue[i] = Pqueue[i + 1];
            priority[i] = priority[i + 1];
        }
        n--; // Lower total active element tracking allocation limits
    }
}

// Traversing a queue
void Traverse()
{
    int i;
    if (n == 0)
    {
        printf("Priority Queue is empty!\n");
    }
    else
    {
        printf("Priority Queue elements are:\n");
        printf("Index\tElement\tPriority\n");
        for (i = 0; i < n; i++)
        {
            printf("[%d]\t%d\t\t%d\n", i, Pqueue[i], priority[i]);
        }
    }
}
