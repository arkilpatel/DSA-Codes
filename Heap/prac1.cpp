#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	long A[n];
	
	int minflag=1,maxflag=1;
	
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	
	for(int i=1;i<=n/2;i++)
	{
		int j=i-1;
		
		if(A[j]>A[(2*j)+1])
		{
			minflag=0;
		}
		else if(A[j]<A[(2*j)+1])
		{
			maxflag=0;
		}
		
		if((2*j)+2<n)
		{
			if(A[j]>A[(2*j)+2])
			{
				minflag=0;
			}
			else if(A[j]<A[(2*j)+2])
			{
				maxflag=0;
			}
		}
		
		if(minflag == 0 && maxflag == 0)
			break;		
	}
	
	if(minflag == 1)
		cout<<"MINHEAP";
	else if(maxflag == 1)
		cout<<"MAXHEAP";
	else
		cout<<"NONE";
		
	return 0;
}


















