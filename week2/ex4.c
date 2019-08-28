#include <stdio.h>
#include <stdlib.h>

void swap(int *a , int *b);

int main()
{
    int a, b ;
    scanf("%d %d", &a , &b);
    
    swap(&a,&b);

    printf("%d %d",a,b);

    return 0;
}

void swap(int *a , int *b){
    int buffer = *a;
    *a = *b;
    *b = buffer;
    return ;
}
