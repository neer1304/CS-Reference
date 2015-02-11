#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define sz 20


int main(int argc,char *argv[])
{
int max=0,i,j,k=0;
char *pat,*inp[sz],*aptr[sz],*temp;
 if(argc!=3)
 printf("Program Usage:- filename max pattern\n");
 else
 {
  max=atoi(argv[1]);
  pat=argv[2];
//allocate memory for the input array
for(i=0;i<max;i++)
inp[i]=(char*)malloc(sz*sizeof(char));

  for(i=0;i<max;i++)
  {
  printf("Enter string %d\n",i);
  scanf("%s",inp[i]);
  if(strcmp(inp[i],"end")==0)
  break;
  else
  continue;
  }
//Allocate memory for the array of pointers which will store the matched pattern
//for(i=0;i<max;i++)
//aptr[i]=(char*)malloc(max*sizeof(char));

for(j=0;j<max;j++)
{
   if(strstr(inp[j],pat))
   {
   aptr[k]=inp[j];
   k++;
   }
   
}

printf("The no. of strings pattern in it are %d\n",k);
//for(i=0;i<k;i++)
//printf("%s ",aptr[i]);
//for(i=0;i<max;i++)
temp=(char*)malloc((k+1)*sz*sizeof(char));
//printf("Size of temp is %d\n",sizeof(temp));
if(NULL==temp)
printf("No memory allocated to temp..\n");
else
{
  for(i=k-1;i>=0;i--)
  {
    strcat(temp, aptr[i]);
  }
   // printf("%s ",aptr[0]);
   puts(temp);
// printf("\n"); 
 }
}
//free(pat);
//pat=NULL;
for(j=0;j<max;j++)
{
free(inp[j]);
inp[j]=NULL;
//free(aptr[j]);
//aptr[j]=NULL;
}

free(temp);
temp=NULL;
 return 1;
}
