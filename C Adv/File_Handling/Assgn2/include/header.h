#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20
#define SUCCESS 1
#define FAILURE 0
#define EMPNUM 10

typedef struct emp
{
int id;
char name[MAX];
char dept[MAX];
long int phno;
}emp;

int insertRec(struct emp *e,int n);
int getRecByName(FILE *fp,char name[]);
int getRecById(FILE *fp,int id);
int getRecByNum(FILE *fp,int n);



