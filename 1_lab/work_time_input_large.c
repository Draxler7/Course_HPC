#include <stdio.h>
#include <time.h>

void main() {
    unsigned long Ns;
    unsigned long S = 0;
    unsigned long i;
    float dT;
    clock_t t1, t2;
    t1 = clock();
    printf("Введите количество единиц: ");
    scanf("%lu", &Ns);
    printf(&Ns);
    for (i = 0; i < Ns ; i++ )
    {
        S = S + i;
    }
    t2 = clock();
    dT = (float) (t2-t1) / CLOCKS_PER_SEC;
    printf("s = %lu\n", S);
    printf("dT = %5.10f\n",dT);
}