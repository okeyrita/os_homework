#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    fprintf(stdout, "H");
    sleep(1);   

    fprintf(stdout, "e");
    sleep(1);   

    fprintf(stdout, "l");
    sleep(1);   

    fprintf(stdout, "l");
    sleep(1);   

    fprintf(stdout, "o");
    sleep(1);   

    fflush( stdout );

    return 0;
}
