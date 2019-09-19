#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 10
void *func(void *arg){
  int *n = (int *)arg;
  printf("Entered thread number %d\n", *n);
  printf("Some text\n");
  printf("Exit thread number %d\n", *n);
}
int main(){
  pthread_t threads[N];
  int i;
  for (i = 0; i < N; ++i){
    pthread_create(&threads[i], NULL, func, (void *)&i);
    printf("Created thread number %d\n", i);
    pthread_join(threads[i], NULL);
  }
  return 0;
}