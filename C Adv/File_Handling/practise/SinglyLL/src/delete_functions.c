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
int del;
node *p;
p=*head;
if(NULL==*head)
{
printf("\nList is Empty\n");
return FAILURE;
}
else if(NULL==(*head)->next)
{
*head=NULL;
free(p);
return SUCCESS;
}
   /* Write the code for deletion here */
else
{
del=p->data;
*head=p->next;
free(p);
p=NULL;
return SUCCESS;
}
}

/******************************************************************************
*
*     FUNCTION NAME   :    delete_last
*
*     DESCRIPTION     :    This function deletes a node from the end of
*                       the single linked list.
*
*     RETURNS         : SUCCESS, if a node is successfully deleted
*			FAILURE, if node is not deleted
*
*******************************************************************************/
int delete_last(
    node **head) /* Parameter for head of the list*/
{
    node *current; /* Temporary node pointer to traverse the list */
    node *temp; /* Temporary node pointer to traverse the list */
    current = *head;

    /* Check if the list is empty */
    if (isempty(*head))
    {
        printf("LIST IS EMPTY");
        return FAILURE;
    }
    else if (NULL == current->next) 
    {

        /* If only one node is in the list it is deleted */
        *head = NULL;
        free(current);
        return SUCCESS;
    }
    else
    {   
        /* Traverse the list to reach the second last node */
        while(NULL != current->next->next)
        {
                current = current->next;
        }
     
        /* Last node is deleted and second last node points to NULL */
        temp = current->next;
        current->next = NULL;
        free(temp);
        return SUCCESS;
    }
}

/******************************************************************************
*
*     FUNCTION NAME   :    delete_node
*
*     DESCRIPTION     :    This function deletes a node after searching the data
*                       in the single linked list.
*
*     RETURNS         : head, the modified node pointer
*
*******************************************************************************/
node * delete_node(
	node *head, /* Parameter for head of the list */
	int number )/* Parameter for the data to be searched */
{

   /* write the code for deletion here */
node *p,*q;
int flag=0;
p=head;
q=p->next;
if(NULL==head)
{
printf("\nList is empty\n");
return FAILURE;
}
else if(NULL ==p->next && head->data==number)
{
flag=1;
head=NULL;
free(p);
}
else if(head->data==number)
{
flag=1;
head=p->next;
free(p);
p=NULL;
}
else
{
while(flag!=1 && NULL!=q->next)
{
//p=q;
//q=q->next;
if(q->data==number)
{
flag=1;
p->next=q->next;
free(q);
q=NULL;
}
if(q!=NULL)
{
p=q;
q=q->next;
}
}
}
if(flag==0)
printf("Number not found\n");
return head;
}



