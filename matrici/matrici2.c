/*
Scrivere un programma che data una matrice quadrata 3x3
(ovvero una matrice con 3 righe e 3 colonne)
determini se questa matrice è una matrice triangolare superiore.
Una matrice è triangolare superiore se tutti i valori sottostanti
alla diagonale principale sono pari a ZERO.
Esempio:
    0   1   2 colonne
    ---------
 0| 1   20  4
 1| 0   75  15
 2| 0   0   25
 righe

è una matrice triangolare superiore.
(gli elementi [1  7  25] costituiscono la diagonale principale).
Mentre questa matrice non lo è (a causa del numero 4)
1   2   4
0   7   15
4   0   25

Variante 2: determinare se la matrice è triangolare inferiore.
*/
#include <stdio.h>

int main()
{
    int m[3][3] = { { 1, 2, 3 }, { 0, 5, 6 }, { 0, 0, 9 } };
    int diagonale = 1;

    //if (m[1][0] == 0 && m[2][0] == 0 && m[2][1] == 0) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            // se num colonna e' min del numero della riga siamo sotto la diagonale
            if (c < r && m[r][c] != 0) {
                diagonale = 0; // NON e' una matrice diagonale
            }
        }
    }
    if (diagonale) {
        printf("la matrice è diagonale\n");
    } else {
        printf("NAAAAA\n");
    }
    return 0;
}