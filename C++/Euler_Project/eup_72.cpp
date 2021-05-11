#include <iostream>

using namespace std;

int euler(int n)
{
    int total = n;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    if (n > 1)
        result -= result / n;
    return result;
}

int main()
{
    long long counter=0;
    for (int k=2; k<=1000000; k++)
        counter += euler(k);
    cout << counter;
    return 0;
}
