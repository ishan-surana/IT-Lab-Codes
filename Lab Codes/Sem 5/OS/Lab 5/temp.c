#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#define BUFLEN 10
int main(void)
{
int i;
char buffer[BUFLEN+1];
pid_t pid1;
pid1 = fork( );
int fork_return = pid1;
if (pid1 == 0)
{ strncpy(buffer, "CHILD\n", BUFLEN); /*in the child process*/
buffer[BUFLEN] = '\0';
}
else if(fork_return > 0) // for parent process
{
strncpy(buffer, "PARENT\n", BUFLEN); /*in the parent process*/
buffer[BUFLEN] = '\0';
}
else if(fork_return == -1)
{
printf("ERROR:\n");
switch (errno)
{
case EAGAIN:
printf("Cannot fork process: System Process Limit Reached\n");
case ENOMEM:
printf("Cannot fork process: Out of memory\n");
}
return 1;
}
for (i=0; i<5; ++i) /*both processes do this*/
{
sleep(1); /*5 times each*/
printf("%s", buffer);
}
return 0;
}

