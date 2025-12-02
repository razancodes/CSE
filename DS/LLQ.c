#include <stdio.h>
#include <stdlib.h>

// to implement stack and queues in linked list:
typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* CreateNode(int val){
    Node* head= (Node*)malloc(sizeof(Node));
    head->data=val;
    head->next=NULL;
    return head;
}

void display(Node* head){
    Node* temp = head;
    while (temp!=NULL){
        printf("%d-> ", temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}


void push(Node* head, int data){
    Node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    printf("Pushed to the stack: %d\n",data);
    temp->next=CreateNode(data);
    return;
}

void pop(Node* head){
    if (head->next==NULL){
        printf("Empty list, cannot pop.\n");
        return;
    }
    Node* fast=head->next;
    Node* slow =head;

    while (fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    printf("Popped from the stack: %d\n",fast->data);
    slow->next=NULL;
    return;
}

int main(){
    Node* head= CreateNode(0);
    push(head,1);
    push(head,2);
    push(head,3);
    display(head);
    pop(head);
    display(head);
    pop(head);
    display(head);
    pop(head);
    pop(head);
    return 0;
}
