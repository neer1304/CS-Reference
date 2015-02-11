/*ReadME :testserver.c 
	DESCRIPTION: A  server,that will accept a string from the client.
*	You need to correct the code, so that it prints the string received 
*	from the client.
****************************************************************************/


#include	<stdio.h>
#include	<stdlib.h>
#include	<errno.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<sys/wait.h>
#include	<fcntl.h>
#include	<unistd.h>
#define MYPORT 34125

void signal_handler(int code)
{
exit(0);
}

void signal_handler1(int code)
{
exit(0);
}

int main( int C, char *V[] )
{
	signal(SIGINT,signal_handler);
	signal(SIGTSTP,signal_handler1);

	int	sd,connfd;
	struct	sockaddr_in
		serveraddress,cliaddr;
	socklen_t len;
	char buf[100],databuf[1024];

	sd = socket( AF_INET, SOCK_STREAM, 0 );
	if( sd < 0 ) {
		perror( "socket" );
		exit( 1 );
	}

	memset( &serveraddress, 0, sizeof(serveraddress) );
	serveraddress.sin_family = AF_INET;
	serveraddress.sin_port = htons(MYPORT);//PORT NO
	serveraddress.sin_addr.s_addr = htonl(INADDR_ANY);//ADDRESS
	bind(sd,(struct sockaddr*)&serveraddress,sizeof(serveraddress));
	
	/*Beginning of the Main Server Processing Loop*/
	listen(sd,5);	
	for(;;)
	{
		printf("I am waiting-----Start of Main Loop\n");
		len=sizeof(cliaddr);
		connfd=accept(sd,(struct sockaddr*)&cliaddr,&len);
		/*Got the Connection Socket Above*/
		if ( connfd < 0)
		{
			if (errno == EINTR) 
			printf("Interrupted system calli\n");
			continue;
		}
		printf("Connection from %s\n",
			inet_ntop(AF_INET,&cliaddr.sin_addr,buf,sizeof(buf)));
			
			read(connfd,databuf, 1024);
			/*databuf Now contains the string*/
			
			printf("Received %s\n", databuf);
			close(connfd);
			printf("Finished Serving one client\n");
	}
	
}


