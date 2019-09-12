#include <stdio.h>
#include <sys/types.h>

int main()
{
    int n;

    n = fork();
    if (n == 0) 
        printf("Hello from child %d - %d\n" ,getpid(), n ) ; 
    else
        printf("Hello from parent %d - %d\n" ,getpid(), n ) ; 

    return 0;
}