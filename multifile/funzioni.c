#include<stdio.h>
#include "funzioni.h"

int contatore;

static int maggiore (int v1, int v2)
{
    if (v1 > v2)
        return v1;
    else
        return v2;
}

int minore (int v1, int v2)
{
    if (v1 < v2)
        return v1;
    else
        return v2;
}
