#include <stdio.h>
#include <stdlib.h>
// to implement doubly linked list and operations in c:
/*
  a) Create a doubly linked list.
  b) Insert a new node to the left of the node.
  c) Delete the node based on a specific value
  d) Display the contents of the list
*/


typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

Node* CreateNode(int val){
    Node* head= (Node*)malloc(sizeof(Node));
    head->data=val;
    head->next=NULL;
    head->prev=NULL;
    return head;
}

Node* InsertLeft(Node* head,int val){
    Node* node = CreateNode(val);
    Node* temp= head;
    temp->prev=node;
    node->next=temp;
    return node;
} 

Node* InsertRight(Node* head, int val){
    Node* node = CreateNode(val);
    Node* temp= head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=node;
    node->prev=temp;
    return node;
}

Node* Delete(Node* head, int val){
    Node* temp=head;
    if (temp->data==val && head->next){
        return head->next;
    }
    while (temp!=NULL && temp->data!=val){
        temp=temp->next;
    }
    if (temp && temp->data==val){
        Node* prevtemp= temp->prev;
        prevtemp->next=temp->next;
        Node* nexttemp=temp->next;
        nexttemp->prev=prevtemp;
        temp->prev=NULL;
        temp->next==NULL;
        printf("deleted node with value: %d \n",val);
        return head;
    }else{
        printf("element not found.");
        return head;
    }
}

void Display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}



int main(){
    Node* head= CreateNode(1);
    InsertRight(head,2);
    InsertRight(head,3);
    InsertRight(head,4);
    Display(head);
    head=InsertLeft(head,0);
    Display(head);
    Delete(head, 3);
    Display(head);
    head=Delete(head,0);
    Display(head);
    return 0;
}
