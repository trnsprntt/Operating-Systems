#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
void handler(int sig){
    printf("Proccess was killed");
    exit(0);
}

int main() {
    int fd[2];
    pipe(fd);
    pid_t child_pid [2];
    child_pid[0] = fork();
    if (!child_pid[0]) {
        pid_t rec;
        read(fd[0], &rec, sizeof(rec));

        printf("1: hey\n");
        sleep(5);

        printf("1: stopping process\n");
        kill(rec, SIGSTOP);

        printf("1: asking process to terminate.\n");
        kill(rec, SIGINT);

    } else {
        child_pid[1] = fork();
    }

    if (!child_pid[1]) {
        signal(SIGINT, handler);
        while (1) {
            printf("2: living\n");
            sleep(1);
        }
    }

    if (child_pid[0]) {
        printf("P: Sending 2nd child PID to 1st child...\n");
        write(fd[1], &child_pid[1], sizeof(child_pid[1]));
        close(fd[1]);
        waitpid(child_pid[1], 0, 0);
    }
    return 0;
}
