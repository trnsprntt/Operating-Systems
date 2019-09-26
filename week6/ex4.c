#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
void sigstop_handler(int signal){
    printf("\nSigstop signal\n");
    exit(0);
}
void sigusr1_handler(int signal) {
    printf("Sigusr1 signal");
    exit(0);
}
void sigkill_handler(int signal) {
    printf("Sigkill signal");
    exit(0);
}
void sigint_handler(int signal) {
    printf("Sigint signal");
    exit(0);
}

int main() {
  signal(SIGSTOP, sigstop_handler);
  signal(SIGUSR1, sigusr1_handler);
  signal(SIGKILL, sigkill_handler);
  while (1){
      pause();
  }
  return 0;
}
