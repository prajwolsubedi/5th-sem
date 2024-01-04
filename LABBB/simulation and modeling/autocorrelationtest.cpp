#include<stdio.h>
#include <cstdlib>
#include <iostream>
using namespace std;
 
#include<math.h>
int main(){
	int m=2,index=2,N=10;
	float a[10],calcz,row,sd,sum=0.00,ml;
	printf("Enter 10 random numbers : ");
	for(int i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	ml=((N-index)/m)-1;
	for(int k=0;k<ml;k++){
		sum=sum+a[index+k*m]*a[index+(k+1)*m];
	}
	sum=sum-0.25;
	row=sum/(ml+1);
	sd=sqrt(13*ml+7)/12*(ml+1);
	calcz=row/sd;
	printf("\n calculated z is: %f",calcz);
	printf("\n we are taking alpha =0.05 so z = 1.96");
	if(calcz>-1.96&&calcz<1.96)
	{
		printf("\n random numbers are independent");
	}
	else{
		printf("\n random numbers are dependent");
	}
	
	
	
}
