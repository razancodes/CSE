#include <stdio.h>
#include <stdlib.h>

// to implement stack and queues in linke list:
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

void display(Node* front,Node* rear){
    if (front->next==rear){
        printf("Queue Empty.");
        return;
    }
    while(front!=rear){
        printf("%d -> ",front->data);
        front=front->next;
    }
    printf("%d \n",rear->data);
}

Node* queue(Node* rear, int data){
    rear->next=CreateNode(data);
    rear=rear->next;
    printf("Enqueued: %d \n",data);
    return rear;
}

Node* dequeue(Node* front,Node* rear){
    if (front==rear){
        printf("Queue Empty: \n");
        return front;
    }
    printf("Dequeued: %d \n",front->data);
    front=front->next;
    return front;
}

int main(){
    Node* front= CreateNode(0);
    Node* rear= front;
    rear=queue(rear,1);
    rear=queue(rear,2);
    rear=queue(rear,3);
    front=dequeue(front,rear);
    display(front,rear);
    front=dequeue(front,rear);
    front=dequeue(front,rear);
    display(front,rear);
    front=dequeue(front,rear);

    return 0;
}
