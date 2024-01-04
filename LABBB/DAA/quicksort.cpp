//quicksort
#include<iostream>
using namespace std;
int b[9];
int count=0;

int partition(int a[],int l,int r)
{
	int x=l;
	int y=r;
	int pivot=a[l];
	count=count+3;
	while(x<y)
	{
		while(a[x]<=pivot)
		{
			x++;
			count=count+3;
		
		}
		while(a[y]>pivot)
		{
			y--;
			count=count+3;
		}
		if(x<y)
		{
			int t=a[x];
			a[x]=a[y];
			a[y]=t;
			count=count+4;
		}
		
	}
	a[l]=a[y];
	a[y]=pivot;
	count=count+3;
	return y;
	
}

void quicksort(int a[], int l,int r)
{
	if(l<r)
	{
		int p=partition(a,l,r);
		quicksort(a,l,p-1);
		quicksort(a,p+1,r);
	}
}


int main()
{
//	int a[9] = {10,8,12,45,89,13,7,16,76};
	int a[9]={1,2,3,4,5,6,7,8,9};
	cout<< "before sorting : \n";
	cout<<endl;
	for(int i=0 ;i<9 ;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<endl;
	quicksort(a,0,8);
	cout<< "after sorting : \n";
	cout<<endl;
	for(int i=0 ;i<9 ;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<endl;
	cout<<"No of Steps required: "<<count;
	return 0;
}

