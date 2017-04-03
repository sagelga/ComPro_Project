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

/*-----------------------------------------------------------------------------
Declare all the libraries that we are going to use here*/
#include <stdio.h>              // Pretty much the basic things
#include <string.h>             // Compares strings and other kind of stuff
#include <math.h>               // Calculate difficult 7-years-old Math
#include <stdlib.h>             // IDK what that will do, but I added it anyways...
#include <time.h>               // Synchronize and manage the time between program and you
#include <ctype.h>              // Compares the string to type of string

/*-----------------------------------------------------------------------------
Declare all the global variables here*/
char username[140] = "Kumamon";
int userPermission = 0; // 0 = Not sign in | 1 = Sales | 2 = Manager | 3 = Admin

/*-----------------------------------------------------------------------------
Declare all the gimmicks functions*/
void switchHub();               // For moving to the selection of the functions
void terminate();               // For save and stop the program
void screenAdjust();            // For calculating the screen size to the optimum size
void screenClear();             // For refreshing the screen to the new one
void settings();                // For setting up the screensize, default login scheme

/*-----------------------------------------------------------------------------
Declare all the gimmicks functions*/
void bannerFullBorder();
void bannerBlankBorder(char text);
void bannerBlankBorderText();
void banner(char bannerLine1, char bannerLine2, char bannerLine3, char bannerLine4); // For showing the program banner

/*-----------------------------------------------------------------------------
Declare all the database file !!build!! functions*/
void customerDatabase();        // For Customer Database
void transactionDatabase();     // For Transaction Database
void inventoryDatabase();       // For Inventory Database
void salesDatabase();           // For Sales Database
void promotionDatabase();       // For Promotion Database

/*-----------------------------------------------------------------------------
Declare all the database file >>Read>> functions*/
void customerFileRead();        // For Customer Database
void transactionFileRead();     // For Transaction Database
void inventoryFileRead();       // For Inventory Database
void salesFileRead();           // For Sales Database
void promotionFileRead();       // For Promotion Database

/*-----------------------------------------------------------------------------
Declare all the database file <<Write<< functions*/
void customerFileWrite();       // For Customer Database
void transactionFileWrite();    // For Transaction Database
void inventoryFileWrite();      // For Inventory Database
void salesFileWrite();          // For Sales Database
void promotionFileWrite();      // For Promotion Database

/*-----------------------------------------------------------------------------
Declare all the database call functions*/

/*-----------------------------------------------------------------------------
Declare all the interface functions*/

/*-----------------------------------------------------------------------------
Declare all the admin tools*/
void adminAuthenticate();
void adminRoleAuthen();
void adminRoleDeauthen();
void adminBackgroundMaintain();

/*-----------------------------------------------------------------------------
Declare all the Inventory can do*/
void inventoryAdd();
void inventoryModify();
void inventoryRemove();

/*-----------------------------------------------------------------------------
Declare all the Customer Database can do*/
void customerAdd();
void customerModify();
void customerRemove();

/*-----------------------------------------------------------------------------
Declare all the Sales Database can do*/
void SaleAdd();
void SaleModify();
void SaleRemove();

/*-----------------------------------------------------------------------------
Declare all the forecast function can do*/
void monthlyForecast();
void quarterForecast();
void annualForecast();

void forecastResults();
void forecastProgram();

void forecastPrint();

/*-----------------------------------------------------------------------------
Declare all the Promotion Database can do*/
void promotionAdd();
void promotionModify();
void promotionRemove();

/*-----------------------------------------------------------------------------
Declasre what the seller can do*/
void cashierInterface();

/*-----------------------------------------------------------------------------
Declares all the authentication functions and interface*/
void authenticate();            // For signing in
void deauthenticate();          // For signing out
//
void authenInternface();
void authenInterfaceComplete();
void authenInterfaceFailed();
void authenInternfaceError();

/*---------------------------------------------------------------------------*/
int main(){
// This program will run first. POS Interface configuration will be called, and ready to work.
    screenAdjust();
    switchHub();
    return 0;
}

void switchHub() {
    // This function will be the STARTUP PROGRAM INTERFACES
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
          //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::70 chart 
    char text1[107] = "";
    char text2[107] = "                                       This is the initiation of the POS Systems!";
    char text3[107] = "              The program screen size is optimized for 140 x pixel terminal";
    char text4[107] = "";
    //banner(text1, text2, text3, text4);
    bannerBlankBorderText();
    printf("::                                                        140 x 40 pixel terminal                                                          :\n");
    for (int i = 0;i<3;i++){
        bannerBlankBorderText();
    }
    printf("::            The box is 140 x 40 pixel in size. If any lines has broken, please configure the terminal screen to optimum size.            :\n");
    printf("::            -----------------------------------------------------------------------------------------------------------------            :\n");
    for (int i = 0;i<27;i++){
        bannerBlankBorderText();
    }
    printf("::                                                         Please type 'Y' to continue...                                                  :\n");
    bannerFullBorder();

    char flags;
    scanf("%c",&flags);
    flags = toupper(flags);

    switch (flags){

        case('Y'):
            return;

        case('N'):
            terminate();
            return;

        default:
            screenClear();
            printf("Invalid response. Try again. \n\n");
            screenAdjust();
            return;
    }
}

void screenClear(){
    // This function will clean the screen, and the other function will reprint the page.
    system("@cls||clear");
}

void banner(char bannerLine1, char bannerLine2, char bannerLine3, char bannerLine4){
    // This function will print out the official banner.
    char bannerLine1 = *bannerLine1;
    char bannerLine2 = *bannerLine2;
    char bannerLine3 = *bannerLine3;
    char bannerLine4 = *bannerLine4;    
    printf(":: ██████╗  ██████╗ ███████╗ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf(":: ██╔══██╗██╔═══██╗██╔════╝ ::%-107s::\n", bannerLine1);
    printf(":: ██████╔╝██║   ██║███████╗ ::%-107s::\n", bannerLine2);
    printf(":: ██╔═══╝ ██║   ██║╚════██║ ::%-107s::\n", bannerLine3);
    printf(":: ██║     ╚██████╔╝███████║ ::%-107s::\n", bannerLine4);
    printf(":: ╚═╝      ╚═════╝ ╚══════╝ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
}

void bannerFullBorder(){
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
}

void bannerBlankBorder(char text){
    printf(":: %-137s ::",text);
}

void bannerBlankBorderText(){
    printf("::%139s::\n", "");
}
/*

                May the god be with us...
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
                Program bug best enemy
        Please. No bug. No crash. No interruption.         */


