#include <stdio.h>
#define N 15
#include <stdlib.h>
#include <time.h>
int array(int a[]);

main()
{
    int arr_new[N], arr_max[N], i, j, id, sum_max, sum_new;
    srand(time(NULL));
    id = 0;
    sum_max = 0;
    for (i=1; i<=10; i++)
    {
        sum_new = array(arr_new);
        if (sum_new > sum_max)
        {
            sum_max = sum_new;
            for (j=0; j< N; j++) arr_max[j] = arr_new[j];
            id = i;
        }
    }
    printf("\n%d-й массив с максимальной суммой элементов:\n", id);
    for (i=0; i< N; i++) printf("%4d", arr_max[i]);
    printf(" - %d\n", sum_max);
}

int array(int a[])
{
    int k, sum;
    sum = 0;
    for (k=0; k< N; k++)
    {
        a[k] = rand()%50;
        sum += a[k];
        printf("%4d", a[k]);
    }
    printf(" - %d\n", sum);
    return sum;
}
