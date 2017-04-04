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

    bannerBlankBorderText("or type 'N' to save and quit");
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
    bannerBlankBorderText("You about to terminate the POS system...");
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
    char text3[107] = "  The program screen size is optimized for 140 x 40 pixel terminal";
    char text4[107] = "";
    banner(text1, text2, text3, text4);
    
    for (int i = 0;i<3;i++)
        bannerBlankBorder();
    
    bannerBlankBorderText("Please configure the terminal screen to optimum size.");
    
    for (int i = 0;i<27;i++)
        bannerBlankBorder();
    
    bannerBlankBorderText("Type 'Y' to continue...");
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
    int length = strlen(text) - 1;  // Remove the terminal '\0'
    int pad = (length >= 134) ? 0 : ((134 - length) / 2);

    printf(":: %*s%s%*s ::\n", pad," ",text,133-pad-length," ");
}

void bannerBlankBorder(){
    printf("::%136s::\n", "");
}

void bannerBlankTerminate(){
    printf("\n>>> ");
}

void settings(){
    bannerFullBorder();
    bannerBlankBorderText("Settings");
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

unsigned int tail(unsigned int table){
    if(table == 1)
        return RecordCount.personnel;
    else if(table == 2)
        return RecordCount.inventory;
    else if(table == 3)
        return RecordCount.category;
    else if(table == 4)
        return RecordCount.transaction;
    else if(table == 5)
        return RecordCount.purchase;
    else if(table == 6)
        return RecordCount.customer;
    else if(table == 7)
        return RecordCount.promotion;
    return 0;
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
    double profit;                      // Profit per item
    char categoryId[MAX_LNG_ID];        // Category ID
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

    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer
    char id[MAX_LNG_ID];
    char name[MAX_LNG_TEXT];

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
void transactionDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(transactionDatabaseFile)){
        fopen(transactionDatabaseFile, "w");
    }

    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer
    char id[MAX_LNG_ID];
    char purchaseId[MAX_LNG_ID];
    char inventoryId[MAX_LNG_ID];

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
void purchaseDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(purchaseDatabaseFile)){
        fopen(purchaseDatabaseFile, "w");
    }

    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer
    char id[MAX_LNG_ID];
    double totalPrice;
    char customerId[MAX_LNG_ID];
    char personnelId[MAX_LNG_ID];       // Cashier
    time_t datetime;                    // Epoch timestamp

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
void customerDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(customerDatabaseFile)){
        fopen(customerDatabaseFile, "w");
    }

    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer
    char id[MAX_LNG_ID];
    char firstname[MAX_LNG_TEXT];
    char lastname[MAX_LNG_TEXT];
    char gender; // 'F' = Female | 'M' = Male
    double point;

    int i = 0;
    fp = fopen(customerDatabaseFile, "r");

    while(fscanf(fp, "%s\t%[^\t]\t%[^\t]\t%c\t%lf", Customer[i].id, Customer[i].firstname, Customer[i].lastname, &Customer[i].gender, &Customer[i].point) != EOF){
        i++;
    }

    RecordCount.customer = i;          // Save a number of records to the Record Counter
    fclose(fp);

    // For debuging
    // i--;
    // printf(">>>> %s\t%s\t%s\t%c\t%lf\n", Customer[i].id, Customer[i].firstname, Customer[i].lastname, Customer[i].gender, Customer[i].point);

}
void promotionDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(promotionDatabaseFile)){
        fopen(promotionDatabaseFile, "w");
    }

    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer
    char id[MAX_LNG_ID];
    double price;
    int status; // 1 = active | 0 = used (exprired)

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
void settingDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(settingDatabaseFile)){
        fopen(settingDatabaseFile, "w");
    }

    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer
    char storeName[MAX_LNG_SCREEN];
    char storeAddress[MAX_LNG_SCREEN];
    double priceToPoint; // When you pay N Baht, you'll receive `N * priceToPoint` points.
    double pointToPrice; // `pointToPrice` point is equal to 1 Baht.


    fp = fopen(settingDatabaseFile, "r");

    fscanf(fp, "%[^\t]\t%[^\t]\t%lf\t%lf", Setting.storeName, Setting.storeAddress, &Setting.priceToPoint, &Setting.pointToPrice);
    fclose(fp);

    // For debuging
    // printf(">>>> %s--%s--%lf--%lf\n", Setting.storeName, Setting.storeAddress, Setting.priceToPoint, Setting.pointToPrice);

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
