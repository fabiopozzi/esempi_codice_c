#include <stdio.h>

typedef struct p {
    int x;
    int y;
    char l;
} punto_t;

int confrontaPunti(punto p1, punto p2)
{
    int uguali = 0;
    if (p1.x == p2.x)
        if (p1.y == p2.y)
            uguali = 1;

    return uguali;
}

punto creaPunto(int valorex, int valorey)
{
    punto tmp;
    tmp.x = valorex;
    tmp.y = valorey;
    tmp.l = 'a';

    return tmp;
}


int main()
{
    punto p1 =  creaPunto(10, 20);
    punto p2;

    printf("x vale %d\ny vale %d,\n l vale %c\n", p1.x, p1.y, p1.l);

    p2 = p1;

    if (confrontaPunti(p1, p2)) {
        printf("SONO UGUALI");
    }
}
