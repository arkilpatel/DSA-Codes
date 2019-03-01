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

	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}	
		
	return 0;
}
