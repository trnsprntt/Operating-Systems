#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
  int n=10;
  pid_t pid;
  switch(pid=fork())
  {
    case -1: printf("Child process was not created\n");
    case 0 : printf("Hello from child %d\n", getpid()-n);
    default : printf("Hello from parent %d\n", getpid()-n);
  }
  return 0;
}
