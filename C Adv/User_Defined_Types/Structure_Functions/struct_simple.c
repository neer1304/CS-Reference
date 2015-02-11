#include<stdio.h>
//#include<alloc.h>
#include<string.h>
#define MAX_LEN 100
int main()
{
typedef struct emp_details
{
	char emp_name[MAX_LEN];
	float emp_sal;
	int emp_age;
}emp_details;
emp_details e;

int n, i;
printf("hw many records u want to insert:\n");
scanf("%d",&n);
//printf("%d",n);


for(i = 0; i< n; i++)
{

printf("emp_name,emp_sal,emp_age\n");
scanf("%s%f%d\n",&e.emp_name,&e.emp_sal,&e.emp_age);
printf("%s%f%d\n",e.emp_name,e.emp_sal,e.emp_age);

}
return 0;}

