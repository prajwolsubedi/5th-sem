//generate 50 random numbers using mixed congurential method  x0=11,m=100,a=5,c=13 
#include <bits/stdc++.h>
using namespace std;
 
// Function to generate random numbers
void linearCongruentialMethod(
    int Xo, int m, int a, int c,vector<int>& randomNums,int noOfRandomNums)
{
 
    // Initialize the seed state
    randomNums[0] = Xo;
 
    // Traverse to generate required
    // numbers of random numbers
    for (int i = 1; i < noOfRandomNums; i++) {
        // Follow the linear congruential method
        randomNums[i] = ((randomNums[i - 1] * a) + c) % m;
    }
}
 
// Driver Code
int main()
{
    int Xo = 1; // Seed value
    int m = 10; // Modulus parameter
    int a = 3; // Multiplier term
    int c = 4; // Increment term
 
    // Number of Random numbers
    // to be generated
    int noOfRandomNums = 20;
 
    // To store random numbers
    vector<int> randomNums(
        noOfRandomNums);
 
    // Function Call
    linearCongruentialMethod(
        Xo, m, a, c,
        randomNums, noOfRandomNums);
 
    // Print the generated random numbers
    for (int i = 0; i < noOfRandomNums; i++) {
        cout << randomNums[i] << " ";
    }
 
    return 0;
}