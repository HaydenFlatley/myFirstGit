#include "common.h"

void getCalc(char* exp){
	int nums[20], ops[20], size=0, opsSize=0;
	//extract ops
	for (int i = 0; i < strlen(exp); i++){
		if (!(exp[i] <42 || exp[i] > 47)){
			ops[opsSize] = exp[i];
			opsSize ++;
		}
	}
	char* token;
	const char delim[] = "+-*/";
	token = strtok(exp,delim);
	nums[size] = atoi(token);
	//extract numbers using ops as tokens
	while(token!=NULL){
		size ++;
		token = strtok(NULL,delim);
		nums[size] = atoi(token);
	}
	printf("%.2lf\n",evaluate(nums, ops, size));
}

void getTime(){
	time_t now = time(0);
	struct tm* currentTime = localtime(&now);
	printf("%d:%d:%d\n",currentTime->tm_hour, currentTime->tm_min, currentTime->tm_sec);
}

void printPath(){
	char path[100];
	if (getcwd(path,sizeof(path))!=NULL){
		printf("Current dir: %s\n",path);
	}
}

void getSortedDir(){
	char path[100];
	if (getcwd(path,sizeof(path))!=NULL){
		sortDirectory(path);
	}
}

int main(){
	while(1){
		char command[7];
		scanf("%s",command);
		if (!(strcmp(command,"calc"))){
			char expression[20];
			scanf("%s",expression);
			getCalc(expression);
		}else if (!(strcmp(command,"time"))){
			getTime();
		}else if (!(strcmp(command,"path"))){
			printPath();
		}else if (!(strcmp(command,"dump"))){
			getSortedDir();
		}else if (!(strcmp(command,"list"))){

		}else{
			printf("Unknown command\n");
		}
	}


	return 0;
}