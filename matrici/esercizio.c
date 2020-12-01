/*
Definire la matrice MX come nel precedente esercizio,
questo programma deve indicare se almeno un quarto dei valori della matrice è pari.
Non interessa sapere quanti siano i valori pari,
ma solo sapere se ce n’è almeno un certo numero noto a priori
(num_righe * num_colonne / 4, attenzione: tronca la parte frazionaria);
quindi quando si arriva a contarne esattamente quel numero si può uscire
dai due cicli annidati per non perdere tempo inutilmente
(è inutile contare anche gli altri).
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RIGHE 20
#define COLONNE 26
int main()
{
    // dichiarazioni variabili locali
    int numero_di_valori_pari_della_matrice;
    int mat[RIGHE][COLONNE];
    int i, j;

    // risoluzione del problema
    numero_di_valori_pari_della_matrice = (RIGHE * COLONNE) / 4;
    srand(time(NULL)); // INIZIALIZZA il nostro generatore di numeri pseudocasuali

    // RIEMPIRE MATRICE di interi a caso
    for (j = 0; j < RIGHE; j++) {
        for (i = 0; i < COLONNE; i++) {
            mat[j][i] = rand() % 200; // vado da 0 a 199
        }
    }

    int variabile = 0;
    // controllo sui numeri pari
    for (j = 0; j < RIGHE; j++) {
        for (i = 0; i < COLONNE; i++) {
            // contare quanti numeri sono pari
            if (mat[j][i] % 2 == 0)
                variabile++;
        }
    }
    // se il numero di valori pari > numero_di_valori_pari_della_matrice
    // allora OK la mia matrice ha almeno un quarto di valori pari
    // altrimenti
    // NO non abbiamo abbastanza valori pari

    return 0;
}