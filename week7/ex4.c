#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void* realloc(void* ptr, size_t size) {
	void* new_p = malloc(size);
	if (ptr == NULL)
		return new_p;
	memcpy(new_p, ptr, size);
	free(ptr);
	return new_p;
}


int main(){
  int s1, s2;
  printf("Enter initial size of array\n");
  scanf("%d", &s1);
	int* a = malloc(s1*sizeof(int));
	for (int i = 0; i < s1; i++)
	{
		a[i] = i;
	}
  printf("Enter new size of array\n");
  scanf("%d", &s2);
  if (s2>=s1){
  	a = realloc(NULL, s2*sizeof(int));
  	for (int i = 0; i < s2; i++)
  		printf("%d ", a[i]);
  }
	return 0;
}
