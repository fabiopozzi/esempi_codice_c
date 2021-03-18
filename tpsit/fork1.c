#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int globvar = 6;
char buf[] = "una prova di stringa\n";

int main (void)
{
	int var;
	pid_t pid;

	var = 88;
	if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1){
		printf("write error");
		return -1;
	}

	printf("before fork\n");
	if ((pid = fork()) < 0) {
		printf("write error");
		return -1;
	} else if (pid == 0) { // child
		globvar++;
		var++;
	} else {
		sleep(2);
	}

	// prima stampa il figlio, mentre il padre arriva dopo 2 secondi
	printf("pid: %ld, globvar = %d, var = %d\n", (long)getpid(), globvar, var);

	return 0;
}
