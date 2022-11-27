#include <stdio.h>

int main()
{
    int n = 1; // dichiarazione con assegnamento

    // for(n=1; n < 5; n++){
    //     printf("CIAONE\n");
    //     printf("-----%d-----\n", n);
    // }

    for(n = 5; n > 0; n--){
        printf("CIAONE\n");
        printf("-----%d-----\n", n);
    }

    printf("HO FINITO IL CICLO");
}