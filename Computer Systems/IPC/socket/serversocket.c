#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main (int argc, char *argv[])
{
  int s, t, sinlen;
  struct sockaddr_in sin;
  char msg[80];
  if (argc < 2) { 
    printf("%s port\n", argv[0] ); /* input error: need port no! */
   return -1;
}
if ( (s = socket(AF_INET, SOCK_STREAM, 0 ) ) < 0) { /* create socket*/
  perror("socket");  /* socket error */
  return -1;
}
sin.sin_family = AF_INET;              /*set protocol family to Internet */
sin.sin_port = htons(atoi(argv[1]));  /* set port no. */
sin.sin_addr.s_addr  = INADDR_ANY;   /* set IP addr to any interface */
if (bind(s, (struct sockaddr *)&sin, sizeof(sin) ) < 0 ){
     perror("bind"); return -1;  /* bind error */
}
/* server indicates its ready, max. listen queue is 5 */
if (listen(s, 5)) { 
    printf ("listen"); /* listen error*/
   return -1;
}
sinlen = sizeof(sin);
while (1) {
	/* accepting new connection request from client,
  	socket id for the new connection is returned in t */
	if ( (t = accept(s, (struct sockaddr *) &sin, &sinlen) ) < 0 ){
  		perror("accept" );  /* accpet error */
  		return -1;
	}
printf( "From %s:%d.\n",inet_ntoa(sin.sin_addr), ntohs(sin.sin_port) );
	if ( read(t, msg, sizeof(msg) ) <0) {  /* read message from client */
     		perror("read");         /*  read error */
     		return -1;
	}
	if ( write(t, msg, strlen(msg) ) < 0 ) {  /* echo message back */
       	perror("write");
     return -1; /*  write error */
	}
	/* close connection, clean up sockets */
	if (close(t) < 0) { perror("close"); return -1;} 
} // not reach below
if (close(s) < 0) { perror("close"); return -1;}
return 0;
}
 

