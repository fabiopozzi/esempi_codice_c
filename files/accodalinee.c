#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 80

int main(void) {
  FILE* fileinput, *fileout;
  char nomefile[N] = {0};
  char riga[N];

  printf("inserisci nome file input");
  scanf("%79s", nomefile);

  fileinput = fopen(nomefile, "r");
  if (fileinput == NULL) {
    perror("file open error");
    return EXIT_FAILURE;
  }
    
  fileout = fopen("risultato.txt", "a");
  if (fileout == NULL) {
    printf("file error");
    return EXIT_FAILURE;
  }

  while(fgets(riga, N, fileinput) != NULL){
    if (strlen(riga) > 20) {
      fprintf(fileout, "--LINEA TROPPO LUNGA--\n");
    }
    else {
      fprintf(fileout, "%s", riga);
    }
  } 

  fclose(fileinput);
  fclose(fileout);

  return 0;
}
