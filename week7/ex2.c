#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
  int n;
  printf("Enter the size of the array\n");
	scanf("%d", &n);
	int* a = malloc(n*sizeof(int));
	for (int i = 0; i < n; i++)
		a[i] = i;
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	free(a);
	return 0;
}
