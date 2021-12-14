#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
struct Node *head = NULL,*temp,*temp2, *new_node;
void pop() {
    printf("\n");
    if( head==NULL) {
        printf("Stack is empty!");
    } else {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void push(int d) {
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = d;
    new_node->next = head;
    head = new_node;
}
void print() {
    temp = head;
    printf("\n");
    if(head==NULL) {
        printf("Empty Stack!");
    } else {
        while (temp != NULL) {
		printf(" %d ", temp->data);
		temp = temp->next;
	    }
    }
}


void main() {
    int ch,num;
    while(1) {
        printf("\n\n1. Push\n2. Pop\n3. Display stack\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: printf("Enter data: ");
                    scanf("%d",&num);
                    push(num);
                    break;
            case 2: pop();
                    break;
            case 3: print();
                    break;
default: printf("Invalid choice number!");
        }
    }
}
