// Why do I need to include this so much library? I don't really know why.
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void switch_hub();
void terminate();

int main(){
// This function will throw in Interface functions to the users.
    printf("[--------------------------------------------------]\n|          Hello! This is the POS Systems!         |\n[--------------------------------------------------]\n");
    switch_hub();
    return 0;
}

void switch_hub() {
// This function will be the startup program interface.
    printf("\n\n\t\tWhat do you like to do?\n____________________________________________________\n");

    // Choose the following functions. Can be programmed in 1 character (from 1-9 and a-z and A-Z)
    printf("1: Login \t\t\t2: Check Inventory\n3: Check inventory\t\t4: Quit\n");

    printf("Please type in your desire! >>");
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
        default:
            // Route back to ask for a valid input
            printf("Your input is unregcognizable. Please try again.\n");
            switch_hub();
            return;
    }
}

void terminate(){
    // Type in the text that will be displayed after the user wants to terminate the program
    char text;
    scanf(" %c",&text);
    switch(text){
        case ('Y'):
            printf("Have a good luck. Bye Bye!");
            return;
        case ('N'):
            printf("I'm so happy that you're back! Redirecting.......");
            switch_hub();
            return;
        default:
            printf("Your input is invalid. Please try again.");
            terminate();
            return;
    }
}
