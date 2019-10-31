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
   int fp1 = open("ex1.txt", O_RDWR);
   int fp2 = open("ex1.memcpy.txt", O_RDWR | O_CREAT);
   struct stat stat1, stat2;
   stat("ex1.txt", &stat1);
   int size1, size2;
   size1 = stat1.st_size;
   ftruncate(fp2, size1);
   stat("ex1.memcpy.txt", &stat2);
   size2 = stat2.st_size;
   char *map1 = mmap(NULL, size1, PROT_READ | PROT_WRITE, MAP_SHARED, fp1, 0);
   char *map2 = mmap(NULL, size2, PROT_READ | PROT_WRITE, MAP_SHARED, fp2, 0);
   memcpy(map2, map1, size1);
   msync(map2, size1, MS_SYNC);
   munmap(map1, size1);
   munmap(map2, size2);
   close(fp1);
   close(fp2);
   return 0;
}
