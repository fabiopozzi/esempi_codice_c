#include <stdio.h>

int main()
{
    int risposta = 42;
    int *p = &risposta;
    int a;

    a = *p;
    printf("il valore di risposta e' %d\n", a);

    *p = 404;
    printf("il valore di risposta e' ora %d\n", risposta);

    return 0;
}
