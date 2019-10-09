#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>
int main(){
	struct rusage usage;
	for (int i = 0; i < 10; i++){
    int* a = malloc(10*1024*1024);
    memset(a, 0, 10*1024*1024);
    getrusage(RUSAGE_SELF, &usage);
    printf("%ld \n", usage.ru_maxrss);
    sleep(1);
  }
	return 0;
}
