#include<header.h>

/******************************************************************************
*
*     FUNCTION NAME   :    main	
*     
*     DESCRIPTION     :    This function calls different functions to perform   *			operations like insertion, deletion, display etc on 	*			single linked list.
*
*     RETURNS         : SUCCESS 
*
*******************************************************************************/
int main(void)
{
    int status; /* Variable to check the return status */
    node * head; /* Head node for the list */
    head =NULL;

    /* Insert data at the end of the list */
    head=insert_last(head,12);
    head=insert_last(head,13);
    head=insert_last(head,23);
    head=insert_last(head,43);
    head=insert_last(head,44);
    head=insert_last(head,50);

    /* Insert data at the begining of the list */
    head=insert_first(head,2);
    head=insert_first(head,1);

    /* Insert data after a specific node in the list */
    head=insert_after(head,3,333);
    head=insert_after(head,6,666);

    /* Display the list */
    display(head);

    /* Delete from the begining of the list */
    status=delete_first(&head);
    if(SUCCESS == status)
        printf("\n Element deleted successfully from start");
    
    /* Display the list */
    display(head);
    
    /* Delete from the end of the list */
   status=delete_last(&head);
    if(SUCCESS == status)
        printf("\n Element deleted successfully from last");
    
    /* Display the list */
    display(head);
   
    /* Delete data after a specific node in the list */
   printf("\nDeleting a particular element\n");
   printf("Deleting 333\n");
    head=delete_node(head,333);
   printf("\nDeleting 12\n");
    head=delete_node(head,12);
   printf("\nDeleting 2\n");
    head=delete_node(head,2);

    /* Display the list */
    display(head);
    
    /* Free the memory which is allocated to the list */
    status= list_free(head);
    if(SUCCESS == status)
        printf("\n List freed successfully\n");
    else
        printf("\n List is emptyi\n");
    
    return SUCCESS;
}

