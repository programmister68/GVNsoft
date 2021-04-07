#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int a, b;
    int arr[5][5] = {
        {131,673,234,103,18},
        {201,96,342,965,150},
        {630,803,746,422,111},
        {537,699,497,121,956},
        {805,732,524,37,331},
    };


    int sum=0;
    for (int k=0; k<5; k++) {
        sum+=arr[0][k];
        arr[0][k]=sum;
    }
    sum=0;
    for (int k=0; k<5; k++) {
        sum+=arr[k][0];
        arr[k][0]=sum;
    }


    for (int k=1; k<5; k++) {
        for (int t=1; t<5; t++) {
            if (arr[t-1][k]>arr[t][k-1]) arr[t][k]+=arr[t][k-1];
            else arr[t][k]+=arr[t-1][k];
        }
    }


     for (int t=0; t<5; t++) {
        cout << endl;
        for (int k=0; k<5; k++) {
            printf  ("%7d", arr[t][k]);
        }
    }
    return 0;
}
