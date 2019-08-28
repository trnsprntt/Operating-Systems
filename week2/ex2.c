#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

char s[100];
/*size_t size = 30;
s = (char *)malloc(size * sizeof(char));
int length = getline(&s,&size,stdin);
*/
printf("Please enter a string\n");
scanf("%s",s);
for(int i=strlen(s)-1;i>=0;i--){
  printf("%c", *(s+sizeof(char)*i));
}
return 0;
}
