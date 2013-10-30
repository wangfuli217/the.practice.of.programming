#include <stdio.h>
#include <string.h>
#include "qsort.h"


void print_v(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d", v[i]);
        if (i < n - 1)
            printf(" -> ");
    }
    printf("\n");
}


void test_quicksort_loop(int v[], int n)
{
    int tmp[n];
    memcpy(tmp, v, sizeof(int) * n);
    quicksort(tmp, n);
    print_v(tmp, n);
}


void test_quicksort(int v[], int n)
{
    int tmp[n];
    memcpy(tmp, v, sizeof(int) * n);
    quicksort(tmp, n);
    print_v(tmp, n);
}

int main(void)
{
    int i;
    int v[] = {5, 3, 4, 8, 2, 1, 0, 7, 9};

    print_v(v, 9);
    test_quicksort(v, 9);
    test_quicksort_loop(v, 9);

    return 0;
}
