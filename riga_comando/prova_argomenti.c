#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("non abbiamo nessun argomento\n");
		printf("argc vale %d\n", argc);
	} else {
		for(int i = 0; i < argc; i++){
			printf("%s\n", argv[i]);
		}
		for(int i = 0; argv[i] != NULL; i++){
			printf("%s\n", argv[i]);
		}
	}
	return 0;
}
