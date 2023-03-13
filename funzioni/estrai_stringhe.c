// 9.17 inizio 9.28
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void estrai_stringhe(char s[], char c, char r[])
{
    char tmp[100];
    int inizio = 0, fine = 0;
    int j = 0;
    int i = 0;

    //CIAO      COME VA?
    while(1) {
        // inizio prima parola
        if(i == 0 && isalpha(s[i])) {
            inizio = 1;
        } else {
            // inizio parole successive
            if (isspace(s[i-1]) && isalpha(s[i])) {
                inizio = 1;
                fine = 0;
            } else if (isalpha(s[i])) {
                // a meta parola  metto inizio a 0
                inizio = 0;
            }
        }
        // fine parola
        if (isspace(s[i]) || s[i] == '\0') {
            /*printf("fine parola: %c\n", s[i]);*/
            fine = 1;
        }
        // se inizia parola resetto indice
        if (inizio) {
            j = 0;
        }
        // se carattere normale lo copio nella posizione corretta
        if (isalpha(s[i])) {
            tmp[j] = s[i];
            j++;
        }
        /*printf("lettera %c, inizio %d, fine %d\n", s[i], inizio, fine);*/
        // se la parola finisce
        if (fine) {
            tmp[j] = '\0';
            if (strchr(tmp, c) != NULL) {
                strcat(r, tmp);
                strcat(r, " ");
            }
        }
        if (s[i] == '\0')
            break;
        i++;
    }
}
int main()
{
    char s[] = "ciao come va pippo abbraccio";
    char r[100] = "";

    estrai_stringhe(s, 'c', r);
    printf("%s\n", r);
    return 0;
}

