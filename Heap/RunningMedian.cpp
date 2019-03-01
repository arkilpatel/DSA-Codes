#include<iostream>
#include<iomanip>
#include<queue>

using namespace std;

void Max_Heapify(float A[],int i,int Heap_Size)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int largest;
	float temp;
	
	if(l<=Heap_Size && A[l]>A[i])
		largest = l;
	else
		largest = i;
	if(r<=Heap_Size && A[r]>A[largest])
		largest = r;
	if(largest != i)
	{
		temp = A[largest];
		A[largest] = A[i];
		A[i] = temp;
		
		Max_Heapify(A,largest,Heap_Size);
	}
}

void Min_Heapify(float A[],int i,int Heap_Size)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int smallest;
	float temp;
	
	if(l<=Heap_Size && A[l]<A[i])
		smallest = l;
	else
		smallest = i;
	if(r<=Heap_Size && A[r]<A[smallest])
		smallest = r;
	if(smallest != i)
	{
		temp = A[smallest];
		A[smallest] = A[i];
		A[i] = temp;
		
		Min_Heapify(A,smallest,Heap_Size);
	}
}

void Insert_MinHeapify(float A[],int i)
{
	if(i == 0)
		return;
	int p = (i-1)/2;
	float temp;
	if(A[i]<A[p])
	{
		temp = A[i];
		A[i] = A[p];
		A[p] = temp;
		
		Insert_MinHeapify(A,p);
	}
}

void Insert_MaxHeapify(float A[],int i)
{
	if(i == 0)
		return;
	int p = (i-1)/2;
	float temp;
	if(A[i]>A[p])
	{
		temp = A[i];
		A[i] = A[p];
		A[p] = temp;
		
		Insert_MaxHeapify(A,p);
	}
}

int main()
{
	int n;
	cin>>n;

	float Max[n],Min[n];
	int max=0,min=0;
	
	for(int i=0;i<n;i++)
	{
		float temp,num;
		cin>>temp;
		if(max == 0)
		{
			Max[max] = temp;
			max++;
		}
		else
		{
			if(temp<Max[0])
			{
				Max[max] = temp;
				max++;
				Insert_MaxHeapify(Max,max-1);
			}
			else
			{
				Min[min] = temp;
				min++;
				Insert_MinHeapify(Min,min-1);
			}
		}
		if(max-min>1)
		{
			max--;
			Min[min] = Max[0];
			min++;
			Max[0] = Max[max];	
			
			Max_Heapify(Max,0,max-1);
			Insert_MinHeapify(Min,min-1);
		}
		else if(min-max>1)
		{
			min--;
			Max[max] = Min[0];
			max++;
			Min[0] = Min[min];	
			
			Min_Heapify(Min,0,min-1);
			Insert_MaxHeapify(Max,max-1);
		}/*
		for(int j=0;j<max;j++)
			cout<<Max[j]<<" ";
		cout<<endl;
		for(int j=0;j<min;j++)
			cout<<Min[j]<<" ";
		cout<<endl;*/
		
		float median;
		
		if((max+min)%2 == 1)
		{
			if(max>min)
			{
				median = Max[0];
				cout<<setprecision(2)<<median<<endl;
			}
			else
			{
				median = Min[0];
				cout<<setprecision(2)<<median<<endl;				
			}
		}
		else
		{
			median = (Max[0]+Min[0])/2;
			cout<<setprecision(3)<<median<<endl;
		}
	}
	
	return 0;	
}




















