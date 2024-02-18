#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define MAXSIZE 90

main()
{
	int sockfd,newsockfd,retval,i,n;
	socklen_t actuallen;
	int recedbytes,sentbytes;
	struct sockaddr_in serveraddr,clientaddr;
	int buff[MAXSIZE];
	
	int a=0;
	sockfd=socket(AF_INET,SOCK_STREAM,0);

	if(sockfd==-1)
	{
	printf("\nSocket creation error");
	}

	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(12345);
	serveraddr.sin_addr.s_addr=htons(INADDR_ANY);
	retval=bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(retval==1)
	{
		printf("Binding error");
		close(sockfd);
	}

	retval=listen(sockfd,1);
	if(retval==-1)
	{
	close(sockfd);
	}
	actuallen=sizeof(clientaddr);
	newsockfd=accept(sockfd,(struct sockaddr*)&clientaddr,&actuallen);
	if(newsockfd==-1)
	{
		close(sockfd);
	}
	
	printf("Received count of numbers:- ");
	int recvsize=recv(newsockfd,&n,sizeof(n),0);
	printf("%d\n",n);
	int arr[n];
	printf("Received numbers:- ");
	int recvarray=recv(newsockfd,arr,sizeof(arr),0);
	for(int j=0;j<n;j++) printf("%d ",arr[j]);
	printf("\n");

	for (i = 0; ; i+=1)
	{
		printf("\n\nLoop iteration %d\n\n",i);
		memset(buff, '\0', sizeof(buff));
		recedbytes=recv(newsockfd,buff,sizeof(buff),0);
		if(recedbytes==-1)
		{
			close(sockfd);
			close(newsockfd);
		}
		
		if(buff[0]==1)
		{
			memset(buff, '\0', sizeof(buff));
			for(int a=0;a<n;a++)
			{
    			for(int b=1;b<(n-a);b++)
    			{
        			if(arr[b]<arr[b-1])
        			{
            			char temp=arr[b];
            			arr[b]=arr[b-1];
            			arr[b-1]=temp;
        			}
    			}
			}
			for(int num=0;num<n;num++)
			buff[num]=arr[num];
			printf("\nOIOIOI ");
			for(int num=0;num<n;num++)
			printf("%d ",buff[num]);
		}
		else if(buff[1]=='2')
		{
			memset(buff, '\0', sizeof(buff));
			for(int a=0;a<n;a++)
			{
    			for(int b=1;b<(n-a);b++)
    			{
        			if(arr[b]<arr[b-1])
        			{
            			char temp=arr[b];
            			arr[b]=arr[b-1];
            			arr[b-1]=temp;
        			}
    			}
			}
			for(int num=0;num<n;num++)
			buff[num]=arr[num];
		}
		else if(buff[1]=='3')
		{
			memset(buff, '\0', sizeof(buff));
			for(int a=0;a<n;a++)
			{
    			for(int b=1;b<(n-a);b++)
    			{
        			if(arr[b]<arr[b-1])
        			{
            			char temp=arr[b];
            			arr[b]=arr[b-1];
            			arr[b-1]=temp;
        			}
    			}
			}
			for(int num=0;num<n;num++)
				buff[num]=arr[num];
		}
		else break;

		sentbytes=send(newsockfd,buff,sizeof(buff),0);
		if(sentbytes==-1)
		{
			close(sockfd);
			close(newsockfd);
		}
	}
	close(sockfd);
	close(newsockfd);
}