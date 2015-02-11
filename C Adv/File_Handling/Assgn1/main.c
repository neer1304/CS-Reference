#include <stdio.h>
#include <string.h>
#define MAX 20

int main(int argc,char *argv[])
{
 FILE *infile1 = NULL,*infile2=NULL,*outfile=NULL; /* file pointer */
 char str[MAX]; /* Array to read from the file */
 int num = 0; /* Reads an integer from file */
 int ret = 0; /* Return value from fclose */
 char *fgets_ret=NULL;
 int fclose_ret=0,str_len=0;

if(argc!=4)  //3 file names and 1 program name
{
printf("Program usage is filename intFile stringFile outputFile\n");
}
else
{
 memset(str, 0, MAX); /* Initializing the array */


 /* Opens the first file for writing */
 infile1 = fopen(argv[1], "w");
 if(NULL == infile1) /* Error check for fopen */
 {
  printf("Integer File can not be opened for writing mode\n");
  return 0;
 }

 /* Formatted writing using fprintf */
 /* Conversion specifiers are used same as scanf */
 fprintf(infile1,"%d",123);
 fprintf(infile1,"\n%d",387);
 fprintf(infile1,"\n%d",367);
// fprintf(infile1,"\n%d",786);
/*****Close the first file after writing****/
 ret = fclose(infile1);
 if(0 != ret)
 {
  printf("fclose failed\n");
  return 0;
 }


 /* Opens the second file for writing */
 infile2 = fopen(argv[2], "w");
 if(NULL == infile2) /* Error check for fopen */
 {
  printf("String File can not be opened for writing mode\n");
  return 0;
 }

 fprintf(infile2,"%s","abc xyz");
 fprintf(infile2,"\n%s","pqr nxd");
 fprintf(infile2,"\n%s","rst wiv");
fprintf(infile2,"\n%s","neer sh");

 /* Close the second file after writing*/
 ret = fclose(infile2);
 if(0 != ret)
 {
  printf("fclose failed\n");
  return 0;
 }

 /* Opens the first integer file for reading */
 infile1 = fopen(argv[1], "r");
 if(NULL == infile1)
 {
  printf("Integer File can not be opened for reading\n");
  return 0;
 }

/*Open the second string file for reading*****/
infile2=fopen(argv[2],"r");
if(NULL == infile2)
{
printf("String File can not be opened for reading mode\n");
return 0;
}

/*Open the third output file in writing mode ****/
outfile=fopen(argv[3],"w");
if(NULL==outfile)
{
printf("\nOutput file cannot be opened for writing");
return 0;
}


 /* Reads from the file using "%s" - a word at a time. We get only the first
    word as fscanf stops at any white space character - space, tab or new line. */

//Reading the string file using fgets
  while(0==feof(infile2) && 0==feof(infile1))
  {
    fgets_ret=fgets(str,MAX,infile2);
    if(NULL==fgets_ret)
     {
      break;
     }
  
     fscanf(infile1,"%d",&num);
     fprintf(outfile,"%d\n",num);
    
 //   fscanf(infile2,"%s",str);
     
    str_len=(int)strlen(str);
     if('\n'==str[str_len-1])
      {
       str[str_len-1]='\0';
      }  
    // fscanf(infile2,"%s",str);
     fprintf(outfile,"%s\n",str);
     
  }
//Read the left over integers from integer file if it has more number of lines
while(feof(infile1)==0)
{
//if(fscanf(infile1,"%d",&num)!=EOF);
fscanf(infile1,"%d",&num);
fprintf(outfile,"%d\n",num);
} 

//Read the left over strings from string file if it has more number of lines
while(feof(infile2)==0)
{
 /*   str_len=(int)strlen(str);
    if('\n'==str[str_len-1])
      {
       str[str_len-1]='\0';
      }  */
//if(fscanf(infile2,"%s",str)!=EOF);
fscanf(infile2,"%s",str);
 fprintf(outfile,"%s ",str);

}

 /* Closes the stream */
 ret = fclose(infile1);
 if(0 != ret)
 {
  printf("fclose failed for int file\n");
  return 0;
 }


 ret = fclose(infile2);
 if(0 != ret)
 {
  printf("fclose failed for string file\n");
  return 0;
}

 ret = fclose(outfile);
 if(0 != ret)
 {
  printf("fclose failed for output file\n");
  return 0;
}
}
 return 0;
}
