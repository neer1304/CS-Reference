#include<stdio.h>
# include<string.h>

#define MAX 128
int main()
{
char str1[MAX],str2[MAX];
int flag=0;

printf("Enter the string:-\n");
fgets(str1,MAX,stdin);
str1[strlen(str1)-1]='\0';
printf("Enter another string-\n");
fgets(str2,MAX,stdin);
str2[strlen(str2)-1]='\0';
while(flag!=1 && strncmp(str2,"quit",4))
{
//if(strncmp(str2,"quit",4))
//{
if(isPigLatin(str1,str2))
{
printf("\nstr2 is piglatin of str1\n");
flag=1;
}
else
{
printf("Not a pig latin..enter str2 again..\n");
//free(str2);
printf("Enter another string-\n");
fgets(str2,MAX,stdin);
str2[strlen(str2)-1]='\0';
}
//}
}
}
