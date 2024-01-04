#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;



int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int modExp(int a, int b, int m) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int generatePrime(int n) {
    int p;
    do {
        p = rand() % n + 1;
    } while (!isPrime(p));
    return p;
}

int generatePublicKey(int phiN) {
    int e;
    do {
        e = rand() % phiN + 1;
    } while (gcd(e, phiN) != 1);
    return e;
}

int generatePrivateKey(int e, int phiN) {
    int d = 0;
    int k = 1;
    while (true) {
        d = (k * phiN + 1) / e;
        if (e * d == k * phiN + 1) {
            break;
        }
        k++;
    }
    return d;
}

string encrypt(string message, int e, int n) {
    string cipherText = "";
    for (int i = 0; i < message.length(); i++) {
        int m = (int)message[i];
        int c = modExp(m, e, n);

        // Convert the integer c to a string using stringstream
        stringstream ss;
        ss << c;
        cipherText += ss.str() + " ";
    }
    return cipherText;
}

string decrypt(string cipherText, int d, int n) {
    string message = "";
    string numStr = "";
    for (int i = 0; i < cipherText.length(); i++) {
        if (cipherText[i] == ' ') {
            int c = atoi(numStr.c_str());
            int m = modExp(c, d, n);
            char ch = (char)m;
            message += ch;
            numStr = "";
        } else {
            numStr += cipherText[i];
        }
    }
    return message;
}

int main() {
    srand(time(NULL));
    int p = generatePrime(100);
    int q = generatePrime(100);
    int n = p * q;
    int phiN = (p - 1) * (q - 1);
    int e = generatePublicKey(phiN);
    int d = generatePrivateKey(e, phiN);
    cout << "Public Key (e, n): " << e << ", " << n << endl;
    cout << "Private Key (d, n): " << d << ", " << n << endl;
    string message = "Hello, world!";
    string cipherText = encrypt(message, e, n);
    cout << "Encrypted Message: " << cipherText << endl;
    string decryptedMessage = decrypt(cipherText, d, n);
    cout << "Decrypted Message: " << decryptedMessage << endl;
    return 0;
}

