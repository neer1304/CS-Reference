#include<header.h>

/******************************************************************************
*
*     FUNCTION NAME   :    isempty
*
*     DESCRIPTION     :    This function checks whether the list is empty or not*			i.e. whether it exist or not
*
*     RETURNS         : SUCCESS if it is empty and FAILURE if not
*
*******************************************************************************/
int isempty(
	node * head) /* Parameter for head of the list*/
{
    /* Check if lists exist or not and return status */
    if (NULL == head)
        return SUCCESS;
    else
        return FAILURE;
}

/******************************************************************************
*
*     FUNCTION NAME   :    display
*
*     DESCRIPTION     :    This function traverses the list to display the data *			in the list.
*
*     RETURNS         : nothing
*
*******************************************************************************/
void display(
	node *head) /* Parameter for head of the list*/
{

    /* Write the code for display here */
while(head!=NULL)
{ 
  printf("%d ->", head->data);
  head=head->next;
}
printf("\n\n");
}

/******************************************************************************
*
*     FUNCTION NAME   :    list_free
*
*     DESCRIPTION     :    This function frees the memory which is allocated to *			the nodes of the list.
*
*     RETURNS         : SUCCESS if memory is freed,
*			FAILURE if list is already empty
*
*******************************************************************************/
int list_free(
	node *head) /* Parameter for head of the list*/
{
    node *current; /* Temporary node pointer to traverse the list */

    /* Check if the list is already empty i.e. does not exist */
    if (isempty(head))
        return FAILURE;

    /* Traverse the list to free each node */
    while (NULL != head)
    {
        current = head->next;
        free(head);
        head = current;
    }

    return SUCCESS;
}
