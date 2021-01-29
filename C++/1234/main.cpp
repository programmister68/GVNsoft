#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "lib.h"
using namespace std;

int main()
{

    int n=10;
    vector <int> h;
    for (int i=0; i<n; i++)
    {
        int k = rand()%100;
        push(h, k);
    }
    for (int i = 0; i<n; i++)
    {
        cout<<pop(h)<<" ";
    }
    return 0;
}
