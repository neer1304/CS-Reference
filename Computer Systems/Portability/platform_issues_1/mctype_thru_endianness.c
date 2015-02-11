/* To Identify type of machine and network*/

#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<inttypes.h>

int main()
{
        unsigned long local = 1;                // Local machine variable
        char *ptr=NULL;                             
        unsigned long network = htonl(local);   // Network formatted long

        // Identify the endianess of the local machine
        ptr = (char*)&local;
        printf("\n%x and  %x\n",ptr ,*ptr);
        if ((*ptr) == 1)                   // Compare first byte
                printf("\nMachine is little endian!\n");
        else
                printf("\nMachine is big endian!\n");


        // Identify the endianess of the network byte order
        ptr = (char*)&network;
        printf("%x and %d\n",ptr,*ptr);
        if ((*ptr) == 1)                   // Compare first byte
                printf("\nNetwork is little endian!\n");
        else
                printf("\nNetwork is big endian!\n");

        return 0;
}
