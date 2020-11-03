#include <stdio.h>

void prova_passaggio(int *x, int *y)
{
    *x = 10;
    *y = 20;

}

int main()
{
    int a, b;

    prova_passaggio(&a, &b);
    printf("a=%d, b=%d", a, b);

    return 0;
}
