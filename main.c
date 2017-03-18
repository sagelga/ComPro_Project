// Why do I need to include this so much library? I don't really know why.
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Declare all the functions that will be used.
void switch_hub();
void terminate();
void terminal_ruler();

int main(){
// This function will throw in Interface functions to the users.
    printf("\t\tWelcome to POS Systems!");
    switch_hub();
    return 0;
}

void switch_hub() {
// This function will be the STARTUP PROGRAM INTERFACES
    char username[] = "Kumamon";
    printf("\n\nWhat do you like to do?\t\tSign in as %.6s\n_________________________________________________\n",username);

    // Choose the following functions. Can be programmed in 1 character (from 1-9 and a-z and A-Z)
    printf("1: Login\t\t2: Check Stock\n3: Sales Export\t\t4: Quit\nS: Check Screen Size\n");

    printf("\nPlease type in your desire! >>> ");
    char functionscall;
    scanf(" %c", &functionscall);

    // Calls other function that are separately programmed
    switch (functionscall) {
        case ('1'):

            return;
        case ('2'):

            return;
        case ('3'):

            return;
        case ('4'):
            printf("Are you really sure about this? (Type Y or N) >>");
            terminate();
            return;
        case('S'):
            // Calling the >>terminal_ruler<< function
            printf("Ok. We will try to configure your screen");
            terminal_ruler();
            return;
        default:
            // The input is invalid. Trying to route back to ask for a valid input
            printf("Your input is invalid. Please try again.\n\n\n");
            switch_hub();
            return;
    }
}

void terminate(){
    // Type in the text that will be displayed after the user wants to terminate the program
    char text;
    scanf(" %c",&text);
    text = toupper(text);
    switch(text){
        case ('Y'):
            printf("Have a good luck. Bye Bye!");
            return;
        case ('N'):
            printf("I'm so happy that you're back! Redirecting.......\n\n");
            switch_hub();
            return;
        default:
            printf("Your input is invalid. Please try again.");
            terminate();
            return;
    }
}

void terminal_ruler(){

}