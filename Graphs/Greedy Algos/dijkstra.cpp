#include<iostream>
#include<queue>
#include<vector>
#include<climits>

#define INF INT_MAX

using namespace std;

struct edge
{
	int v,w;
};

struct node 
{
	int d,v;
};

auto comp = [](node &p1, node &p2)
{
	return p1.d>p2.d;
};

typedef priority_queue<node, vector<node>, decltype(comp) > minheap;

vector<vector<edge> > g;

int main()
{
	int t;
	cin>>t;
	for(int k=0;k<t;k++)
	{
		int n,m;
		cin>>n>>m;
		
		g.clear();
		g.resize(n);
		
		for(int i=0;i<m;i++)
		{	
			int u,v,w;
			cin>>u>>v>>w;
			u--;
			v--;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		
		int src,dest;
		cin>>src>>dest;
		
		int dist[n],vis[n];
		
		for(int i=0;i<n;i++)
		{
			dist[i] = INF;
			vis[i] = 0;
		}
		
		minheap pq(comp);
		pq.push({dist[src] = 0,src});
		
		while(!pq.empty())
		{
			auto p = pq.top();
			pq.pop();
			
			if(vis[p.v] == 1)
				continue;
			vis[p.v] = 1;
			if(p.v == dest)
				break;
			for(auto &e: g[p.v])
			{
				if(!vis[e.v] && dist[e.v] > p.d + e.w)
					pq.push({dist[e.v] = p.d+e.w,e.v});
			}
		}
		
		if(vis[dest] == 1)
			cout<<dist[dest]<<endl;
		else
			cout<<"-1"<<endl;
	}
	return 0;
}




























