
#include <header.h>

/******************************************************************************
*
*     FUNCTION NAME   :    insert_first
*
*     DESCRIPTION     :    This function inserts a new node at the begining of  *			the single linked list.
*
*     RETURNS         : head, the modified node pointer
*
*******************************************************************************/
node * insert_first(
	node *head, /* Parameter for head of the list*/
	int number) /* Parameter for the data to be inserted */
{
    node *newnode;/* Node pointer for the new node which needs to be inserted */

    /* Allocate memory to the new node */
    newnode = (node*) malloc (sizeof(node));

    /* Check if memory is allocated or not */
    if (NULL ==newnode)
    {
        printf("Memory not available");
        exit(FAILURE);
    }
    else
    {
        newnode->data = number; /* Assigning data */

        /*
        * The node currently pointed to by head will now be pointer by this 
        * node
        */
        newnode->next = head; 
        head = newnode; /* Head will now point to the new node added */
        return head;
    }
}
/******************************************************************************
*
*     FUNCTION NAME   :    insert_last
*
*     DESCRIPTION     :    This function inserts a new node at the end of       *			the single linked list.
*
*     RETURNS         : head, the modified node pointer
*
*******************************************************************************/

node * insert_last(
	node *head, /* Parameter for head of the list*/
	int number) /* Parameter for the data to be inserted */
{

    /* Write the code for insertion here */
node *newnode,*p;
newnode = (node*)malloc(sizeof(node));
if(NULL==newnode)
{
printf("\nMemory not available\n");
exit(FAILURE);
}
newnode->data=number;
newnode->next=NULL;
if(NULL==head)
{
head=newnode;
}
else
{
p=head;
while(NULL!=p->next)
{
p=p->next;
}
p->next=newnode;
} 
return head; 
}

/******************************************************************************
*
*     FUNCTION NAME   :    insert_after
*
*     DESCRIPTION     :    This function inserts a new node after the given node*			number in the single linked list.
*
*     RETURNS         : head, the modified node pointer
*
*******************************************************************************/
node * insert_after(
	node *head, /* Parameter for head of the list*/
	int node_no, /* Parameter for the node number after which a node has to be inserted */
	int number) /* Parameter for the data to be inserted */
{

    /* Write the code for insertion here */
node *newnode,*p,*q;
int i;
newnode=(node*)malloc(sizeof(node));
if(NULL==newnode)
{
printf("\nMemory not available\n");
exit(FAILURE);
}
newnode->data=number;
p=head;
q=p->next;
for(i=1;i<node_no;i++)
{
p=q;
q=p->next;
}
p->next=newnode;
newnode->next=q;
return head;
}

