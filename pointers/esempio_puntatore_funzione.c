#include<stdio.h>

typedef int (*fpT) (int, int);


int maggiore (int v1, int v2)
{
    if (v1 > v2)
        return v1;
    else
        return v2;
}

int main()
{
    int a = 10;
    int b = 20;


    fpT fp = maggiore;

    int c = fp(a, b);

    printf("il valore piu' grande tra %d e %d e' %d\n", a, b, c);
}