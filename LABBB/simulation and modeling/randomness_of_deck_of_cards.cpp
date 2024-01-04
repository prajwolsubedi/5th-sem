#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

int main() {
    int i, randSuit, randRank, count[52] = {0};
    srand(time(NULL));

    for (i = 0; i < 10000; i++) {
        randSuit = rand() % 4;
        randRank = rand() % 13;
        count[randSuit * 13 + randRank]++;
    }

    for (i = 0; i < 52; i++) {
        printf("%s of %s: %d\n", ranks[i % 13], suits[i / 13], count[i]);
    }

    return 0;
}
