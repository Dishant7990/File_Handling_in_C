#include<stdio.h>
#include<string.h>

void updateDataOfFie(const char *inputfile, const char *outputfile);

int main(){
	updateDataOfFile("task2.txt", "updated_task2.txt");
	return 0;
}

void updateDataOfFile(const char *ifile, const char *ofile){
	FILE *fp;
	fp = fopen(ifile, "r");
	if(fp == NULL){
		printf("Input file is not open !!\n");
		return;
	}
	
	FILE *fp2;
	fp2 = fopen(ofile, "w");
	if(fp2 == NULL){
		printf("Output File is not open !!\n");
		return;
	}

	char buffer[100];
	char name[50];
	char lastname[50];
	int age;
	float salary;

	while(fgets(buffer, sizeof(buffer), fp) != NULL){
		if(sscanf(buffer, "Person name : %[^\n]s", name) == 1){
			printf("Enetr Lastname of '%s' : ", name);
			//scanf("%[^\n]s", lastname);
			fgets(lastname, sizeof(lastname), stdin);
			int len = strlen(lastname);
			if(len > 0 && lastname[len - 1] == '\n'){
				lastname[len - 1] = '\0';
			}


			fgets(buffer, sizeof(buffer), fp);
			sscanf(buffer, "age : %d", &age);

			fgets(buffer, sizeof(buffer), fp);
			sscanf(buffer, "salary : %f", &salary);

			fprintf(fp2,"Person name \t: %s\n", name);
			fprintf(fp2, "Lastname \t: %s\n", lastname);
			fprintf(fp2, "Age \t\t: %d\n", age);
			fprintf(fp2, "Salary \t\t: %.2f\n\n", salary);

		}
	}

	fclose(fp);
	fclose(fp2);
	printf("\nLast names added and saved to %s.\n", ofile);
}
