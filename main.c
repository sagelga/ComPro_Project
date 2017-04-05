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

    char text1[107] = "Welcome back <user_name_goes_here>!";
    strcat(text1,username);
    char text2[107] = "";
    char text3[107] = "You are now connecting to the POS system";
    char text4[107] = "<user_permission_level_goes_here_in_this_line>";
    bannerInverse(text1, text2, text3, text4);

    bannerBlankBorderTextCen("What do you want to do?");
    bannerBlankBorder();

    //These choice will be removed, when the program detects the permission level.
    bannerBlankBorderTextCen("1. Login / Logout");
    bannerBlankBorderTextCen ("2. Go to POS System");
    bannerBlankBorderTextCen("3. Check Inventory Database");
    bannerBlankBorderTextCen("4. Check Customer Database");
    bannerBlankBorderTextCen("5. Check Category Database");
    bannerBlankBorderTextCen ("6. Check Promotion Database");
    bannerBlankBorderTextCen("7. Check Forecast");
    bannerBlankBorderTextCen("8. Settings");
    bannerBlankBorder();

    for (int i = 0;i<20;i++)
        bannerBlankBorder();

    bannerBlankBorderTextCen("or type 'N' to save and quit");
    bannerFullBorder();
    bannerUserInput();

    char functionscall;
    scanf(" %c", &functionscall);

    switch (functionscall) {
        case ('1'): // Sign In / Sign Out
            authInterface ();
            return;

        case ('2'):// Go to POS Systems Interface (for cashier)
            initDatabase();
            cashierInterface ();
            return;

        case ('3'):// Go to check Inventory Database
            initDatabase();
            inventorySwitchHub ();
            return;

        case ('4'):
            customerSwitchHub ();
            return;

        case ('5'):
            initDatabase();

            return;

        case ('6'):
            initDatabase ();
            promotionSwitchHub ();
            return;

        case ('7'):
            initDatabase ();

            return;

        case ('8'):
            settingsSwitchHub ();
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
    bannerBlankBorderTextCen("You about to terminate the POS system...");
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
    
    bannerBlankBorderTextCen("Please configure the terminal screen to optimum size.");
    
    for (int i = 0;i<27;i++)
        bannerBlankBorder();
    
    bannerBlankBorderTextCen("Type 'Y' to continue...");
    bannerFullBorder();

    bannerUserInput();
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
    for ( int i = 0; i < 14; i++ )
        printf ("::::::::::");
    printf("\n");
}

void bannerBlankBorderTextCen(char *text){
    int length = strlen(text) - 1;  // Remove the terminal '\0'
    int pad = (length >= 134) ? 0 : ((134 - length) / 2);

    printf(":: %*s%s%*s ::\n", pad," ",text,133-pad-length," ");
}

void bannerBlankBorderText(char *text){
    printf(":: %134s ::\n", text);
}

void bannerBlankBorder(){
    printf("::%136s::\n", "");
}

void bannerUserInput(){
    printf("\n>>> ");
}

void settingsSwitchHub () {
    bannerFullBorder();
    bannerBlankBorderTextCen("Settings");
    bannerFullBorder();

    bannerBlankBorderTextCen("What do you want to do?");
    bannerBlankBorderTextCen("1. Change Username");
    bannerBlankBorderTextCen("2. Change Password");
    
    bannerFullBorder();
    
    bannerBlankBorderTextCen("3. Change store name");
    bannerBlankBorderTextCen("4. Change store address");

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
    // Check a Database file existence, if it doesn't exist then create the new one.
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

    // For debugging
    // i--;
    // printf(">>>> %s-%s-%s\n", Transaction[i].id, Transaction[i].purchaseId, Transaction[i].inventoryId);

}
void purchaseDatabase(){
    // Check a Database file existence, if it doesn't exist then create the new one.
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

    // For debugging
    // i--;
    // printf(">>>> %s\t%lf\t%s\t%s\t%lu\n", Purchase[i].id, Purchase[i].totalPrice, Purchase[i].customerId, Purchase[i].personnelId, Purchase[i].datetime);

}
void customerDatabase(){
    // Check a Database file existence, if it doesn't exist then create the new one.
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

    // For debugging
    // i--;
    // printf(">>>> %s\t%s\t%s\t%c\t%lf\n", Customer[i].id, Customer[i].firstname, Customer[i].lastname, Customer[i].gender, Customer[i].point);

}
void promotionDatabase(){
    // Check a Database file existence, if it doesn't exist then create the new one.
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

    // For debugging
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

    // For debugging
    // printf(">>>> %s--%s--%lf--%lf\n", Setting.storeName, Setting.storeAddress, Setting.priceToPoint, Setting.pointToPrice);

}

void inventoryDatabaseInterface(){
    bannerFullBorder();
    bannerBlankBorderText(" ID                 | Name                                             | Price         | Profit        | Category                ");

    /* REMOVE THIS LINE UNTIL IT WAS REDONE
    for (int i = 0;i<36;i--){ // Using 10 data as an example... Maxed with 36 lines...

        // Pulls data from the database...
        char id[20] = "<this_is_id>";
        char name[50] = "<this_is_item_name>";
        char price[15] = "<price>";
        char profit[15] = "<profit>";
        char category[25] = "<this_is_category>";

        char text_formation = "";
        strcpy(id,"|");
        strcpy(name,"|");
        strcpy(price,"|");
        strcpy(profit,"|");
        strcpy(category,"|");

        strcpy(text_formation,id);
        strcpy(text_formation,name);
        strcpy(text_formation,price);
        strcpy(text_formation,profit);
        strcpy(text_formation,category);

        bannerBlankBorderText(text_formation);
    }
    int page = 1; // Current page number
    int total_page = 1; // Total page number

    if(page-total_page >= 2){
        char previous_max = "|<<"; // Visible when page > total page by 2
    }
    else{
        char previous_max = "   ";
    }

    if (page-total_page >= 1){
        char previous = "<"; // Visible when page > total page by 1
    }
    else{
        char previous = " ";
    }


    if (total_page-page >= 1){
        char next = ">"; // Visible when page < total page by 1
    }
    else{
        char next = " ";
    }

    if (total_page-page >= 2){
        char next_max = ">>|"; // Visible when page < total page by 2
    }
    else{
        char next_max = "   ";
    }

    //char text_formation = "%s  %s  ( Page %d of %d )  %s  %s",previous_max,previous,page,total_page,next,next_max;
    char text_formation = "";

    strcpy(text_formation,previous_max);
    strcpy(text_formation,previous);
    strcpy(text_formation,"( Page");
    strcpy(text_formation,page);
    strcpy(text_formation,"of");
    strcpy(text_formation,total_page);
    strcpy(text_formation,")");
    strcpy(text_formation,next);
    strcpy(text_formation,next_max);

    bannerBlankBorderTextCen(&text_formation);
    
    REMOVE THIS LINE UNTIL IT WAS REDONE*/

    bannerFullBorder();

}

void inventorySwitchHub () {
    bannerFullBorder ();
    bannerBlankBorderTextCen ("Inventory Hub");
    bannerFullBorder ();

    bannerBlankBorderTextCen ("What are you going to do?");
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("1. Check the database");
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("2. Add data to the database manually");
    bannerBlankBorderTextCen ("3. Add data to the database automatically");
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("4. Edit data from the database manually");
    bannerBlankBorderTextCen ("5. Edit data from the database using the scanner");
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("6. Removing data from the database");
    for ( int i = 0; i < 23; i++ ) {
        bannerBlankBorder ();
    }
    bannerBlankBorderTextCen ("or type 'N' to return back to the hub");
    bannerFullBorder ();
    bannerUserInput ();

    char userInput;
    scanf (" %c", &userInput);

    switch ( userInput ) {
        case ('1'):
            inventoryDatabaseInterface ();
            return;
        case ('2'):
            inventoryAddInterface ();
            return;
        case ('3'):
            return;
        case ('4'):
            inventoryModifyInterface ();
            return;
        case ('5'):
            return;
        case ('6'):
            inventoryRemoveInterface ();
            return;
        default:
            printf ("Your input is invalid. Please try again...");
            inventorySwitchHub ();
            return;
    }
}

void authInterface () {

}

void cashierInterface () {

}

void categorySwitchHub () {

}

void transactionSwitchHub () {

}

void purchaseSwitchHub () {

}

void customerSwitchHub () {

}

void promotionSwitchHub () {

}

void inventoryAddInterface () {

}

void inventoryModifyInterface () {

}

void inventoryRemoveInterface () {

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
