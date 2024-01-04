#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double mean, sd, x, z, margin_of_error;
    printf("Enter the sample size: ");
    scanf("%d", &n);
    printf("Enter the sample mean: ");
    scanf("%lf", &mean);
    printf("Enter the population standard deviation: ");
    scanf("%lf", &sd);
    printf("Enter the confidence level (in percentage, e.g. 95 for 95%%): ");
    scanf("%lf", &x);
    z = (100 - x) / 2;
    z = z / 100;
    z = sqrt(z);
    margin_of_error = z * sd / sqrt(n);
    printf("The %.0lf%% confidence interval is [%.4lf, %.4lf]", x, mean - margin_of_error, mean + margin_of_error);
    return 0;
}

