#include<iostream>

using namespace std;

void addEdge(int adj[][6], int u,int v)
{
	adj[u-1][v-1] = 1;
}

bool isSink(int adj[][6], int i)
{
	for(int j=0;j<6;j++)
	{
		if(adj[i][j] == 1)
			return false;
		if(adj[j][i] == 0 && j!=i)
		{
			cout<<"Here"<<endl;
			return false;
		}
	}
	return true;
}

int main()
{
	int e;
	cin>>e;
	int adj[6][6]={0};
	for(int i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;
		addEdge(adj,u,v);
	//	adj[u-1][v-1] = adj[v-1][u-1] = 1;
	}

	int i=0,j=0;
	
	while(i<6 && j<6)
	{
		if(adj[i][j] == 0)
			j=j+1;
		else
			i=i+1;
	}
	
	if(i>=6 || isSink(adj,i) == false)
		cout<<"No"<<endl;
	if(isSink(adj,i) == true)
		cout<<"Yes"<<endl;
		
	return 0;
}
