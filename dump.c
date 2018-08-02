#include "common.h"

void sortDirectory(char* dir){
	char strings[20][20];
	printf("%s\n",dir);
	DIR *direc;
	int i =0;
	struct dirent *ent;
	if ((direc = opendir(dir)) != NULL){
		while((ent = readdir(direc))!=NULL){
			strcpy(strings[i-2],ent->d_name);
			i++;
		}
		closedir(direc);
	}
	i-=2;
	for (int x= 0; x<i; x++){
		printf("%s\n",strings[x]);
	}
}