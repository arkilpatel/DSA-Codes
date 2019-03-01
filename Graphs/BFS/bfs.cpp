#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> v[10];
int level[10];
bool vis[10];

void bfs(int s)
{
//	priority_queue<int,vector<int>,greater<int> > pq;

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
				q.push(v[p][i]);
				vis[v[p][i]] = true;
				cout<<"Now visited node: "<<v[p][i] + 1<<endl;
			}
		}
	}
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
		
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);		
	}
	
	int source;
	cout<<"Enter source: ";
	cin>>source;
	bfs(source-1);
	
	return 0;
}

























