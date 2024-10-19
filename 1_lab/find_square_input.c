#include <stdio.h>
#include <math.h>
#include <time.h>

// Функция, которую мы хотим интегрировать
float f(float x) {
    // Вычисление значения функции f(x) = 0.05x^3 + 0.5x^2 - 5x + 150
    return (0.05 * pow(x,3)) + (0.5 * pow(x,2)) - 5 * x + 150;
}

int main(int argc, char **argv) {
    // Проверка количества аргументов командной строки
    if (argc != 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }

    // Чтение значения n из аргумента командной строки
    float n;
    if (sscanf(argv[1], "%f", &n) != 1) {
        printf("Invalid number of intervals\n");
        return 1;
    }

    // Определение границ интервала интегрирования
    float a = -20.0; // начало интервала
    float b = 20.0; // конец интервала

    // Вычисление ширины отрезка
    float h = (b - a) / n;

    // Инициализация суммы функций в начале и конце интервала
    float sum = 0.5 * (f(a) + f(b));

    // Запуск таймера для измерения времени выполнения
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // Вычисление суммы функций в середине отрезков
    for (int i = 1; i < n; i++) {
        float x = a + i * h;
        sum += f(x);
    }

    // Вычисление интеграла
    float integral = h * sum;

    // Остановка таймера и вычисление времени выполнения
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    double execution_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    // Вывод результатов: количество интервалов, значение интеграла и время выполнения
    printf("%10.0f, ",n);
    printf("%f, ", integral);
    printf("%5.10f\n",execution_time);

    return 0;
}