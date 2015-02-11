#ifndef msg_h

#define msg_h
#define msgsize  300
#define type1   1
#define type2   2
#define type3  3
#define pro    63
#define keyname "./keyfile5"
typedef struct samplebuf
{
long mtype;
char mtext[msgsize];
}samplebuf;
#endif

