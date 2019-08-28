#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i <=n-1 ; ++i){

        for (int j = 1 ; j <= n - i ; ++j){
            printf(" ");
        }

        for (int g = 0 ; g <= i*2 ; ++g){
            printf("*");
        }
        
        printf("\n");
    }
    return 0;
}