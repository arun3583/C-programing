#include<stdio.h>
int arr[100];
int top=-1,l,c;
void push(void);
void pop(void);
void display(void);
int main()
{
printf("enter stack limit");
scanf("%d",&l);
do
{
printf("enter your choice\n1.push\n2.pop\n3.display\n4.Exit\n");
scanf("%d",&c);
switch(c)
{
case 1:
	push();
	break;
case 2:
	pop();
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
void push()
{
int e;
if(top>l)
{
printf("the stack is overflow");
}
else
{
printf("enter the element to push");
scanf("%d",&e);
arr[top+1]=e;
top++;
}
}
void pop()
{
int p,d;
if(top<=-1)
{
printf("the stack is underflow");
}
else
{
printf("the popped element is%d\n",arr[top]);
top--;
}
}
void display()
{
int i;
if(top>=0)
{
printf("stack elements are");
for(i=top;i>=0;i--)
{
printf("%d\n",arr[i]);
}
}
else
{
printf("stack is empty");
}
}
