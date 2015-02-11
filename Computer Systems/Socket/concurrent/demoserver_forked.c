/**********************************************************************
*	FILENAME :demoserverfrk.c
*	DESCRIPTION:Contains Code for a  server,that will accept 
*       a string from a client process , prints the string and the 
*	IP Address of the client .(Shows a typical FORKED SERVER )
*	Invoke the Executable as a.out   
*	Copyright 2007 Aricent 
*********************************************************************/


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

#define DATABUF 1024
#define BUFSIZE 512
#define MYPORT 16651 /*The port users will be connecting to*/

void readstring(int,char *);

int main(int C, char *V[] )
{
	int	listensocket,connectionsocket,retchild,binderror;
	struct	sockaddr_in
		serveraddress,cliaddr;
	socklen_t len;
	char buf[100],databuf[DATABUF];

	listensocket = socket(AF_INET, SOCK_STREAM, 0 );
	if (listensocket < 0 ) 
	{
		perror("socket" );
		exit(1 );
	}

	memset(&serveraddress, 0, sizeof(serveraddress) );
	serveraddress.sin_family = AF_INET;
	serveraddress.sin_port = htons(MYPORT);/*PORT NO*/
	serveraddress.sin_addr.s_addr = htonl(INADDR_ANY);/*ADDRESS*/
	bind(listensocket,(struct sockaddr*)&serveraddress,
		sizeof(serveraddress));
	if(-1 == binderror)
	{
		perror("bind");
		exit(-1);
	}
	listen(listensocket,5);
	/*Beginning of the Main Server Processing Loop*/
	
	for (;;)
	{
		printf("Server:I am waiting-----Start of Main Loop\n");
		len=sizeof(cliaddr);
		connectionsocket=accept(listensocket,
					(struct sockaddr*)&cliaddr,&len);
		if (connectionsocket < 0)
		{
			if (errno == EINTR) 
			printf("Interrupted system call ??");
			continue;
		}
		printf("Connection from %s\n",
			inet_ntop(AF_INET,&cliaddr.sin_addr,buf,sizeof(buf)));
		retchild=fork();
		
		if (-1==retchild)
		{
			printf("Cannot fork  Now , denying service\n");
			continue;
		}
	
		if (0==retchild)
		{	
			/*Close the listening socket in the child*/
			close(listensocket);
		
			/*Serve the Client */
			readstring(connectionsocket , databuf);
			
			/*Now the child exits*/
			printf("Finished Serving One Client\n");
			printf("Server Child with Pid=%d now exiting\n",
				getpid());
			close(connectionsocket);
			exit(0);
		}
		/*Close the old connection socket in the parent*/
		close(connectionsocket);
	}
	
}

/********************************************************************
*	FUNCTION NAME:readstring
*	DESCRIPTION: Reads the string  sent by the client over the 
*	socket	and stores it in the array fname .
*	NOTES : No Error Checking is done .
*	RETURNS :void 
*********************************************************************/

void readstring(
	int connectionsocket,		/*Socket Descriptor*/	 
	char *fname)	/*Array , to be populated by the string from client*/
/********************************************************************/
{	
	int pointer=0,n;
	while ((n=read(connectionsocket,(fname + pointer),BUFSIZE))>0)
	{
		pointer=pointer+n;
	}
	fname[pointer]='\0';
	printf("Server Child(%d) :Received   %s\n " ,getpid(),fname);

}
/**********************************************************************/

