#include <stdio.h>

int main()
{
    int val = 141;


    switch(val) {
        case 120:
        // questo codice viene eseguito SSE
        // if(val == 120)
        printf("VAL VALE 120\n");
        break;
        case 140:
        // passa oltre
        case 141:
        printf("VAL VALE 140 o 141 \n");
        break;
        default:
        printf("val non vale nessuno dei valori precedenti");
    }
}