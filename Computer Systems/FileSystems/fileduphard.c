/*demonstrate redirection of standard output to a file.
     */

     #include <stdio.h>
     #include <fcntl.h>
     #include <sys/types.h>
     #include <sys/stat.h>

     int main()
     {
        int fd;

        fd = open("input",O_WRONLY | O_CREAT, S_IREAD | S_IWRITE );
        if (fd == -1)
        {
           perror("foo.bar");
           exit (1);
        }
        close(1);         /* close standard output  */
        printf("Good1\n");
        printf("Goo21\n");
	dup(fd);       /* fd will be duplicated into standard output (fd =1) */
        close(fd);        /* close the extra file descriptor*/
        printf("Hello, world!\n");    /* should go to file input */
        exit (0);         /* exit() will close the files */
     }



