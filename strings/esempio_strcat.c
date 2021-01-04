#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20
int main()
{
    char stringa[N] = "ciao";
    int l = strlen(stringa);

    //strcat(stringa, "Mario");
    strncat(stringa, "Mariocaoncaosncsaoinconas!\n", N - l - 1);
    stringa[N - 1] = '\0';
    printf("%s", stringa);

    return (0);
}