#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *p1, int *p2) {
 int temp = *p1;
 *p1 = *p2;
 *p2 = temp;
}

int main() {
 int i1, *p1 = &i1;
 int i2, *p2 = &i2;
 printf("Please enter first integer\n");
 scanf("%d", &i1);
 printf("Please enter second integer\n");
 scanf("%d", &i2);
 printf("Integer 1 = %d, Integer 2 = %d\n",i1,i2);
 swap(p1, p2);
 printf("Integer 1 = %d, Integer 2 = %d\n",i1,i2);
 return 0;
}
