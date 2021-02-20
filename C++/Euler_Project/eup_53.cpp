#include <iostream>

using namespace std;

double factorial(int n)
{
 if (n==0) return 1;
 return n*factorial(n-1);
}

int main()
{
 int counter=0;
 for (int i=1; i<=100; i++)
  for (int k=1; k<=i; k++){
   double sochitanie=factorial(i)/(factorial(k)*factorial(i-k));
   if (sochitanie>1000000)
     counter++;
   }

cout << "Answer: " << counter;
return 0;
}
