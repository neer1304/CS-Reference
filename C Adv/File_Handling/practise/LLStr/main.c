#include<stdio.h>
#include"header.h"
#include"ftrace.h"

int main()
{
FILE *fp,*fp2,*fp3,*ft;
int len;
char word[MAX];
node *head=NULL,*p,*q;
ft=fopen("trace","w");
fp =fopen("inpstr","r");
	if(NULL==fp)
	{
	  printf("Input file cannot be opened for reading..\n");
	}

	while(1)
	{	
	 fscanf(fp,"%s",word);
		if(feof(fp)) //executed when non null is returned which is returned when EOF is reached
		{
		  //printf("End of the input file reached\n");
		   break;
		}
	   insert_last(&head,word);
           XXX_TRACE(DETAILED_TRACE,(ft,"%s %s\n",word," inserted in the linked list"));
	}	
//fprintf(stdout,"%s ",str);
	fclose(fp);

	printf("Displaying the contents of the linked list.\n");
	display(head);

	fp2=fopen("inpstr2","r");

	if(NULL==fp2)
	{
	 printf("Error in opening the second file in read mode..\n");
	}
	while(1)
	{
	 q=head; //head pointer
	 p=q->next;  //forward pointer

	 fscanf(fp2,"%s",word);
		
 		if(feof(fp2))
		break;

		if(strcmp(word,q->data)==0)  //if the head pointer is matching
                {
		delete_first(&head);
                XXX_TRACE(DETAILED_TRACE,(ft,"%s %s\n",word,"deleted at head node"));
                }
		else
		{
		  while(strcmp(word,p->data) && p->next!=NULL)  //check for other nodes take two pointers node to delete is p while q is trailing pointer
		  {
			//printf("Inside the main while loop checking for same words\n");
			q=p;
			p=p->next;
		  }
			//printf("Inside main where word matches deleting the matched word\n");
			if(p->next!=NULL) 
                        {
			delete_match(&q,&p);
                        XXX_TRACE(DETAILED_TRACE,(ft,"%s %s\n",word,"deleted from between in linked list"));
                        }
			else if(p->next==NULL && (strcmp(word,p->data)==0)) //for deleting last node 
			{ 
                          printf("Deleting the last word..\n");
                          XXX_TRACE(DETAILED_TRACE,(ft,"%s %s\n",word,"deleted from the last of the linked list"));
			  q->next=NULL;
		          free(p);
		          p=NULL;
			}			
		}
	 }
	fclose(fp2);

	printf("Linked list after deleting the matching element from the second file..\n");
	display(head);

        fp3=fopen("outstr","w");
        while(head!=NULL)
	{
	fprintf(fp3,"%s ",head->data);
        head=head->next;
        }
        fclose(fp3);
        fclose(ft);
}
