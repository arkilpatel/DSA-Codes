#include<iostream>
#include<vector>
#include<queue>

using namespace std;
/*
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	level[s] = 1;
	vis[s] = true;
	
	while(!q.empty() and flag==0)
	{
		int p = q.front();
		q.pop();
		
		if(level[p] >= l)
		{
			flag=1;
		}
		if(level[p]<l)
		{
			for(int i=0; i<v[p].size(); i++)
			{
				if(vis[v[p][i]] == false)
				{
					level[v[p][i]] = level[p] + 1;
					if(level[v[p][i]] == l)
					{
						n++;
					}
					q.push(v[p][i]);
					vis[v[p][i]] = true;
				}
			}
		}
	}
}
*/
int main()
{
	int ver;
	cin>>ver;
	
	vector<int> v[ver];
	int level[ver];
	bool vis[ver];
	
	int n=0,flag=0;
	
	for(int i=1;i<ver;i++)
	{
		int a,b;
		cin>>a>>b;
		
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);		
	}

	int l;
	cin>>l;
	
	queue<int> q;
	q.push(0);
	level[0] = 1;
	vis[0] = true;
	
	while(!q.empty() && flag==0)
	{
		int p = q.front();
		q.pop();
		
		if(level[p] >= l)
		{
			flag=1;
		}
		if(level[p]<l)
		{
			for(int i=0; i<v[p].size(); i++)
			{
				if(vis[v[p][i]] == false)
				{
					level[v[p][i]] = level[p] + 1;
					if(level[v[p][i]] == l)
					{
						n++;
					}
					q.push(v[p][i]);
					vis[v[p][i]] = true;
				}
			}
		}
	}
	
	cout<<n;
	
	return 0;
}
