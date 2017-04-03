// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

/*---------------------------------------------------------------------------*/
int main(){
// This program will run first. POS Interface configuration will be called, and ready to work.
    screenAdjust();
    switchHub();
    initDatabase();
    return 0;
}

void init(){
    // Initial the value of Record counter
    RecordCount.personnel = 0;
    RecordCount.inventory = 0;
    RecordCount.category = 0;
    RecordCount.transaction = 0;
    RecordCount.purchase = 0;
    RecordCount.customer = 0;
    RecordCount.promotion = 0;
}

void switchHub() {
    // New Switch Hub

    /* Original switchHub();
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
    */
}

void terminate(){
    // Type in the text that will be displayed after the user wants to terminate the program
    printf("Are you really sure about this? (Type Y or N) >>");
    char text;
    scanf(" %c",&text);
    text = toupper(text);
    switch(text){
        case ('Y'):
            printf("Have a good luck. Bye Bye!");
            return;

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
    
    for (int i = 0;i<27;i++)
        bannerBlankBorder();
    
    bannerBlankBorderText("                                                         Please type 'Y' to continue...");
    bannerFullBorder();

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

void bannerFullBorder(){
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
}

void bannerBlankBorderText(char *text){
    printf(":: %-134s ::\n", text);
}

void bannerBlankBorder(){
    printf("::%136s::\n", "");
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
/*
unsigned int tailIndex(unsigned int table){
    if(table == 1){
        // PersonnelDatabase

    }

}*/

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

    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer
    char id[MAX_LNG_ID];
    char firstname[MAX_LNG_TEXT];
    char lastname[MAX_LNG_TEXT];
    int role;                           // 0 = Manager | 1 = Marketing | 2 = Sale
    char username[MAX_LNG_TEXT];
    char password[MAX_LNG_TEXT];
    char barcode_token[MAX_LNG_TOKEN];  // For use a barcode authentication

    int i = 0;
    fp = fopen(personnelDatabaseFile, "r");

    while(fscanf(fp, "%s\t%[^\t]\t%[^\t]\t%d\t%[^\t]\t%[^\t]\t%[^\n]", Personnel[i].id, Personnel[i].firstname, Personnel[i].lastname, &Personnel[i].role, Personnel[i].username, Personnel[i].password, Personnel[i].barcode_token) != EOF){
        i++;
    }

    RecordCount.personnel = i;          // Save a number of records to the Record Counter
    fclose(fp);

    // For debuging
    // i--;
    // printf(">>>> %s-%s-%s-%d-%s-%s-%s\n", Personnel[i].id, Personnel[i].firstname, Personnel[i].lastname, Personnel[i].role, Personnel[i].username, Personnel[i].password, Personnel[i].barcode_token);
}

void inventoryDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(inventoryDatabaseFile)){
        fopen(inventoryDatabaseFile, "w");
    }

    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer
    char id[MAX_LNG_ID];
    char name[MAX_LNG_SCREEN];
    double price;
    double profit; // Profit per item
    char categoryId[MAX_LNG_ID]; // Category ID
    unsigned int remain;

    int i = 0;
    fp = fopen(inventoryDatabaseFile, "r");

    while(fscanf(fp, "%s\t%[^\t]\t%lf\t%lf\t%s\t%u", Inventory[i].id, Inventory[i].name, &Inventory[i].price, &Inventory[i].profit, Inventory[i].categoryId, &Inventory[i].remain) != EOF){
        i++;
    }

    RecordCount.inventory = i;          // Save a number of records to the Record Counter
    fclose(fp);

    // For debuging
    // i--;
    // printf(">>>> %s\t%s\t%lf\t%lf\t%s\t%u\n", Inventory[i].id, Inventory[i].name, Inventory[i].price, Inventory[i].profit, Inventory[i].categoryId, Inventory[i].remain);

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
        Please. No bug. No crash. No interruption.         */


