#include <iostream>

using namespace std;

int main()
{
    unsigned long long red = 6, blue = 15;
    for (unsigned long long i=0; red+blue<=1000000000000; i)
    {
        red = 2 * blue + red - 1; //red  [n] = 2 * blue [n-1] + red [n-1] - 1
        blue = 2 * red + blue; //blue [n] = blue [n-1] + 2 * red[n]
    }
    cout << "Answer: " << blue;
    return 0;
}
