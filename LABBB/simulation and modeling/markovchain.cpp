//implement markov chain to predict weather
#include <iostream>
using namespace std;
#define n 3
//check for markov matrix
bool check(double arr[][n]){
   for (int i = 0; i <n; i++){
      double sum = 0;
      for (int j = 0; j < n; j++)
         sum = sum + arr[i][j];
      if (sum != 1)
         return false;
   }
   return true;
}
int main(){
   double arr[3][3] = { { 0, 0, 1 },
      { 0.5, 0, 0.5 },
      { 0.9, 0, 0.1 } };
   if (check(arr))
      cout << "its a markov matrix ";
   else
      cout << "its not a markov matrix ";
}

