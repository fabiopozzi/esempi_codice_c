#include <stdio.h>

void incrementa(int *val) {
    *val = *val + 1;
}

int main() {
    // scrivi una funzione incrementa che
    // incrementi il contenuto di una variabile intera senza
    // fare uso del valore di ritorno.
    int val = 42;

    incrementa(&val);
    incrementa(&val);
    incrementa(&val);
    printf("%d", val);
}
