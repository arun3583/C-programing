#include<stdio.h>
#include<stdlib.h>
int s[]={0,0,0,0,0,0,0,0,0};
int p[]={0,0,0,0,0,0,0,0,0};
void reset()
{
int i;
for(i=0;i<=9;i++)
{
s[i]=0;
p[i]=0;
}
}
void input()
{
int size,i,x,v,size1;
reset();
printf("enter the size of first set(max=9)");
scanf("%d",&size);
printf("enter the elements");
for(i=0;i<size;i++)
{
printf("\nEnter element %d : ", i + 1);
scanf("%d",&x);
s[x-1]=1;
}
printf("enter the size of secound set(max=9)");
scanf("%d",&size1);
printf("enter the elements");
for(i=0;i<size1;i++)
{
printf("\nEnter element %d : ", i + 1);
scanf("%d",&v);
p[v-1]=1;
}
}
void display( int k[])
{
int i;
printf("elements of set\n{");
for(i=0;i<=9;i++)
{
if(k[i]==1){
printf("%d,",i+1);
}
}
printf("}\n");
}
void union1()
{
int uni[]={0,0,0,0,0,0,0,0,0},i;
for(i=0;i<9;i++)
{
if(s[i]==1||p[i]==1)
{
uni[i]=1;
}
}
display(uni);
}
void inter()
{
int inter[]={0,0,0,0,0,0,0,0,0},i;
for(i=0;i<9;i++)
{
if(s[i]==1&&p[i]==1)
{
inter[i]=1;
}
}
display(inter);
}
void diff()
{
int diff[]={0,0,0,0,0,0,0,0,0},i;
for(i=0;i<9;i++)
{
diff[i]=s[i];
if(s[i]==1&&p[i]==1)
{
diff[i]=0;
}
}
display(diff);
}
void main()
{
while(1)
{
int c;
printf("\n1.input\n2.union\n3.intersection\n4.difference\nenter your choice\n");
scanf("%d",&c);
switch(c)
 {
 case 1:input();
 	break;
 default:printf("enter valid entry");
 	break;
 	
 case 2:union1();
 	break;
 case 3:inter();
 	break;
 case 4:diff();
 	break;
 
 }
 }
 }
