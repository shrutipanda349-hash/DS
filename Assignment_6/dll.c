#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
    struct Node *prev;
};

struct Node *START = NULL;

void insert_begin_dll(int item) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->info = item;
    if (START == NULL) {
        ptr->next = ptr->prev = NULL;
        START = ptr;
    } else {
        ptr->next = START;
        START->prev = ptr;
        ptr->prev = NULL;
        START = ptr;
    }
    printf("Inserted %d at beginning\n", item);
}

void insert_end_dll(int item) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->info = item;
    ptr->next = NULL;
    if (START == NULL) {
        ptr->prev = NULL;
        START = ptr;
    } else {
        struct Node *loc = START;
        while (loc->next != NULL) loc = loc->next;
        loc->next = ptr;
        ptr->prev = loc;
    }
    printf("Inserted %d at end\n", item);
}

void insert_specific_loc_dll(int item, int posn) {
    if (posn == 1) { insert_begin_dll(item); return; }
    struct Node *temp = START;
    for (int i = 1; i < posn-1 && temp != NULL; i++) temp = temp->next;
    if (temp == NULL) { printf("Invalid position\n"); return; }
    
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->info = item;
    ptr->prev = temp;
    ptr->next = temp->next;
    if (temp->next != NULL) temp->next->prev = ptr;
    temp->next = ptr;
    printf("Inserted %d at position %d\n", item, posn);
}

void delete_begin_dll() {
    if (START == NULL) { printf("List empty\n"); return; }
    struct Node *temp = START;
    if (START->next == NULL) START = NULL;
    else { START = START->next; START->prev = NULL; }
    printf("Deleted %d\n", temp->info);
    free(temp);
}

void delete_end_dll() {
    if (START == NULL) { printf("List empty\n"); return; }
    struct Node *ptr = START;
    if (ptr->next == NULL) { START = NULL; printf("Deleted %d\n", ptr->info); free(ptr); return; }
    while (ptr->next != NULL) ptr = ptr->next;
    ptr->prev->next = NULL;
    printf("Deleted %d\n", ptr->info);
    free(ptr);
}

void delete_specific_loc_dll(int posn) {
    if (START == NULL) { printf("List empty\n"); return; }
    if (posn == 1) { delete_begin_dll(); return; }
    struct Node *temp = START;
    for (int i = 1; i < posn && temp != NULL; i++) temp = temp->next;
    if (temp == NULL) { printf("Invalid position\n"); return; }
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    printf("Deleted %d at position %d\n", temp->info, posn);
    free(temp);
}

// 7) TRAVERSE - Forward & Backward (Advantage of DLL)
void traverse_dll() {
    if (START == NULL) { printf("List empty\n"); return; }
    struct Node *ptr = START;
    printf("Forward : NULL <-> ");
    while (ptr != NULL) { printf("%d <-> ", ptr->info); if(ptr->next==NULL) break; ptr=ptr->next; }
    printf("NULL\nBackward: NULL <-> ");
    while (ptr != NULL) { printf("%d <-> ", ptr->info); ptr=ptr->prev; }
    printf("NULL\n");
}

// 8) SEARCH
void search_dll(int item) {
    struct Node *ptr = START; int pos = 1;
    while (ptr != NULL) {
        if (ptr->info == item) { printf("Found %d at position %d\n", item, pos); return; }
        ptr = ptr->next; pos++;
    }
    printf("Item %d not found\n", item);
}

// 9) SORT
void sort_dll() {
    if (START == NULL) { printf("List empty\n"); return; }
    struct Node *ptr, *loc; int t;
    for (ptr = START; ptr->next != NULL; ptr = ptr->next) {
        for (loc = ptr->next; loc != NULL; loc = loc->next) {
            if (ptr->info > loc->info) { t = ptr->info; ptr->info = loc->info; loc->info = t; }
        }
    }
    printf("List Sorted\n");
    traverse_dll();
}

int main() {
    int choice, item, pos;
    char ch;
    do {
        printf("\n--- MENU DRIVEN DLL ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Location\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Any Location\n");
        printf("7. Traverse\n");
        printf("8. Search\n");
        printf("9. Sort\n");
        printf("10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: printf("Enter item: "); scanf("%d",&item); insert_begin_dll(item); break;
            case 2: printf("Enter item: "); scanf("%d",&item); insert_end_dll(item); break;
            case 3: printf("Enter item and pos: "); scanf("%d %d",&item,&pos); insert_specific_loc_dll(item,pos); break;
            case 4: delete_begin_dll(); break;
            case 5: delete_end_dll(); break;
            case 6: printf("Enter pos to delete: "); scanf("%d",&pos); delete_specific_loc_dll(pos); break;
            case 7: traverse_dll(); break;
            case 8: printf("Enter item to search: "); scanf("%d",&item); search_dll(item); break;
            case 9: sort_dll(); break;
            case 10: exit(0);
            default: printf("Invalid choice\n");
        }
        printf("Continue y/n: ");
        scanf(" %c",&ch);
    } while(ch=='y' || ch=='Y');
    return 0;
}
