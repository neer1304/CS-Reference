#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<sys/types.h>


void mergesort(int arr[],int low,int high);
void merge(int arr[],int x,int y,int z,int t);


