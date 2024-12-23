#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node* head = NULL;


void front_insertion() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node)); 
    printf("Enter the element to be inserted at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    newnode->prev = NULL;
    if (head != NULL) {
        head->prev = newnode;
    }
    head = newnode;
}


void end_insertion() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node)); 
    struct node* temp = head;
    printf("Enter the element to be inserted at the end: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}


void middle_insertion() {
    int position, i = 1;
    struct node* newnode = (struct node*)malloc(sizeof(struct node)); 
    struct node* temp = head;
    printf("Enter the element to be inserted: ");
    scanf("%d", &newnode->data);
    printf("Enter the position to insert at (1-based index): ");
    scanf("%d", &position);
    
    if (position == 1) {
        front_insertion();
        return;
    }
    
    while (i < position - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position is out of range.\n");
    } else {
        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newnode;
        }
        temp->next = newnode;
    }
}


void front_deletion() {
    struct node* temp;
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}


void middle_deletion() {
    int position, i = 1;
    struct node* temp = head;
    struct node* to_delete;
    
    printf("Enter the position to delete from (1-based index): ");
    scanf("%d", &position);
    
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    if (position == 1) {
        front_deletion();
        return;
    }
    
    while (i < position && temp != NULL) {
        temp = temp->next;
        i++;
    }
    
    if (temp == NULL) {
        printf("Position is out of range.\n");
    } else {
        to_delete = temp;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        free(to_delete);
    }
}


void end_deletion() {
    struct node* temp = head;
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL; 
    }
    
    free(temp);
}


void display() {
    struct node* temp = head;
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    printf("List elements from head to rear: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int choice;
    
    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Middle\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at Middle\n");
        printf("6. Delete at End\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                front_insertion();
                break;
            case 2:
                end_insertion();
                break;
            case 3:
                middle_insertion();
                break;
            case 4:
                front_deletion();
                break;
            case 5:
                middle_deletion();
                break;
            case 6:
                end_deletion();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
