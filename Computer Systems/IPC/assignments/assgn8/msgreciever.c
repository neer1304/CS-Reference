#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include "msgheader.h"
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
msgbuf buf;
int msgqid;
key_t key;
int i;
long type;
int rmsgrcv;

if((key=ftok(KEY_NAME,PROJ_ID_KEY))==-1)
{
perror("ftok");
exit(-1);
}

msgqid=msgget(key,0666|IPC_CREAT);
if(msgqid==-1)
{
perror("msgget");
exit(-1);
}
printf("msgqid first time is %d\n",msgqid);

printf("Receiver :ready to recieve message\n");

/*if(i==0)
type=TYPE3_MSG;
else if(i==1)
type=TYPE2_MSG;
else
type=TYPE1_MSG;
*/

rmsgrcv=msgrcv(msgqid,(struct msgbuf*)&buf,sizeof(msgbuf),TYPE3_MSG,0);
if(rmsgrcv>=0)
{
printf("receiver%d :\"%s\"\n",buf.mtype,buf.mtext);
//buf.mtype=TYPE3_MSG;
}
else
{
perror("In msgrcv for TYPE3_MSG");
if(EIDRM==errno)
{
perror("msg queue");
}
}

//msgqid=msgget(key,0666);

printf("msgqid second time is %d\n",msgqid);
rmsgrcv=msgrcv(msgqid,(struct msgbuf*)&buf,sizeof(msgbuf),TYPE2_MSG,0);

if(rmsgrcv>=0)
{
//buf.mtype=TYPE2_MSG;
printf("receiver%d :\"%s\"\n",buf.mtype,buf.mtext);
}
else
{
perror("In msgrcv for TYPE2__MSG");
if(EIDRM==errno)
{
perror("msg queue");
}
}

//msgqid=msgget(key,0666);

printf("msgqid third time is %d\n",msgqid);

rmsgrcv=msgrcv(msgqid,(struct msgbuf*)&buf,sizeof(msgbuf),TYPE1_MSG,0);

if(rmsgrcv>=0)
{
//buf.mtype=TYPE1_MSG;
printf("receiver%d :\"%s\"\n",buf.mtype,buf.mtext);
}
else
{
perror("In msgrcv for TYPE1_MSG");
if(EIDRM==errno)
{
perror("msg queue");
}
}
}
