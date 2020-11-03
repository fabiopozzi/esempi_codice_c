#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define S1 "mondo"

int main()
{
    char s[] = "ciao,";

    int n = strlen(s) + 6;
    char *p = calloc(n, sizeof(char));

    strncat(p, s, strlen(s));
    strncat(p, S1, 5);

    printf("%s\n", p);

    return 0;

}

