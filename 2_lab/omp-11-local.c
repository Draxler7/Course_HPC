#include <stdio.h>
#include <omp.h>

int main()
{
    int i, S = 10;
    printf("i\tThNum\tS\n");
#pragma omp parallel for reduction(+:S)
    for (i = 0; i < 20; i++)
    {
        S++;
        printf("%d\t%d\t%d\n", i, omp_get_thread_num(), S);
    }
    printf("%d\t%d\t%d\n", 20, omp_get_thread_num(), S);
}