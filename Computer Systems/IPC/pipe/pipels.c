#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pfds[2];

    pipe(pfds);

    if (!fork()) 
    {
        close(pfds[0]); /* we don't need this */
        close(1);       /* close normal stdout */
        dup(pfds[1]);   /* make stdout same as pfds[1] */
        execlp("ls", "ls", NULL);
    } 
   else 
   {
        close(pfds[1]); /* we don't need this */
        close(0);       /* close normal stdin */
        dup(pfds[0]);   /* make stdin same as pfds[0] */
        execlp("wc", "wc", "-l", NULL);
    }
}
