#include <stdio.h>
#include <string.h>

int main()
{
    char s[5];

    printf("stringa:");
    scanf("%4s", s);

    for(int i = 0; i < 5; i++) {
        if (s[i] == '\0') {
            printf("-terminatore-");
            break;
        }
        else {
            printf("-%c-\n", s[i]);
        }
    }
    return 0;
}

