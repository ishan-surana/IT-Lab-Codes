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
main()
{
int s,r,recb,sntb,x;
int ca;
printf("INPUT port number: ");
scanf("%d",&x);
socklen_t len;
struct sockaddr_in server,client;
char buff[50];
s=socket(AF_INET,SOCK_DGRAM,0);
if(s==-1)
{
printf("\nSocket creation error.");
exit(0);
}
printf("\nSocket created!");
server.sin_family=AF_INET;
server.sin_port=htons(x);
server.sin_addr.s_addr=htonl(INADDR_ANY);
len=sizeof(client);
ca=sizeof(client);
r=bind(s,(struct sockaddr*)&server,sizeof(server));
if(r==-1)
{
printf("\nBinding error!");
exit(0);
}
printf("\nSocket binded!");
while (1) {
recb=recvfrom(s,buff,sizeof(buff),0,(struct sockaddr*)&client,&ca);
if(recb==-1)
{
printf("Message Recieving Failed!");
close(s);
exit(0);
}
printf("Message Recieved:- ");
printf("%s",buff);
if(!strcmp(buff,"stop"))
{
printf("\n");
break;
}
printf("\n\nSend Reply:- ");
fflush(stdin);
gets(buff);
sntb=sendto(s,buff,sizeof(buff),0,(struct sockaddr*)&client, len);
if(sntb==-1)
{
printf("\nMessage Sending Failed!");
close(s);
exit(0);
}
if(!strcmp(buff,"stop"))
{
printf("\n");
break;
}
}
close(s);
}
