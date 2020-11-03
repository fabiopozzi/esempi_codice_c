/*
 * Scrivere un programma che legga una stringa dall'utente (con la scanf) e stampi a video
 * la lunghezza della stringa (contare il numero di lettere che compongono la stringa)
 * non contare il terminatore di stringa.
 * NO STRLEN
 */
#include<stdio.h>
int main() {

    char stringa[100];
    int lung = 0;
    int i;

    scanf("%s", stringa);
    // si ferma quando incontra uno spazio

    // quanto e' lunga la stringa ??
    for(i = 0; i < 100; i++) {
        if (stringa[i] == '\0')
            break;
    }

    while(stringa[lung] != '\0') {
        lung++;
    }
    printf("la stringa e' lunga %d\n", lung);

    return 0;
}

