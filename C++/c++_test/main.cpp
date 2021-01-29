#include <iostream>
#include "500_1.h"

using namespace std;

int main()
{
    int a, b;
    char k;
    cout << "Inter math expression: " << endl;
    cin >> a >> k >> b;
    cout << endl;
    cout << "Answer: " << a << k << b << "=" << answer (a, b, k) << endl; // V dannom sluchae my ispolzuem vyvod vnachale cherez peremennye, a potom vyvodim funktsiej kak otdelnoe chislo
    return 0;
}
