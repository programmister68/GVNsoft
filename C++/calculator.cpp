#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");
    int a, b;
    char k;
    cout << "Inter math expression: " << endl;
    cin >> a >> k >> b;
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
