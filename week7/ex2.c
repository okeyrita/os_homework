#include <stdio.h>
#include <stdlib.h>
int main(){
	printf("Enter the nuber N: ");
	int n;
	scanf("%d", &n);
	int *arr = malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++){
		arr[i] = i;
	}
	for (int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
	return 0;
}