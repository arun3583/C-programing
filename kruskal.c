#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int i,j,k,a,b,u,v,n,no_edges=0;
int min,mincost=0,G[9][9],parent[9];
int find(int);
int uni(int,int);
void main()
{
	printf("\nEnter the no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the cost adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&G[i][j]);
			if(G[i][j]==0)
				G[i][j]=INT_MAX;
		}
	}
	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(no_edges < n-1)
	{
		min = INT_MAX;
		for(i=1;i<=n;i++){
			for(j=1;j <= n;j++)
			{
				if(G[i][j] < min)
				{
					min=G[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("(%d,%d) =%d\n",a,b,min);
			mincost = mincost+min;
			no_edges++;
		}
		G[a][b]=G[b][a]=INT_MAX;
	}
	printf("\n\tMinimum cost = %d\n",mincost);
}
int find(int i)
{
	while(parent[i])
		i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
