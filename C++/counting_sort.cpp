#include <iostream>
#include <stdlib.h>

using namespace std;

void my_sort(int *arr, int n)
{
    int counter[100];
    for (int i = 0; i < 100; i++)
        *(counter+i) = 0;
    for (int i = 0; i < n; i++)
        *(counter+(*(arr+i))) += 1;
    int index = 0;
    for (int i = 0; i < 100; i++)
    {
        while (*(counter+i) > 0)
        {
            *(arr+index) = i;
            (*(counter+i)) --;
            index ++;
        }
    }
}


int main()
{
    int n = 100;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        *(arr+i) = rand()%100;
        cout << arr[i] << ' ';
    }
    cout << endl << endl;
    my_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << *(arr+i) << ' ';
    }
    cout << endl;
}