#include <stdio.h>
#include <fcntl.h>
int main(){
char s[20];
FILE *fp;
FILE *output = fopen("ex1.txt","w");
fp = fopen("/dev/urandom", "r");
fread(&s, 1, 20, fp);
fputs(s,output);
printf("%s",s);
fclose(fp);
fclose(output);
	return 0;
}
