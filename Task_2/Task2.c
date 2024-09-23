#include <stdio.h>
#include <string.h>

struct Person {
	char name[50];
	int age;
	float salary;
};

void writeDataToFile(struct Person, FILE *fp);
void readPerson(struct Person *, FILE *fp);

int main() {
	int numPerson = 0;

	printf("How many people do you want to enter ?\n");
	scanf("%d", &numPerson);

	FILE *fp = NULL;
	fp = fopen("task2.txt", "w");
	if(fp == NULL){
		printf("File is not open !!\n");
		return -1;
	}
	struct Person people[numPerson];

	for (int i = 0; i < numPerson; i++) {
		readPerson(&people[i], fp);
	}


	/*char nameToSearch[50];
	printf("\nEnter the name of the person you want to search for: ");
	scanf("%s", nameToSearch);


	int index = searchTown(people, nameToSearch);

	if (index != -1) {
		printf("This person lives in %s\n", people[index].town);
	} else {
		printf("The name entered is not present in the array.\n");
	}*/

	fclose(fp);

	return 0;
}

void writeDataToFile(struct Person p, FILE *fp){
	fprintf(fp, "Person name \t: %s\n", p.name);
	fprintf(fp, "age	 \t: %d\n", p.age);
	fprintf(fp, "salary 	 \t: %.2f\n\n", p.salary);
}

void readPerson(struct Person *p, FILE *fp) {
	printf("Enter person name: ");
	scanf(" %[^\n]s", p->name);
	printf("Enter %s's age : ", p->name);
	scanf("%d", &p->age);
	printf("Enter %s's salary :", p->name);
	scanf("%f", &p->salary);
	
	writeDataToFile(*p, fp);
}

