#include "qsort.h"

void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


void quicksort(int v[], int n)
{
    int i, last;

    if (1 >= n)
        return;

    swap(v, 0, rand() % n);
    last = 0;
    for (i = 1; i < n; i++)
    {
        if (v[i] < v[0])
            swap(v, ++last, i);
    }

    swap(v, 0, last);
    quicksort(v, last);
    quicksort(v + last + 1, n - last - 1);
}


int qstack_push(qitem *stack, int top, int start, int end)
{
    stack[top].start = start;
    stack[top].end = end;
    return ++top;
}


void quicksort_loop(int v[], int n)
{
    qitem q_stack[n*2];
    int top = 0;
    int i;

    // stack init
    top = qstack_push(q_stack, top, 0, n);

    while (0 < top)
    {
        int start;
        int end;
        int last;
        int len;

        top--;
        start = q_stack[top].start;
        end = q_stack[top].end;
        len = end - start;
        if (1 >= len)
            continue;

        swap(v, start, start + rand() % len);
        last = start;
        for (i = start + 1; i < end; i++)
        {
            if (v[i] < v[start])
                swap(v, ++last, i);
        }
        swap(v, start, last);
        top = qstack_push(q_stack, top, last + 1, end);
        top = qstack_push(q_stack, top, start, last);
    }
}
