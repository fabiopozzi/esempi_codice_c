#include <stdio.h>

void prova(int v[]) {
    printf("\n%p", v);
    v[0] = 42;
    // tutte le modifiche RIMANGONO
    // questa riga e' valida
}

int main() {
    int v[5];
    int a = 5;

    if (v[3] == *(v + 3)) {
        printf("vero\n");
    }
    printf("%p", &v[0]);
    prova(v);

    /*
         0x12345678
        ----------------
        |  |  |  | x |  |
        ----------------
         0   1  2  3  4   posizioni nel vettore

        v == &v[0] // sono sinonimi
        p = &v[0]
        v[3] -->   *(p + 3)
        */
}
/*
p e' un puntatore ad intero quanto e' grande un intero? 4  se p
        vale 0x12345670 quindi p +
    1 vale 0x12345670 + 4 = 0x12345674
    */