#include <iostream>
#include <cmath>

using namespace std;

/*
Дано натуральное число n. Получить все такие натуральные q, что n делится на q^2 и не делится на q^3.
*/

int main()
{
    int n = 1, q = 1;
    cin >> n;
    for (int q = 1; q <= sqrt(n); q++) {
        if (n%(q*q) == 0 and n%(q*q*q) != 0) {
            cout << q << ' ';
        }
    }
    return 0;
}
