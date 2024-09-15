#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid=fork();
    if(pid==0) printf("Child process: PID=%d, PPID=%d\n", getpid(), getppid());
    else
    {
        printf("Parent process: PID=%d, PPID=%d\n", getpid(), getppid());
        wait(NULL);
    }
    return 0;
}
