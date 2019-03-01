#include<iostream>
#include<vector>

using namespace std;

bool dfs(int s,int col,vector<int> adj[],bool vis[],int color[])
{
	vis[s] = true;
	if(col == 1)
		color[s] = 1;
	if(col == -1)
		color[s] = -1;
		
	for(int i=0;i<adj[s].size();i++)
	{
		if(color[adj[s][i]] == col)
			return false;
		if(vis[adj[s][i]] == false)
		{
			return dfs(adj[s][i],-col,adj,vis,color);
		}
	}
	
	return true;
}

int main()
{
	int t;
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
		int n,e;
		cin>>n>>e;
		
		vector<int> adj[n];
		bool vis[n] = {false};
		int color[n] = {0};
		
		for(int k=0;k<n;k++)
		{
			adj[k].clear();
		}
		
		for(int j=0;j<e;j++)
		{
			int a,b;
			cin>>a>>b;
		
			adj[a-1].push_back(b-1);
			adj[b-1].push_back(a-1);
		}
		
		if(dfs(0,1,adj,vis,color))
		{
			cout<<"Scenario #"<<i<<":"<<endl;
			cout<<"No suspicious bugs found!"<<endl;
		}
		else
		{
			cout<<"Scenario #"<<i<<":"<<endl;
			cout<<"Suspicious bugs found!"<<endl;
		}
			
	}
	
	return 0;
}
