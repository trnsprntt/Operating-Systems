#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	char **s = malloc(16*16*sizeof(int));
	char foo[] = "Hello World";
	*s = foo;
	printf("s is %s\n", s[0]);
	s[0] = foo;
	printf("s[0] is %s\n",s[0]);
	return(0);
}
