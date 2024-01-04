//lab 2: Implementation of MERGE SORT
#include<iostream>
using namespace std;
int b[10];
int count;
void merge(int a[],int ,int ,int );
void mergesort(int a[],int l,int r)
{
	if(l<r){
		int m=(l+r)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m+1,r);
	}
}
void merge(int a[],int l,int m,int r){
	int x=l;
	int y=m;
	int k=l;
	count=count+3;
	while(x<m&&y<=r){
		if(a[x]<a[y])
		
		{
			b[k]=a[x];
			k++;
			x++;
//		 suruma compare grxa ekstep ani value rakhxa arko feri k++ 2 vyo ani x++ 2 total:6
			count=count+6;
			
		}
		else{
			b[k]=a[y];
			k++;
			y++;
			count=count+6;
		}
		
	}
	while(x<m)
	{
		b[k]=a[x];
		k++;
		x++;
		count=count+6;
	}
	while(y<=r){
		b[k]=a[y];
		k++;
		y++;
		count=count+6;
	}
	for(int i=0;i<=r;i++)
	{
		a[i]=b[i];
		count=count+ 5;
	}
}
int main()
{
	//int a[]={10,8,12,45,89,13,7,16,76};
	int a[]={1,2,3,4,5,6,7,8,9};
	cout<<"before sorting: ";
	cout<<endl;
	for(int i=0;i<9;i++){
		cout<<a[i]<<"\t";
		
	}
	cout<<endl;
	mergesort(a,0,8);
	cout<<"after sorting: ";
	cout<<endl;
	for(int i=0;i<9;i++){
		cout<<a[i]<<"\t";
		
	}
	cout<<endl;
	cout<<"total step taken is: "<<count;
	
	
}
