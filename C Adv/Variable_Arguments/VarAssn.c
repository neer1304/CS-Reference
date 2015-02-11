#include<stdio.h>
#include<stdarg.h>
#include<string.h>

void concat_str(char*,...);
int main()
{

concat_str("neeraj","amit","sumit",(char*)NULL);
return 1;
}

void concat_str(char* first,...)
{
va_list listPointer;
char *name,*final;
int len;
//first find the amount of memory to be allocated using string length
len=strlen(first);

va_start(listPointer,first);
while((name=va_arg(listPointer,char*))!=NULL)
len+=strlen(name);
va_end(listPointer);

final=malloc(len+1);

//again start the list
va_start(listPointer,first);

if(first==NULL)
return;

strcpy(final,first);
while( (name = va_arg(listPointer,char *)) !=  NULL)
{
//printf("%d",i++);
//printf("%s\n",name);
strcat(final,name);
}
printf("%s\n",final);
va_end(listPointer);

free(final);
}


