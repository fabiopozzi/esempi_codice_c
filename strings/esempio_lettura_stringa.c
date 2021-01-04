#include <stdio.h>
#include <string.h>

#define N 5
int main()
{
    char s[N];

    // modo 1
    // uso il for perche' leggo una lettera alla volta
    for (int i = 0; i < N - 1; i++) {
        s[i] = getchar(); // leggo una lettera alla volta
        // buttare via il carattere '\n'
        getchar();
    }
    s[4] = '\0';
    // modo 2
    // qui non serve il FOR
    scanf("%s", s);
    // meglio
    scanf("%4s", s);

    // modo 3
    fgets(s, N, stdin);
    // problema: in fondo viene lasciato lo \n
    int tmp = strlen(s);
    s[tmp - 1] = '\0';

    /*
    0 1 2 3 4
    c i a o \0
    */
    printf("hai inserito %s\n", s);
    return 0;
}
