#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[10];
bool vis[10] = {false};
int color[10] = {0};

bool dfs(int s,int col)
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
			return dfs(adj[s][i],-col);
		}
	}
	
	return true;
}

int main()
{
	int e;
	cout<<"Enter no of edges: ";
	cin>>e;
	
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);		
	}
	
	
	if(dfs(0,1))
		cout<<"YES";
	else
		cout<<"NO";
	cout<<endl;
	
	return 0;		
}
















