#include<iostream>

using namespace std;

int main()
{
	int n,k;
	cin>>k;
	cin>>n;
	
	long A[k][n];
	
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>A[i][j];
		}
	}
	
	int point[k]={0},count=0;
	
	while(count<n*k)
	{
		int j;
		long min;
		min = 1000000000;
		for(int i=0;i<k;i++)
		{
			if(point[i]<n)
			if(A[i][point[i]]<min)
			{
				j=i;
				min = A[i][point[i]];
			}
		}
		point[j]++;
		cout<<min<<" ";
		count++;
	}
	
	return 0;
}
