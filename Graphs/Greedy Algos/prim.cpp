#include<iostream>
#include<vector>
#include<queue>
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
	return p1.d > p2.d;
};

typedef priority_queue< node, vector<node>, decltype(comp) > minheap;

vector<vector<edge> > g;

int main()
{
	int t;
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
		
		int w[n],parent[n],vis[n];
		
		for(int i=0;i<n;i++)
		{
			w[i] = INF;
			parent[i]=-1;
			vis[i]=0;
		}
		
		minheap pq(comp);
		pq.push({w[0] = 0,0});
		int mst = 0;
		
		while(!pq.empty())
		{
			auto p = pq.top();
			pq.pop();
			
			if(vis[p.v])
				continue;
			vis[p.v] = 1;
			mst = mst+p.d;
			
			for(auto &e: g[p.v])
			{
				if(!vis[e.v] && w[e.v] > e.w)
				{
					parent[e.v] = p.v;
					pq.push({w[e.v] = e.w, e.v});
				}
			}
		}
		cout<<mst<<endl;		
	}
	return 0;
}























