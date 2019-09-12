#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
  int n=10;
  fork();
  fork();
  fork();
  fork();
  fork();
  sleep(5);
  return 0;
}
