#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
    int n = 5;
    int arr[n];
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout<<get_min(arr,n);
    return 0;
}
