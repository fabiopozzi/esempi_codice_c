#include <stdio.h>
int main()
{
    typedef enum {
        lunedi,
        martedi,
        mercoledi,
        giovedi,
        venerdi,
        giorni_della_settimana
    } giorni;

    giorni g1 = lunedi;
    giorni g2 = venerdi;
    int ora[giorni_della_settimana];
    printf("%d\n", lunedi);
}