#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
int main(){
  char s[] = "This is a nice day";
  int fp = open("ex1.txt", O_RDWR);
  struct stat file_stat;
  ftruncate(fp, strlen(s));
  stat("ex1.txt", &file_stat);
  char *file_addr = mmap(NULL, file_stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fp, 0);
  memcpy(file_addr, s, strlen(s));
  munmap(file_addr, file_stat.st_size);
  close(fp);
}
