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

// 2) Insert at end
void insert_end_sll(int item) {
    struct Node *ptr, *loc;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->info = item;
    ptr->next = NULL;
    if (START == NULL) { // single node in list
        START = ptr;
    } else { // many nodes in list
        loc = START;
        while (loc->next != NULL) {
            loc = loc->next;
        }
        loc->next = ptr;
    }
    printf("Inserted %d at the end\n", item);
}

// 3) Insert at any location - position wise
void insert_specific_loc_sll(int item, int posn) {
    struct Node *ptr, *temp;
    int i;
    if (posn == 1) {
        insert_begin_sll(item);
        return;
    }
    ptr = (struct Node *)malloc(sizeof(struct Node));
    temp = START;
    // Traverse up to posn-1
    for (i = 1; i < posn-1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position %d not found\n", posn);
        free(ptr);
        return;
    }
    ptr->info = item;
    ptr->next = temp->next;
    temp->next = ptr;
    printf("Inserted %d at position %d\n", item, posn);
}

// 4) Delete from beginning
void delete_begin_sll() {
    struct Node *ptr;
    if (START == NULL) { // No nodes in list
        printf("List is empty!\n");
        return;
    } else { // more nodes in list
        ptr = START;
        START = START->next;
        printf("Deleted node with value %d\n", ptr->info);
        free(ptr);
    }
}

// 5) Delete from end
void delete_end_sll() {
    struct Node *ptr, *loc;
    if (START == NULL) { // No nodes in list
        printf("List is empty!\n");
        return;
    } else if (START->next == NULL) { // Single node in list
        ptr = START;
        START = NULL;
        printf("Deleted last node with value %d\n", ptr->info);
        free(ptr);
    } else { // more nodes in list
        loc = START;
        ptr = START->next;
        while (ptr->next != NULL) {
            loc = ptr;
            ptr = ptr->next;
        }
        loc->next = NULL;
        printf("Deleted last node with value %d\n", ptr->info);
        free(ptr);
    }
}

// 6) Delete from any location - Case 1: Item-wise, Case 2: Position-wise
// Case-1: Item wise deletion (assumption: all elements are unique)
void delete_specific_item_sll(int item) {
    struct Node *ptr, *loc;
    if (START == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (START->info == item) {
        delete_begin_sll();
        return;
    }
    ptr = START;
    loc = ptr;
    while (ptr != NULL) {
        if (ptr->info == item) {
            loc->next = ptr->next;
            printf("Item %d found and deleted\n", item);
            free(ptr);
            return;
        } else {
            loc = ptr;
            ptr = ptr->next;
        }
    }
    printf("Item %d not found in the list\n", item);
}

// Case-2: Position wise deletion
void delete_specific_pos_sll(int posn) {
    struct Node *ptr, *temp;
    int i;
    if (START == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (posn == 1) {
        delete_begin_sll();
        return;
    }
    temp = START;
    ptr = temp->next;
    for (i = 1; i < posn-1; i++) {
        temp = temp->next;
        ptr = ptr->next;
        if (ptr == NULL) break;
    }
    if (ptr == NULL) {
        printf("Position out of range\n");
        return;
    }
    temp->next = ptr->next;
    printf("Deleted node at position %d with value %d\n", posn, ptr->info);
    free(ptr);
}

// 7) Traverse the elements
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

// 8) Search a node
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

// 9) Sort the nodes - Bubble sort by swapping info
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

int main() {
    int choice, item, pos;
    char ch;
    do {
        printf("\n--- Menu driven window for single linked list ---\n");
        printf("1) Insert node at beginning\n");
        printf("2) Insert node at end\n");
        printf("3) Insert node at any location\n");
        printf("4) Delete node from beginning\n");
        printf("5) Delete node from end\n");
        printf("6) Delete node from any location\n");
        printf("7) Traverse the elements\n");
        printf("8) Search a node\n");
        printf("9) Sort the nodes\n");
        printf("10) Exit\n");
        printf("Enter Your option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item: "); scanf("%d", &item);
                insert_begin_sll(item); break;
            case 2:
                printf("Enter item: "); scanf("%d", &item);
                insert_end_sll(item); break;
            case 3:
                printf("Enter item and position: "); scanf("%d %d", &item, &pos);
                insert_specific_loc_sll(item, pos); break;
            case 4:
                delete_begin_sll(); break;
            case 5:
                delete_end_sll(); break;
            case 6:
                printf("Delete by: 1.Item 2.Position: ");
                int c; scanf("%d",&c);
                if(c==1){ printf("Enter item to delete: "); scanf("%d",&item); delete_specific_item_sll(item); }
                else { printf("Enter position to delete: "); scanf("%d",&pos); delete_specific_pos_sll(pos); }
                break;
            case 7:
                traverse_sll(); break;
            case 8:
                printf("Enter item to search: "); scanf("%d",&item);
                search_node_sll(item); break;
            case 9:
                sort_nodes_sll(); break;
            case 10:
                exit(0);
            default:
                printf("Invalid option\n");
        }
        printf("Do you want to continue (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return 0;
}