#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
void sigterm_handler(int signal){
    printf("\n Got sygterm signal\n");
    exit(0);
}

int main() {
  pid_t pid = fork();
    if (pid < 0){
        printf("Child process has not been created\n");
        return 1;
    }
    else if (pid > 0) {
        sleep(10);
        kill(pid, SIGTERM);
    }
    else {
        signal(SIGTERM, sigterm_handler);
        while (1) {
            printf("I'm alive\n");
            sleep(1);
        }

    }
    return 0;
}
