#include <stdio.h>

#define MAX_PROCESSES 10

typedef struct {
    char name;
    int arrival_time;
    int burst_time;
} Process;

// Abbreviation of the Round_Robin_Scheduler
void runner_RRS(Process processes[], int num_processes, int time_slice) {
    int remaining_burst_time[MAX_PROCESSES];
    for (int i = 0; i < num_processes; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
    }

    int current_time = 0;
    while (1) {
        int all_finished = 1;
        for (int i = 0; i < num_processes; i++) {
            if (remaining_burst_time[i] > 0) {
                all_finished = 0;
                int slice = (remaining_burst_time[i] >= time_slice) ? time_slice : remaining_burst_time[i];
                printf("Executing process %c from %d to %d\n", processes[i].name, current_time, current_time + slice);
                remaining_burst_time[i] -= slice;
                current_time += slice;
            }
        }
        if (all_finished) break;
    }
}

int RRS() {
    Process processes[] = {
        {'1', 0, 8},
        {'2', 1, 4},
        {'3', 2, 9},
        {'4', 3, 5}
    };
    int num_processes = sizeof(processes) / sizeof(processes[0]);
    int time_slice = 3;

    printf("Running Round Robin Scheduler:\n");
    runner_RRS(processes, num_processes, time_slice);

    return 0;
}