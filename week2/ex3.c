#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  int n=*(argv[1])-48;
  printf("%d\n",n);
for(int i=1;i<=n;i++){
  for(int j=1;j<=n-i;j++){
    printf(" ");
  }
  for(int j=1;j<=1+2*(i-1);j++){
    printf("*");
  }
  printf("\n");
}
return 0;
}
