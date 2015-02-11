/*
Server side of the program to demonstrate the endianness issue over the network.
This program demonstrates the endianness problem when you try to send 
data on the network.  It sends a data object of integer type which 
probably is of 4 bytes
Client and the Server are running on two different types of machines: client on big endian and server on little endian
Client sends a number and if the number is smaller than 'ffff' then the number is incremented by the server and if it is greater then it is decremented. 
Server sends back the number after doing increment/decrement operation.
However the intended result where the client receives the number either incremented or decremented by 1 does not happen.
*/

#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>


int main(int argc, char *argv[])
{
	int					sd;
	int					connfd;
	socklen_t 			len;
	struct sockaddr_in 	serveraddress;
	struct sockaddr_in 	cliaddr;

	unsigned int 		receivedInt;
	unsigned int 		intArray;
	unsigned int 		receivedsize;
	unsigned int 		sentsize;


	if (argc != 3) {
		printf("please provide my IP address & port as cmdline args\n");
		exit(1);
	}
	sd = socket( AF_INET, SOCK_STREAM, 0 );
	if( sd < 0 ) {
		perror( "socket" );
		exit(1);
	}
	memset( &serveraddress, 0, sizeof(serveraddress) );
	serveraddress.sin_family = AF_INET;
	serveraddress.sin_port = htons(atoi(argv[2]));//PORT NO
	if (strcmp(argv[1], "0") == 0)
		serveraddress.sin_addr.s_addr = INADDR_ANY;
	else if (strcmp(argv[1], "-1") == 0)
		serveraddress.sin_addr.s_addr = INADDR_LOOPBACK;
	else
		serveraddress.sin_addr.s_addr = inet_addr(argv[1]);//ADDRESS

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
		receivedsize = read(connfd, (unsigned char *) &intArray, sizeof(int));
		if (receivedsize != sizeof(int))
		{
			printf("data receive error \n");
			close(connfd);
		}
		receivedInt = intArray;
		printf("received integer value %x\n", receivedInt);

		/*
		Server decreases the value of the received integer from the client 
		if the value is greater than ffff else it increases the value by 1
		it tries to bring the value of the integer closer to ffff
		*/
		if (0x0000ffff < receivedInt)
		{
			receivedInt--;
			intArray = receivedInt;
		}
		else
		{
			receivedInt++;
			intArray = receivedInt;
		}
		sentsize = write(connfd, (unsigned char *)&intArray, sizeof(int));
		if (sentsize != sizeof(int))
		{
			printf("integer data could not be sent to the client \n");
			close(connfd);
		}
		printf("sent integer value %x\n", intArray);
		close(connfd);
	}
	close(sd);
}
