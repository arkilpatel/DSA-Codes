#include<iostream>
#include<vector>

using namespace std;

int cnt = 0;

void dfs(int s,vector<int> adj[],bool vis[])
{
	cnt++;
	vis[s] = true;
	for(int i=0;i<adj[s].size();i++)
	{
		if(vis[adj[s][i]] == false)
			dfs(adj[s][i],adj,vis);
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	
	vector<int> adj[n];
	bool vis[n];
	
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	
	int x;
	cin>>x;
	dfs(x-1,adj,vis);
	
	cout<<n-cnt;
	
	return 0;
}















