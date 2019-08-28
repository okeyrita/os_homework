#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[100];
    scanf("%s", string);
    int size =  strlen(string);

    for (int i = size - 1 ; i >= 0 ; --i){

        printf("%c",string[i]);

    }
    return 0;
}