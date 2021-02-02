/*
** Data una frase, sostituire i caratteri in posizione pari
** con equivalenti caratteri maiuscoli, sostituire i caratteri
** in posizione dispari con equivalenti caratteri minuscoli
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	char s[] = "Piove, SULLE tamerici arse e SALMASTRE, piove sui pini";

	int l = strlen(s);
	for(int i = 0; i < l; i++) {
		if (i % 2 == 0) {
			s[i] = toupper(s[i]);
		} else {
			s[i] = tolower(s[i]);
		}
	}
	printf("%s\n", s);
	return 0;
}
