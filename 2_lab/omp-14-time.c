#include <stdio.h>
#include <omp.h>
#include <time.h>

int main()
{
    long long i, S = 0;
    double T;
    printf("S = %lld\n", S);
    clock_t t;
    double tt;
    t = clock();
    tt = omp_get_wtime();

    // Запуск таймера для измерения времени выполнения
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

#pragma omp parallel for reduction(+:S)
    for (i = 0; i < 10000000000; i++)
        S++;
    t = clock() - t;
    tt = omp_get_wtime() - tt;
    T = (float)t / CLOCKS_PER_SEC;

    // Остановка таймера и вычисление времени выполнения
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    double execution_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    printf("S = %lld\n", S);
    printf("T_win = %2.10f c\tTick = %2.10f c\n", T, 1./ (float) CLOCKS_PER_SEC);
    printf("T_omp = %2.10f c\tTick = %2.10f c\n", tt, omp_get_wtick());
    printf("T_exec = %2.10f c\tTick = %2.10f c\n",execution_time, 1./1e9);
}

    