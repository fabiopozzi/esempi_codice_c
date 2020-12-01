#include <stdio.h>
#include <string.h>

#define N 5
int main()
{
    char s[N];

    char format[4];
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
