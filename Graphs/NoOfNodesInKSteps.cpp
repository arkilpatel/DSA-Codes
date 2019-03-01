#include<iostream>

using namespace std;

void addEdge(int adj[][10], int u,int v)
{
	adj[u-1][v-1] = adj[v-1][u-1] = 1;
}

int main()
{
	int adj[10][10]={0};
	int e;
	cin>>e;
	for(int i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;
		addEdge(adj,u,v);
	//	adj[u-1][v-1] = adj[v-1][u-1] = 1;
	}
	
	int k,n,num=0;
	cout<<"Enter k: ";
	cin>>k;
	cout<<"Enter n: ";
	cin>>n;
	
	int mul[10][10];
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			mul[i][j] = adj[i][j];
		}
	}
	
	for(int z=0;z<k-1;z++)
	{
		int temp[10][10];
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				temp[i][j] = 0;
				for(int k=0;k<10;k++)
				{
					temp[i][j] = temp[i][j] + mul[i][k]*adj[k][j];
				}
			}
		}
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				mul[i][j] = temp[i][j];
			}
		}
	}
	
	for(int k=0;k<10;k++)
	{
		if(mul[n-1][k]>0)
			num++;
	}
	
	cout<<"Number is: "<<num<<endl;
	
	return 0;
}
