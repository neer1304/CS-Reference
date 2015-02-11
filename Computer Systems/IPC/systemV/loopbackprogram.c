#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "msgheader.h"

#define SIZE_OF_MSG (sizeof(samplemsgbuf))

int main(void)
{
    int           msqid;
    size_t        readchars = 0;
    key_t         key;
    samplemsgbuf  mbuf1;
    samplemsgbuf  mbuf2;

    if ((key = ftok(KEY_NAME, PROJ_ID_KEY)) == -1) 
    {
        perror("ftok");
        exit(-1);
    }

    if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) 
    {
        perror("msgget");
        exit(-1);
    }
    
    printf("reciever: ready to receive messages.\n");

    for(;;) /* receiver quits only if the queue has been removed */
    {
        readchars = read(0, mbuf1.mtext, MSGSIZE-1);
        mbuf1.mtext[readchars-1] = '\0';
        mbuf1.mtype = TYPE2_MSG;
        if (msgsnd(msqid, (struct msgbuf *)&mbuf1, SIZE_OF_MSG, 0) == -1)
        {
                perror("msgsnd");
                if (EIDRM == errno)
                    break;
        }
        /* Only a message of TYPE1 type can be retrieved*/ 
        if (msgrcv(msqid, (struct msgbuf *)&mbuf2, SIZE_OF_MSG, TYPE1_MSG, 0) >= 0) 
        {
            printf("receiver: %d : \"%s\"\n", mbuf2.mtype, mbuf2.mtext);
        }
        else
        {
            perror("In msgrcv for TYPE1_MSG");
            if (EIDRM == errno)
            {
                perror("msg queue");
                break;
            }
        }
    }
    return 0;
}
