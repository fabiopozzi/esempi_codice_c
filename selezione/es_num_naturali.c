/* Scrivi un programma che permetta all’utente di inserire 5 numeri interi e verifichi
se questi numeri appartengono alla sequenza dei numeri naturali,
cioè siano tutti differenti e abbiano tra di loro distanza unitaria.
10 11 12 13 14
*/
#include <stdio.h>

int main()
{
    int i = 0;
    while (i < 10) {

        if (i == 5) {
            i++;
            printf("voglio saltare il 5 perche' e' antipatico");
            break;
        }
        printf("%d", i);
        i++;
    }
    return 0;
}
