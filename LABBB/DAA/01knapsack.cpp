
#include <stdio.h>
int count =0;

int max(int a, int b) { return (a > b) ? a : b; }


int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	int K[n + 1][W + 1];

	
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
			{
			K[i][w] = 0;
			count += 2;	
			}
				
			else if (wt[i - 1] <= w)
			{
			K[i][w] = max(val[i - 1]
								+ K[i - 1][w - wt[i - 1]],
							K[i - 1][w]);
					count +=6;			
			}
				
			else
			{
			K[i][w] = K[i - 1][w];
			count++;	
			}
		count +=4;		
		}
		count += 4;
	}

	return K[n][W];
}


int main()
{
	int profit[] = { 60, 100, 120 };
	int weight[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(profit) / sizeof(profit[0]);
	printf("Maximum Profit Earned : %d\n", knapSack(W, weight, profit, n));
	printf("No. Of Step Required : %d", count);
	return 0;
}

