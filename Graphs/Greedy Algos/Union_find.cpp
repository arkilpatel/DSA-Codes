#include<iostream>
#include<cstdlib>

using namespace std;

struct Edge
{
	int src,dest;
};

struct Graph
{
	int V,E;
	
	struct Edge *edge;
};

struct Graph *createGraph(int V, int E)
{
	struct Graph *G = new Graph;
	G->V = V;
	G->E = E;
	G->edge = new Edge[E];
	
	return G;
}

int find(int parent[], int i)
{
	if(parent[i] == -1)
		return i;
	return find(parent,parent[i]);
}

void Union(int parent[], int x, int y)
{
	int xset = find(parent,x);
	int yset = find(parent,y);
	
	parent[xset] = yset;
}

bool isCyclic(struct Graph *G)
{
	int parent[G->V];
	
	for(int i=0;i<G->V;i++)
		parent[i] = -1;
	
	for(int i=0; i<G->E; i++)
	{
		int x = find(parent,G->edge[i].src);
		int y = find(parent,G->edge[i].dest);
		
		if(x==y)
			return true;
			
		Union(parent,x,y);
	}
	return false;
}

int main()
{
	int E,V;
	cin>>V>>E;
	
	struct Graph *G = createGraph(V,E);
	
	for(int i=0;i<E;i++)
	{
		int u,v;
		cin>>u>>v;
		G->edge[i].src = u;
		G->edge[i].dest = v;
	}
	
	if(isCyclic(G))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	
	return 0;
}


