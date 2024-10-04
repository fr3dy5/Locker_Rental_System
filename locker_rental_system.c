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

/*
int menudisplay() {
    int choice;
    printf("Locker Rental Menu\n");
    printf("=============================\n");
    printf("1. View a locker\n2. Rent a locker\n3. End a locker rental\n4. List all locker contents\n5. Quit\n");
    printf("\nEnter your choice (1-5): ");
    scanf("%d", &choice);
    return 0;
}*/

//at start all lockers are empty
void initLockers() {
    for( int i = 0; i < MAX_LOCKERS + 1; i++) {
        lockers[i].empty = true;
        strcpy(lockers[i].contents, "");
    }
}

//check locker emptyness or print contents
void lockerCont(struct Locker lockers[], int lockerNumber) {
    if (lockerNumber < 0 || lockerNumber >= (MAX_LOCKERS + 1)) {
        printf("Invalid locker number.\n");
        return;
    }
                //pointer to locker at lockerNumber-index in lockers array
    struct Locker *locker = &lockers[lockerNumber];
    
    if (locker->empty) {
        printf("Locker %d: Empty\n", lockerNumber);
        return;
    } else {
        printf("Locker %d: Contents: %s\n", lockerNumber, locker->contents);
        return;
    }
}

//strncpy to lockers.contents from contents minus a character and replace character with null terminator
void addcont(int lockerNumber, const char* contents) {
    strncpy(lockers[lockerNumber].contents, contents, MAX_ITEM_LENGTH - 1);
    lockers[lockerNumber].contents[MAX_ITEM_LENGTH - 1] = '\0';
    printf("Locker %d has been rented for %s storage\n", lockerNumber, contents);
    return;
}


void endrent(int lockerNum) {
    if (lockers[lockerNum].empty == true) {
        printf("Locker %d is not currently rented\n", lockerNum);
        return;
    } else {
        printf("Locker %d rental has ended, please take you %s\n", lockerNum, lockers[lockerNum].contents);
        //change flag and copy null byte into its place
        lockers[lockerNum].empty = true;
        strncpy(lockers[lockerNum].contents, lockers[lockerNum].contents, '\0');
        return;
    }
}

int main() {
    int userInput;
    int lockerNum;
    char contents[MAX_ITEM_LENGTH];

    //at start all lockers are empty
    initLockers();
   // menudisplay();
   
    printf("Locker Rental Menu\n");
    printf("=============================\n");
    printf("1. View a locker\n2. Rent a locker\n3. End a locker rental\n4. List all locker contents\n5. Quit\n");
    printf("\nEnter your choice (1-5): ");
    scanf("%d", &userInput);

    do {
        //menudisplay();

        switch (userInput)
        {
        case 1:{
            printf("Enter locker number (1-100): \n");
            scanf("%d", &lockerNum);
            lockerCont(lockers, lockerNum);
            }break;
        case 2:
            printf("Enter locker number (1-100): \n");
            scanf("%d", &lockerNum);
            if (lockers[lockerNum].empty) {
                printf("Enter the item you want to store in the locker: \n");
                //take up to 49 char input or new line
                scanf(" %s49[\n]", contents);
                addcont(lockerNum, contents);
                //switch flag to false
                lockers[lockerNum].empty = false;
            } else {
                printf("Sorry but locker %d has already been rented!\n", lockerNum);
            }
            break;    
        case 3:
            printf("Enter locker number (1-100): \n");
            scanf("%d", &lockerNum);
            endrent(lockerNum);
            break;
       /* case 4:
            for (int i = 0;  i < MAX_LOCKERS; i++) {
                if (lockers[i].empty == false)  {
                printf("Locker %d: %s\n", lockerNum, contents);}
           } break;*/
        case 5:
            printf("Exiting the program. Goodbye!\n");
            break;    
        default:
            printf("Invalid menu choice\n");
            break;
        } 
    } while (userInput != 5);
    
    return 0;
}