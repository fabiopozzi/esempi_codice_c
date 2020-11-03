#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100];
    char s2[100];
    int diversi;

    printf("stringa1");
    fgets(s1, 100, stdin);
    printf("stringa2");
    fgets(s2, 100, stdin);

    size_t l1 = strlen(s1);
    size_t l2 = strlen(s2) - 1; // saltare il \n alla fine
    for (int i = 0; i < l1; i++) {
        if (s1[i] == s2[0]) {
            diversi = 0;
            for (int j = 0; j < l2; j++) {
                if (s1[i + j] != s2[j]) {
                    printf("le lettere %c %c son diverse\n", s1[i + j], s2[j]);
                    diversi = 1;
                }
            }
            if (diversi == 0) {
                printf("la stringa %s e' sottostringa di %s\n", s2, s1);
                break;
            }
        }
    }
    return 0;
}