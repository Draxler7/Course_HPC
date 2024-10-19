#include <stdio.h>
#include <omp.h>

void main()
{
omp_set_num_threads(2);
printf("1\n");
#pragma omp parallel
    printf("2\n");

printf("3\n");
}