#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Compute a^b mod p efficiently
int modpow(int a, int b, int p) {
    int result = 1;
    a %= p;
    while (b > 0) {
        if (b & 1) {
            result = (result * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    return result;
}

int main() {
    // Generate a large prime number p and a generator g
    srand(time(NULL));
    int p = 23;
    int g = 5;

    cout << "Public parameters (p, g): (" << p << ", " << g << ")" << endl;

    // Alice chooses a random secret number a
    int a = rand() % (p - 1) + 1;

    // Bob chooses a random secret number b
    int b = rand() % (p - 1) + 1;

    // Alice computes A = g^a mod p
    int A = modpow(g, a, p);

    // Bob computes B = g^b mod p
    int B = modpow(g, b, p);

    // Alice and Bob exchange A and B

    // Alice computes the shared secret s = B^a mod p
    int s_A = modpow(B, a, p);

    // Bob computes the shared secret s = A^b mod p
    int s_B = modpow(A, b, p);

    cout << "Alice's shared secret: " << s_A << endl;
    cout << "Bob's shared secret: " << s_B << endl;

    return 0;
}

