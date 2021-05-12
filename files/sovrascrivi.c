#include <stdio.h>

int main()
{
	FILE *fp;
	char s[80];
	int val;

	fp = fopen("file_prova.txt", "r+");

	for(int i = 0; i < 3; i++){
		fgets(s, 80, fp);
	}
	sscanf(s, "%d", val);
	val++;
	fseek(fp, -3, SEEK_CUR);

	fprintf(fp, "%d\n", val);
	fclose(fp);
	
	return 0;
}
