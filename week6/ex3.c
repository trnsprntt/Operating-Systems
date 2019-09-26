#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
void handler(int signal) {
    printf("\nUser pressed ctrl-c\n");
    exit(0);
}
int main() {
    signal(SIGINT, handler);
    while (1){
        pause();
    }
    return 0;
}
