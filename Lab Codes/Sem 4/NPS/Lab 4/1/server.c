#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	int s,r,recb,sntb,x,ns,a=0;
	printf("INPUT port number: ");
	scanf("%d", &x);
	socklen_t len;
	struct sockaddr_in server,client;
	char buff[50],buff1[50];

	s=socket(AF_INET,SOCK_STREAM,0);
	if(s==-1)
	{
		printf("\nSocket creation error.");
		exit(0);
	}
	printf("\nSocket created.");

	server.sin_family=AF_INET;
	server.sin_port=htons(x);
	server.sin_addr.s_addr=htonl(INADDR_ANY);

	r=bind(s,(struct sockaddr*)&server,sizeof(server));
	if(r==-1)
	{
		printf("\nBinding error.");
		exit(0);
	}
	printf("\nSocket binded.");

	r=listen(s,8);
	if(r==-1)
	{
		close(s);
		exit(0);
	}
	printf("\nSocket listening. Waiting for connections..");
	len=sizeof(client);

	ns=accept(s,(struct sockaddr*)&client, &len);
	if(ns==-1)
	{
		close(s);
		exit(0);
	}
	printf("\nSocket accepting.\n\nEnter binary data: ");
	scanf("%s",buff1);
	buff[0]='0';
	buff[1]='\0';
	strcat(buff,buff1);
	buff[strlen(buff)]='\0';
	sntb=send(ns,buff,sizeof(buff),0);
	if(sntb==-1)
	{
		printf("\nMessage Sending Failed");
		close(s);
		close(ns);
		exit(0);
	}
	recb=recv(ns,buff,sizeof(buff),0);
	if(recb==-1)
	{
		printf("\nMessage Recieving Failed");		
		close(s);
		close(ns);
		exit(0);
	}
	printf("\nClient message => %s",buff);

	close(ns);
	close(s);
}