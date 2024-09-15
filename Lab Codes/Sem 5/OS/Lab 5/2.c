#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void sort_strings(char *arr[], int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(strcmp(arr[i], arr[j])>0)
            {
                char *temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
}

int main(int argc, char *argv[]) {
    pid_t pid=fork();
    if(pid==0)
    {
        sort_strings(&argv[1], argc-1);
        printf("Sorted strings:\n");
        for(int i=1;i<argc;i++) printf("%s ", argv[i]);
        printf("\n");
	    exit(0);
    }
    else
    {
        wait(NULL);
        printf("Unsorted strings:\n");
        for(int i=1;i<argc;i++) printf("%s ", argv[i]);
	    printf("\n");
    }
    return 0;
}
