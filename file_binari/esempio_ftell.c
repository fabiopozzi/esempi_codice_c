#include <stdio.h>

int main () {
   FILE *fp;
   int len;

   fp = fopen("file.txt", "r");
   if( fp == NULL )  {
      perror ("Errore apertura file");
      return(-1);
   }
   fseek(fp, 0, SEEK_END);

   len = ftell(fp);
   fclose(fp);

   printf("Dimensione di file.txt = %d bytes\n", len);

   return(0);
}
