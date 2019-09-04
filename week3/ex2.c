#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr , int n);

int main()
{
    int arr[4] = {0,3,5,1};
    bubble_sort(arr, 4);
    return 0;
}

void bubble_sort(int *arr , int n){
    for (int i = 0; i <n-1 ; ++i){
        for( int j = 0; j <n-1-i ; ++j){
            if(arr[j]>arr[j+1]){
                int buffer = arr[j];
                arr[j]=arr[j+1];
                arr[j+1] = buffer;
            }
        }
    }
}