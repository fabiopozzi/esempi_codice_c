#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// riferimento: https://www.gnu.org/software/libc/manual/html_node/Parsing-Program-Arguments.html

// alternativa (int argc, char **argv)
int main(int argc, char *argv[]) {
  int flag_a = 0;
  int flag_b = 0;
  char *stringa = NULL;
  int i;
  int c;

  // Variabili globali definite altrove (unistd)
  /* opterr: errori parsing
   * optopt: carattere sconosciuto
   * optind: indice del prossimo elemento da analizzare
   */

  opterr = 0;

  // quando getopt restituisce -1 non c'è altro da fare (parsing concluso)
  // specifiche opzioni:
  // - lettera normale = flag
  // - lettera piu' ':' = opzione con argomento
  while ((c = getopt(argc, argv, "abc:")) != -1)
    switch (c) {
    case 'a':
      flag_a = 1;
      break;
    case 'b':
      flag_b = 1;
      break;
    case 'c':
      stringa = optarg;
      break;
    case '?':
      if (optopt == 'c')
	fprintf(stderr, "L'opzione -%c richiede un argomento.\n", optopt);
      else if (isprint(optopt))
	fprintf(stderr, "Opzione sconosciuta `-%c'.\n", optopt);
      else
	fprintf(stderr, "Carattere sconosciuto `\\x%x'.\n", optopt);
      return 1;
    default:
      abort();
    }

  printf("flag_a = %d, flag_b = %d, cvalue = %s\n", flag_a, flag_b, cvalue);

  for (i = optind; i < argc; i++)
    printf("Non-option argument %s\n", argv[i]);
  return 0;
}
