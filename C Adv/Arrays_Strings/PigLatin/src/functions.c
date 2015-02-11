#define MAX 128
#define conc(str1,str2) str1##str2
#include<string.h>
#include<stdlib.h>
#define SZ 5

int isPigLatin(char str[MAX],char str1[MAX])
{
char t,*c="ay";
char len=strlen(str);
char *temp=(char*)malloc(2*MAX);
if((str[0]=='a')||(str[0]=='e')||(str[0]=='i')||(str[0]=='o')||(str[0]=='u'))
{
strncpy(temp,str,SZ-1);
strncat(temp,c,MAX-len-2);
if(strcmp(temp,str1))
return 1;
else
return 0;
}
else
{
t=str[0];
str[0]='\0';
strncpy(temp,str,SZ-1);
strncat(temp,t,MAX-len-2);
strncat(temp,c,MAX-len-2);
if(strcmp(temp,str1))
return 1;
else
return 0;
}
}
