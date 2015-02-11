#define MAX 100
#include<stdio.h>

struct metro
{
int pop;
int area;
};
typedef struct metro metro;


typedef enum 
{
beach=0,hill_st,hist
}type;


typedef struct tourist 
{
char airport[MAX];
type et;
}tourist;

union places 
{
struct metro m;
struct tourist t;
};
typedef union places places;


typedef struct country
{
char cname[MAX];
places pl;
struct country *next;
char ty;
}country;
//country *head = NULL;


typedef enum 
{
FAILURE=0,SUCCESS=1
}ret_type;


ret_type store(struct country **head,char type);
ret_type display(struct country *head);

