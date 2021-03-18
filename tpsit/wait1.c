#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void pr_exit(int status)
{
	if (WIFEXITED(status))
		printf("Normal termination, exit status = %d\n", WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("Abnormal termination, signal number %d%s\n", WTERMSIG(status), "core file generated");
	else if (WIFSTOPPED(status))
		printf("child stopped, signal number %d\n", WSTOPSIG(status));
}

int main(void)
{
	pid_t pid;
	int   status;

	if ((pid = fork()) < 0) {
		printf("errore di sistema in fork()");
		return -1;
	} else if (pid == 0) { // padre
		exit(7);
	}

	if (wait(&status) != pid) {
		printf("errore di sistema in wait()");
		return -1;
	}
	pr_exit(status);

	if ((pid = fork()) < 0) {
		printf("errore di sistema in fork()");
		return -1;
	} else if (pid == 0) { // padre
		abort();
	}

	if (wait(&status) != pid) {
		printf("errore di sistema in wait()");
		return -1;
	}
	pr_exit(status);

	if ((pid = fork()) < 0) {
		printf("errore di sistema in fork()");
		return -1;
	} else if (pid == 0) { // padre
		status /= 0;       // dividi per zero
	}

	if (wait(&status) != pid) {
		printf("errore di sistema in wait()");
		return -1;
	}
	pr_exit(status);

	return 0;
}
