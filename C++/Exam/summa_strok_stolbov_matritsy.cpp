#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int a[N][M];
    int sc[M];
    int s, i, j;
    srand (time(NULL));

    for (i=0; i< M; i++) sc[i] = 0;
    for (i=0; i< N; i++)
    {
        s = 0;
        for (j=0; j< M; j++)
        {
            a[i][j] = rand() % 100;
            printf("%5d", a[i][j]);
            s += a[i][j];
            sc[j] += a[i][j];
        }
        printf(" |%d\n", s);
    }
    for (i=0; i< M; i++)
        printf("%5s", "--");
    printf("\n");
    for (i=0; i< M; i++)
        printf("%5d", sc[i]);
    printf("\n");
}
