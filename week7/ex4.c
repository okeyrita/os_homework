#include <stdlib.h>
#include <stdio.h>

void *my_realloc(void *arr, int new_size){
	if (arr==NULL){
		return malloc(new_size);
	}
	if (new_size==0){
		free(arr);
		return arr;
	}
	char * tmp = ( char *) malloc(new_size);
    bcopy(arr, tmp, (int) new_size);
	free(arr);
	return tmp;
}

int main(){
	printf("\nEnter original array size: ");

	int n1;
	scanf("%d", &n1);
	char* a1 = (char *) malloc(n1);
	int i;
	for(i=0; i<n1; i++){
		a1[i]=100;
		printf("%d ", a1[i]);
	}
	printf("\nEnter new array size: ");
	int n2;
	scanf("%d",&n2);
	a1 = (char *) my_realloc(a1, n2);
	for(i=0; i<n2;i++){
		printf("%d ",a1[i]);
	}
	printf("\n");
	return 0;
}