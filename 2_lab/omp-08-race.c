#include <stdio.h>
#include <omp.h>

int main()
{
    int i, S = 0;
#pragma omp parallel for
    for (i = 0; i < 100000; i++)
        S++;
    printf("Sum = %d\n", S);
}