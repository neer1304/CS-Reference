/*******************************************************************************
*
*     FILENAME       :    insert_functions.c
*
*     DESCRIPTION    :    This file defines the insertion function to insert the word at the last of linked list.
*
*******************************************************************************/

#include <header.h>

/******************************************************************************
*
*     FUNCTION NAME   :    insert_last
*
*     DESCRIPTION     :    This function inserts a new node at the end of the single linked list.
*
*     RETURNS         :    int
*
*******************************************************************************/

int   insert_last(
	node **head, /* Parameter for head of the list*/
	char w[]) /* Parameter for the word to be inserted */
{

    /* Write the code for insertion here */
node *newnode,*p;
newnode = (node*)malloc(sizeof(node));
	if(NULL==newnode)
	{
	  printf("\nMemory not available\n");
	  exit(FAILURE);
	}
	strcpy(newnode->data,w);
	newnode->next=NULL;
	if(NULL==*head)
	{
	 *head=newnode;
	}
	else
	{
	//traverse to the end of the list
	p=*head;
	   while(NULL!=p->next)
	   {
	    p=p->next;
           }
	p->next=newnode;
}	 
}

