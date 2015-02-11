/*
This program demonstrates various types of problems which you may encounter when you try to send data on the network/IPC, especially composite types like user defined structures.

There are two programs here: Client and the Server.
They are running on two different types of machines.
Client sends a structure as an opaque type through socket based IPC to the Server. They both print the values (value sent by the client and the values received by the server) 

1. It demonstrates the endianness problem for the types which are bigger than a byte (say a 32 bit integer)

2. It also demonstrates the problem which may occur due to the fact that the sizes of a data type may be different on two different machines. 
It may lead to different offsets for a member inside a structure on two different machines leading to incorrect reception of values.

3. It also demonstrates that a pointer can't be sent acrosss IPC channels
*/

#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>

#include	"prototype.h"


int main(int argc, char *argv[])
{
	int			sd;
	int			connfd;
	socklen_t 		len;
	struct sockaddr_in 	serveraddress;
	struct sockaddr_in 	cliaddr;

	unsigned int 		receivedsize;
	unsigned int 		sentsize;
	datatobeexchanged 	receivedvalue;
	datatobeexchanged	sentvalue;


	if (argc != 2) {
		printf("please provide my tcp port no as cmdline arg\n");
		exit(1);
	}
	sd = socket( AF_INET, SOCK_STREAM, 0 );
	if( sd < 0 ) {
		perror( "socket" );
		exit(1);
	}
	memset( &serveraddress, 0, sizeof(serveraddress) );
	serveraddress.sin_family = AF_INET;
	serveraddress.sin_port = htons(atoi(argv[1]));//PORT NO
	serveraddress.sin_addr.s_addr = INADDR_ANY;

	bind(sd,(struct sockaddr*)&serveraddress,sizeof(serveraddress));

	listen(sd,5);

	for(;;)
	{
		printf("I am waiting for a connection\n");
		len=sizeof(cliaddr);
		connfd=accept(sd,(struct sockaddr*)&cliaddr,&len);
		if (connfd < 0)
		{
			continue;
		}
		printf("a client has connected\n");
		receivedsize = read(connfd, (unsigned char *) &receivedvalue, sizeof(datatobeexchanged));
		if (receivedsize != sizeof(datatobeexchanged))
		{
			printf("data receive error \n");
			close(connfd);
		}

		printf("size of received structure of %d \n", sizeof(datatobeexchanged));
		printf("recvd value int type first member  : %x\n", receivedvalue.firstmember);
		printf("recvd value int type second member : %x\n", receivedvalue.secondmember);
		printf("recvd value char type third member[0] : %x\n", receivedvalue.thirdmember[0]);
		printf("recvd value char type third member[1] : %x\n", receivedvalue.thirdmember[1]);
		printf("recvd value char type sixth member[0] : %x\n", receivedvalue.sixthmember[0]);
		printf("recvd value char type sixth member[1] : %x\n", receivedvalue.sixthmember[1]);
		printf("recvd value character string : %s\n", receivedvalue.pCharVar);
		printf("recvd value integer (pointer to a global variable) : %x\n", *receivedvalue.pIntVar);
		close(connfd);
	}
	close(sd);
}
