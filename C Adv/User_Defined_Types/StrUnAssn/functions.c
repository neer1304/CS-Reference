#include"header.h"

ret_type store(struct country **head,char type)
{
country *new;
new =(country*)malloc(sizeof(country));
if(NULL==new)
return FAILURE;
printf("Enter the name of the place\n");
scanf("%s",new->cname);
while(getchar()!='\n');
new->ty=type;
if(type=='m')
{
printf("\nEnter the population of metropolitan city:-\n");
scanf("%d",&new->pl.m.pop);
while(getchar()!='\n');
printf("\nEnter the area of the metropolitian city:-\n");
scanf("%d",&new->pl.m.area);
while(getchar()!='\n');
}

else if(type=='t')
{
printf("\nEnter the name of the nearest airport:-\n");
scanf("%s",new->pl.t.airport);
while(getchar()!='\n');
printf("\nEnter the type of tourist place 0-beach,1-Hill Station and 2-Historical\n");
scanf("%d",&new->pl.t.et);
while(getchar()!='\n');
}

else
printf("\nPlease enter valid option\n");

if(NULL==*head)
{
new->next=NULL;
}
else
{
new->next=*head;
}
*head=new;
return SUCCESS;
}

ret_type display(struct country *head)
{
country *curr =head;
while(curr!=NULL)
{
if(curr->ty=='m')
{
printf("\nThe name of the place is %s",curr->cname);
printf("\nThe population of the metro is %d",curr->pl.m.pop);
printf("\nThe area of the metro is %d",curr->pl.m.area);
}
else if(curr->ty=='t')
{
printf("\nThe name of the place is %s",curr->cname);
printf("\nThe nearest airport to %s is %s",curr->cname,curr->pl.t.airport);
printf("\nThe type of tourist place is %d",curr->pl.t.et);
}
else
printf("\nPlease enter an valid option\n");

curr=curr->next;
}
return SUCCESS;
}

int free_list(country *head)
{
country *curr;
if(NULL==head)
return 0;
while(NULL!=head)
{
curr=head->next;
free(head);
head=curr;
}
return 1;
} 
