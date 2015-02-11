#include<stdio.h>

int main()
{
FILE *fp;
int len;
char str[100];
fp =fopen("inpstr","r");
if(NULL==fp)
{
printf("Input file cannot be opened for reading..\n");
}
while(1)
{
fgets(str,80,fp);
if(feof(fp))
{
//printf("End of the input file reached\n");
break;
}
/*len=strlen(str);
if(str[len-1]=='\n')
str[len-1]='\0'; */
//puts(str);
fputs(str,stdout);
}
//fprintf(stdout,"%s ",str);
fclose(fp);
}

