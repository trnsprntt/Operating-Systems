#define MAXLINE 100
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
  char command[MAXLINE];
  printf(">");
  scanf("%s",command);
  system(command);
  return 0;
}
