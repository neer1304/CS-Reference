#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

#define BLOCKSIZE 10

int main(int argc,char *argv[])
{
int fd1,fd2,readbytes,i=0,j,size_file1,size_file2;
//char buff[BLOCKSIZE];
char *buf,word[10];
memset(word,0,BLOCKSIZE);
if(argc!=3)
{
printf("Program Usage: ExecutableFile InputFile OutputFile\n");
}
	else
	{	
	fd1=open(argv[1],O_RDONLY);
		if(fd1<0)
		{
		printf("Cannot open file for reading\n");
		perror("File Error");
		exit(1);
		}
	fd2=open(argv[2],O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
		if(fd2<0)
		{
		printf("Cannot open file for writing\n");
		perror("File Error");
		exit(1);
		}
        size_file1= lseek(fd1,0,SEEK_END);
        if((off_t)-1==size_file1)
        {
	perror("Lseek error");
	exit(1);
	}
	lseek(fd1,0,SEEK_SET);

      /*  size_file2= lseek(fd2,size_file1,SEEK_END);
        if((off_t)-1==size_file2)
        {
	perror("Lseek error");
	exit(1);
	}
*/
/*	while((readbytes=read(fd1,buff,BLOCKSIZE))>0)
	{
         i=0;
	 while(buff[i]!=' ' && buff[i]!='\n')
	 i++;
         printf("The value of i is %d\n",i);

	 lseek(fd2,-i-1,SEEK_CUR);

	 for(j=0;j<i;j++)
	 {
	 write(fd2,&buff[j],1);
	 }

	 lseek(fd1,-readbytes+i-1,SEEK_CUR);
	}
*/
buf=(char*)malloc(sizeof(char));
while((readbytes=read(fd1,buf,1))>0)
{
i=0;
while(buf[0]!=' ' && buf[0]!='\n')
{
word[i]=buf[0];
i++;
//printf("Value of i is %d\n",i);
if(read(fd1,buf,1));
}
printf("Value of i is %d\n",i);
lseek(fd2,size_file1-i-1,SEEK_SET);
//lseek(fd2,-i-1,SEEK_CUR);
size_file1=size_file1-i-1;
write(fd2,buf,1); //write space
write(fd2,word,strlen(word));
//write(fd2,word,i);
//printf("The length of word is %d\n",strlen(word));
memset(word,0,10);
}
}


close(fd1);
close(fd2);
return 0;
}
