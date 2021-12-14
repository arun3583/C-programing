#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*link;
};
struct node *temp,*head=NULL,*newnode,*temp1;
void enqueue(int d)
{
newnode=(struct node*)malloc(sizeof(struct node));
newnode->link=NULL;
newnode->data=d;
newnode->link=head;
head=newnode;
}
void dequeue()
{
if(head==NULL)
{
printf("Queue is empty");
}
else if(head->link==NULL)
{
head=NULL;
}
else
{
temp=head;
while(temp->link!=NULL)
{
temp1=temp;
temp=temp->link;
}
temp1->link=NULL;
free(temp);
}
}
void display()
{
if(head==NULL)
{
printf("Queue is empty");
}
else
{
temp=head;
while(temp!=NULL)
{
printf("%d->",temp->data);
temp=temp->link;
}
}
}
void main()
{
int c,d;
while(1)
{
printf("\n1.enqueue\n2.dequeue\n3.display\n");
printf("enter your choice\n");
scanf("%d",&c);
switch(c)
{
case 1:printf("enter the element to enqueue");
	scanf("%d",&d);
	enqueue(d);
	break;
case 2:dequeue();
	break;
case 3:display();
	break;
default:printf("invalid entry");
	break;
}
}
}


