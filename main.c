#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void switch_hub(text);

int main(){
// This function will throw in Interface functions to the users.
    printf("[--------------------------------------------------]\n|          Hello! This is the POS Systems!         |\n[--------------------------------------------------]\n");
    printf("Please type '1' to start\n");
    int text;
    scanf("%d",&text);

    if (text == 1)
        switch_hub(text);
    return 0;
}

void switch_hub(text){
// This function will be the startup program interface.
    printf("\t\t\tWhat do you like to do?\n");

    // Choose the following functions. Can be programmed in 1 character (from 1-9 and a-z and A-Z)
    printf("1: Login \t\t\t\t\t2: Check Inventory\n3: Check inventory\t\t\t4: Quit\n");

    printf("Please type in your desire! >>");
    char functionscall;
    scanf("%[^\n]",&functionscall);

    // Calls other function that are separately programmed
    switch (functionscall){
        case ('1'):

            break;
        case ('2'):

            break;
        case ('3'):

            break;
        default:
            // Route back to ask for a valid input
            printf("Your input is unregcognizable. Please try again.");
            //switch_hub();
    }
    //return 0;
}
