#include <stdio.h>

void bubblesort (int n, int array[n], int (*cmp)(int,int)){
for (int i = 0; i < n; i++){
    for ( int j = 0; j < n-i-1; j++){
      if (cmp(array[j],array[j + 1])==1){
        int *x1=&array[j];
        int *x2=&array[j+1];
        int temp = *x1;
        *x1 = *x2;
        *x2 = temp;
      }
    }
  }
}

  int sort_desc(int x1, int x2){
    if(x1<x2){
      return 1;
    }
    else{
      return 0;
    }
  }

  int sort_asc(int x1, int x2){
    if(x1>x2){
      return 1;
    }
    else{
      return 0;
    }
  }

  int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
      printf("Enter an element of the array: ");
      scanf("%d",&a[i]);
    }
    bubblesort(n,a,sort_desc);
    printf("\nArray sorted in descending order\n");
    for(int i=0;i<n;i++){
      printf(" %d",a[i]);
    }
    bubblesort(n,a,sort_asc);
    printf("\nArray sorted in ascending order\n");
    for(int i=0;i<n;i++){
      printf(" %d",a[i]);
    }
    return 0;
  }
