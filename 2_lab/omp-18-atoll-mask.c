#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    long long N, i, S = 0;
    double tt;
    N = atoll(argv[1]);
    tt = omp_get_wtime();

    // Запуск таймера для измерения времени выполнения
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

#pragma omp parallel for reduction(+:S)
    for (i = 0; i < N; i++)
        S++;

    tt = omp_get_wtime() - tt;

    // Остановка таймера и вычисление времени выполнения
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    double execution_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    printf("%lld,\t%lld,\t", N, S);
    printf("%2.10f,\t%2.10f\n", tt, execution_time);
}

    