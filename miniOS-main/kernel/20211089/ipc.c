#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int IPC() {
	char write_msg[BUFFER_SIZE] = "IPC Produced";
	char read_msg[BUFFER_SIZE];
	int status;
	int fd[2];
	pid_t pid;

	if (pipe(fd) == -1) { // create the pipe
		fprintf(stderr, "Pipe Failed");
		return 1;
	}

	pid = fork();
	if (pid < 0) { // fork a child process
		fprintf(stderr, "Fork Failed");
		return 1;
	}

	if (pid > 0) { // parent process
		close(fd[READ_END]);
		write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
		close(fd[WRITE_END]);
		wait(&status);
	}

	else { // child process
		close(fd[WRITE_END]);
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		printf("IPC : %s\n", read_msg);
		close(fd[READ_END]);
		exit(0);
	}

	return 0;
}