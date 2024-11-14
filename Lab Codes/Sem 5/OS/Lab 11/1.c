#include <stdio.h>
#include <limits.h>
#include <math.h>

int dist(int a, int b) {
    return abs(a-b);
}

void fcfs(int requests[], int nr, int head) {
    int seekTime = 0;
    printf("FCFS:- %d", head);
    for (int i = 0; i < nr; i++) 
    {
        seekTime += dist(head, requests[i]);
        printf(" -> %d", requests[i]);
        head = requests[i];
    }
    printf("\nTotal seek time: %d\n", seekTime);
}

void sstf(int requests[], int nr, int head) {
    printf("SSTF:- %d", head);
    int seekTime = 0, visited[nr];
    for (int i = 0; i < nr; i++) visited[i] = 0;
    for (int i = 0; i < nr; i++) {
        int min = INT_MAX, minIndex = -1;
        for (int j = 0; j < nr; j++) {
            if (!visited[j] && dist(head, requests[j]) < min)
            {
                min = dist(head, requests[j]);
                minIndex = j;
            }
        }
        visited[minIndex] = 1;
        printf(" -> %d", requests[minIndex]);
        seekTime += min;
        head = requests[minIndex];
    }
    printf("\nTotal seek time: %d\n", seekTime);
}

void scan(int requests[], int nr, int head, int tail) {
    int seekTime = 0, visited[nr];
    for (int i = 0; i < nr; i++) visited[i] = 0;
    int direction = tail-head<head?1:-1;
    // sort the requests
    int requestsCopy[nr+1];
    for (int i = 0; i < nr; i++) requestsCopy[i] = requests[i];
    requestsCopy[nr] = direction == 1?tail:0;
    for (int i = 0; i < nr; i++)
        for (int j = 0; j < nr-i; j++)
            if (requestsCopy[j] > requestsCopy[j+1])
            {
                int temp = requestsCopy[j];
                requestsCopy[j] = requestsCopy[j+1];
                requestsCopy[j+1] = temp;
            }
    printf("SCAN:- %d", head);
    int i, headIndex;
    for (i = 0; i < nr; i++)
        if (requestsCopy[i] <= head && requestsCopy[i+1] >= head) {
            headIndex = i;
            break;
        }
    // first go in direction until the end (tail or head)
    while (i >= 0 && i <= nr)
    {
        printf(" -> %d", requestsCopy[i]);
        seekTime += dist(head, requestsCopy[i]);
        head = requestsCopy[i];
        i += direction;
    }
    // then go in the opposite direction until the end (tail or head)
    direction *= -1;
    i = headIndex + direction;
    while (i >= 0 && i <= nr)
    {
        printf(" -> %d", requestsCopy[i]);
        seekTime += dist(head, requestsCopy[i]);
        head = requestsCopy[i];
        i += direction;
    }
    printf("\nTotal seek time: %d\n", seekTime);
}

void cscan(int requests[], int nr, int head, int tail) {
    int seekTime = 0, visited[nr];
    for (int i = 0; i < nr; i++) visited[i] = 0;
    int direction = tail-head<head?1:-1;
    // sort the requests
    int requestsCopy[nr];
    for (int i = 0; i < nr; i++) requestsCopy[i] = requests[i];
    for (int i = 0; i < nr - 1; i++)
        for (int j = 0; j < nr-i-1; j++)
            if (requestsCopy[j] > requestsCopy[j+1])
            {
                int temp = requestsCopy[j];
                requestsCopy[j] = requestsCopy[j+1];
                requestsCopy[j+1] = temp;
            }
    printf("C-SCAN:- %d", head);
    int i, headIndex;
    for (i = 0; i < nr - 1; i++)
        if (requestsCopy[i] <= head && requestsCopy[i+1] >= head) {
            headIndex = i;
            break;
        }
    while (head != requestsCopy[(headIndex-direction)%nr])
    {
        printf(" -> %d", requestsCopy[i]);
        seekTime += dist(head, requestsCopy[i]);
        if ((i == 0 && direction == -1) || (i == nr-1 && direction == 1)) {
            seekTime += dist(requestsCopy[i], 0);
            printf(" -> 0");
            printf(" -> %d", tail);
            seekTime += dist(tail, requestsCopy[nr-1]);
            i = direction == 1?0:nr-1;
        }
        else if ((i == 0 && direction == 1) || (i == nr-1 && direction == -1)) {
            seekTime += dist(requestsCopy[i], tail);
            printf(" -> %d", tail);
            printf(" -> 0");
            seekTime += dist(0, requestsCopy[0]);
            i = direction == 1?0:nr-1;
        }
        head = requestsCopy[i];
        i = (i+direction)%nr;
    }
    printf("\nTotal seek time: %d\n", seekTime);
}

void look(int requests[], int nr, int head, int tail) {
    int seekTime = 0, visited[nr];
    for (int i = 0; i < nr; i++) visited[i] = 0;
    int direction = tail-head<head?1:-1;
    // sort the requests
    int requestsCopy[nr];
    for (int i = 0; i < nr; i++) requestsCopy[i] = requests[i];
    for (int i = 0; i < nr-1; i++)
        for (int j = 0; j < nr-i-1; j++)
            if (requestsCopy[j] > requestsCopy[j+1])
            {
                int temp = requestsCopy[j];
                requestsCopy[j] = requestsCopy[j+1];
                requestsCopy[j+1] = temp;
            }
    printf("LOOK:- %d", head);
    int i, headIndex;
    for (i = 0; i < nr-1; i++)
        if (requestsCopy[i] <= head && requestsCopy[i+1] >= head) {
            headIndex = i;
            break;
        }
    // first go in direction until the end (tail or head)
    while (i >= 0 && i < nr)
    {
        printf(" -> %d", requestsCopy[i]);
        seekTime += dist(head, requestsCopy[i]);
        head = requestsCopy[i];
        i += direction;
    }
    // then go in the opposite direction until the end (tail or head)
    direction *= -1;
    i = headIndex + direction;
    while (i >= 0 && i < nr)
    {
        printf(" -> %d", requestsCopy[i]);
        seekTime += dist(head, requestsCopy[i]);
        head = requestsCopy[i];
        i += direction;
    }
    printf("\nTotal seek time: %d\n", seekTime);
}

void clook(int requests[], int nr, int head, int tail) {
    int seekTime = 0, visited[nr];
    for (int i = 0; i < nr; i++) visited[i] = 0;
    int direction = tail-head<head?1:-1;
    // sort the requests
    int requestsCopy[nr];
    for (int i = 0; i < nr; i++) requestsCopy[i] = requests[i];
    for (int i = 0; i < nr - 1; i++)
        for (int j = 0; j < nr-i-1; j++)
            if (requestsCopy[j] > requestsCopy[j+1])
            {
                int temp = requestsCopy[j];
                requestsCopy[j] = requestsCopy[j+1];
                requestsCopy[j+1] = temp;
            }
    printf("C-LOOK:- %d", head);
    int i, headIndex;
    for (i = 0; i < nr - 1; i++)
        if (requestsCopy[i] <= head && requestsCopy[i+1] >= head) {
            headIndex = i;
            break;
        }
    while (head != requestsCopy[(headIndex-direction)%nr])
    {
        printf(" -> %d", requestsCopy[i]);
        seekTime += dist(head, requestsCopy[i]);
        if ((i == 0 && direction == -1) || (i == nr-1 && direction == 1)) {
            printf(" -> 0");
            printf(" -> %d", tail);
            i = direction == 1?0:nr-1;
        }
        else if ((i == 0 && direction == 1) || (i == nr-1 && direction == -1)) {
            printf(" -> %d", tail);
            printf(" -> 0");
            i = direction == 1?0:nr-1;
        }
        head = requestsCopy[i];
        i = (i+direction)%nr;
    }
    printf("\nTotal seek time: %d\n", seekTime);
}

int main() {
    int nr, head, tail;
    printf("Enter the number of requests: ");
    scanf("%d", &nr);
    int requests[nr];
    printf("Enter the request queue: ");
    for (int i = 0; i < nr; i++) scanf("%d", &requests[i]);
    printf("Enter the head position: ");
    scanf("%d", &head);
    printf("Enter the tail position: ");
    scanf("%d", &tail);
    printf("1. FCFS\n2. SSTF\n3. SCAN\n4. C-SCAN\n5. LOOK\n6. C-LOOK\n7. Exit\n");
    while(1)
    {
        printf("\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                fcfs(requests, nr, head);
                break;
            case 2:
                sstf(requests, nr, head);
                break;
            case 3:
                scan(requests, nr, head, tail);
                break;
            case 4:
                cscan(requests, nr, head, tail);
                break;
            case 5:
                look(requests, nr, head, tail);
                break;
            case 6:
                clook(requests, nr, head, tail);
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

/*
8
95 180 34 119 11 123 62 64
50
199
*/