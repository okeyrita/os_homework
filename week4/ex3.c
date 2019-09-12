#include <stdio.h>
#include <stdlib.h>

int main()
{
    char com[256];
    while(1){
        scanf("%s", com);
        system(com);
    }
    return 0;
}