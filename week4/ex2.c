#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int n ;
    for (int i = 1;i<=5;++i){
        n = fork();
        sleep(5);
    }
    return 0;
}    