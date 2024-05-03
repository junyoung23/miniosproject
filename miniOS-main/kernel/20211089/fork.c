#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int Fork() {
	pid_t pid;
	// fork a child process
	pid = fork();

	if (pid < 0) {
		fprintf(stderr, "Fork Failed\n");
		return 1;
	}

	else if (pid == 0) {
		execlp("/bin/ls", "ls", NULL);
	}

	else {
		// parent will wait for the child to complete
		wait(NULL);
		printf("Child Complete\n");
	}

	return 0;
}
