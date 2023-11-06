#include <stdio.h>
#define N 12

int p(int v[], int sx, int dx)
{
    int val, pos;
    int tmp;

    pos = sx;
    val = v[pos];

    while (sx < dx) {
        while((v[sx] <= val) && (sx < dx)) {
            sx++;
        }
        while (v[dx] > val) {
            dx--;
        }

        if (sx < dx) {
            tmp = v[sx];
            v[sx] = v[dx];
            v[dx] = tmp;
        }
    }
    tmp = v[pos];
    v[pos] = v[dx];
    v[dx] = tmp;

    return dx;
}

void a(int vett[], int s, int d)
{
    int q;

    if (s < d) {
        q = p(vett, s, d);
        a(vett, s, q - 1);
        a(vett, q + 1, d);
    }
}

int main()
{
    int v[N] = {27, 7, 49, 44, 45, 30, 31, 6, 39, 19, 33, 26};

    a(v, 0, 11);
}
