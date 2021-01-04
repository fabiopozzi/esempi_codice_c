#include <stdio.h>

int main() {
    int risposta = 42;
    int *p = &risposta;

    printf("Il valore di risposta è %d\n", *p);
    *p = 128;
    printf("%p\n", &risposta);
    printf("Il valore di risposta è %d\n", *p);
    printf("Il valore di risposta è %d\n", risposta);
    printf("l'indirizzo di risposta è %p\n", p);
    return 0;
}