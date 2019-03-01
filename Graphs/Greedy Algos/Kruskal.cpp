#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct edge
{
	int u,v,w;
};

auto comp = [](edge &e1, edge &e2)
{
	return e1.w < e2.w;
};

struct DisjointSet
{
	vector<int> parent,size;
	
	DisjointSet(int n)
	{
		parent.resize(n);
		size.resize(n);
		
		for(int i=0;i<n;i++)
		{
			parent[i] = i;
			size[i] = 1;
		}
	}
	
	int find(int u)
	{
		return (u == parent[u]) ? u : parent[u] = find(parent[u]);
	}
	
	void connect(int u, int v)
	{
		u = find(u);
		v = find(v);	
		if(u == v)
			return;
		if(size[u] < size[v])
			swap(u,v);
		parent[v] = u;
		size[u] = size[u] + size[v];
	}
	
	bool connected(int u,int v)
	{
		return find(u) == find(v);
	}
};

vector<edge> E;

int main()
{
	int t;
	cin>>t;
	for(int k=0;k<t;k++)
	{
		int n,m;
		cin>>n>>m;
		
		E.clear();
		E.resize(n);
		
		for(int i=0;i<m;i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
			u--;
			v--;
			E.push_back({u,v,w});
		}
		
		sort(E.begin(),E.end(),comp);
		
		DisjointSet dsu(n);
		int mst = 0;		
		
		for(auto &e: E)
		{
			if(!dsu.connected(e.u,e.v))
			{
				dsu.connect(e.u,e.v);
				mst = mst+e.w;
			}
		}
		cout<<mst<<endl;
	}
	return 0;
}






















