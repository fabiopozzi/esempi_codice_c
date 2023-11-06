/* Esempio tratto da https://en.cppreference.com/w/c/io/fseek */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* Prepara un array di valori float. */
    #define SIZE 5
    float A[SIZE] = {1.,2.,3.,4.,5.};
    /* Scrivi l'array in un file. */
    FILE *fp;
    // fp = fopen("test.bin", "wb");
    // fwrite(A,sizeof(float),SIZE,fp);
    // fclose (fp);

    /* Leggi i float dentro un nuovo array B. */
    float B;
    fp = fopen("test.bin","rb");


    // if (fseek(fp, 0 ,SEEK_END) != 0)
    // {
    //     perror("fseek()");
    //     fprintf(stderr,"fseek() e' esplosa nel file %s alla linea %d\n", __FILE__,__LINE__);
    //     exit(EXIT_FAILURE);
    // }
    // int i, ret_code;
    // for (i = 0; i < 5; i++) {
    //     if (i){
    //         fseek(fp, -2L * (sizeof(float)), SEEK_CUR);
    //     } else {
    //         fseek(fp, -1L * (sizeof(float)), SEEK_CUR);
    //     }
    //     ret_code = fread(&B, sizeof(float), 1, fp);   /* leggi un nuovo valore float  */
    //     if (ret_code == 1)
    //         printf("%.1f\n", B);                        /* stampa il valore letto */
    //     else {
    //         if (feof(fp))
    //             printf("IL FILE E' FINITO!\n");
    //     }
    // }

    // int i = 1, ret_code;
    // while(1) {
    //     if (fseek(fp, i * (sizeof(float)), SEEK_END) != 0) {
    //         printf("fseek fallita\n");
    //         perror("fseek");
    //         break;
    //     }
    //     ret_code = fread(&B, sizeof(float), 1, fp);   /* leggi un nuovo valore float  */
    //     if (ret_code == 1)
    //         printf("%.1f\n", B);                        /* stampa il valore letto */
    //     else {
    //         if (feof(fp))
    //             printf("IL FILE E' FINITO!\n");

    //     }
    //     i++;
    // }

    int i = 0, ret_code;
    while(1) {
        if (fseek(fp, i * (sizeof(float)), SEEK_SET) != 0) {
            printf("fseek fallita\n");
            perror("fseek");
            break;
        }
        ret_code = fread(&B, sizeof(float), 1, fp);   /* leggi un nuovo valore float  */
        if (ret_code == 1)
            printf("%.1f\n", B);                        /* stampa il valore letto */
        else {
            if (feof(fp)) {
                printf("IL FILE E' FINITO!\n");
                //break;
            }
        }
        i += 2;
    }

    fclose(fp);
    return EXIT_SUCCESS;
}
