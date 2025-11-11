#include <stdio.h>
#include <stdlib.h> 
struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* insertAtFirst(struct node* head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct node* insertAtEnd(struct node* head, int data) {
    struct node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head; 
}

struct node* insertAtPos(struct node* head, int data, int pos) {
    if (pos == 1) {
        return insertAtFirst(head, data);
    }
    struct node* newNode = createNode(data);
    struct node* temp = head;
    int i;
    for (i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position %d. List is shorter.\n", pos);
        free(newNode); 
        return head;   
    }
    newNode->next = temp->next;
    temp->next = newNode;      

    return head; 
}

void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL; 
    printf("creation and display\n");
    display(head);
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    display(head);
    printf("\nInserting at First");
    head = insertAtFirst(head, 5);
    display(head); 
    printf("\nInserting at Position(P3)");
    head = insertAtPos(head, 15, 3);
    display(head); 
    printf("\nInserting at Position (P1)");
    head = insertAtPos(head, 1, 1);
    display(head); 
    printf("\nInserting at Invalid Position (P10)");
    head = insertAtPos(head, 99, 10);
    display(head); 
    struct node* temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
