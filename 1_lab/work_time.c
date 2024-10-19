#include <stdio.h>
#include <time.h>

int main() {
    int Ns = 10000000000;
    int S = 0;
    int i;
    float dT;
    clock_t t1, t2;
    t1 = clock();
    for (i = 0; i < Ns ; i++ )
        S = S + 1;
    t2 = clock();
    dT = (float) (t2-t1) / CLOCKS_PER_SEC;
    printf("s = %d,", S);
    printf("Ns = %d,",Ns);
    printf("dT = %5.10f\n",dT);
}