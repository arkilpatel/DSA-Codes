#include<iostream>
#include<vector>
#include<queue>

using namespace std;
/*
int bfs(int s, int n, vector<int> v[], int level[], bool vis[])
{
	queue<int> q;
	q.push(s);
	level[s] = 0;
	vis[s] = true;
	
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		
		for(int i=0; i<v[p].size(); i++)
		{
			if(vis[v[p][i]] == false)
			{
				level[v[p][i]] = level[p] + 1;
				if(v[p][i] == n-1)
				{
					return level[v[p][i]];
				}
				q.push(v[p][i]);
				vis[v[p][i]] = true;
			}
		}
		
	}
}
*/
int main()
{
	int t;
	cin>>t;
	
	for(int j=0;j<t;j++)
	{
		int n,m;
		cin>>n>>m;
		
		vector<int> v[n];
		int level[n]={0};
		bool vis[n]={false};
		
		for(int k=0;k<n;k++)
		{
			v[k].clear();
		}
		
		for(int i=1;i<=m;i++)
		{
		
			int a,b;
			cin>>a>>b;
		
			v[a-1].push_back(b-1);
			v[b-1].push_back(a-1);		
		}
	
//		cout<<bfs(0,n,v,level,vis)<<endl;

		queue<int> q;
		q.push(0);
		level[0] = 0;
		vis[0] = true;
		
		while(!q.empty())
		{
			int p = q.front();
			q.pop();
			
			for(int i=0; i<v[p].size(); i++)
			{
				if(vis[v[p][i]] == false)
				{
					level[v[p][i]] = level[p] + 1;
					if(v[p][i] == n-1)
					{
						cout<<level[v[p][i]]<<endl;
					}
					q.push(v[p][i]);
					vis[v[p][i]] = true;
				}
			}
		
		}
	}
	
	return 0;
}
