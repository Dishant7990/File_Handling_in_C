#include<stdio.h>
#include<string.h>

void searchPersonData(FILE *,const char *);

int main(){
	char personName[40];
	printf("Enter a person name : ");
	scanf("%[^\n]s", personName);

	FILE *fp;
	fp = fopen("task2.txt", "r");
	if(fp == NULL){
		printf("File is not open!!\n");
		return 1;
	}

	searchPersonData(fp, personName);

	fclose(fp);
	return 0;
}

void searchPersonData(FILE *fp, const char *nameToSearch){
	char buffer[100];
	char name[30];
	int age;
	float salary;
	int found = 0;

	while(fgets(buffer, sizeof(buffer), fp) != NULL){
		if(sscanf(buffer, "Person name : %[^\n]s", name) == 1){

			if(strcmp(name, nameToSearch) == 0){
				fgets(buffer, sizeof(buffer), fp);
				sscanf(buffer, "age : %d", &age);

				fgets(buffer, sizeof(buffer), fp);
				sscanf(buffer, "salary : %f", &salary);

				printf("Person found :\n");
				printf("Name \t: %s\n", name);
				printf("Age\t: %d\n", age);
				printf("Salary\t: %.2f\n", salary);

				found = 1;
				break;		
			}
		}
	}

	if(!found){
		printf("Person with name '%s' not found.\n", nameToSearch);
	}
}
