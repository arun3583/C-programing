#include<stdio.h>
void main()
{
int arr[30],*r,i,p,l,d,s,f=0,temp,h,z;
printf("enter the array limit");
scanf("%d",&l);
printf("enter the elements");
for(i=0;i<l;i++) 
{
scanf("%d",&arr[i]);
}
printf("array elements");
for(i=0;i<l;i++) 
{
printf("%d\n",arr[i]);
}
r=arr;
printf("\n1.insert\n2.delete\n3.search\n");
scanf("%d",&z);
if(z==1)
{
printf("enter the element to be inserted");
scanf("%d",&d);
printf("enter the element position to be inserted");
scanf("%d",&p);
if(p>=l||p<=0)
{
printf("invalid position");
}
else
{
for(i=l;i>=p;i--)
{
arr[i]=arr[i-1];
}
arr[p-1]=d;
l++;
}
printf("\narray elements\n");
for(i=0;i<l;i++) 
{
printf("%d\n",arr[i]);
}}
else if(z==2)
{
printf("enter position to be deleted");
scanf("%d",&h);
for(i=h-1;i<l-1;i++)
{
arr[i]=arr[i+1];
}
printf("array elements\n");
for(i=0;i<l-1;i++) 
{
printf("%d\n",arr[i]);
}
}
else if(z==3)
{
printf("enter ELEMENT to be searched");
scanf("%d",&s);
for(i=0;i<l;i++)
{

if(s==*r)
{
f=1;
break;
}
r++;
}
if(f==1)
{
printf("element found at %d position",i+1);
}
else
{
printf("element not found");
}
}
}
