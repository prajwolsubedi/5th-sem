//generate 50 random numbers using multilicative congurential method a=5 , x0=13,m=1000,m=5
#include <bits/stdc++.h>
using namespace std;
 
// Function to generate random numbers
void multiplicativeCongruentialMethod(
    int Xo, int m, int a,
    vector<int>& randomNums,
    int noOfRandomNums)
{
 
    // Initialize the seed state
    randomNums[0] = Xo;
 
    // Traverse to generate required
    // numbers of random numbers
    for (int i = 1; i < noOfRandomNums; i++) {
 
        // Follow the multiplicative
        // congruential method
        randomNums[i]
            = (randomNums[i - 1] * a) % m;
    }
}
 
// Driver Code
int main()
{
    int Xo = 3; // seed value
    int m = 15; // modulus parameter
    int a = 7; // multiplier term
 
    // Number of Random numbers
    // to be generated
    int noOfRandomNums = 10;
 
    // To store random numbers
    vector<int> randomNums(noOfRandomNums);
 
    // Function Call
    multiplicativeCongruentialMethod(
        Xo, m, a, randomNums,
        noOfRandomNums);
 
    // Print the generated random numbers
    for (int i = 0; i < noOfRandomNums; i++) {
        cout << randomNums[i] << " ";
    }
    return 0;
}