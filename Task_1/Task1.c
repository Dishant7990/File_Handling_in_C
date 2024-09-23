#include <stdio.h>
#include <string.h>

#define N 3
struct Person {
    char name[50];
    char town[50];
};

void readPerson(struct Person *p) {
    printf("Enter name: ");
    scanf("%s", p->name);
    printf("Enter town or city: ");
    scanf("%s", p->town);
}


int searchTown(struct Person arr[], char nameToSearch[]) {
    for (int i = 0; i < N; i++) {
        if (strcmp(arr[i].name, nameToSearch) == 0) {
            return i;  // Return the index of the found person
        }
    }
    return -1;  // Return -1 if the name is not found
}

int main() {
    struct Person people[N];
    
    for (int i = 0; i < N; i++) {
        readPerson(&people[i]);
    }

    char nameToSearch[50];
    printf("\nEnter the name of the person you want to search for: ");
    scanf("%s", nameToSearch);
    

    int index = searchTown(people, nameToSearch);

    if (index != -1) {
        printf("This person lives in %s\n", people[index].town);
    } else {
        printf("The name entered is not present in the array.\n");
    }
    
    return 0;
}

