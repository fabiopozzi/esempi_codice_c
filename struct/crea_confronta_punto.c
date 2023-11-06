#include <stdio.h>

typedef struct p {
    int x;
    int y;
    char label;
} punto_t;

// facendo uso della struttura dati punto_t scrivi le funzioni
// punto_t creaPunto(int valorex, int valorey)
// int confrontaPunti(punto_t p1, punto_t p2)

int confrontaPunti(punto_t p1, punto_t p2)
{
    int uguali = 0;
    if (p1.x == p2.x)
        if (p1.y == p2.y)
            uguali = 1;

    return uguali;
}

punto_t creaPunto(int valorex, int valorey)
{
    punto_t tmp;
    tmp.x = valorex;
    tmp.y = valorey;
    tmp.label = 'a';

    return tmp;
}


int main()
{
    punto_t p1 =  creaPunto(10, 20);
    punto_t p2;

    printf("x vale %d\ny vale %d,\n etichetta %c\n", p1.x, p1.y, p1.label);

    p2 = p1;

    if (confrontaPunti(p1, p2)) {
        printf("SONO UGUALI");
    }
}
