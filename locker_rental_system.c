/*
1. When the user selects "View a locker," the program should prompt the user to enter a locker number (1-100) and display the contents of that locker. If the locker is empty, it should display a message indicating that the locker is empty.
2. When the user selects "Rent a locker," the program should prompt the user to enter a locker number (1-100) and the item they want to store in the locker. If the locker is already rented, it should display a message indicating that the locker is unavailable.
3. When the user selects "End a locker rental," the program should prompt the user to enter a locker number (1-100) and end the rental for that locker. If the locker is not currently rented, it should display a message indicating that the locker is not rented.
4. When the user selects "List all locker contents," the program should display the contents of all rented lockers. If no lockers are currently rented, it should display a message indicating that no lockers are rented.
5. When the user selects "Quit," the program should exit.
6. The program should handle invalid user inputs gracefully and display appropriate error messages.
7. The program should continue running until the user chooses to quit.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LOCKERS 100
#define MAX_ITEM_LENGTH 50

//each locker is empty((?) true or false)
struct Locker {
    bool empty;
    char contents[MAX_ITEM_LENGTH];
};

//100 lockers
struct Locker lockers[MAX_LOCKERS];

//at start all lockers are empty
void initLockers() {
    for( int i = 0; i < MAX_LOCKERS; i++) {
        lockers[i].empty = true;
        strcpy(lockers[i].contents, "");
    }
}

//if input negative or over 100 its invalid
void add_item(int lockerNum, const char* contents) {
    if (lockerNum < 0 || lockerNum > MAX_LOCKERS) {
        printf("Sorry, there are only 100 lockers available.\n");
        return;
    }//if its not empty its taken
    if (lockers[lockerNum].empty = false) {
        printf("Sorry, but locker %d has already been rented!\n", lockerNum);
        return;
    }
    
}

int main() {
    int userInput;
    int lockerNum;
    char contents;
   
    printf("Locker Rental Menu\n");
    printf("=============================\n");
    printf("1. View a locker\n2. Rent a locker\n3. End a locker rental\n4. List all locker contents\n5. Quit\n");
    printf("\nEnter your choice (1-5): ");
    scanf("%d", &userInput);

        switch (userInput)
        {
        case 1:
            printf("Enter locker number (1-100): %d\n", lockerNum);
            printf("Locker %d is %s.\n", lockerNum, contents);
            break;
        case 2:
            printf("Enter locker number (1-100): %d\n", Lockers);
            printf("Enter the item you want to store in the locker: \n", contents);
            break;    
        case 3:
            printf("Enter locker number (1-100): %d\n", Lockers);
            printf("Locker %d rental has ended, please take your %s.\n", lockerNum, contents);
            break;
        case 4:
            printf("Locker %d: %s\n", lockerNum, contents);
            break;
        case 5:
            printf("Exiting the program. Goodbye!\n");
            break;    
        default:
            printf("Invalid menu choice\n");
            break;
        }
    
    return 0;
}