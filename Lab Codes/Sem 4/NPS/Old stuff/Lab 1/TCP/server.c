#include<string.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<sys/stat.h>
void main()
{
int s,r,recb,sntb,x,ns,a=0;
printf("INPUT port number:- ");
scanf("%d",&x);
socklen_t len;
struct sockaddr_in server,client;
char buff[50];
s=socket(AF_INET,SOCK_STREAM,0);
if(s==-1)
{
printf("\nSocket creation error!");
exit(0);
}
printf("\nSocket created!");
server.sin_family=AF_INET;
server.sin_port=htons(x);
server.sin_addr.s_addr=htonl(INADDR_ANY);
r=bind(s,(struct sockaddr*)&server,sizeof(server));
if(r==-1)
{
printf("\nBinding error!");
exit(0);
}
printf("\nSocket binded!");
r=listen(s,1);
if(r==-1)
{
close(s);
exit(0);
}
printf("\nSocket listening...");
len=sizeof(client);
ns=accept(s,(struct sockaddr*)&client,&len);
if(ns==-1)
{
close(s);
exit(0);
}
printf("\nSocket accepting...\n");

recb=recv(ns,buff,sizeof(buff),0);
if(recb==-1)
{
printf("\nMessage Recieving Failed!");
close(s);
close(ns);
exit(0);
}

printf("Buffer is :-");
puts(buff);
sntb=send(ns,buff,sizeof(buff),0);
if(sntb==-1)
{
printf("\nMessage Sending Failed!");
close(s);
close(ns);
exit(0);
}

int choice;
while(1)
{
recb=recv(ns,&choice,sizeof(choice),0);
if(recb==-1)
{
printf("\nMessage Recieving Failed!");
close(s);
close(ns);
exit(0);
}
char retbuff[50];
switch(choice)
{
case 1:
    char key;
    recb=recv(ns,&key,sizeof(key),0);
    if(recb==-1)
    {
    close(s);
    close(ns);
    exit(0);
    }
    int i,flag=0;
    for(i=0;i<strlen(buff);i++)
    {
        if(key==buff[i])
        {
            flag=1;
            break;
        }
    }
        if(!flag) strcpy(retbuff,"FOUND!");
        else strcpy(retbuff,"NOT FOUND!");
    break;
}
sntb=send(ns,retbuff,sizeof(retbuff),0);
sntb=send(ns,retbuff,sizeof(retbuff),0);
//puts(retbuff);
if(sntb==-1)
{
printf("\nMessage Sending Failed!");
close(s);
close(ns);
exit(0);
}
}
close(ns);
close(s);
}