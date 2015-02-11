/**************************************************************************
*       DESCRIPTION:Contains Code for a program that copies the source file 
*	content to destination file 
*       
*       Invoke the Executable as a.out
*       Copyright 2011 Aricent
****************************************************************************/
/* set of header files */

#include<stdio.h>
#include<sys/stat.h>  //for S_IRWXU
//#include<sys/types.h>
#include<fcntl.h>  //for O_RDONLY,O_CREAT,O_RDWR,O_TRUNC
#include<unistd.h>  //read,write,close
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int fd,fd1,insize,osize;
	int ret,n=3,currpos;
	char buff[20]="\0";
	if ( NULL == argv[1])
	{
		perror("Pl. provide the name of the file\n");
		exit(1);
	}
	if ( NULL == argv[2])
	{
		perror("pl provide name of destination file \n");
		exit(1);
	}
	/* open system call to open file in Readonly mode */
	/* refer man page for more details */
	fd = open(argv[1],O_RDONLY);

	if (fd < 0)
	{       
 		printf("File opening failed in read mode\n");
		perror("File opening error \n");
		exit(0);
	}
         insize=lseek(fd,0,SEEK_END);
         printf("The size of input file is %d\n",insize);
	 lseek(fd,0,SEEK_SET); 
        	
	/* open system call to creat a file and if exists then truncate existing content */
	/* refer man page for more details */
	fd1 = open(argv[2],O_CREAT|O_RDWR|O_TRUNC,S_IRWXU);
	if (fd1 < 0)
	{
        printf("File opening failed in write mode\n");
        perror("File opening failed \n");
        exit(0);
	}
	while(1)
	{
		ret = read(fd,buff,n);
		if (ret == 0)
			break;	
                currpos =  lseek(fd,n,SEEK_CUR);
                if((off_t)-1==currpos)
		{
		 printf("Cannot lseek\n");
		 perror("Lseek error\n");
 		 exit(1);
		}
                buff[ret]='\0'; //
             //    printf("Size of buff is %d\n",sizeof(buff));
             //   printf("strlen of buff is %d\n",strlen(buff));
		//write(fd1,buff,sizeof(buff)-1);
		write(fd1,buff,strlen(buff));
	}	
        osize =lseek(fd1,0,SEEK_END);
	printf("The size of output file is %d\n",osize);
         
close(fd);
close(fd1);
return 0;
}






