#include <stdio.h>

int main() {
    int Ns = 1000000;
    int S = 0;
    int i;
    for (i = 0; i < Ns ; i++ )
        S = S + 1;
    printf("Ns = %d\n",Ns);
    printf("s = %d\n", S);
}