/* Esempio tratto da https://en.cppreference.com/w/c/io/fseek */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* Prepara un array di valori float. */
    #define SIZE 5
    float A[SIZE] = {1.,2.,3.,4.,5.};
    /* Scrivi l'array in un file. */
    FILE *fp = fopen("test.bin", "wb");
    fwrite(A,sizeof(float),SIZE,fp);
    fclose (fp);

    /* Leggi i float dentro un nuovo array B. */
    float B[SIZE];
    fp = fopen("test.bin","rb");
    /* Sposta l'indice all'interno del file all'inizio del terzo valore float */
    /* abbiamo usato 2L per specificare una costante senza segno di tipo LONG INT */
    if (fseek(fp,sizeof(float)*4L,SEEK_SET) != 0)
    {
        perror("fseek()");
        fprintf(stderr,"fseek() e' esplosa nel file %s alla linea %d\n", __FILE__,__LINE__);
        exit(EXIT_FAILURE);
    }

    int ret_code = fread(B,sizeof(float),1,fp);   /* leggi un nuovo valore float  */
    printf("%.1f\n", B[0]);                        /* stampa il valore letto */

    fclose(fp);
    return EXIT_SUCCESS;
}
