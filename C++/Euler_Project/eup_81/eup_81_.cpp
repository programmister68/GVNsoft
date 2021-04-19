#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    int a, summa=0;
    ifstream file { "matrix.txt" };
    if (!file.is_open()) return -1;
    int array[80][80] {};
    for (int i{}; i != 80; ++i)
    {
        for (int j{}; j != 80; ++j)
        {
            file >> array[i][j];
        }
    }
    for (int k=0; k<80; k++)
    {
        summa+=array[0][k];
        array[0][k]=summa;
    }
    summa=0;
    for (int k=0; k<80; k++)
    {
        summa+=array[k][0];
        array[k][0]=summa;
    }


    for (int k=1; k<80; k++)
    {
        for (int t=1; t<80; t++)
        {
            if (array[t-1][k]>array[t][k-1]) array[t][k]+=array[t][k-1];
            else array[t][k]+=array[t-1][k];
        }
    }

    cout << "Answer: " << array[79][79] << endl;

    return 0;
}
