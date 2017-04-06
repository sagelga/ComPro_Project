// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

/*---------------------------------------------------------------------------*/
int main(){
// This program will run first. POS Interface configuration will be called, and ready to work.
    screenClear();
    initDatabase();
    screenAdjust();
    return 0;
}

void screenAdjust(){
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
            authInterface();
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

void authInterface () {
    bannerFullBorder ();
    bannerBlankBorderTextCen ("Sign in to the System");
    bannerFullBorder();
    bannerBlankBorderTextCen ("Please type in your username");
    for (int i = 0;i<34;i++)
        bannerBlankBorder();
    bannerFullBorder();

    char flags[130] = "Welcome Back";
    char username[130] = "Kumamon"; // Copy data to SESSION struct;
    bannerUserInput();
    scanf("%s",username); // Then save to session struct

    screenClear ();

    bannerFullBorder ();
    bannerBlankBorderTextCen ("Sign in to the System");
    bannerFullBorder();

    strcpy(flags,username);
    strcpy(flags,"!");
    bannerBlankBorderTextCen(flags);

    bannerBlankBorder();
    bannerBlankBorderTextCen("Please type in your password");
    for (int i = 0;i<32;i++)
        bannerBlankBorder();
    bannerFullBorder();
    bannerUserInput();

    char password[130];
    scanf("%s",password);

    screenClear();
    // If the username and the password is matched from the database -> Call authInterfaceComplete(); --> check_matched = 1
    // If the username and the password is not matched from the database -> Call authInterfaceFail(); --> check_matched = 2
    // If these were interrupt -> Call authInterfaceError(); --> check_matched = 0
    check_matched = 0;
    for (int user_count = 0; user_count < RecordCount.personnel; ++user_count)
    {
        if (strcmp(username, Personnel[user_count].username) == 0)
        {
            if (strcmp(password, Personnel[user_count].password) == 0)
            {
                check_matched = 1;
                break;
            }
            else
            {
                check_matched = 2;
                break;
            }
        }
    }
    //Call function depending on check_mathed
    if (check_matched == 1)
    {
        authInterfaceComplete();
    }
    else if (check_matched = 2)
    {
        authInterfaceFail();
    }
    else
    {
        authInterfaceError();
    }


    /* In case of BETA TEST only     Calling ->*/ authInterfaceComplete ();

}

void switchHub() {
    char username[8] = "Default";
    char text1[107] = "Welcome back ";
    strcat(text1,username);
    strcat(text1,"!");
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
    bannerBlankBorderTextCen("7. Check Sales Report");
    bannerBlankBorderTextCen("8. Settings");
    bannerBlankBorder();

    for (int i = 0;i<20;i++)
        bannerBlankBorder();

    bannerBlankBorderTextCen("or type 'N' to save and quit");
    bannerFullBorder();
    bannerUserInput();

    char flags;
    scanf(" %c", &flags);
    screenClear ();

    switch (flags) {
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
            categorySwitchHub ();
            return;

        case ('6'):
            initDatabase ();
            promotionSwitchHub ();
            return;

        case ('7'):
            initDatabase ();
            saleDatabaseInterface();
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

void switchHubManager() {
    char username[8] = "Default"; // Pull data from the SESSION struct
    char text1[107] = "Welcome back ";
    strcat (text1, username);
    strcat (text1, "!");
    char text2[107] = "";
    char text3[107] = "You are now connecting to the POS system";
    char text4[107] = "<user_permission_level_goes_here_in_this_line>";
    bannerInverse (text1, text2, text3, text4);

    bannerBlankBorderTextCen ("What do you want to do?");
    bannerBlankBorder ();

    //These choice will be removed, when the program detects the permission level.
    bannerBlankBorderTextCen ("1. Login / Logout");
    bannerBlankBorderTextCen ("2. Go to POS System");
    bannerBlankBorderTextCen ("3. Check Inventory Database");
    bannerBlankBorderTextCen ("4. Check Customer Database");
    bannerBlankBorderTextCen ("5. Check Category Database");
    bannerBlankBorderTextCen ("6. Check Promotion Database");
    bannerBlankBorderTextCen ("7. Check Sales Report");
    bannerBlankBorderTextCen ("8. Settings");
    bannerBlankBorder ();

    for ( int i = 0; i < 20; i++ )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("or type 'N' to save and quit");
    bannerFullBorder ();
    bannerUserInput ();

    char flags;
    scanf (" %c", &flags);

    switch ( flags ) {
        case ('1'): // Sign In / Sign Out
            authInterface ();
            return;

        case ('2'):// Go to POS Systems Interface (for cashier)
            initDatabase ();
            cashierInterface ();
            return;

        case ('3'):// Go to check Inventory Database
            initDatabase ();
            inventorySwitchHub ();
            return;

        case ('4'):
            customerSwitchHub ();
            return;

        case ('5'):
            initDatabase ();
            categorySwitchHub ();
            return;

        case ('6'):
            initDatabase ();
            promotionSwitchHub ();
            return;

        case ('7'):
            initDatabase ();
            saleDatabaseInterface ();
            return;

        case ('8'):
            settingsSwitchHub ();
            return;

        case ('n'):
            terminate ();
            return;

        case ('N'):
            terminate ();
            return;

        default:
            // The input is invalid. Trying to route back to ask for a valid input
            printf ("Your input is invalid. Please try again.\n\n\n");
            switchHub ();
            return;
    }
}

void switchHubSales() {
    char username[8] = "Default";
    char text1[107] = "Welcome back ";
    strcat (text1, username);
    strcat (text1, "!");
    char text2[107] = "";
    char text3[107] = "You are now connecting to the POS system";
    char text4[107] = "<user_permission_level_goes_here_in_this_line>";
    bannerInverse (text1, text2, text3, text4);

    bannerBlankBorderTextCen ("What do you want to do?");
    bannerBlankBorder ();

    //These choice will be removed, when the program detects the permission level.
    bannerBlankBorderTextCen ("1. Login / Logout");
    bannerBlankBorderTextCen ("2. Go to POS System");
    bannerBlankBorderTextCen ("3. Check Inventory Database");
    bannerBlankBorderTextCen ("4. Check Customer Database");
    bannerBlankBorderTextCen ("5. Check Category Database");
    bannerBlankBorderTextCen ("6. Check Promotion Database");
    bannerBlankBorderTextCen ("7. Check Sales Report");
    bannerBlankBorderTextCen ("8. Settings");
    bannerBlankBorder ();

    for ( int i = 0; i < 20; i++ )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("or type 'N' to save and quit");
    bannerFullBorder ();
    bannerUserInput ();

    char flags;
    scanf (" %c", &flags);

    switch ( flags ) {
        case ('1'): // Sign In / Sign Out
            authInterface ();
            return;

        case ('2'):// Go to POS Systems Interface (for cashier)
            initDatabase ();
            cashierInterface ();
            return;

        case ('3'):// Go to check Inventory Database
            initDatabase ();
            inventorySwitchHub ();
            return;

        case ('4'):
            customerSwitchHub ();
            return;

        case ('5'):
            initDatabase ();
            categorySwitchHub ();
            return;

        case ('6'):
            initDatabase ();
            promotionSwitchHub ();
            return;

        case ('7'):
            initDatabase ();
            saleDatabaseInterface ();
            return;

        case ('8'):
            settingsSwitchHub ();
            return;

        case ('n'):
            terminate ();
            return;

        case ('N'):
            terminate ();
            return;

        default:
            // The input is invalid. Trying to route back to ask for a valid input
            printf ("Your input is invalid. Please try again.\n\n\n");
            switchHub ();
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

    char flags;
    scanf(" %c",&flags);
    flags = toupper(flags);

    switch(flags){
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
    printf(":: %134s ::\n", "");
}

void bannerUserInput(){
    printf("\n>>> ");
}

void bannerFullBorderSection(){
    printf(":: %*s ::\n", 134,"-");
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

void inventorySwitchHub () {

    bannerBlankBorderTextCen ("What are you going to do?");
    bannerBlankBorder ();
    bannerBlankBorderText("Inventory");
    bannerFullBorderSection ();
    bannerBlankBorderTextCen ("1. Check the database");
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("2. Add inventory data to the database");
    bannerBlankBorderTextCen ("3. Edit inventory data from the database");
    bannerBlankBorderTextCen ("4. Removing inventory from the database");

    for (int i = 0;i<2;i++)
        bannerFullBorder ();

    bannerBlankBorderText ("Category");
    bannerFullBorderSection ();
    bannerBlankBorderTextCen ("5. Check the category database");
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("6. Add new category to the database");
    bannerBlankBorderTextCen ("7. Edit category from the database");
    bannerBlankBorderTextCen ("8. Remove category from the database");

    for ( int i = 0; i < 25; i++ ) {
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

void authInterfaceComplete(){
    bannerFullBorder();
    bannerBlankBorderTextCen ("Your login is now complete. We are now proceeding you to the program");
    bannerFullBorder ();

    for ( int i = 0; i < 36; i++ ) {
        bannerBlankBorder ();
    }
    bannerFullBorder ();
    delay (5);
    // If user are admin (0) -> Redirect to switchHub();
    // If user are manager (1) -> Redirect to switchHubManager();
    // If user are sales (2) -> Redirect to switchHubSale();

    /* During this betq test only (assuming all user are admin) ->*/ switchHub ();
}

void authInterfaceFail () {
    bannerFullBorder ();
    bannerBlankBorderTextCen ("Your login credentials is incorrect.");
    bannerFullBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("We are redirecting you try again. If you wish to do that, type anything to continue");
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("or type 'N' to exit the program");

    for ( int i = 0; i < 32; i++ )
        bannerBlankBorder ();

    bannerFullBorder ();
    bannerUserInput ();
    char flag;
    scanf (" %c", &flag);

    switch (flag) {

        case ('N'):
            terminate ();
            return;

        case ('n'):
            terminate ();
            return;

        default:
            authInterface ();
            return;
    }
    // If user type anything (except N or n) program will not be terminate + rerouting to login page again
    // If user type 'N' or 'n' program will be rerouting to terminate(); and they can shut the program down...
}

void authInterfaceError () {
    bannerFullBorder ();
    bannerBlankBorderTextCen ("Oops!");
    bannerFullBorder ();

    bannerBlankBorderTextCen ("The username that you have type are not in the system...");
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Please try again or contact an administrator if this happens too many times");
    for ( int i = 0; i < 33; i++ )
        bannerBlankBorder ();
    bannerFullBorder ();
    delay (10);
    authInterface ();

    // Program will delay for 10 seconds, and will be redirect back to login page...
}

void delay (int interval) {
    // This function will stop all threads from executing everything. Please be cautious about this...
        sleep (interval-1); // Stopping all threads from executing something for x seconds.
    screenClear ();
    sleep(1);
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

    // For debugging
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

    // For debugging
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

    // For debugging
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

    // For debugging
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

    // For debugging
    // i--;
    // printf(">>>> %s\t%lf\t%d\n", Promotion[i].id, Promotion[i].price, Promotion[i].status);

}

void settingFileRead(){
    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer

    fp = fopen(settingDatabaseFile, "r");

    fscanf(fp, "%[^\t]\t%[^\t]\t%lf\t%lf", Setting.storeName, Setting.storeAddress, &Setting.priceToPoint, &Setting.pointToPrice);
    fclose(fp);

    // For debugging
    // printf(">>>> %s--%s--%lf--%lf\n", Setting.storeName, Setting.storeAddress, Setting.priceToPoint, Setting.pointToPrice);

}

/*
void inventoryDatabaseInterface(){

    numberOfRecords = RecordCount.personnel;
    fp = fopen(personnelDatabaseFile, "w+");

    for(int i = 0; i < numberOfRecords; i++)
        fprintf(fp, "%s\t%s\t%s\t%d\t%s\t%s\t%s\n", Personnel[i].id, Personnel[i].firstname, Personnel[i].lastname, Personnel[i].role, Personnel[i].username, Personnel[i].password, Personnel[i].barcodeToken);

    fclose(fp);
}
*/

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

void personnelFileWrite(){

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

int personnelInsert(char *id, char *firstname, char *lastname, int role, char *username, char *password, char *barcodeToken){
    int tailIndex = RecordCount.personnel;

    // To comfirm that `id`, `username` and `barcodeToken` is unique
    for(int i = 0; i < tailIndex; i++){
        if(strcmp(Personnel[i].id, id) == 0 || strcmp(Personnel[i].username, username) == 0 || strcmp(Personnel[i].barcodeToken, barcodeToken) == 0)
            return 0;   // Error: Some field already exists
    }

    strcpy(Personnel[tailIndex].id, id);
    strcpy(Personnel[tailIndex].firstname, firstname);
    strcpy(Personnel[tailIndex].lastname, lastname);
    Personnel[tailIndex].role = role;
    strcpy(Personnel[tailIndex].username, username);
    strcpy(Personnel[tailIndex].password, password);
    strcpy(Personnel[tailIndex].barcodeToken, barcodeToken);

    RecordCount.personnel++;    // Update the amount of records

    personnelFileWrite();       // Save to a Database file
    return 1;   // Operation Success
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

int inventorySelectById(char *id, char *name, double *price, double *profit, char *categoryId, unsigned int *remain){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.inventory;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Inventory[i].id, id) == 0){
            // Return all values back by reference
            strcpy(name, Inventory[i].name);
            *price = Inventory[i].price;
            *profit = Inventory[i].profit;
            strcpy(categoryId, Inventory[i].categoryId);
            *remain = Inventory[i].remain;

            return 1;   // Found a record
        }
    }
    return 0;           // Not found the given `id` in the records
}

int inventoryInsert(char *id, char *name, double price, double profit, char *categoryId, unsigned int remain){
    int tailIndex = RecordCount.inventory;

    // To comfirm that `id` is unique
    for(int i = 0; i < tailIndex; i++){
        if(strcmp(Inventory[i].id, id) == 0)
            return 0;   // Error: Barcode ID already exists
    }

    strcpy(Inventory[tailIndex].id, id);
    strcpy(Inventory[tailIndex].name, name);
    Inventory[tailIndex].price = price;
    Inventory[tailIndex].profit = profit;
    strcpy(Inventory[tailIndex].categoryId, categoryId);
    Inventory[tailIndex].remain = remain;

    RecordCount.inventory++;    // Update the amount of records

    inventoryFileWrite();       // Save to a Database file
    return 1;                   // Operation Success
}

int inventoryUpdateName(char *id, char *name){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.inventory;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Inventory[i].id, id) == 0){
            strcpy(Inventory[i].name, name);
            inventoryFileWrite();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int inventoryUpdatePrice(char *id, double price){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.inventory;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Inventory[i].id, id) == 0){
            Inventory[i].price = price;
            inventoryFileWrite();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int inventoryUpdateProfit(char *id, double profit){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.inventory;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Inventory[i].id, id) == 0){
            Inventory[i].profit = profit;
            inventoryFileWrite();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int inventoryUpdateCategory(char *id, char *categoryId){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.inventory;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Inventory[i].id, id) == 0){
            strcpy(Inventory[i].categoryId, categoryId);
            inventoryFileWrite();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int inventoryUpdateRemain(char *id, unsigned int remain){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.inventory;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Inventory[i].id, id) == 0){
            Inventory[i].remain = remain;
            inventoryFileWrite();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int inventoryDelete(char *id){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.inventory;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Inventory[i].id, id) == 0){
            while(i < numberOfRecords - 1){
                Inventory[i] = Inventory[i+1];
                i++;
            }
            RecordCount.inventory--;    // Update the amount of records
            inventoryFileWrite();   // Save to a Database file
            return 1;               // Record successfully deleted
        }
    }
    return 0;   // Not found the given `id` in the records
}

int categorySelectById(char *id, char *name){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.category;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Category[i].id, id) == 0){
            // Return all values back by reference
            strcpy(name, Category[i].name);

            return 1;   // Found a record
        }
    }
    return 0;           // Not found the given `id` in the records
}

int categoryInsert(char *name){
    int tailIndex = RecordCount.category;

    // To comfirm that `name` is unique
    for(int i = 0; i < tailIndex; i++){
        if(strcmp(Inventory[i].name, name) == 0)
            return 0;   // Error: Category name already exists
    }

    char id[10];
    intToString(id, tailIndex + 1);     // Auto-increment (+ 1 to Start at 1)
    strcpy(Category[tailIndex].id, id);
    strcpy(Category[tailIndex].name, name);

    RecordCount.category++;    // Update the amount of records

    categoryFileWrite();       // Save to a Database file
    return 1;                  // Operation Success
}

int categoryUpdateName(char *id, char *name){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.category;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Category[i].id, id) == 0){
            strcpy(Category[i].name, name);
            categoryFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int categoryDelete(char *id){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.category;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Category[i].id, id) == 0){
            while(i < numberOfRecords - 1){
                Category[i] = Category[i+1];
                i++;
            }
            RecordCount.category--;    // Update the amount of records
            categoryFileWrite();       // Save to a Database file
            return 1;                  // Record successfully deleted
        }
    }
    return 0;   // Not found the given `id` in the records
}

int transactionSelectById(char *id, char *purchaseId, char *inventoryId){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.transaction;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Transaction[i].id, id) == 0){
            // Return all values back by reference
            strcpy(purchaseId, Transaction[i].purchaseId);
            strcpy(inventoryId, Transaction[i].inventoryId);

            return 1;   // Found a record
        }
    }
    return 0;           // Not found the given `id` in the records
}

void transactionInsert(char *purchaseId, char *inventoryId){
    int tailIndex = RecordCount.transaction;
    char id[10];
    intToString(id, tailIndex + 1);     // Auto-increment (+ 1 to Start at 1)
    strcpy(Transaction[tailIndex].id, id);
    strcpy(Transaction[tailIndex].purchaseId, purchaseId);
    strcpy(Transaction[tailIndex].inventoryId, inventoryId);

    RecordCount.transaction++;    // Update the amount of records

    transactionFileWrite();       // Save to a Database file
}

int purchaseSelectById(char *id, double *totalPrice, char *customerId, char *personnelId, time_t *datetime){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.purchase;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Purchase[i].id, id) == 0){
            // Return all values back by reference
            *totalPrice = Purchase[i].totalPrice;
            strcpy(customerId, Purchase[i].customerId);
            strcpy(personnelId, Purchase[i].personnelId);
            *datetime = Purchase[i].datetime;

            return 1;   // Found a record
        }
    }
    return 0;           // Not found the given `id` in the records
}

void purchaseInsert(double totalPrice, char *customerId, char *personnelId, time_t datetime){
    int tailIndex = RecordCount.purchase;
    char id[10];
    intToString(id, tailIndex + 1);     // Auto-increment (+ 1 to Start at 1)
    strcpy(Purchase[tailIndex].id, id);
    Purchase[tailIndex].totalPrice = totalPrice;
    strcpy(Purchase[tailIndex].customerId, customerId);
    strcpy(Purchase[tailIndex].personnelId, personnelId);
    Purchase[tailIndex].datetime = datetime;

    RecordCount.purchase++;    // Update the amount of records

    purchaseFileWrite();       // Save to a Database file
}

int customerSelectById(char *id, char *firstname, char *lastname, char *gender, double *point, double *totalBuy){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            // Return all values back by reference
            strcpy(firstname, Customer[i].firstname);
            strcpy(lastname, Customer[i].lastname);
            *gender = Customer[i].gender;
            *point = Customer[i].point;
            *totalBuy = Customer[i].totalBuy;

            return 1;   // Found a record
        }
    }
    return 0;           // Not found the given `id` in the records
}

int customerInsert(char *id, char *firstname, char *lastname, char gender){
    int tailIndex = RecordCount.customer;

    // To confirm that `id` is unique
    for(int i = 0; i < tailIndex; i++){
        if(strcmp(Customer[i].id, id) == 0)
            return 0;   // Error: Customer ID already exists
    }

    strcpy(Customer[tailIndex].id, id);
    strcpy(Customer[tailIndex].firstname, firstname);
    strcpy(Customer[tailIndex].lastname, lastname);
    Customer[tailIndex].gender = gender;
    Customer[tailIndex].point = 0;          // Initail value
    Customer[tailIndex].totalBuy = 0;       // Initail value

    RecordCount.customer++;    // Update the amount of records

    customerFileWrite();       // Save to a Database file
    return 1;                  // Operation Success
}

int customerUpdateFirstname(char *id, char *firstname){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            strcpy(Customer[i].firstname, firstname);
            customerFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int customerUpdateLastname(char *id, char *lastname){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            strcpy(Customer[i].lastname, lastname);
            customerFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int customerUpdateGender(char *id, char gender){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            Customer[i].gender = gender;
            customerFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int customerUpdatePoint(char *id, double point){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            Customer[i].point = point;
            customerFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int customerUpdatetotalBuy(char *id, double totalBuy){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            Customer[i].totalBuy = totalBuy;
            customerFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int customerDelete(char *id){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            while(i < numberOfRecords - 1){
                Customer[i] = Customer[i+1];
                i++;
            }
            RecordCount.customer--;    // Update the amount of records
            customerFileWrite();       // Save to a Database file
            return 1;                  // Record successfully deleted
        }
    }
    return 0;   // Not found the given `id` in the records
}

int promotionSelectById(char *id, double *price, int *status){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.promotion;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Promotion[i].id, id) == 0){
            // Return all values back by reference
            *price = Promotion[i].price;
            *status = Promotion[i].status;

            return 1;   // Found a record
        }
    }
    return 0;           // Not found the given `id` in the records
}

int promotionInsert(char *id, double price){
    int tailIndex = RecordCount.promotion;

    // To comfirm that `id` is unique
    for(int i = 0; i < tailIndex; i++){
        if(strcmp(Promotion[i].id, id) == 0)
            return 0;   // Error: Barcode ID already exists
    }

    strcpy(Promotion[tailIndex].id, id);
    Promotion[tailIndex].price = price;
    Promotion[tailIndex].status = 1;        // Initail Value (1 = Active)

    RecordCount.promotion++;                // Update the amount of records

    promotionFileWrite();                   // Save to a Database file
    return 1;                   // Operation Success
}

int promotionUpdatePrice(char *id, double price){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.promotion;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Promotion[i].id, id) == 0){
            Promotion[i].price = price;
            promotionFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int promotionUpdateStatus(char *id, int status){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.promotion;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Promotion[i].id, id) == 0){
            Promotion[i].status = status;
            promotionFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int promotionDelete(char *id){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.promotion;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Promotion[i].id, id) == 0){
            while(i < numberOfRecords - 1){
                Promotion[i] = Promotion[i+1];
                i++;
            }
            RecordCount.promotion--;    // Update the amount of records
            promotionFileWrite();       // Save to a Database file
            return 1;                  // Record successfully deleted
        }
    }
    return 0;   // Not found the given `id` in the records
}

void settingUpdateStoreName(char *storeName){

    strcpy(Setting.storeName, storeName);
    settingFileWrite();    // Save to a Database file

}

void settingUpdateAddress(char *storeAddress){
    strcpy(Setting.storeAddress, storeAddress);
    settingFileWrite();    // Save to a Database file
}

void settingUpdatePriceToPoint(double priceToPoint){
    Setting.priceToPoint = priceToPoint;
    settingFileWrite();    // Save to a Database file
}

void settingUpdatePointToPrice(double pointToPrice){
    Setting.pointToPrice = pointToPrice;
    settingFileWrite();    // Save to a Database file
}

int authenticateByUsername(char *username, char *password){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;

    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Personnel[i].username, username) == 0){
            if(strcmp(Personnel[i].password, password) == 0){
                // Save user's information on the Session
                Session.user = Personnel[i];
                Session.isLogedin = 1;
                return 1;
            }
            else
                return 0;
        }
    }
    return 0;
}

int authenticateByToken(char *barcodeToken){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;

    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Personnel[i].barcodeToken, barcodeToken) == 0){
            // Save user's information on the Session
            Session.user = Personnel[i];
            Session.isLogedin = 1;
            return 1;
        }
    }
    return 0;
}

void deauthenticate(){
    Session.isLogedin = 0;
}

void inventoryDatabaseInterface () {
    /*ID|Name|Price|Profit|Category|In Stock
      -|-|-|-|-|-
      13 char|62 char|10 double|10 double|25 char|8 int*/
    bannerFullBorder();
    bannerBlankBorderText(" ID          | Name                                                         | Price    | Profit   | Category                | In Stock");
    bannerFullBorder ();
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

void saleDatabaseInterface(){
    bannerFullBorder();
    bannerBlankBorderText(" ID          | Name                                                         | Price    | Profit   | Category                | In Stock");
    bannerFullBorder ();
}

void cashierInterface () {
    char username[137] = "Kumamon"; // Pull the username from the struct SESSION
    char text1[107] = "<store_name>";
    char text2[107] = "Welcome! My name is ";
    strcpy(text2,username);
    char text3[107] = "";
    char text4[107] = "";
    banner (text1,text2,text3,text4);

}

void transactionSwitchHub () {

}

void purchaseSwitchHub () {

}

void customerSwitchHub () {

}

void promotionSwitchHub () {

}

void categorySwitchHub (){

}

void inventoryAddInterface () {
    bannerBlankBorderTextCen ("Inventory in mode 'ADD'");
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

   :: ██████╗  ██████╗ ███████╗ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
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
