#include <stdio.h>
#include <locale.h>

int main(int argc, char **argv) { 
 
    printf("Кол-во аргументов: ");
    printf("%d\n", argc);
 
    for (int i = 0; i < argc; i++) {
        printf("%d",i);
        printf(" = ");
        printf(argv[i]);
        printf("\n");
    }
}