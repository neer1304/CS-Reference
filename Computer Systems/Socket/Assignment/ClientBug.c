/*ReadME : testclient.c
*	DESCRIPTION: A client sends a string to a Server and it exits.
*	The client accepts the IP Address, String via Cmd Line.
*	Invoke the Executable as  client IPAddress String
*	The server simply displays the recived string.  
*	You need to check the errors which are there in the code, fix them and
*	Execute it. 
*****************************************************************************/
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<errno.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<fcntl.h>
#define SERVERPORT 34125


int main( int C, char *V[] )
{
	int	sd;
	struct	sockaddr_in serveraddress;
	
	sd = socket( AF_INET, SOCK_STREAM, 0 );
	if( sd < 0 ) {
		perror( "socket" );
		exit( 1 );
	}

	if (V[1] == NULL ) {
		printf ("PL specfiy the IP address of the server. \n");
		exit(0);
	}
	if (V[2] == NULL ) {
		printf ("PL specfiy the String to be sent \n");
		exit(0);
	}

	memset( &serveraddress, 0, sizeof(serveraddress) );
	serveraddress.sin_family = AF_INET;
	serveraddress.sin_port = htons(SERVERPORT);//PORT NO
	serveraddress.sin_addr.s_addr = inet_addr(V[1]);//ADDRESS

	if(connect(sd,
		   (struct sockaddr*)&serveraddress,
		   sizeof(serveraddress)) < 0)
	{
		printf("Cannot Connect to server");
		exit(1);
	}

	write(sd,V[2],strlen(V[2]));
        close(sd);
	return 0;
}




