#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    char a;
    setlocale (LC_ALL, "rus");
    cout << "Введите один из символов: @, $, &, *, ?, !" << endl;
    cin >> a;
    if (a == '@')
    {
        cout << "Это символ собака";
    }
    if (a == '&')
    {
        cout << "Это амперсанд";
    }
    if (a == '*')
    {
        cout << "Это звёздочка";
    }
    if (a == '!')
    {
        cout << "Это восклицательный знак";
    }
    if (a == '?')
    {
        cout << "Это вопросительный знак";
    }
    if (a == '$')
    {
        cout << "Это значок доллара";
    }
    return 0;
}
