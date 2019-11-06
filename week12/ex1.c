#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *output, *c;
    c = fopen("/dev/urandom", "r");
    char string[20];

    fread(&string , 1 , 20, c);
    fclose(c);

    output = fopen("ex1.txt", "w+");
    fputs(string , output);
    fclose(output);
    
    int i ;
    for (int i = 0; i < 20; ++i){
        printf("%c",string[i]);
    }
    printf("\n");

    return 0;
}
