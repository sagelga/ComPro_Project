// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

/*---------------------------------------------------------------------------*/
int main(){
// This program will run first. POS Interface configuration will be called, and ready to work.
    screenClear();
    screenAdjust();
    return 0;
}

void switchHub() {
    // New Switch Hub
    char text1[107] = "Welcome back <user_name_goes_here>!";
    char text2[107] = "";
    char text3[107] = "You are now connecting to the POS system";
    char text4[107] = "<user_permission_level_goes_here_in_this_line>";
    bannerInverse(text1, text2, text3, text4);

    bannerBlankBorderText("What do you want to do?");
    bannerBlankBorder();

    //These choice will be removed, when the program detects the permission level.
    bannerBlankBorderText("1. Login / Logout");
    bannerBlankBorderText("2. Go to Sales");
    bannerBlankBorderText("3. Check Inventory Database");
    bannerBlankBorderText("4. Check Customer Database");
    bannerBlankBorderText("5. Check Category Database");
    bannerBlankBorderText("6. Check Customer Database");
    bannerBlankBorderText("7. Check Forecast");
    bannerBlankBorderText("8. Settings");
    bannerBlankBorder();

    for (int i = 0;i<20;i++)
        bannerBlankBorder();

    bannerBlankBorderText("                                                  or type 'N' to save and quit");
    bannerFullBorder();
    bannerBlankTerminate();

    char functionscall;
    scanf(" %c", &functionscall);

    switch (functionscall) {
        case ('1'):
            initDatabase();
            return;
        
        case ('2'):
            initDatabase();
            return;
        
        case ('3'):
            initDatabase();
            return;
        
        case ('n'):
            terminate();
            return;
        
        case ('N'):
            terminate();
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
    screenClear();

    bannerFullBorder();
    bannerBlankBorderText("                            You about to terminate the POS system...");
    bannerFullBorder();

    printf("Are you really sure about this? (Type Y or N) >>");

    char text;
    scanf(" %c",&text);
    text = toupper(text);

    switch(text){
        case ('Y'):
            printf("Shutting the program down.... Please be patient!\n");
            printf("Have a good luck. Bye Bye!\n");
            exit(0);

        case ('N'):
            printf("I'm so happy that you're back! Redirecting.......\n\n");
            screenClear();
            return;

        default:
            printf("Your input is invalid. Please try again.");
            terminate();
            return;
    }
} 


void screenAdjust(){
                     //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::70 chart 
                     //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    char text1[107] = "";
    char text2[107] = "  This is the initiation of the POS Systems!";
    char text3[107] = "  The program screen size is optimized for 140 x pixel terminal";
    char text4[107] = "";
    banner(text1, text2, text3, text4);
    
    for (int i = 0;i<3;i++)
        bannerBlankBorder();
    
    bannerBlankBorderText("            The box is 140 x 40 pixel in size. If any lines has broken, please configure the terminal screen to optimum size.");
    bannerBlankBorderText("            -----------------------------------------------------------------------------------------------------------------");
    
    for (int i = 0;i<26;i++)
        bannerBlankBorder();
    
    bannerBlankBorderText("                                                   Please type 'Y' to continue...");
    bannerFullBorder();

    bannerBlankTerminate();
    char flags;
    scanf(" %c",&flags);
    flags = toupper(flags);

    switch (flags){

        case('Y'):
            screenClear();
            switchHub();
            return;

        case('N'):
            screenClear();
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
    system("clear");
}

void banner(char *bannerLine1, char *bannerLine2, char *bannerLine3, char *bannerLine4){
    // This function will print out the official banner.
    printf(":: ██████╗  ██████╗ ███████╗ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf(":: ██╔══██╗██╔═══██╗██╔════╝ :: %-105s ::\n", bannerLine1);
    printf(":: ██████╔╝██║   ██║███████╗ :: %-105s ::\n", bannerLine2);
    printf(":: ██╔═══╝ ██║   ██║╚════██║ :: %-105s ::\n", bannerLine3);
    printf(":: ██║     ╚██████╔╝███████║ :: %-105s ::\n", bannerLine4);
    printf(":: ╚═╝      ╚═════╝ ╚══════╝ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
}

void bannerInverse(char *bannerLine1, char *bannerLine2, char *bannerLine3, char *bannerLine4){
    // This function will print out the official banner.
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ██████╗  ██████╗ ███████╗ ::\n");
    printf(":: %105s :: ██╔══██╗██╔═══██╗██╔════╝ ::\n", bannerLine1);
    printf(":: %105s :: ██████╔╝██║   ██║███████╗ ::\n", bannerLine2);
    printf(":: %105s :: ██╔═══╝ ██║   ██║╚════██║ ::\n", bannerLine3);
    printf(":: %105s :: ██║     ╚██████╔╝███████║ ::\n", bannerLine4);
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ╚═╝      ╚═════╝ ╚══════╝ ::\n");
}

void bannerFullBorder(){
    for (int i = 0;i<140;i++)
        printf(":");
    printf("\n");
}

void bannerBlankBorderText(char *text){
    int charLength = strlen(text);
    int leftAlign = (134-charLength)/2;
    int rightAlign = (134-charLength)/2;

    printf(":: ");
    for (int i =leftAlign;i>0;i--);
        printf(" ");
    
    for (int i = rightAlign;i>0;i--);
        printf(" ");
    printf(" ::\n");
    //printf(":: %-134s ::\n", text);
}

void bannerBlankBorder(){
    printf("::%136s::\n", "");
}

void bannerBlankTerminate(){
    printf("What do you want to do? >>> ");
}

void settings(){
    bannerFullBorder();
    bannerBlankBorderText("                                                Settings");
    bannerFullBorder();

    bannerBlankBorderText("What do you want to do?");
    bannerBlankBorderText("1. Change Username");
    bannerBlankBorderText("2. Change Password");
    
    bannerFullBorder();
    
    bannerBlankBorderText("3. Change store name");
    bannerBlankBorderText("4. Change store address");

    char functionSwitch;
    scanf("%c", &functionSwitch);

    switch(functionSwitch){

        case ('1'):
            return;
        default:
            return;

    }
}

int isFileExist(const char *filename){
    if( access( filename, F_OK ) != -1 ) {
        // file exists
        return 1;
    } else {
        // file doesn't exist
        return 0;
    }
}

void initDatabase(){

    personnelDatabase();
    inventoryDatabase();
    categoryDatabase();
    transactionDatabase();
    purchaseDatabase();
    customerDatabase();
    promotionDatabase();
    settingDatabase();

}

void personnelDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(personnelDatabaseFile)){
        fopen(personnelDatabaseFile, "w");
    }
}

void inventoryDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(inventoryDatabaseFile)){
        fopen(inventoryDatabaseFile, "w");
    }

}
void categoryDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(categoryDatabaseFile)){
        fopen(categoryDatabaseFile, "w");
    }

}
void transactionDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(transactionDatabaseFile)){
        fopen(transactionDatabaseFile, "w");
    }

}
void purchaseDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(purchaseDatabaseFile)){
        fopen(purchaseDatabaseFile, "w");
    }

}
void customerDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(customerDatabaseFile)){
        fopen(customerDatabaseFile, "w");
    }

}
void promotionDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(promotionDatabaseFile)){
        fopen(promotionDatabaseFile, "w");
    }

}
void settingDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(settingDatabaseFile)){
        fopen(settingDatabaseFile, "w");
    }

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
          Please. No bug. No crash. No interrupt.         
*/

/* :: ██████╗  ██████╗ ███████╗ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
   :: ██╔══██╗██╔═══██╗██╔════╝ :: Welcome to the POS System program.                                                                        ::
   :: ██████╔╝██║   ██║███████╗ :: Please feel free to look around...                                                                        ::
   :: ██╔═══╝ ██║   ██║╚════██║ :: Created by the 1st year student of Information Technology Ladkrabang.                                     ::
   :: ██║     ╚██████╔╝███████║ :: Redistribution or copies are not allowed. No commercial use is allowed.                                   ::
   :: ╚═╝      ╚═════╝ ╚══════╝ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

      Lists of the team members
      Kunanon Srisuntiroj      @sagelga         59070022    UI Team
      Thanawat Laodkaew        @skydddoogg      59070071    Background Work Team
      Noppanut Ploywong        @noppanut15      59070082    Background Work Team
      Vasanchai Prakobkij      @59070156        59070156    Background Work Team
  
 */

