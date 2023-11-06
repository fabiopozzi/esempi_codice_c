#include<stdlib.h>
#include<string.h>
#include<stdio.h>

char* my_strdup(char s[])
{
    char *p;
    size_t dimensione = strlen(s);

    p = (char *)malloc(dimensione + 1); // spazio per terminatore
    if (p != NULL) {
        strcpy(p, s);
    }
    // copio terminatore
    p[dimensione] = '\0';
    return p;
}

int main()
{
    char s[] = "ciao come va?";

    char *p;
    p = my_strdup(s);

    printf("%s\n", p);
    return 0;
}
