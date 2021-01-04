#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selection_sort(int n, char *argv[], int par);

int main(int argc, char *argv[])
{
    int par = atoi(argv[argc - 1]);
    // 1 ordina in modo crescente
    // 0 ordina in modo decrescente
    selection_sort(argc - 1, argv, par);
    return 0;
}

/* TODO: ordina delle stringhe, andrebbero convertiti in numeri interi ed
 * inseriti in un array */
void selection_sort(int n, char *argv[], int par)
{
    int i, j;
    int min;
    char *p;
    int cur_num, min_val;

    for (i = 1; i < n - 1; i++) {
        min = i;
        min_val = atoi(argv[i]);
        for (j = i + 1; j < n; j++) {
          cur_num = atoi(argv[j]);
          if (par == 0) {
            // trova posizione stringa minima
            if (cur_num < min_val) {
              min = j;
              min_val = atoi(argv[min]);
            }
          } else {
            // trova posizione stringa massimo
            if (cur_num > min_val) {
              min = j;
              min_val = atoi(argv[min]);
            }
          }
        }
        // scambia minimo con posizione iesima
        p = argv[min];
        argv[min] = argv[i];
        argv[i] = p;
    }
    for (i = 1; i < n; i++)
      printf("%s\n", argv[i]);
    return;
}

/* void bubble_sort(int n, char *argv[]) */
/* { */
/*     for(i=1;i<n-1;i++){ */
/*         if(strcmp(argv[i], argv[i+1])>0) { */
/*             p = argv[i+1]; */
/*             argv[i+1] = argv[i]; */
/*             argv[i] = p; */
/*             //scambia */
/*         } */
/*     } */
/* } */
