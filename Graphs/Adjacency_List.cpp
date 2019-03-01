#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> adj[10];
	
	int e;
	cin>>e;
	for(int i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u-1].push_back(v);
		adj[v-1].push_back(u);
	}
	
	for(int i=0;i<10;i++)
	{
		cout<<"For node "<<i+1<<": ";
		for(int j=0;j<adj[i].size();j++)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
