#include<iostream>
#include<vector>
#include<deque>
#include<climits>

using namespace std;

struct node
{
	int to,weight;
};

void zeroOneBFS(int src, vector<node> adj[], int n)
{
	int dist[n];
	for(int i=0;i<n;i++)
		dist[i] = INT_MAX;
	
	deque<int> q;
	dist[src] = 0;
	q.push_back(src);
	
	while(!q.empty())
	{
		int v = q.front();
		q.pop_front();
		
		for(int i=0; i<adj[v].size(); i++)
		{
			if(dist[adj[v][i].to] > dist[v] + adj[v][i].weight)
			{
				dist[adj[v][i].to] = dist[v] + adj[v][i].weight;
				
				if(adj[v][i].weight == 0)
					q.push_front(adj[v][i].to);
				else
					q.push_back(adj[v][i].to);
			}
		}
	}
	
	for(int i=0; i<n; i++)
	{
		cout<<dist[i]<<" ";
	}		
	cout<<endl;
}

int main()
{
	int n,e;
	cin>>n>>e;
	
	vector<node> adj[n];	
	
	for(int i=0;i<e;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		
		adj[a-1].push_back({b-1, w});
		adj[b-1].push_back({a-1, w});
	}
	
	zeroOneBFS(0,adj,n);
	
	return 0;
}

















