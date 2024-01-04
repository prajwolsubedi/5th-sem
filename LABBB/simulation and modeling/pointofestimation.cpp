#include <stdio.h>

int main() {
    int n,i;
    double mean, sample_mean, bias,sum=0,sample;
    printf("Enter the sample size: ");
    scanf("%d", &n);
    printf("Enter the population mean: ");
    scanf("%lf", &mean);
    for (i = 0; i < n; i++) {
        printf("Enter value for sample %d: ", i + 1);
        scanf("%lf", &sample);
        sum += sample;
    }

    sample_mean = sum / n;
    printf("The point of estimation is: %.4lf",sample_mean);
    bias = sample_mean - mean;
    printf("Point of estimation is: %.4lf\n", sample_mean);
    printf("Bias of estimation is: %.4lf\n", bias);
    return 0;
}

