#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int arr[SIZE],front=-1,rear=-1;

void insert(int d) {
    if(front==rear+1 || (front==0 && rear == SIZE-1)) {
        printf("full");
        return;
    }
    if(front == -1)
    front = 0;  
    rear = (rear+1)%SIZE;
    arr[rear] = d;
    printf("inserted");
}

void delete() {
    if(front == -1) {
        printf("empty");
        return;
    }
    if(front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front+1)%SIZE;
    }
}

void print() {
    if(front == -1) {
        printf("empty");
        return;
    }
    int i;
    for (i = front; i != rear; i = (i + 1)%SIZE) {
      printf("%d ", arr[i]);
    }
    printf(" %d",arr[i]);
}

void main() {
    int ch,num;
    while(1) {
        printf("\n\n1. insert\n2. delete\n3. print\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: printf("Enter data: ");
                    scanf("%d",&num);
                    insert(num);
                    break;
            case 2: delete();
                    break;
            case 3: print();
                    break;
            default: printf("Invalid choice number!");
        }
    }
}
