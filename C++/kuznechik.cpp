#include <iostream>
#include <stdlib.h>

using namespace std;


int main()
{
    int n = 0;
    cin >> n;
    n = n + 1;
    int arr[n];
    arr[0] = 1;
    arr[1] = 0;
    arr[2] = 1;
    for (int i = 3; i<n; i++)
    {
        arr[i] = arr[i-2] + arr[i-3];
        if (i == 7)
        {
            arr[i] = 0;
        }
    }
    cout << arr[n-1];
}