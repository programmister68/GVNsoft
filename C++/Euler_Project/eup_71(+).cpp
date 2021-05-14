#include <iostream>

using namespace std;

int main()
{
    int n=5, d=12; //n=3 + 2 ; d = 7 + 5
    for (int i=1; i>0; i)
    {
        d=d+7;

        if (d>1000000)
        {
            break;
        }
        n=n+3;
    }
    cout << "Answer: " << n ;
    return 0;
}
