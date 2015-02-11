#include"header.h"


int push(snode **top,char sword)
{
snode *newnode;
newnode=(snode*)malloc(sizeof(snode));


if(NULL==newnode)
 {
   printf("Memory not available\n");
   exit(FAILURE);
 }
else
 {  
   newnode->word=sword;
   if(NULL==*top)
   {
      newnode->next=NULL;
      *top=newnode;
     return SUCCESS;
   }
   else
   {
   newnode->next=*top;
   *top=newnode;
   return SUCCESS;
   }  
 }
}


char pop(snode **top)
{
char del;
snode *p;
p=*top;
del=p->word;
 if(NULL==*top)
 {
   printf("Stack is empty\n");
   exit(FAILURE);
 }
 else
 {
 *top=p->next;
 free(p);
 p=NULL;
 }
return del;
}
