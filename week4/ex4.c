#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char com[256];
    while(1){
        fgets(com, 256, stdin);
        system(com);
    }
    return 0;
}