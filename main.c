#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void tutorials();
void switchhub();

int main(){
    void tutorials();
    return 0;
}

void tutorials(){
// This function will give the user instructions to switch to the correct functions.
    printf("Initializing the POS Systems...\n");
    printf("[--------------------------------------------------]\n");
    printf("|          Hello! This is the POS Systems!         |\n");
    printf("[--------------------------------------------------]\n");
    printf("               What do you like to do?\n");
    printf("1: Login \t\t\t\t\t2: Check Inventory\n3: Check inventory\t\t\t4: Quit\n");
    void switch_hub();
}

void switch_hub(){
// This function will be the startup program interface.
    printf("Please type in your desire! >>");
    char functionscall;
    scanf("%[^\n]",&functionscall);
    switch (functionscall){
        case ('1'):

            break;
        case ('2'):

            break;
        case ('3'):

            break;
        default:
            printf("Your input is unregcognizable. Please try again.");
            void switch_hub();
    }
}
