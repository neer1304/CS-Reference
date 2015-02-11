/********************** Header File Inclusions ********************************/
#include <stdio.h>
#include<stdlib.h>

/********************** Macro definitions *************************************/
# define SUCCESS 1
# define FAILURE 0
           
/********************** Structure Definition **********************************/
typedef  struct node_list
{      
    int data;
    struct node_list *next;
}node;

/********************** Function Declaration **********************************/
int isempty(node * head);
node * insert_first(node *head,int number);
node * insert_last(node *head, int number);
node * insert_after(node *head, int node_no, int number);
int delete_first(node **head);
int delete_last(node **head);
node * delete_node(node *head, int number);
void display(node *head);
int list_free(node *head);
