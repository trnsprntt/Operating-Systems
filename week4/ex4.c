#define MAXLINE 100
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
int main(){
  char *args[MAXLINE];
  char input[MAXLINE];
  printf(">");
  scanf ("%[^\n]%*c", input);
  int temp=0;
  args[temp] = strtok(input," ");
  while (args[temp] != NULL){
        temp++;
        args[temp] = strtok(NULL, " ");
  }
  int bg = (int) !(strcmp(args[temp-1],"&"));
  if (bg){
    args[temp-1]=NULL;
  }
    pid_t pid;
    pid=fork();
    if (!bg){
      execvp(args[0],args);
    }
    else
    {
      if (pid==-1){
        printf("ERROR\n");
        return 1;
      }
      else if (pid==0){
        execvp(args[0],args);
      }
      else{
        int status;
        wait(&status);
      }
    }
  return 0;
}
