#include<stdio.h>
#define FAILURE 0
#define SUCCESS 1
int main()
{
FILE *fp,*fp1;
int num;
fp =fopen("input","r");
if(NULL==fp)
{
printf("File cannot be opened..\n");
return FAILURE;
}
fp1 =fopen("outint","w");
if(NULL==fp1)
{
printf("Cannot open output file for writing..\n");
}

while(0==feof(fp))
{
/*if(!feof(fp))
{
break;
}*/
fscanf(fp,"%d ",&num);
//printf("%d ",num);
fprintf(fp1,"%d ",num);
}

printf("\n");
fclose(fp);
fclose(fp1);
printf("Now opening output file for reading and printing output on console..\n");
fp1=fopen("outint","r");
if(NULL==fp1)
{
printf("Error in reading output file..\n");
}

while(0==feof(fp1))
{
fscanf(fp1,"%d ",&num);
printf("%d ",num);
}
printf("\n");
fclose(fp1);
}

