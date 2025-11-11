#include <stdio.h>
#define MAXSIZE 5
int q[MAXSIZE];
int l=0,r=0;
int count=0;
void enqueue(int x){
    if (count==MAXSIZE){
        printf("The Q is full. ");
        return;
    }
    q[r]=x;
    r=(r+1)%MAXSIZE;
    count++;
}
int dequeue(){
    if (count==0){
        printf("The Q is EMPTY. ");
        return -1;
    }
    int x = q[l];
    l=(l+1)%MAXSIZE;
    count--;
    return x;
}

void display(){
    int i=l;
    for (int c=0;c<count;c++){
        printf("%d ",q[i]);
        i=(i+1)%MAXSIZE;
    }
    printf("\n");
}
int main(){
    printf("\nEnqueing 1, 2 and 3\n");
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    printf("\nEnqueing 4\n");
    enqueue(4);
    display();
    enqueue(5);
    printf("\nEnqueing 5\n");
    dequeue();
    printf("\nDequeing 1\n");
    enqueue(6);
    printf("\nEnqueing 6\n");
    display();
    return 0;
}
