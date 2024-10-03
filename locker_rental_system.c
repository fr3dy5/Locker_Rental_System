/*
Create a program designed to simulate the management of locker rentals that 
1. allows users to rent lockers, 
2. view the contents of a specific locker, 
3. end a locker rental, 
4. list the contents of all rented lockers.
Program should provide a menu-driven interface for users to make choices 
and can be implemented using 
1. constants, 
2. arrays, 
3. strings, 
4. functions, 
5. standard library functions, 
6.switch and break statements, 
7. loops, 
8.Boolean operators 
9. conditional statements.
*/

#include <stdio.h>

#define MAX_LOCKERS 100
#define MAX_ITEM_LENGTH 50

int Lockers[MAX_LOCKERS][MAX_ITEM_LENGTH] = {0};


int main() {
    int userInput;
    
    printf("Locker Rental Menu\n=============================\n");
    printf("1. View a locker\n2. Rent a locker\n3. End a locker rental\n4. List all locker contents\n5. Quit\n");
    printf("\nEnter your choice (1-5): ");
    scanf("%d", userInput);

        switch (userInput)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;    
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            printf("Exiting the program. Goodbye!\n");
            break;    
        default:
            break;
        }
    
    return 0;
}