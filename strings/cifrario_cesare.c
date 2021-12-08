#include<stdio.h>
#include<ctype.h>

int main()
{
    int i;
    char p[100] = {0};
    char c[100] = {0};
    int key = 3;

    fgets(p, 100, stdin);

    for(i = 0; p[i] != '\0'; i++) {
        if (isalpha(p[i])) {
            if (islower(p[i])) {
                int val = p[i] - 'a'; // prendo posizione nell'alfabeto

                // calcolo nuova posizione nell'alfabeto
                val = (val + key) % 26;
                c[i] = val + 'a';
            }
        } else {
            c[i] = p[i];
        }
    }
    printf("%s", p);
    printf("%s", c);
    printf("-----------------\n");

    for(i = 0; c[i] != '\0'; i++) {
        if (isalpha(c[i])) {
            if (islower(c[i])) {
                int val = c[i] - 'a'; // prendo posizione nell'alfabeto

                // calcolo nuova posizione nell'alfabeto
                if ((val - key) >= 0)
                    val = (val - key) % 26;
                else
                    val = (val - key) + 26; // gestisco differenza negativa
                printf("%c", val + 'a');
            }
        } else {
            printf("%c", c[i]);
        }
    }

    return 0;
}

