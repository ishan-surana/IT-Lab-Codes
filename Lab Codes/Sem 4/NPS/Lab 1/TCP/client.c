#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 50

main()
{
	int buff[MAXSIZE];
	int sockfd,retval,i,n;
	int recedbytes,sentbytes;
	struct sockaddr_in serveraddr;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
		printf("\nSocket Creation Error");
		return;
	}

	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(12345);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	retval=connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(retval==-1)
	{
		printf("Connection error");
		return;
	}

	printf("Enter count of numbers:- ");
	scanf("%d",&n);
	int sentsize=send(sockfd,&n,sizeof(n),0);
	int arr[n];
	printf("Enter numbers:- ");
	for(int j=0;j<n;j++) scanf("%d",&arr[j]);
	int sentarray=send(sockfd,arr,sizeof(arr),0);

	for (i = 0; ; i+=1)
	{
		printf("\n\nLoop iteration %d\n\n",i);
		memset(buff, '\0', sizeof(buff));
		printf("Enter the choice:- ");
		scanf(" %d",&buff[0]);
		sentbytes=send(sockfd,buff,sizeof(buff),0);
		if(sentbytes==-1)
		{
			printf("!!");
			close(sockfd);
		}
		memset(buff, '\0', sizeof(buff));
		recedbytes=recv(sockfd,buff,sizeof(buff),0);
		printf("Output:- ");
		for(int num=0;num<n;num++)
			printf("%d ",buff[num]);
	}
	close(sockfd);
}