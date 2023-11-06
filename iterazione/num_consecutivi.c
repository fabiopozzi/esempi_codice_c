#include <stdio.h>

int main()
{
    int num;
    int val;
    int prec = 0;
    int count = 0;
    int vero = 0;

    printf("inserisci num: ");
    scanf("%d", &num);

    for(int i = 0; i < num; i++) {
        printf("numero %d: ", i+1);
        scanf("%d", &val);
        if (prec != 0) {
            if (val == prec+1) {
                if (count != 0) {
                    count++;
                } else {
                    count = 2;
                }
            } else {
                count = 0;
            }
        }
        prec = val;
        if (count >= 3) {
            vero = 1;
        }
    }
    if (vero == 1)
        printf("VERO\n");
    else
        printf("FALSO\n");
    return 0;
}

