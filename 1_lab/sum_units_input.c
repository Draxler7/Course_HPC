#include <stdio.h>

int main() {
    int Ns;
    int S = 0;
    int i;
    printf("Введите коичество единиц: ");
    scanf("%d", &Ns);
    printf("Ns = %d\n",Ns);

    for (i = 0; i < Ns ; i++ )
        S = S + 1;
    
    printf("s = %d\n", S);
}
