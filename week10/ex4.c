#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <dirent.h>
#include <sys/stat.h>

int main(){

	char *dir = "./tmp/";
	DIR* dirp = opendir(dir);
	if (dirp == NULL) {
		printf("Directory cannot be opened");
		return -1;
	}

	char name[20];
	struct stat s;
	char path[100];
	char command[100];
	char str[40];
	char tmp[50];
	struct dirent *dp;
	FILE* output = fopen("ex4.txt", "w");

	while ((dp = readdir(dirp)) != NULL){
		strcpy(name,dp->d_name);
		if (name[0] != '.'){
			strcpy(path, dir);
			strcat(path, name);
			stat(path, &s);
			if (s.st_nlink > 1) {
				fprintf(output, "File %s\n %ld links:\n", name, s.st_nlink);
				printf("File %s\n %ld links:\n", name, s.st_nlink);
				snprintf(str, 40, "%ld", s.st_ino);
				strcpy(command, "find ./ -inum ");
				fprintf(output,"%s\n", path);
				strcat(command, str);
				system(command);
			}
		}
	}
	fclose (output);
	return 0;

    }
