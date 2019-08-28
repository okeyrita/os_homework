#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main()
{
    int i = INT_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;

    printf("max value of integer : %d\n", i);
    printf("max value of float : %f\n", f);
    printf("max value of double : %lf\n", d);   

    printf("size of integer : %lu\n", sizeof(i)); 
    printf("size of float : %lu\n", sizeof(f)); 
    printf("size of double : %lu\n", sizeof(d)); 

    return 0;
}