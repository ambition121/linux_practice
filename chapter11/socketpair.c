#include<stdio.h>
#include<sys/socket.h>
#define DATA1 "Fine thanks,and you "
#define DATA2 "How are you "
int main(void)
{
	int sockets[2],child;
	char buf[1024];

	/*creat socketpair*/
	if(socketpair(AF_UNIX,SOCK_STREAM,0,sockets) < 0)
		perror("socketpaif error");

	/*creat child's process*/
	if((child = fork()) == -1)
		perror("fork error");
	if(child != 0){	//this is parent
		close(sockets[0]);//close child's socket

		/*read message from child*/
		if(read(sockets[1],buf,sizeof(buf)) < 0)
			perror("reading socket error");
		printf("parent %d received request:%s\n",getpid(),buf);

		/*write message to child*/
		if(write(sockets[1],DATA1,sizeof(DATA1)) < 0)
			perror("write socket error");
		close(sockets[1]);	//end
	
	}
	else{	//this is child
	close(sockets[1]); //close parent's socket

	/*write message to parent*/
	if(write(sockets[0],DATA2,sizeof(DATA2)) < 0)
		perror("write socket error");

	/*read message from parent */
	if(read(sockets[0],buf,sizeof(buf)) < 0)
		perror("reading socket error");
	printf("child process %d received answer:%s\n",getpid(),buf);
	close(sockets[0]);
	}
}
