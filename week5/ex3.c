#include <stdio.h>
#include <pthread.h>

#define N 8

int count=0;
int array[N];
int psleep = 0;
int csleep = 0;

void *cfunc(void *arg){
  while (1){
    while (csleep){}
    if (count == 0){
      csleep = 1;
      continue;
    }
    printf("Fetch %d\n", array[count]);
    count--;
    if (psleep){
      psleep = 0;
    }
  }
}

int main(){
  pthread_t cthread;
  pthread_create(&cthread, NULL, cfunc, NULL);
  int a;
  while (1){
    while (psleep){}
    if (count == N){
      psleep = 1;
      continue;
    }
    array[count] = a++;
    printf("Insert %d\n", array[count]);
    count++;
    if (csleep){
      csleep = 0;
    }
  }
  pthread_exit(NULL);
}