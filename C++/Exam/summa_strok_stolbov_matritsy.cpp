#include <stdio.h>
#include <cstdlib>
#define M 10
#define N 5
#include <time.h>
main()
{
    int a[N][M];
    int sc[M];
    int s, i, j;

    for (i=0; i< M; i++) sc[i] = 0;
    for (i=0; i< N; i++)
    {
        s = 0;
        for (j=0; j< M; j++)
        {
            a[i][j] = rand() % 10;
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
