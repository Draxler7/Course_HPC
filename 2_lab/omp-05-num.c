#include <stdio.h>
#include <omp.h>

void main()
{
printf("1\n");
#pragma omp parallel num_threads(4)
    printf("2\n");

printf("3\n");
}