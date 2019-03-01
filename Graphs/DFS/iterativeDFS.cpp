#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main()
{
	int n,e;
	cin>>n>>e;
	
	vector<int> adj[n];
	bool vis[n] = {false};
	int color[n] = {0};
	
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);		
	}
	
	int col=1,flag=0;
	
	stack<int> s;
	s.push(0);
	vis[0] = true;
	color[0] = col;
	
	while(!s.empty())
	{
		int p = s.top();
		s.pop();
		col=-col;
		for(int i=0;i<adj[p].size();i++)
		{
			if(color[adj[p][i]] == color[p])
				flag=1;
			
			if(vis[adj[p][i]] == false)
			{
				s.push(adj[p][i]);
				vis[adj[p][i]] = true;
				color[adj[p][i]] = col;
			}
		}
	}
	
	if(flag == 0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;	
	
	return 0;		
}
















