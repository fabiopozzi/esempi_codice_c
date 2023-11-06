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
        if(i == 0 || (isspace(s[i-1]) && isalpha(s[i]))) {
                  for(j = 0; isspace(s[i]) == 0 && s[i] != '\0'; j++) {
                       tmp[j] = s[i];
                       i++;
                  }
        }
        tmp[j] = '\0';
        if (strchr(tmp, c) != NULL) {
            strcat(r, tmp);
            strcat(r, " ");
        }
             // uscire con terminatore
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

