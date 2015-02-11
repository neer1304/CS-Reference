#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include "msgheader.h"
#include<sys/types.h>
#include<errno.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>


int main()
{
int msgqid;
int readchars=0;
key_t key;
msgbuf mbuf;
int i;


if((key=ftok(KEY_NAME,PROJ_ID_KEY))==-1)
{
perror("ftok");
exit(-1);
}

msgqid=msgget(key,0666|IPC_CREAT);
//if((msgqid=msgget(key,0644|IPC_CREAT))==-1)
if(msgqid==-1)
{
perror("msgget");
exit(-1);
}

printf("Enter the data to be send to receiver :-\n");

for(i=0;i<3;i++)
{

if(i==0)
mbuf.mtype=TYPE1_MSG;
else if(i==1)
mbuf.mtype=TYPE2_MSG;
else
mbuf.mtype=TYPE3_MSG;


readchars=read(0,mbuf.mtext,MSG_SIZE-1);
mbuf.mtext[readchars-1]='\0';


if(msgsnd(msgqid,(struct msgbuf*)&mbuf,sizeof(mbuf),0)==-1)
{
perror("msgsnd");
if(EIDRM==errno)
break;
}
}

/*if(msgctl(msgqid,IPC_RMID,NULL)==-1)
{
perror("msgctl");
exit(-1);
}
*/
return 0;
}


