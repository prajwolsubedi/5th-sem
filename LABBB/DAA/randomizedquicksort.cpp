//quicksort
#include<iostream>
#include<math.h>
using namespace std;
int partition(int a[],int ,int );
int b[9];
int count=0;
int randpartition(int a[],int l,int r)
{
	int k=l+rand()%(r-l);//remainder tw kaile mathi hudenw
	int t=a[l];
	a[l]=a[k];
	a[k]=t;
	return (partition(a,l,r));
	count=count+4;
}

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

void randquicksort(int a[], int l,int r)
{
	if(l<r)
	{
		int p=randpartition(a,l,r);
		randquicksort(a,l,p-1);
		randquicksort(a,p+1,r);
	}
}


int main()
{
int a[9] = {72,29,62,45,89,43,7,16,76};
	//int a[9]={10,11,12,13,14,15,16,17,18};
	cout<< "before sorting : \n";
	cout<<endl;
	for(int i=0 ;i<9 ;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<endl;
	randquicksort(a,0,8);
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

