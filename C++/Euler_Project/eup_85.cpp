#include <iostream>

using namespace std;

int main()
{
    long long max, min, S;
    int  nx, ny;
    for (nx=0; nx<2000000; nx++)
    {
        for (ny=0; ny<2000000; ny++)
        {
            S = (nx*(nx+1)/2) * (ny*(ny+1)/2);
            if(S < 2000000)
            {
                max=2000000-S;
            }
            else
            {
                max = S-2000000;
                break;
            }
            if(max < min )
            {
                min = max;
                cout << "Answer: " << nx*ny;
            }

        }
    }
    return 0;
}
