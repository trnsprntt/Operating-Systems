#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#define MAX_STR_LEN 50
int main() {
  int fd[2];
  char s1[MAX_STR_LEN] = "";
  char s2[]  = "not empty string";
  printf("Before creating the pipe the strings are\n %s\n %s\n", s1, s2);
  pipe(fd);
  if (pipe(fd)==0){
       write(fd[1], s2, strlen(s2)+1);
       read(fd[0], s1, MAX_STR_LEN);
       printf("After creating the pipe the strings are\n %s\n %s\n", s1, s2);
       return EXIT_SUCCESS;
   }
   else{
       return EXIT_FAILURE;
   }
  return 0;
}
