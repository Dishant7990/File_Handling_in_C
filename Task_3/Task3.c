#include<stdio.h>	// for printf, scanf
#include<string.h>

int main(){
	FILE *fp;
	fp = fopen("task2.txt", "r");
	if(fp == NULL){
		printf("File is not open !!\n");
		return -1;
	}

	char buffer[10];
	while(fgets(buffer, 10, fp) != NULL){
	printf("%s", buffer);
	}

	fclose(fp);

	return 0;
}
