#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#define MAX_FILE_SIZE 256

int main()
{
    int fd;
    struct stat localstat;
    char filename[MAX_FILE_SIZE];
    memset(filename, '\0', 256);
    printf("Enter the filename\n");
    scanf("%s", filename);
    stat(filename, &localstat);
    printf("file size %d\n", localstat.st_size);
    printf("Blocksize =%d\n,No of Blocks =%d\n",localstat.st_blksize,localstat.st_blocks);
}


