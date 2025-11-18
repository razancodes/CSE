#include <stdio.h>
#include <stdlib.h>
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

Node* Insert(Node* head, int val){
    Node* node=CreateNode(val);
    if (head==NULL){
        return node;
    }
    Node* temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=node;
    return head;
}

void display(Node* head){
    Node* temp = head;
    while (temp!=NULL){
        printf("%d-> ", temp->data);
        temp=temp->next;
    }
    printf("NULL ");
}
Node* Concat(Node* head1, Node* head2){
    if (head1==NULL){
        return head2;
    }if (head2==NULL){
        return head1;
    }
    Node* temp1= head1;
    while (temp1->next!=NULL){
        temp1=temp1->next;
    }
    temp1->next=head2;
    return head1;
}


Node* reverse(Node* head){
    Node* prev= NULL;
    Node* curr=head;
    Node* next=NULL;
    while (curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

Node* Middle(Node* head){
    if (head==NULL || head->next==NULL){
        return head;
    }

    Node* slow= head;
    Node* fast= head->next;

    while (fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* middle=slow->next;
    slow->next=NULL;
    return middle;

}


Node* Merge(Node* a, Node* b){
    Node *result=NULL;
    if (a==NULL) return b;
    if (b==NULL) return a;

    if (a->data<=b->data){
        result=a;
        result->next = Merge(a->next,b);
    }else{
        result=b;
        result->next=Merge(a,b->next);
    }
    return result;
}

Node* Mergesort(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* middle= Middle(head);
    Node* firsthalf = Mergesort(head);
    Node* secondHalf = Mergesort(middle);

    return Merge(firsthalf,secondHalf);

}

Node*  CreateList(){
    Node* head=CreateNode(1);
    Insert(head,2);
    Insert(head,3);
    Insert(head,4);
    Insert(head,4);
    display(head);
    return head;
}


int main(){
    Node* head=CreateNode(1);
    Insert(head,2);
    Insert(head,3);
    Insert(head,4);
    Insert(head,4);
    
    Node* head2= CreateNode(5);
    Insert(head2,6);
    Insert(head2,7);
    Insert(head2,8);
    Insert(head2,9);
    Node* head1=Concat(head,head2);
    printf("\n Concataned Lists: \n");
    display(head1);

    printf("\n Reversed List: \n");
    head=reverse(head);
    display(head);

    printf("\n Reversed List: \n");
    Node* headS = CreateNode(4);
    Insert(headS, 1);
    Insert(headS, 3);
    Insert(headS, 2);
    Insert(headS, 5);

    Node* nhead=Mergesort(headS);
    display(nhead);
    return 0;
}
