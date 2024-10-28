#include <stdio.h>

void firstFit(int holes[], int nh, int processes[], int np) {
    int allocation[np];
    for (int i = 0; i < np; i++) {
        allocation[i] = -1; // Initially, no process is allocated
    }

    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nh; j++) {
            if (holes[j] >= processes[i]) {
                allocation[i] = j; // Allocate the process to the hole
                holes[j] -= processes[i]; // Reduce the size of the hole
                break;
            }
        }
    }

    for (int i = 0; i < np; i++) {
        if (allocation[i] != -1) {
            printf("   %d    - Hole %d\n", i + 1, allocation[i] + 1);
        } else {
            printf("   %d    - Not allocated\n", i + 1);
        }
    }
}

void bestFit(int holes[], int nh, int processes[], int np) {
    int allocation[np];
    for (int i = 0; i < np; i++) {
        allocation[i] = -1; // Initially, no process is allocated
    }

    for (int i = 0; i < np; i++) {
        int bestIndex = -1;
        for (int j = 0; j < nh; j++) {
            if (holes[j] >= processes[i]) {
                if (bestIndex == -1 || holes[j] < holes[bestIndex]) {
                    bestIndex = j; // Update best fit hole
                }
            }
        }
        if (bestIndex != -1) {
            allocation[i] = bestIndex; // Allocate the process to the best hole
            holes[bestIndex] -= processes[i]; // Reduce the size of the hole
        }
    }

    for (int i = 0; i < np; i++) {
        if (allocation[i] != -1) {
            printf("   %d    - Hole %d\n", i + 1, allocation[i] + 1);
        } else {
            printf("   %d    - Not allocated\n", i + 1);
        }
    }
}

int main() {
    int nh, np;
    printf("Enter the number of holes: ");
    scanf("%d", &nh);
    int holes[nh];
    printf("Enter the sizes of the holes: ");
    for (int i = 0; i < nh; i++) {
        scanf("%d", &holes[i]);
    }
    printf("Enter the number of processes: ");
    scanf("%d", &np);
    int processes[np];
    printf("Enter the sizes of the processes: ");
    for (int i = 0; i < np; i++) {
        scanf("%d", &processes[i]);
    }
    printf("1. First Fit\n2. Best Fit\n3. Exit");
    while(1)
    {
        printf("\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("FIRST FIT\nProcess - Hole\n");
                firstFit(holes, nh, processes, np);
                break;
            case 2:
                printf("BEST FIT\nProcess - Hole\n");
                bestFit(holes, nh, processes, np);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
