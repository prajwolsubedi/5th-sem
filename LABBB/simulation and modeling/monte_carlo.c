#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SEED time(NULL)

int main() {

 srand( SEED );
 int i, count, n;
 double x,y,z,pi;

 printf("n = ");
 scanf("%d", &n);

 count = 0;

 for(i = 0; i < n; ++i) {

     x = (double)rand() / RAND_MAX;
     printf("x=%d\n",x);

     y = (double)rand() / RAND_MAX;
     printf("y=%d\n",y);

     z = x * x + y * y;
     printf("z=%d\n",z);              

     if( z <= 1 ) 
	 	count++;
 }

 pi = (double) count / n * 4;
 
 printf("Approximate PI = %g", pi);

 return(0);
}
