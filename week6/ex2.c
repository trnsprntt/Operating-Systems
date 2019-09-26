#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX_STR_LEN 50
int main() {
  int fd[2];
  pid_t process;
  char s1[MAX_STR_LEN] = "";
  char s2[]  = "not empty string";
  printf("Before creating the pipe the strings are\n %s\n %s\n", s1, s2);
  pipe(fd);
  if (pipe(fd)==0){

    process = fork();

    if (process < 0) {
        printf("Child process has not been created\n");
        return 1;
    }

    else if (process > 0) {
        close(fd[0]);
        write(fd[1], s2, strlen(s2)+1);
        close(fd[1]);
    }
    else  {
        close(fd[1]);
        read(fd[0], s1, MAX_STR_LEN);
        close(fd[0]);
        printf("After creating the pipe the strings are\n %s\n %s\n", s1, s2);
        exit(0);
    }
   }
   else{
       printf("Pipe has not been created\n");
       return EXIT_FAILURE;
   }
  return 0;
}
