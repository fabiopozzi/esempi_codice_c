#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long val;
    char str[20] = "9899";

    // prova con "9891234", "9898aaaa"   "9899   "
    val = strtol(str, NULL, 10);
    // manca la gestione degli errori nel caso
    // la conversione non vada a buon fine (ma lo vedremo in futuro)
    // per chi vuole approfondire coinvolge l'uso di errno
    printf("%s = %ld\n", str, val);

    return (0);
}