#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>

struct Page{
	int number;
  int counter;
} page;

int is_hit (struct Page* page_table, int request,int frames){
    for (int i = 0; i < frames; i++){
        if (page_table[i].number == request)
            return 1;
    }
    return 0;
}

void insert_page(struct Page *page_table, int request, int frames){
    int min_age = page_table[0].counter;
    int page_to_delete = 0;
    for (int i = 1; i < frames; i ++){
      if (page_table[i].counter < min_age){
          min_age = page_table[i].counter;
          page_to_delete = i;
      }
    }
      page_table[page_to_delete].number = request;
      page_table[page_to_delete].counter = 1<<31;
}

int main(void){
    int frames;
    printf("Enter the number of page frames:\n");
    scanf("%d", &frames);
    struct Page* page_table = malloc(frames*sizeof(struct Page));
    FILE* fp = fopen("Lab 09 input.txt", "r");
    int size = 0;
    int t = 0;
    while (!feof(fp)){
  		fscanf(fp, "%d", &t);
  		size++;
    }

    int hit = 0;
    int miss = 0;
    rewind(fp);
    for (int i = 0; i < size; i++){
        int request;
        fscanf(fp, "%d", &request);
        if (is_hit(page_table,request,frames)==1){
          hit++;
        }
        else{
          miss++;
          insert_page(page_table, request, frames);
        }
        for (int i = 0; i < frames; i++){
          if (page_table[i].number == request){
              page_table[i].counter = page_table[i].counter >> 1;
              page_table[i].counter += (1<<31);
            }
            else
              page_table[i].counter = page_table[i].counter >> 1;
            }
    }
    fclose(fp);
    printf("Hits = %d misses = %d Ratio for %d frames is %f",hit,miss, frames, hit/(miss*1.0));
    return 0;
}
