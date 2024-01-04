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

// Compute the modular inverse of a modulo p
int modinv(int a, int p) {
    int b = p, u = 1, v = 0;
    while (b) {
        int t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= p;
    if (u < 0) u += p;
    return u;
}

// Generate a random prime number between min and max (inclusive)
int genprime(int min, int max) {
    bool isprime;
    int p;
    do {
        p = rand() % (max - min + 1) + min;
        isprime = true;
        for (int i = 2; i <= sqrt(p); i++) {
            if (p % i == 0) {
                isprime = false;
                break;
            }
        }
    } while (!isprime);
    return p;
}

int main() {
    // Generate a large prime number p
    srand(time(NULL));
    int p = genprime(100, 1000);

    // Generate a random integer g in the range [2, p-1]
    int g = rand() % (p - 2) + 2;

    // Generate a random private key a in the range [1, p-2]
    int a = rand() % (p - 2) + 1;

    // Compute the public key A = g^a mod p
    int A = modpow(g, a, p);

    cout << "Public key (p, g, A): (" << p << ", " << g << ", " << A << ")" << endl;

    // Generate a random message m in the range [1, p-2]
    int m = rand() % (p - 2) + 1;

    cout << "Message to be encrypted: " << m << endl;

    // Choose a random secret number k in the range [1, p-2]
    int k = rand() % (p - 2) + 1;

    // Compute the ciphertext (C1, C2) = (g^k mod p, A^k * m mod p)
    int C1 = modpow(g, k, p);
    int C2 = (modpow(A, k, p) * m) % p;

    cout << "Ciphertext (C1, C2): (" << C1 << ", " << C2 << ")" << endl;

    // Decrypt the ciphertext
    int m_prime = (C2 * modinv(modpow(C1, a, p), p)) % p;

    cout << "Decrypted message: " << m_prime << endl;

    return 0;
}

