/*
Client side of the program to demonstrate the endianness issue over the network
The detailed explanation is provided in the server.c file
*/


#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>

#include	"prototype.h"

unsigned int	globalVar = 10;


int main(int argc, char *argv[]) 
{
	int			sd = 0;
	unsigned int 		sentsize;
	unsigned int 		receivedsize;
	datatobeexchanged 	receivedvalue;
	datatobeexchanged	sentvalue;

	struct	sockaddr_in 	serveraddress;

	if (argc != 7) {
		printf("please provide following command line arguments\n");
		printf("server IP address\n");
		printf("server port\n");
		printf("the data to be sent \n");
		exit(1);
	}
	sd = socket(AF_INET, SOCK_STREAM, 0);
	if( sd < 0 ) {
		perror( "socket" );
		exit( 1 );
	}

	//the data to be sent to the server
	sentvalue.firstmember     = atoi(argv[3]);
	sentvalue.secondmember    = atoi(argv[4]);
	sentvalue.thirdmember[0]  = atoi(argv[5]);
	sentvalue.thirdmember[1]  = atoi(argv[6]);
	sentvalue.sixthmember[0]  = atoi(argv[5]);
	sentvalue.sixthmember[1]  = atoi(argv[6]);
	sentvalue.pIntVar         = &globalVar; 
	sentvalue.pCharVar        = (unsigned char *)malloc(32);
	strcpy(sentvalue.pCharVar, "will it reach the server?");

	memset( &serveraddress, 0, sizeof(serveraddress) );
	serveraddress.sin_family = AF_INET;
	serveraddress.sin_port   = htons(atoi(argv[2]));    //SERVER TCP PORT
	serveraddress.sin_addr.s_addr = inet_addr(argv[1]); //SERVER IP ADDRESS
	if (0 != connect(sd,(struct sockaddr*)&serveraddress,sizeof(serveraddress)))
	{
		printf("cannot connect to server");
		close(sd);
		exit(1);
	}
	sentsize = write(sd, (unsigned char *)&sentvalue, sizeof(datatobeexchanged));
	if (sentsize != sizeof(datatobeexchanged))
	{
		printf("integer data could not be sent to server \n");
		close(sd);
		exit(1);
	}

	printf("size of sent structure of %d \n", sizeof(datatobeexchanged));

	/*
	Endianness problem for the integer types as they are bigger than a byte
	*/

	printf("sent value int type first member  : %x\n", sentvalue.firstmember);
	printf("sent value int type second member : %x\n", sentvalue.secondmember);

	/*
	No endianness problem with the character types as their sizes are 
	equal to a byte 
	*/

	printf("sent value char type third member[0] : %x\n", sentvalue.thirdmember[0]);
	printf("sent value char type third member[1] : %x\n", sentvalue.thirdmember[1]);

	/*
	However for the character types if the offset of the member in 
	the structure is not equal on two different machines then the 
	reception is incorrect
	*/

	printf("sent value char type sixth member[0] : %x\n", sentvalue.sixthmember[0]);
	printf("sent value char type sixth member[1] : %x\n", sentvalue.sixthmember[1]);


	/*
	Pointer to a variable in the program can't be sent to another program
	*/

	printf("sent value integer (pointer to a global variable) : %x\n", *sentvalue.pIntVar);

	/*
	By sending a pointer to a dynamically allocated area on the 
	IPC channel will not transmit the dynamically allocated memory bytes
	to the other process
	*/

	printf("sent value character string : %s\n", sentvalue.pCharVar);


	close(sd);
	return 0;
}
