#include <stdio.h>

int main()
{
	FILE *fp = fopen("es1_file.c", "r");
	char s[80];

	while(fgets(s, 80, fp) != NULL) {
		printf("riga letta: %s", s);
	}
	fclose(fp);
	return 0;
}
