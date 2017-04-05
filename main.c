// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

/*---------------------------------------------------------------------------*/
int main(){
// This program will run first. POS Interface configuration will be called, and ready to work.
    //screenAdjust();
    //switchHub();
    initDatabase();
    return 0;
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
            printf("Have a good luck. Bye Bye! MyDay");
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

void intToString(char *str, int number){
    char buffer[200];
    sprintf(buffer, "%d", number);
    strcpy(str, buffer);
}

void initDatabase(){
    // Database Initial
    personnelDatabase();
    inventoryDatabase();
    categoryDatabase();
    transactionDatabase();
    purchaseDatabase();
    customerDatabase();
    promotionDatabase();
    settingDatabase();

    // Database Seeding
    personnelFileRead();  
    inventoryFileRead();  
    categoryFileRead();   
    transactionFileRead();
    purchaseFileRead();   
    customerFileRead();   
    promotionFileRead();  
    settingFileRead();    

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

void personnelFileRead(){
    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer

    int i = 0;
    fp = fopen(personnelDatabaseFile, "r");

    while(fscanf(fp, "%s\t%[^\t]\t%[^\t]\t%d\t%[^\t]\t%[^\t]\t%[^\n]", Personnel[i].id, Personnel[i].firstname, Personnel[i].lastname, &Personnel[i].role, Personnel[i].username, Personnel[i].password, Personnel[i].barcodeToken) != EOF){
        i++;
    }

    RecordCount.personnel = i;          // Save a number of records to the Record Counter
    fclose(fp);

    // For debuging
    // i--;
    // printf(">>>> %s-%s-%s-%d-%s-%s-%s\n", Personnel[i].id, Personnel[i].firstname, Personnel[i].lastname, Personnel[i].role, Personnel[i].username, Personnel[i].password, Personnel[i].barcodeToken);

}

void inventoryFileRead(){
    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer

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

void categoryFileRead(){
    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer

    int i = 0;
    fp = fopen(categoryDatabaseFile, "r");

    while(fscanf(fp, "%s\t%[^\n]", Category[i].id, Category[i].name) != EOF){
        i++;
    }

    RecordCount.category = i;          // Save a number of records to the Record Counter
    fclose(fp);

    // For debuging
    // i--;
    // printf(">>>> %s\t%s\n", Category[i].id, Category[i].name);

}

void transactionFileRead(){

    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer

    int i = 0;
    fp = fopen(transactionDatabaseFile, "r");

    while(fscanf(fp, "%s\t%s\t%s", Transaction[i].id, Transaction[i].purchaseId, Transaction[i].inventoryId) != EOF){
        i++;
    }

    RecordCount.transaction = i;          // Save a number of records to the Record Counter
    fclose(fp);

    // For debuging
    // i--;
    // printf(">>>> %s-%s-%s\n", Transaction[i].id, Transaction[i].purchaseId, Transaction[i].inventoryId);

}

void purchaseFileRead(){

    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer

    int i = 0;
    fp = fopen(purchaseDatabaseFile, "r");

    while(fscanf(fp, "%s\t%lf\t%s\t%s\t%lu", Purchase[i].id, &Purchase[i].totalPrice, Purchase[i].customerId, Purchase[i].personnelId, &Purchase[i].datetime) != EOF){
        i++;
    }

    RecordCount.purchase = i;          // Save a number of records to the Record Counter
    fclose(fp);

    // For debuging
    // i--;
    // printf(">>>> %s\t%lf\t%s\t%s\t%lu\n", Purchase[i].id, Purchase[i].totalPrice, Purchase[i].customerId, Purchase[i].personnelId, Purchase[i].datetime);

}

void customerFileRead(){
    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer

    int i = 0;
    fp = fopen(customerDatabaseFile, "r");

    while(fscanf(fp, "%s\t%[^\t]\t%[^\t]\t%c\t%lf\t%lf", Customer[i].id, Customer[i].firstname, Customer[i].lastname, &Customer[i].gender, &Customer[i].point, &Customer[i].totalBuy) != EOF){
        i++;
    }

    RecordCount.customer = i;          // Save a number of records to the Record Counter
    fclose(fp);

    // For debuging
    // i--;
    // printf(">>>> %s\t%s\t%s\t%c\t%lf\t%lf\n", Customer[i].id, Customer[i].firstname, Customer[i].lastname, Customer[i].gender, Customer[i].point, Customer[i].totalBuy);

}

void promotionFileRead(){
    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer

    int i = 0;
    fp = fopen(promotionDatabaseFile, "r");

    while(fscanf(fp, "%s\t%lf\t%d", Promotion[i].id, &Promotion[i].price, &Promotion[i].status) != EOF){
        i++;
    }

    RecordCount.promotion = i;          // Save a number of records to the Record Counter
    fclose(fp);

    // For debuging
    // i--;
    // printf(">>>> %s\t%lf\t%d\n", Promotion[i].id, Promotion[i].price, Promotion[i].status);

}

void settingFileRead(){
    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer

    fp = fopen(settingDatabaseFile, "r");

    fscanf(fp, "%[^\t]\t%[^\t]\t%lf\t%lf", Setting.storeName, Setting.storeAddress, &Setting.priceToPoint, &Setting.pointToPrice);
    fclose(fp);

    // For debuging
    // printf(">>>> %s--%s--%lf--%lf\n", Setting.storeName, Setting.storeAddress, Setting.priceToPoint, Setting.pointToPrice);

}

void personnelFileWrite(){
    // Save all of the records to a database file
    FILE *fp;                   // File Pointer
    int numberOfRecords;        // Number of the records in a table

    numberOfRecords = RecordCount.personnel;
    fp = fopen(personnelDatabaseFile, "w+");

    for(int i = 0; i < numberOfRecords; i++)
        fprintf(fp, "%s\t%s\t%s\t%d\t%s\t%s\t%s\n", Personnel[i].id, Personnel[i].firstname, Personnel[i].lastname, Personnel[i].role, Personnel[i].username, Personnel[i].password, Personnel[i].barcodeToken);

    fclose(fp);
}

void inventoryFileWrite(){
    // Save all of the records to a database file
    FILE *fp;                   // File Pointer
    int numberOfRecords;        // Number of the records in a table

    numberOfRecords = RecordCount.inventory;
    fp = fopen(inventoryDatabaseFile, "w+");

    for(int i = 0; i < numberOfRecords; i++)
        fprintf(fp, "%s\t%s\t%lf\t%lf\t%s\t%u\n", Inventory[i].id, Inventory[i].name, Inventory[i].price, Inventory[i].profit, Inventory[i].categoryId, Inventory[i].remain);

    fclose(fp);
}

void categoryFileWrite(){
    // Save all of the records to a database file
    FILE *fp;                   // File Pointer
    int numberOfRecords;        // Number of the records in a table

    numberOfRecords = RecordCount.category;
    fp = fopen(categoryDatabaseFile, "w+");

    for(int i = 0; i < numberOfRecords; i++)
        fprintf(fp, "%s\t%s\n", Category[i].id, Category[i].name);

    fclose(fp);
}

void transactionFileWrite(){
    // Save all of the records to a database file
    FILE *fp;                   // File Pointer
    int numberOfRecords;        // Number of the records in a table

    numberOfRecords = RecordCount.transaction;
    fp = fopen(transactionDatabaseFile, "w+");

    for(int i = 0; i < numberOfRecords; i++)
        fprintf(fp, "%s\t%s\t%s\n", Transaction[i].id, Transaction[i].purchaseId, Transaction[i].inventoryId);

    fclose(fp);
}

void purchaseFileWrite(){
    // Save all of the records to a database file
    FILE *fp;                   // File Pointer
    int numberOfRecords;        // Number of the records in a table

    numberOfRecords = RecordCount.purchase;
    fp = fopen(purchaseDatabaseFile, "w+");

    for(int i = 0; i < numberOfRecords; i++)
        fprintf(fp, "%s\t%lf\t%s\t%s\t%lu\n", Purchase[i].id, Purchase[i].totalPrice, Purchase[i].customerId, Purchase[i].personnelId, Purchase[i].datetime);

    fclose(fp);
}

void customerFileWrite(){
    // Save all of the records to a database file
    FILE *fp;                   // File Pointer
    int numberOfRecords;        // Number of the records in a table

    numberOfRecords = RecordCount.customer;
    fp = fopen(customerDatabaseFile, "w+");

    for(int i = 0; i < numberOfRecords; i++)
        fprintf(fp, "%s\t%s\t%s\t%c\t%lf\t%lf\n", Customer[i].id, Customer[i].firstname, Customer[i].lastname, Customer[i].gender, Customer[i].point, Customer[i].totalBuy);

    fclose(fp);
}

void promotionFileWrite(){
    // Save all of the records to a database file
    FILE *fp;                   // File Pointer
    int numberOfRecords;        // Number of the records in a table

    numberOfRecords = RecordCount.promotion;
    fp = fopen(promotionDatabaseFile, "w+");

    for(int i = 0; i < numberOfRecords; i++)
        fprintf(fp, "%s\t%lf\t%d\n", Promotion[i].id, Promotion[i].price, Promotion[i].status);

    fclose(fp);
}

void settingFileWrite(){
    // Save all of the settings to a database file
    FILE *fp;               // File Pointer

    fp = fopen(settingDatabaseFile, "w+");

    fprintf(fp, "%s\t%s\t%lf\t%lf\n", Setting.storeName, Setting.storeAddress, Setting.priceToPoint, Setting.pointToPrice);
    fclose(fp);
}

int personnelSelectById(char *id, char *firstname, char *lastname, int *role, char *username, char *password, char *barcodeToken){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Personnel[i].id, id) == 0){
            // Return all values back by reference
            strcpy(firstname, Personnel[i].firstname);
            strcpy(lastname, Personnel[i].lastname);
            *role = Personnel[i].role;
            strcpy(username, Personnel[i].username);
            strcpy(password, Personnel[i].password);
            strcpy(barcodeToken, Personnel[i].barcodeToken);
            return 1;   // Found a record
        }
    }
    return 0;           // Not found the given `id` in the records
}

void personnelInsert(char *id, char *firstname, char *lastname, int role, char *username, char *password, char *barcodeToken){
    int tailIndex = RecordCount.personnel;

    strcpy(Personnel[tailIndex].id, id);
    strcpy(Personnel[tailIndex].firstname, firstname);
    strcpy(Personnel[tailIndex].lastname, lastname);
    Personnel[tailIndex].role = role;
    strcpy(Personnel[tailIndex].username, username);
    strcpy(Personnel[tailIndex].password, password);
    strcpy(Personnel[tailIndex].barcodeToken, barcodeToken);

    RecordCount.personnel++;    // Update the amount of records

    personnelFileWrite();       // Save to a Database file
}

int personnelUpdateFirstname(char *id, char *firstname){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Personnel[i].id, id) == 0){
            strcpy(Personnel[i].firstname, firstname);
            personnelFileWrite();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int personnelUpdateLastname(char *id, char *lastname){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Personnel[i].id, id) == 0){
            strcpy(Personnel[i].lastname, lastname);
            personnelFileWrite();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int personnelUpdateRole(char *id, int role){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Personnel[i].id, id) == 0){
            Personnel[i].role = role;
            personnelFileWrite();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int personnelUpdatePassword(char *id, char *password){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Personnel[i].id, id) == 0){
            strcpy(Personnel[i].password, password);
            personnelFileWrite();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int personnelDelete(char *id){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Personnel[i].id, id) == 0){
            while(i < numberOfRecords - 1){
                Personnel[i] = Personnel[i+1];
                i++;
            }
            RecordCount.personnel--;    // Update the amount of records
            personnelFileWrite();   // Save to a Database file
            return 1;               // Record successfully deleted
        }
    }
    return 0;   // Not found the given `id` in the records
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


