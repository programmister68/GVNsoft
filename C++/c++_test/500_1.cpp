#include <iostream>
#include "500_1.h"

using namespace std;

double answer (int a, int b, char k) //double stavim u vyvodimogo elementa, chto by on vyvodil ne tolko tseluju, no i drobnuju chasti chisla
{
    if (k != '+' and k != '-' and k != '/' and k != '*'){
        cout << "You enter the wrong data!";
    }
    if (k == '+'){
        return a + b;
    }
    if (k == '-'){
        return a - b;
    }
    if (k == '*'){
        return a * b;
    }
    if (k == '/'){
        return (double)a / b;
    }
    return 0;
}
