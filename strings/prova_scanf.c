#include <stdio.h>
#include <string.h>

#define N 5
int main()
{
    char s[N];

    char format[4];
    // %% permette di inserire un '%' nella stringa
    // %d permette di inserire il valore numerico
    // quindi "%%%ds" permette di generare "%4s" come risultato
    sprintf(format, "%%%ds", N - 1);
    scanf(format, s);

    for (int i = 0; i < 5; i++) {
        if (s[i] == '\0') {
            printf("-terminatore-");
            break;
        } else {
            printf("-%c-\n", s[i]);
        }
    }

    return 0;
}
