#include"header.h"

int push(snode **head,char w[])
{
snode *new;
new =(snode*)malloc(sizeof(snode));

if(NULL==new)
{
printf("Malloc failed\n");
exit(1);
}
new->str=(char*)malloc(strlen(w)+1);
strcpy(new->str,w);
if(NULL==*head)
{
*head=new;
new->next=NULL;
}
else 
{
new->next=(*head);
*head=new;
}
return 1;
}

char* pop(snode **head)
{
char *s;
s=malloc(strlen((*head)->str)+1);
snode *t;
if(NULL==*head)
{
printf("Stack empty\n");
return 0;
}
else
{
t=*head;
*head=t->next;
strcpy(s,t->str);
free(t->str);
t->str=NULL;
free(t);
t=NULL;
return s;
}
}

void free_stack(snode *head)
{
snode *temp;
temp=head;
while(temp!=NULL)
{
temp=head->next;
free(head);
head=NULL;
}
}
