#include<stdio.h>
#define N 5

struct risultati {
    int max;
    int min;
    float media;
};


struct risultati maxminmedia(int v[]);

int main()
{
    int v[] = {1, 2, 10, 0, 4};
    struct risultati r;

    r = maxminmedia(v);
    printf("max: %d, min %d\n", r.max, r.min);
    return 0;
}

struct risultati maxminmedia(int v[])
{
    struct risultati b;

    b.max = v[0];
    b.min = v[0];

    for (int i = 0; i < N; i++) {
        if(v[i] > b.max) {
            b.max = v[i];
        }
        if(v[i] < b.min) {
            b.min = v[i];
        }
    }

    return b;
}
