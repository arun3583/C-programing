#include<stdio.h>
int arr[100];
int rear=0,front=0,l,c;
void enqueue(void);
void dequeue(void);
void display(void);
int main()
{
printf("enter queue limit");
scanf("%d",&l);
do
{
printf("enter your choice\n1.enqueue\n2.dequeue\n3.display\n4.Exit\n");
scanf("%d",&c);
switch(c)
{
case 1:
	enqueue();
	break;
case 2:
	dequeue();
	break;
case 3:
	display();
	break;
default:
	printf("enter a valid choice");
	break;
}
}
while(c!=4);
return 0;
}
void enqueue()
{
int e;
if(rear>l)
{
printf("the queue is overflow");
}
else
{
printf("enter the element to enqueue");
scanf("%d",&e);
arr[rear]=e;
rear++;
}
}
void dequeue()
{
int p,d;
if(rear==front)
{
printf("the queue is empty");
}
else
{
printf("the dequeued element is%d\n",arr[front]);
front++;
}
}
void display()
{
int i;
if(rear!=front)
{
printf("queue elements are");
for(i=front;i<rear;i++)
{
printf("%d\n",arr[i]);
}
}
else
{
printf("queue is empty");
}
}
