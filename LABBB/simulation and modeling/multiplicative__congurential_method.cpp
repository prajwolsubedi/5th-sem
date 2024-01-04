#include <stdio.h>
#include<math.h>

int main() {
    int i,  a, c, m;
    float seed;
    float randNum;

    printf("Enter seed value: ");
    scanf("%d", &seed);
    printf("Enter a value: ");
    scanf("%d", &a);
    printf("Enter c value: ");
    scanf("%d", &c);
    printf("Enter m value: ");
    scanf("%d", &m);

    for (i = 0; i < 10; i++) {
        seed = (a * seed + c) % m;
        randNum = seed / (m - 1.0);
        printf("Random number %d: %f\n", i + 1, randNum);
    }

    return 0;
}

