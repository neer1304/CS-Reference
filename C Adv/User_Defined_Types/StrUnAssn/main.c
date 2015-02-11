#include<stdio.h>
#include"header.h"

int main()
{
char ty,c1,ch;
int flag=1,n=0,rv;
country *head=NULL;
country c;
int cnt=0;
while(flag)
{
//printf("Enter the place name\n");
//fscanf(stdin,"%s",head->cname);

printf("\nEnter the place type- type 'm' for metropolitian and 't' for tourist ");
//while(getchar()!='\n');
//ty=getchar();  
scanf("%c",&ty);
while(getchar()!='\n');
if(store(&head,ty))
printf("\nData stored successfully");
else
printf("\nError in store function");
printf("\nDo you want to enter more enter y or n:- ");
scanf("%c",&c1);
while(getchar()!='\n');
if(c1=='n')
flag=0;
else if(c1=='y') 
flag=1;
else
break;
}


printf("\nDisplaying the entered data for the country:-\n");
//printf("Press 'm' to  display metro records and 't' to display tourist records\n");
//scanf("%c",&ch);
//while(getchar()!='\n');
//printf("Please enter number of records you want to display:-\n");
//scanf("%d",&n);
if(display(head))
printf("\nData displayed successfully.\n");
else
printf("\nError in displaying data.\n");

if(free_list(head))
printf("\nMemory freed successfully..\n");

return 0;
}
