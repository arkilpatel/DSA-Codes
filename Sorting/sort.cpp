#include<iostream>

using namespace std;

void insertion(int a[],int b[],int n)
{
	for(int i=0;i<n;i++)
	{
		int j=i;
		if(j!=0)
		{
			while(j>=0 && b[j]>a[i])
			{
				b[j+1] = b[j];
				j--;
			}
			j++;
		}
		b[j] = a[i];
	}
	
	for(int i=0;i<n;i++)
	{
		a[i] = b[i];
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n],b[n];
	cout<<"Enter the array: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	insertion(a,b,n);
	
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	
	cout<<endl;
	
	return 0;
}
