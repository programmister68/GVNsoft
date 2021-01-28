#include <iostream>
#include "500_1.h"

using namespace std;

int answer (int a, int b, char k){

    if (k != '+' and k != '-' and k != '/' and k != '*'){
        cout << "You enter the wrong data!";
    }
    if (k == '+'){
        cout << a << k << b << " = " << a + b;
    }
    if (k == '-'){
        cout << a << k << b << " = " << a - b;
    }
    if (k == '*'){
        cout << a << k << b << " = " << a * b;
    }
    if (k == '/'){
        cout << a << k << b << " = " << (double)a / b;
    }
    return 0;
}
