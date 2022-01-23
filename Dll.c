#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* link;
struct node* prev;
};
struct node* temp,*temp1,*temp2,*newnode;
struct node* head=NULL;
void insertbeg (int d)
{
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=d;
newnode->prev=NULL;
newnode->link=head;
head=newnode;
}
void insertend (int d)
{
newnode=(struct node*)malloc(sizeof(struct node));
newnode->link=NULL;
newnode->data=d;
temp=head;
while(temp->link!=NULL)
{
temp=temp->link;
}
temp->link=newnode;
newnode->prev=temp;
}
void display()
{
if(head==NULL)
{
printf("linked list is empty");
}
else
{
temp=head;
while(temp!=NULL)
{
printf("%d""\n",temp->data);
temp=temp->link;
}
}
}
void insertpos(int d,int pos)
{
newnode=(struct node*)malloc(sizeof(struct node));
newnode->link=NULL;
if(pos==1)
{
insertbeg(d);
return;
}
temp=head;
for(int i=0;i<pos-1;i++)
{
temp1=temp;
temp=temp->link;
}
newnode->link=temp;
newnode->prev=temp1;
temp1->link=newnode;
temp->prev=newnode;
newnode->data=d;
}
void deletebeg()
{
temp=head;
head=head->link;
head->prev=NULL;
free(temp);
}
void deleteend()
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
void deletepos(int d)
{
int i;
if(d==1)
{
deletebeg();
}
else{
temp=head;
for(i=0;i<d-1;i++)
{
temp1=temp;
temp=temp->link;
}
temp1->link=temp->link;
temp2=temp->link;
temp2->prev=temp1;
free(temp);
}
}
void main()
{
int n,i,d,c,pos;
printf("enter the no: of nodes");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter data of %d node:",i+1);
scanf("%d",&d);
if(i==0)
{
insertbeg(d);
}
else
{
insertend(d);
}
}
while(1)
{
printf("\n1.insert at begining\n2.insert at end\n3.insert at specified position\n4.display linked list\n5.delete element at begining\n6.delete element at end\n7.delete specified element\n");
printf("\nenter your choice\n");
scanf("%d",&c);
switch(c)
{
case 1:printf("enter the data element");
	scanf("%d",&d);
	insertbeg(d);
	break;
case 2:printf("enter the data element");
	scanf("%d",&d);
	insertend(d);
	break;
case 3:printf("enter the data element");
	scanf("%d",&d);
	printf("enter the data position to be inserted");
	scanf("%d",&pos);
	insertpos(d,pos);
	break;
case 4:display();
	break;
case 5:deletebeg();
	break;
case 6:deleteend();
	break;
case 7:printf("enter the position to be deleted");
	scanf("%d",&d);
	deletepos(d);
	break;
}
}
}
