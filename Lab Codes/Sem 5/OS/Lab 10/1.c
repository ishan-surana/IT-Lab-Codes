#include <stdio.h>

void fifo(int pages[], int np, int frames[], int nf) {
    int faults = 0, current = 0, frameQueue[nf];
    for (int i = 0; i < nf; i++) frameQueue[i] = -1;
    for (int i = 0; i < np; i++) {
        int hit = 0;
        for (int j = 0; j < nf; j++)
            if (frameQueue[j] == pages[i])
            {
                hit = 1;
                printf("Page %d already in frame %d!\n", pages[i], j);
                break;
            }
        if (!hit)
        {
            faults++;
            frameQueue[current % nf] = pages[i];
            printf("Page %d loaded into frame %d\n", pages[i], current++);
        }
    }
    printf("Number of page faults: %d\n", faults);
}

void lru(int pages[], int np, int frames[], int nf) {
    int faults = 0, current = 0, frameQueue[nf], lastUsed[nf];
    for (int i = 0; i < nf; i++) frameQueue[i] = -1;
    for (int i = 0; i < nf; i++) lastUsed[i] = -1;
    for (int i = 0; i < np; i++)
    {
        int hit = 0;
        for (int j = 0; j < nf; j++)
            if (frameQueue[j] == pages[i])
            {
                hit = 1;
                printf("Page %d already in frame %d!\n", pages[i], j);
                lastUsed[j] = current++;
                break;
            }
        if (!hit)
        {
            faults++;
            int leastUsed = 0;
            for(int j = 0; j < nf; j++) if(lastUsed[j] < lastUsed[leastUsed]) leastUsed = j;
            frameQueue[leastUsed] = pages[i];
            lastUsed[leastUsed] = current++;
            printf("Page %d loaded into frame %d\n", pages[i], leastUsed);
        }
    }
    printf("Number of page faults: %d\n", faults);
}

void optimal(int pages[], int np, int frames[], int nf) {
    int faults = 0, current = 0, frameQueue[nf], positions[nf];
    for (int i = 0; i < nf; i++) frameQueue[i] = -1;
    for (int i = 0; i < np; i++)
    {
        int hit = 0, isEmpty = 0;
        for (int j = 0; j < nf; j++)
            if (frameQueue[j] == pages[i])
            {
                hit = 1;
                printf("Page %d already in frame %d!\n", pages[i], j);
                break;
            }
        if (!hit)
        {
            faults++;
            for (int j = 0; j < nf; j++) if (frameQueue[j] == -1) isEmpty = 1;
            if (isEmpty)
            {
                for (int j = 0; j < nf; j++)
                    if (frameQueue[j] == -1) 
                    {
                        frameQueue[j] = pages[i];
                        break;
                    }
                printf("EMPTY! Page %d loaded into frame %d\n", pages[i], current++);
            }
            else
            {
                for (int j = 0; j < nf; j++) positions[j] = np;
                for (int j = 0; j < nf; j++)
                {
                    for (int k = i + 1; k < np; k++)
                        if (frameQueue[j] == pages[k])
                        {
                            positions[j] = k;
                            break;
                        }
                }
                int max = 0;
                for (int j = 0; j < nf; j++) if (positions[j] > positions[max]) max = j;
                frameQueue[max] = pages[i];
                printf("Page %d loaded into frame %d\n", pages[i], max);
            }
        }
    }
    printf("Number of page faults: %d\n", faults);
}

int main() {
    int np, nf;
    printf("Enter the number of pages: ");
    scanf("%d", &np);
    int pages[np];
    printf("Enter the page numbers: ");
    for (int i = 0; i < np; i++) scanf("%d", &pages[i]);
    printf("Enter the number of frames: ");
    scanf("%d", &nf);
    int frames[nf];
    for (int i = 0; i < nf; i++) frames[i] = -1;
    printf("1. FIFO\n2. Optimal\n3. LRU\n4. Exit\n");
    while (1) {
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                fifo(pages, np, frames, nf);
                break;
            case 2:
                optimal(pages, np, frames, nf);
                break;
            case 3:
                lru(pages, np, frames, nf);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

/*
20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
3
*/