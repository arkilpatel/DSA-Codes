#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void printEulerianCircuit(vector<int> adj[])
{
	stack<int> curr_path;
	vector<int> circuit;
	
	curr_path.push(0);
	int curr_v = 0;
	
	while(!curr_path.empty())
	{
		if(adj[curr_v].size())
		{
			curr_path.push(curr_v);
			int next_v = adj[curr_v].back();
			
			adj[curr_v].pop_back();
			
			curr_v = next_v;
		}
		
		else
		{
			circuit.push_back(curr_v);
			
			curr_v = curr_path.top();
			curr_path.pop();
		}
	}
	
	for(int i = circuit.size()-1; i>=0; i--)
	{
		cout<<circuit[i]<<" ";
	}
}
