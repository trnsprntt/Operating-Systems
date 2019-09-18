#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#define NUMBER_OF_THREADS 10

void *print_hello_world (void *tid)
{
  printf("Hello from thread %d - I was created by a thread %d !\n", (int) pthread_self(), (int) (pthread_t) tid);
  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t threads[NUMBER_OF_THREADS];
  int status, i;
  pthread_t tid;
  for(i=0; i < NUMBER_OF_THREADS; i++) {
      tid = pthread_self();
      printf("I am a thread %d. Creating a new %d th thread\n", (int) tid, i);
      status = pthread_create(&threads[i], NULL, print_hello_world, (void*) tid);
      if (status != 0) {
          printf("Oops. pthread create returned error code %d\n", status);
          exit(-1);
      }
      pthread_join(threads[i], NULL);
      /*else{
        printf("\n I am thread %d. Created new thread (%d) in iteration %d ...\n", (int) pthread_self(), (int) threads[i], i);
      }*/
      if (i % 5 == 0) sleep(1);
  }
pthread_exit(NULL);
}
