#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void bubble_sort(char *arr[], int n) {
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(strcmp(arr[j], arr[j+1])>0) {
                char *temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
}

void selection_sort(char *arr[], int n) {
    sleep(2);
    for(int i=0;i<n-1;i++) {
        int min_idx=i;
        for(int j=i+1;j<n;j++) {
            if(strcmp(arr[j], arr[min_idx])<0) min_idx=j;
        }
        if(min_idx!=i) {
            char *temp=arr[i];
            arr[i]=arr[min_idx];
            arr[min_idx]=temp;
        }
    }
}

int main() {
    int n;
    printf("Enter n:- ");
    scanf("%d", &n);
    char *arr[n];
    printf("Enter array:- ");
    for(int i=0;i<n;i++) {
        arr[i]=(char *)malloc(100*sizeof(char));
        scanf("%s", arr[i]);
    }
    pid_t pid1=fork();
    if(pid1==0) {
        bubble_sort(arr, n);
        printf("Bubble sort result:\n");
        for(int i=0;i<n;i++) printf("%s ", arr[i]);
	    printf("\n");
        exit(0);
    }
    pid_t pid2=fork();
    if(pid2==0) {
        selection_sort(arr, n);
        printf("Selection sort result:\n");
        for(int i=0;i<n;i++) printf("%s ", arr[i]);
        printf("\n");
	    exit(0);
    }
    pid_t finished_pid = wait(NULL);
    printf("Process executed with PID = %d\n", finished_pid);
    if (finished_pid == pid1) kill(pid2, SIGKILL);
    else kill(pid1, SIGKILL);
    // wait(NULL); // Ensure we wait for the terminated child process to clean up
    return 0;
}
    /*int status;
    pid_t finished_pid;
    while(1) {
        finished_pid=waitpid(pid1, &status, WNOHANG);
        if(finished_pid==pid1 || finished_pid==pid2) break;
        finished_pid=waitpid(pid2, &status, WNOHANG);
        if(finished_pid==pid1 || finished_pid==pid2) break;
        sleep(1);
    }*/
    //return 0;
    /*int status;
    while(1) {
        pid_t finished_pid=waitpid(-1, &status, WNOHANG);
        if(finished_pid>0) break;
        sleep(1);
    }*/
    /*waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);*/
    //return 0;
