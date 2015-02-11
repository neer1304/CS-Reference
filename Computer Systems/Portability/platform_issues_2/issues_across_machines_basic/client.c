/*
Client side of the program to demonstrate the endianness issue over the network
The detailed explanation is provided in the server.c file
*/

#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>

int main(int argc, char *argv[]) 
{
	int					sd = 0;
	struct	sockaddr_in serveraddress;
	unsigned int 		sentsize;
	unsigned int 		receivedsize;
	unsigned int 		intArray;
	unsigned int 		sentvalue;
	unsigned char * 	pChar = (unsigned char *)&intArray;

	if (argc != 4) {
		printf("please provide following command line arguments\n");
		printf("server IP address\n");
		printf("server port\n");
		printf("the numner to be sent \n");
		exit(1);
	}
	sd = socket(AF_INET, SOCK_STREAM, 0);
	if( sd < 0 ) {
		perror( "socket" );
		exit( 1 );
	}

	//the integer to be sent to the server
	intArray  = atoi(argv[3]);
	sentvalue = intArray;

	memset( &serveraddress, 0, sizeof(serveraddress) );
	serveraddress.sin_family = AF_INET;
	serveraddress.sin_port = htons(atoi(argv[2]));       //PORT NO
	serveraddress.sin_addr.s_addr = inet_addr(argv[1]);  //ADDRESS
	if (0 != connect(sd,(struct sockaddr*)&serveraddress,sizeof(serveraddress)))
	{
		printf("cannot connect to server");
		close(sd);
		exit(1);
	}
	sentsize = write(sd, (unsigned char *)&intArray, sizeof(int));
	if (sentsize != sizeof(int))
	{
		printf("integer data could not be sent to server \n");
		close(sd);
		exit(1);
	}
	printf("I have sent : %x \n", intArray);
	receivedsize = read(sd, (unsigned char *) &intArray, sizeof(int));
	if (receivedsize != sizeof(int))
	{
		printf("data receive error \n");
		close(sd);
		exit(1);
	}
	if (0x0000ffff > sentvalue)
		printf("I should have received the value incremented by 1 ");
	else
		printf("I should have received the value decremented by 1 ");
	printf("but I received value %x\n", intArray);
	close(sd);
	return 0;
}
