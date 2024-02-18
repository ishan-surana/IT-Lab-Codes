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
#include<string.h>
char* stringbuff(char s[])
{
char copy[100];
strcpy(copy,s);
char rs[100];
strrev(s);
strcpy(rs,s),
strrev(s);
if(strcmp(s,rs)==0) strcat(s,"String is a palindrome. ");
else strcat(s, "String is NOT a palindrome. ");
strcat(s,"Length of the string is ");
strcat(s, strlen(s));
strcat(s, ". ");
int a=0,e=0,i=0,o=0,u=0;
for(int j=0;j<strlen(copy);j++)
{
if(copy[j]=='a' || copy[j]=='A') a++;
if(copy[j]=='e' || copy[j]=='E') e++;
if(copy[j]=='i' || copy[j]=='I') i++;
if(copy[j]=='o' || copy[j]=='O') o++;
if(copy[j]=='u' || copy[j]=='U') u++;
}
strcat(s, "Counts of A=");
strcat(s, a);
strcat(s, ", E=");
strcat(s, e);
strcat(s, ", I=");
strcat(s, i);
strcat(s, ", O=");
strcat(s, o);
strcat(s, ", U=");
strcat(s, u);
strcat(s, ".");
return s;
}
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
char response[100];
strcpy(response,stringfunc(buff));
sntb=sendto(s,response,sizeof(response),0,(struct sockaddr*)&client, len);
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
