#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "system.h"
void print_minios(char* str);

#define MAX_PROCESSES 10

typedef enum {
    PROCESS_NEW,
    PROCESS_READY,
    PROCESS_RUNNING,
    PROCESS_WAITING,
    PROCESS_TERMINATED
} ProcessState;

typedef struct {
    int pid;
    ProcessState state;
    char process_name[256];
} ProcessControlBlock;

ProcessControlBlock processTable[MAX_PROCESSES];
int currentProcess = -1;

void initializeProcessTable() {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processTable[i].pid = -1;
        processTable[i].state = PROCESS_NEW;
    }
}

int createProcess(char *process_name) {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (processTable[i].state == PROCESS_NEW || processTable[i].state == PROCESS_TERMINATED) {
            processTable[i].pid = i;
            strcpy(processTable[i].process_name, process_name);
            processTable[i].state = PROCESS_READY;
            return i;
        }
    }
    return -1;
}

void terminateProcess(int pid) {
    if (pid >= 0 && pid < MAX_PROCESSES) {
        processTable[pid].state = PROCESS_TERMINATED;
        printf("[MiniOS SSU] Process %d terminated.\n", pid);
    }
}

int main() {
    initializeProcessTable();
    print_minios("[MiniOS SSU] Hello, World!");

    char *input;

    while(1) {
        input = readline("커맨드를 입력하세요(종료:exit) : ");

        if (strcmp(input, "exit") == 0) {
            break;
        }

        if (strcmp(input, "minisystem") == 0) {
            minisystem();
        }
        else if (strcmp(input, "create") == 0) {
            int pid = createProcess("Sample Process");
            if (pid != -1) {
                printf("Process created with PID: %d\n", pid);
            } else {
                printf("Failed to create process.\n");
            }
        }
        else if (strncmp(input, "kill ", 5) == 0) {
            int pid = atoi(input + 5);
            terminateProcess(pid);
        }
        else {
            system(input);
        }
    }

    free(input);
    print_minios("[MiniOS SSU] MiniOS Shutdown........");

    return 1;
}

void print_minios(char* str) {
    printf("%s\n", str);
}
