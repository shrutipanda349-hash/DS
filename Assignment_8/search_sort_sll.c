//Single linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

struct Node *START = NULL;

// 1) Insert at beginning
void insert_begin_sll(int item) {
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->info = item;
    if (START == NULL) { // single node in list
        ptr->next = NULL;
    } else { // many nodes in list
        ptr->next = START;
    }
    START = ptr;
    printf("Inserted %d at the beginning\n", item);
}

// 2) Search a node
void search_node_sll(int item) {
    struct Node *ptr;
    int pos = 1;
    if (START == NULL) {
        printf("List is empty\n");
        return;
    }
    ptr = START;
    while (ptr != NULL) {
        if (ptr->info == item) {
            printf("SEARCH SUCCESSFUL: Item %d found at position %d\n", item, pos);
            return;
        }
        ptr = ptr->next;
        pos++;
    }
    printf("SEARCH UNSUCCESSFUL: Item %d not found\n", item);
}

// 3) Sort the nodes - Bubble sort by swapping info
void sort_nodes_sll() {
    struct Node *ptr, *loc;
    int temp;
    if (START == NULL) {
        printf("List is empty\n");
        return;
    }
    for (ptr = START; ptr->next != NULL; ptr = ptr->next) {
        for (loc = ptr->next; loc != NULL; loc = loc->next) {
            if (ptr->info > loc->info) {
                temp = ptr->info;
                ptr->info = loc->info;
                loc->info = temp;
            }
        }
    }
    printf("List sorted successfully\n");
    traverse_sll();
}

// 4) Traverse the elements
void traverse_sll() {
    struct Node *ptr;
    if (START == NULL) {
        printf("List is empty\n");
        return;
    }
    ptr = START;
    printf("List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->info);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, item, pos;
    char ch;
    do {
        printf("\n--- Menu driven forsorting and searching of single linked list ---\n");
        printf("1) Insert node at beginning\n");
    	printf("2) Search a node\n");
        printf("3) Sort the nodes\n");
        printf("4) Exit\n");
        printf("Enter Your option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item: "); scanf("%d", &item);
                insert_begin_sll(item); break;
            case 2:
                printf("Enter item to search: "); scanf("%d",&item);
                search_node_sll(item); break;
            case 3:
                sort_nodes_sll(); break;
            case 4:
                exit(0);
            default:
                printf("Invalid option\n");
        }
        printf("Do you want to continue (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
