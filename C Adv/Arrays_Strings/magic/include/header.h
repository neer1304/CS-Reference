#ifndef header_
#define header_
#define MAX 128

void get_input(int *r,int *c,int a[][MAX]);

int check_square_matrix(int r,int c);

void display_matrix(int (*arr)[MAX],int r,int c );

int check_magic(int (*arr)[MAX],int r,int c);


#endif
