#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define MAXSIZE 5500

main()
{
int sockfd,newsockfd,retval;
socklen_t actuallen;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr,clientaddr;
pid_t pid;
char buff[MAXSIZE],receivemsg[5500];
char rmessage[MAXSIZE],smessage[MAXSIZE];
int a=0;
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1)
printf("\nSocket creation error");
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(3388);
serveraddr.sin_addr.s_addr=htons(INADDR_ANY);
retval=bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(retval==1)
{
printf("Binding error");
close(sockfd);
}
retval=listen(sockfd,1);
if(retval==-1)
close(sockfd);

actuallen=sizeof(clientaddr);
newsockfd=accept(sockfd,(struct sockaddr*)&clientaddr,&actuallen);

pid =fork();
if(pid==0)
while(1)
{
recedbytes=recv(newsockfd,receivemsg,sizeof(receivemsg), MSG_WAITALL);
if(strcmp(receivemsg, "exit")==0) break;
strcpy(smessage,"Received message:- ");
strcat(smessage, receivemsg);
puts(smessage);
if(strcmp(buff, "exit")==0) break;
}

else if (pid>0)
while(1)
{
gets(buff);
strcpy(rmessage,"Received message:- ");
strcat(rmessage, buff);
sentbytes=send(newsockfd,rmessage,sizeof(rmessage),0);
if(strcmp(receivemsg, "exit")==0) break;
if(strcmp(buff, "exit")==0) break;
}

if(newsockfd==-1)
close(sockfd);
if(sentbytes==-1)
{
close(sockfd);
close(newsockfd);
}
close(sockfd);
close(newsockfd);
}
