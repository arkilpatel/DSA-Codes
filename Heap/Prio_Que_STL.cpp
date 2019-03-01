#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	priority_queue <int,vector<int>,greater<int> > minheap;
	priority_queue <int> maxheap;

	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		
		if(maxheap.empty())
		{
			maxheap.push(temp);
		}
		else
		{
			if(temp<maxheap.top())
			{
				maxheap.push(temp);
			}
			else
			{
				minheap.push(temp);
			}
		}
		if(maxheap.size()-minheap.size()>1)
		{
			minheap.push(maxheap.top());
			maxheap.pop();
		}
		else if(minheap.size()-maxheap.size()>1)
		{
			maxheap.push(minheap.top());
			minheap.pop();
		}

		int median;
		
		if((maxheap.size()+minheap.size())%2 == 1)
		{
			if(maxheap.size()>minheap.size())
			{
				median = maxheap.top();
				cout<<median<<endl;
			}
			else
			{
				median = minheap.top();
				cout<<median<<endl;				
			}
		}
		else
		{
			median = (maxheap.top()+minheap.top())/2;
			cout<<median<<endl;
		}
	}
	
	return 0;	
}




















