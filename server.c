#include <socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/stat.h>



void request(int client)
{
		char buff[1024];


		
}


/*get the listen fd*/
int getListenSocket()
{
		struct sockaddr_in server;
		unsigned short port = 8888;
		int sock;

		if((sock = socket(AF_INET,SOCK_STREAM,0)<0)
				perror("socket");

		memset(server,0,sizeof(sock));
		server.sin_family = AF_INET;
		server.sin_port = htons(port);
		server.sin_addr.s_addr = htonl(INADDR_ANY);

		if(bind(sock,(struct sockaddr)&server,sizeof(server)<0)
				perror("bind");

		if(listen(sock,5)<0)
				perror("listen");

		return sock;
}


		


int main(void)
{
		struct sockaddr client;
		int server_sock;
		socklen_t len = sizeof(struct sockaddr);
		pthread_t pthread;
		
		server_sock = getListenSocket();
		

		for(;;)
		{
			if((accept(server_sock,(struct sockaddr)&client,&len)) <0)
					err_quit("accpet");

			if(pthread_create(&pthread,NULL,request,NULL)!=0)
					perror("pthread_create");

			
		}
		close(server_sock);

		exit(0);
}


		
