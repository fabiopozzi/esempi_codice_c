#include<stdio.h>
#include<string.h>
int main()
{
    char riga[10];
    int spazi = 0;

    scanf("%s", riga); // salta gli spazi iniziali,
    scanf("%s", &riga[0]);   //legge dentro a riga,
                        // si ferma al primo spazio
                        // PROB: legge anche piu' di 10
                        // caratteri

    scanf("%9s", riga); // salta gli spazi iniziali, legge
                        // dentro a riga,
                        // si ferma al primo spazio

    fgets(riga, 10, stdin); // legge fino a 9 caratteri
                            // + terminatore
                            // PROB: lascia lo \n nella
                            //stringa.
                            // PROB: non salta gli spazi
                            //iniziali.
    // tolgo lo \n
    riga[strlen(riga)-1] = '\0'; // tolgo lo \n

    riga[strcspn(riga,"\n")] = '\0';

    int n = strlen(riga);
    // mi restituisce il numero di caratteri
    // che compongono riga
    // NON CONTA IL TERMINATORE
    return 0;
}