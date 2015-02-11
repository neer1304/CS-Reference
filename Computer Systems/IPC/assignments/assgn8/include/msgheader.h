#ifndef MSG_H
#define MSG_H

#define MSG_SIZE 256

#define TYPE1_MSG 1
#define TYPE2_MSG 2
#define TYPE3_MSG 3

#define PROJ_ID_KEY 13

#define KEY_NAME "../bin/mykey"

typedef struct msgbuf
{
long mtype;
char mtext[MSG_SIZE];
}msgbuf;

#endif

