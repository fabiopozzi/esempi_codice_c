#include <stdio.h>

int main() {
    int *pointer; /* dichiara pointer come un puntatore a int */
    int x = 1, y = 2;
    pointer = &x; /* assegna a pointer l'indirizzo di x */

    y = *pointer; /* assegna a y il contenuto di pointer */
    x = pointer;  /* assegna ad x l'indirizzo contenuto in pointer. */
    *pointer = 3; /* assegna al contenuto di pointer il valore 3 */

    return 0;
}
