#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdbool.h>
int main(int argc, char** argv){
  size_t size;
  char tmp[1000];
	int length;
	char* op;
	if (argc == 1){
		char buf;
		while(fread(&buf, 1, 1, stdin))
			printf("%c",buf);
		return 0;
	}
	if (strcmp(argv[1], "-a")){
		length = argc;
		op = "w+";
	}
	else{
    length = argc - 1;
		op = "a+";
	}
	FILE **output = malloc(length * sizeof(FILE*));
	output[0] = stdout;
	for(int i=1;i<argc+1;i++){
		output[i] = fopen(argv[i + argc - length], op);
  }
	while((size = fread(tmp, 1, 1000, stdin))){
		for(int j = 0; j < length; j++){
			for(int k = 0; k < size; k++){
				fwrite(&tmp[i], 1, 1, output[j]);
      }
      fclose(output[j]);
    }
	}
	return 0;
}
