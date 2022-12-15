#include<stdio.h>
#define SI 1
#define NO 0

#define N 3

int main() {
    int v[N]={1, 2, 3}, w[N]={1, 2, 3};
    int uguali = SI; /* flag */
    int i;
    for (i=0; i<N ; i++) {
        if (v[i]!=w[i]) {
            break;
        }
    }
    if (i == N)
        printf("Sono uguali");
    else printf("Non sono uguali");
}
