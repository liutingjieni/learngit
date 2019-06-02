#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 4507
#define MAXSU 1024

pthread_t tid[2];

struct info{
	int  num;
	char buf[1024];
};

void my_err(const char*err_string , int line)
{
	fprintf(stderr,"line:%d",line);
	perror(err_string);
	exit(1);
}

void *my_send(void *conn_fd)
{
	struct info sendbuff = {0};
	int ret,oldtype;
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,&oldtype);
	while(1)
	{
		scanf("%s %d",sendbuff.buf,&sendbuff.num);
		if((ret = send(*(int *)conn_fd , &sendbuff , sizeof(struct info) , 0)) < 0)
			my_err("send",__LINE__);
		if(!strcmp(sendbuff.buf,"bye"))
		{
			close(*(int*)conn_fd);
			pthread_cancel(tid[1]);
			break;
		}
		memset(&sendbuff,0,sizeof(sendbuff));
	}
}

void *my_recv(void *conn_fd)
{
	struct info recvbuff = {0};
	int ret;

	while(1)
	{
		if((ret = recv(*(int*)conn_fd , &recvbuff , sizeof(struct info) , 0)) < 0)
			my_err("recv",__LINE__);
		printf("\n%s\n",recvbuff.buf);
		memset(&recvbuff,0,sizeof(struct info));
	}
}

int main(int argc , char *argv[])
{
	int sock_fd , ret;
	int haha;
	struct sockaddr_in seve;
	if((sock_fd = socket(AF_INET,SOCK_STREAM,0)) < 0)
		my_err("socket",__LINE__);
	seve.sin_family = AF_INET;
	seve.sin_port = htons(PORT);
	seve.sin_addr.s_addr = htonl(INADDR_ANY);
	if(connect(sock_fd,(struct sockaddr*)&seve,sizeof(struct sockaddr_in)) < 0)
		my_err("connect",__LINE__);
	recv(sock_fd,&haha , sizeof(int) , 0);
	printf("编号:%d\n",haha);
	if((ret = pthread_create(&tid[0],NULL,my_send,(void*)&sock_fd)) < 0)
		my_err("pthread_creat",__LINE__);
	if((ret = pthread_create(&tid[1],NULL,my_recv,(void*)&sock_fd)) < 0)
		my_err("pthread_creat",__LINE__);
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	return 0;
}
