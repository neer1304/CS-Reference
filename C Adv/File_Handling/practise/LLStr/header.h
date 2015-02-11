/*******************************************************************************
*
*     FILENAME       :    header.h
*
*     DESCRIPTION    :    This file defines the macros and the structure of the node used for the list.
*
*******************************************************************************/

/********************** Header File Inclusions ********************************/
#include <stdio.h>
#include<stdlib.h>

/********************** Macro definitions *************************************/
# define SUCCESS 1
# define FAILURE 0
# define MAX 30           
/********************** Structure Definition **********************************/
typedef  struct node_list
{      
    char data[MAX];
    struct node_list *next;
}node;

/********************** Function Declaration **********************************/
int insert_last(node **head, char[]);
int delete_match(node **q,node **p);
int delete_first(node **head);
void display(node *head);
int list_free(node *head);
