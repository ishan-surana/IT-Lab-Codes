#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void preemptiveSJF(int processes[][7], int n);
void roundRobin(int processes[][7], int n, int quantum);
void priorityScheduling(int processes[][7], int n);

void displayResults(int processes[][7], int n) {
    printf("\nProcess\tArrival\tBurst\tStart\tFinish\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            processes[0][i], processes[1][i], processes[2][i],
            processes[3][i], processes[4][i], processes[5][i], processes[6][i]);
    }
}

int main() {
    int n;

    printf("Input number of processes: ");
    scanf("%d", &n);

    // Allocate memory for processes array dynamically
    int (*processes)[7] = malloc(n * sizeof(*processes));
    if (processes == NULL) {
        perror("Unable to allocate memory");
        return 1;
    }

    printf("Enter process numbers: ");
    for (int i = 0; i < n; i++) scanf("%d", &processes[0][i]);

    printf("Enter process arrival times: ");
    for (int i = 0; i < n; i++) scanf("%d", &processes[1][i]);

    printf("Enter process burst times: ");
    for (int i = 0; i < n; i++) scanf("%d", &processes[2][i]);

    for (int i = 0; i < n; i++) {
        processes[3][i] = 0; // Start time
        processes[4][i] = 0; // Finish time
        processes[5][i] = 0; // Waiting time
        processes[6][i] = 0; // Turnaround time
    }

    int choice, quantum;
    while (1) {
        int (*ps)[7] = processes;
        printf("\nMenu:\n");
        printf("1. Preemptive Shortest Job First (SJF)\n");
        printf("2. Round Robin\n");
        printf("3. Non-Preemptive Priority Scheduling\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                preemptiveSJF(ps, n);
                break;
            case 2:
                printf("Enter time quantum for Round Robin: ");
                scanf("%d", &quantum);
                roundRobin(ps, n, quantum);
                break;
            case 3:
                priorityScheduling(ps, n);
                break;
            case 4:
                free(ps);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        displayResults(processes, n);
    }
}

void preemptiveSJF(int processes[][7], int n) {
    int remainingBurst[n];
    int time = 0;
    int completed = 0;
    int minIndex;

    for (int i = 0; i < n; i++) remainingBurst[i] = processes[2][i];

    while (completed < n) {
        minIndex = -1;
        int minBurst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (processes[1][i] <= time && remainingBurst[i] > 0 && remainingBurst[i] < minBurst) {
                minBurst = remainingBurst[i];
                minIndex = i;
            }
        }

        if (minIndex != -1) {
            processes[3][minIndex] = time;
            remainingBurst[minIndex]--;
            time++;

            if (remainingBurst[minIndex] == 0) {
                processes[4][minIndex] = time;
                processes[6][minIndex] = processes[4][minIndex] - processes[1][minIndex];
                processes[5][minIndex] = processes[6][minIndex] - processes[2][minIndex];
                completed++;
            }
        } else {
            time++;
        }
    }
}

void roundRobin(int processes[][7], int n, int quantum) {
    int remainingBurst[n];
    int time = 0;
    int completed = 0;

    for (int i = 0; i < n; i++) remainingBurst[i] = processes[2][i];

    while (completed < n) {
        // checking for all incomplete processes
        int flag = 0;
        for (int i = 0; i < n; i++) {
        if (processes[1][i] <= time && remainingBurst[i] > 0)
        {
            flag = 1;
            if (processes[3][i] == 0) processes[3][i] = time;
            if (remainingBurst[i] > quantum) {
                remainingBurst[i] -= quantum;
                time += quantum;
            } else {
                time += remainingBurst[i];
                processes[4][i] = time;
                processes[6][i] = processes[4][i] - processes[1][i]; // Turnaround time = finish time - arrival time
                processes[5][i] = processes[6][i] - processes[2][i]; // Waiting time = turnaround time - burst time
                remainingBurst[i] = 0;
                completed++;
            }
        }
    }
    if(!flag) time++;
    }
}

void priorityScheduling(int processes[][7], int n) {
    int remainingBurst[n];
    int priority[n];
    int time = 0;
    int completed = 0;
    int minIndex;
    for(int i = 0; i < n; i++) remainingBurst[i] = processes[2][i];

    printf("Enter process priorities: ");
    for (int i = 0; i < n; i++) scanf("%d", &priority[i]);

    while (completed < n) {
        minIndex = -1;
        int minPriority = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (processes[1][i] <= time && remainingBurst[i] > 0 && priority[i] < minPriority) {
                minPriority = priority[i];
                minIndex = i;
            }
        }
        if (minIndex != -1) {
            processes[3][minIndex] = time;
            time += remainingBurst[minIndex];
            processes[4][minIndex] = time;
            processes[6][minIndex] = processes[4][minIndex] - processes[1][minIndex];
            processes[5][minIndex] = processes[6][minIndex] - processes[2][minIndex];
            remainingBurst[minIndex] = 0;
            completed++;
        } else {
            time++;
        }
    }
}
