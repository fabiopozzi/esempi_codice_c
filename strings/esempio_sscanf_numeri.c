/*
  Calcola la media degli interi letti dall'utente.
  Le linee che iniziano con # sono commenti
  e non vengono considerate.
*/
#include<stdlib.h>
#include<stdio.h>

int main() {
    char buf[200];
    int i, x, y;
    int n = 0, somma = 0;
    float media;
    int valori_letti;

    /* legge una riga per volta */
    for(i = 0; i < 10; i++){
        fgets(buf, 200, stdin);

        if( buf[0] != '#' ) {
            valori_letti = sscanf(buf, "%d %d", &x, &y);
            if (valori_letti == 2){
                somma+=(x+y);
                n+=2;
            }
        } else {
            printf("riga commento\n");
        }
    }


    /* stampa la media */
    media = (float)somma / n;
    printf("La media e' %f\n", media);

    return 0;
}

