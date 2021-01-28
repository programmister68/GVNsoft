#include <iostream>
#include "500_1.h"

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");
    int a, b;
    char k;
    cout << "Inter math expression: " << endl;
    cin >> a >> k >> b;
    cout << answer (a, b, k) << endl;
    return 0;
}
