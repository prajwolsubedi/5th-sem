#include<stdio.h>
#include<conio.h>

int countstep=0;
int sequentialsearch(int a[],int n,int key){
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==key){
			countstep=countstep+5;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int key;
	int a[]={11,10,13,15,16,21,19,22,21,23};
	printf("Enter key to search: ");
	scanf("%d",&key);
	if(sequentialsearch(a,10,key))
	{
		printf("%d found \n",key);
	
	}
	else
	{
		printf("%d not found",key);
	}
		printf("%d steps taken",countstep);
}