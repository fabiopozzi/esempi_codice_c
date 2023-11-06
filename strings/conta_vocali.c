// data una stringa, contare le vocali
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 10

int main()
{
    int i;
    int conta = 0; // DEVO METTERLO A ZERO
    char s[N];
    char c;

    fgets(s, N, stdin);

    for(i = 0; s[i] != '\0'; i++) {
        c = tolower(s[i]);
        if((c == 'a') || (c == 'e')|| (c == 'i')
        || (c == 'o')|| (c == 'u')) {
            conta++;
        }
    }
    printf("numero vocali: %d\n", conta);
}