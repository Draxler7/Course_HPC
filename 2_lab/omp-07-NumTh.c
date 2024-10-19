#include <stdio.h>
#include <omp.h>

int main()
{
    printf("ThNum\tNumTh\n");
#pragma omp parallel
    printf("%d\t%d\n", omp_get_thread_num(),omp_get_num_threads());
}