
# Task 1

Write a program that asks the user to enter the name and the home town of 3 persons. Name and home town are stored in a structure Person. The 3 persons are stored in an array. Afterwards, the program asks the user to enter a name and searches the town that person lives in.

Use the functions readPerson and searchTown

The function searchTown has 2 arguments:

- the array that needs to be searched

- a variable of the type Person that contains the name that needs to be searched. The town member of that variable needs to be filled with the town found by the function searchTown.

Reading the name of the person you want to search for is done in the main function. Printing the resulting town can also be done in the main function. If the name entered is not present in the array, an appropriate message needs to be printed.

```bash
Enter name: Prit

Enter town or city: Rajkot

Enter name: Yash

Enter town or city: V V Nagar

Enter name: Yogi

Enter town or city: Anand

==========================================================

Enter the name of the person you want to search for: Yogi
This person lives in Anand

```