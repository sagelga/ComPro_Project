/* Welcome to the POS System program.
 * Please feel free to look around...
 * Created by the 1st year student of Information Technology Ladkrabang.
 * Redistribution or copies are not allowed. No commercial use is allowed.
 *
 * Thank you for participating.
 * The Team

 * ---------------------
 * Lists of the team members
 * Kunanon Srisuntiroj @sagelga Lead UI Team
 * Noppanut Ploywong @noppanut Lead Background Work Team
 *
 */

// Declare all the libraries that we are going to use here
#include <stdio.h>              // Pretty much the basic things
#include <string.h>             // Compares strings and other kind of stuff
#include <math.h>               // Calculate difficult 7-years-old Math
#include <stdlib.h>             // IDK what that will do, but I added it anyways...
#include <time.h>               // Synchronize and manage the time between program and you
#include <ctype.h>              // Compares the string to type of string

// Declare all the gimmicks functions
void switchHub();               // For moving to the selection of the functions
void terminate();               // For save and stop the program
void screenAdjust();           // For calculating the screen size to the optimum size
void screenclear();             // For refreshing the screen to the new one
void banner();                  // For showing the program banner
void settings();                // For setting up the screensize, default login scheme
void authenticate();            // For signing in
void deauthenticate();          // For signing out

// Declare all the database functions
void customerDatabase();        // For Customer Database
void transactionDatabase();     // For Transaction Database
void inventoryDatabase();       // For Inventory Database
void salesDatabase();           // For Sales Database
void promotionDatabase();       // For Promotion Database

// Declare all the database retrieval functions
void customerFileRead();        // For Customer Database
void transactionFileRead();     // For Transaction Database
void inventoryFileRead();       // For Inventory Database
void salesFileRead();           // For Sales Database
void promotionFileRead();       // For Promotion Database

// Declare all the database retrieval functions
void customerFileWrite();       // For Customer Database
void transactionFileWrite();    // For Transaction Database
void inventoryFileWrite();      // For Inventory Database
void salesFileWrite();          // For Sales Database
void promotionFileWrite();      // For Promotion Database

// Declare all the database storage functions

// Declare all the interface functions

// Declare all the admin tools
void adminAuthenticate();
void adminRoleAuthen();
void adminRoleDeauthen();
void adminBackgroundMaintain();

// Declare all the Inventory can do
void inventoryAdd();
void inventoryModify();
void inventoryRemove();

// Declare all the Customer Database can do
void customerAdd();
void customerModify();
void customerRemove();

// Declare all the Sales Database can do

// Declare all the Promotion Database can do

// Declasre what the seller can do
void cashierInterface();

// Declares all the authentication interface
void authenInternface();
void authenInterfaceComplete();
void authenInterfaceFailed();
void authenInternfaceError();

int main(){
    // Starting with is function. POS Interface need to be configurated and ready to work.
    screenAdjust();
    //switch_hub();
    return 0;
}

void switchHub() {
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
            screenAdjust();
            return;
        default:
            // The input is invalid. Trying to route back to ask for a valid input
            printf("Your input is invalid. Please try again.\n\n\n");
            switchHub();
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
            switchHub();
            return;
        default:
            printf("Your input is invalid. Please try again.");
            terminate();
            return;
    }
} 


void screenAdjust(){
          //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::70 char
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                 The POS system will works perfectly with                                                 :\n");
    printf(":                                                                                                                                          :\n");
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                         140 x 40 pixel terminal                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":             The box is 140 x 40 pixel in size. If any lines has broken, please configure the terminal screen to optimum size.            :\n");
    printf(":             -----------------------------------------------------------------------------------------------------------------            :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf(":                                                                                                                                          :\n");
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
}

void screenClear(){
    // This function will clean the screen, and the other function will reprint the page.
    system("@cls||clear");
}

void banner(){
    // This function will print out the official banner.
    printf("   ██████╗  ██████╗ ███████╗    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("   ██╔══██╗██╔═══██╗██╔════╝    ::%-160s::\n", "Test");
    printf("   ██████╔╝██║   ██║███████╗    ::%-160s::\n", "Test");
    printf("   ██╔═══╝ ██║   ██║╚════██║    ::%-160s::\n", "Test");
    printf("   ██║     ╚██████╔╝███████║    ::%-160s::\n", "Test");
    printf("   ╚═╝      ╚═════╝ ╚══════╝    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
}

void customerDatabase(){

}
void transactionDatabase(){

}
void inventoryDatabase(){

}
void salesDatabase(){

}
void promotionDatabase(){

}

/*               May the god be with us...
                           _
                        _ooOoo_
                       o8888888o
                       88" . "88
                       (| -_- |)
                       O\  =  /O
                    ____/`---'\____
                  .'  \\|     |//  `.
                 /  \\|||  :  |||//  \
                /  _||||| -:- |||||_  \
                |   | \\\  -  /'| |   |
                | \_|  `\`---'//  |_/ |
                \  .-\__ `-. -'__/-.  /
              ___`. .'  /--.--\  `. .'___
           ."" '<  `.___\_<|>_/___.' _> \"".
          | | :  `- \`. ;`. _/; .'/ /  .' ; |
          \  \ `-.   \_\_`. _.'_/_/  -' _.' /
===========`-.`___`-.__\ \___  /__.-'_.'_.-'================
                        `=--=-'
                Programs' bug best enemy
        Please. No bug. No crash. No interruption.         */


