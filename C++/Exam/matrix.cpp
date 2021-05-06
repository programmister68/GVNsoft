#include <iostream>
#include <stdlib.h>
#include <time.h>

/*
3. Дана матрица A из N строк и M столбцов. Элементы матрицы А равны 0 и 1. Найти наибольший квадрат (подматрица С x C максимального размера) состоящую из одних единиц.
Для решения задачи ввод данных реализовать через чтение файла с именем “test.txt”, вывод результата выполнить в консоль.

Примечание: Необходимо немного код подредактировать, чтобы всё работало.
*/


using namespace std;

int main()
{
    srand(time(0));
    int n = 10;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = rand() % 2;
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            for (int length = min(n - i, n - j); length > 0 and length > mx; length --)
            {
                bool flag = true;
                for (int k = 0; k < length; k++)
                {
                    for (int d = 0; d < length; d++)
                    {
                        if (arr[i+k][j+d] == 0)
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag)
                    {
                        break;
                    }
                }
                if (flag and length > mx)
                {
                    mx = length;
                    break;
                }
            }
        }
    }
    cout << mx * mx;
    return 0;
}
