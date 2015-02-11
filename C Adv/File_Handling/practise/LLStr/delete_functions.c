/*******************************************************************************
*
*     FILENAME       :    delete_functions.c
*
*     DESCRIPTION    :    This file defines the deletion functions.
*******************************************************************************/

#include<header.h>

/******************************************************************************
*
*     FUNCTION NAME   :    delete_first
*
*     DESCRIPTION     :    This function deletes a node from the begining of
*                       the single linked list.
*
*     RETURNS         : SUCCESS, if a node is successfully deleted
*			FAILURE, if node is not deleted
*
*******************************************************************************/
int delete_first(
    node **head)/* Parameter for head of the list*/
{
node *p;
p=*head;
printf("Inside the delete first function..\n");
	if(NULL==*head)
	{
	 printf("\nList is Empty\n");
	 return FAILURE;
	}	
	else if(NULL==(*head)->next)
	{
	 printf("If head->next is NULL..\n");
	 *head=NULL;
	 free(p);
	 return SUCCESS;
	}	
	else
	{
	 printf("If head->next is not null..\n");
	//del=p->data;
	*head=p->next;
	free(p);
	p=NULL;
	return SUCCESS;
	}	
}

/******************************************************************************
*
*     FUNCTION NAME   :    delete_match
*
*     DESCRIPTION     :    This function deletes a node p and q is the previous
*                           node to p in the single linked list.
*
*     RETURNS         : integer
*
*******************************************************************************/
int delete_match(
                node **q, //the previous node
                node **p) 
{
//printf("Inside the delete match function..\n");
	if(*q==NULL) 
	{
	 return 0;
	}
	else if(*p==NULL) //if the node to be deleted is NULL
	{
	 return 0;
	//free(*q);
	//*q=NULL;
	}
	else//(*q!=NULL && *p!=NULL)
	{
	  (*q)->next=(*p)->next;
	  free(*p);
	  *p=NULL;
	}	
}
