/*      Hello. Do you know about trucks, right? - Donald Trump
 *      https://www.youtube.com/watch?v=oguvSPdtHQ8
 */

/*-----------------------------------------------------------------------------
Declare all the libraries that we are going to use in this project*/
#include <stdio.h>              // Pretty much the basic things
#include <string.h>             // Compares strings and other kind of stuff
#include <math.h>               // Calculate difficult 7-years-old Math
#include <stdlib.h>             // IDK what that will do, but I added it anyways...
#include <time.h>               // Synchronize and manage the time between program and you
#include <ctype.h>              // Compares the string to type of string
#include <unistd.h>             // Use access() to check a file is exist

/*-----------------------------------------------------------------------------
Define all the constant values here*/
#define MAX_IDX_PERSONNEL 10        // Maximum amount of Personnels
#define MAX_IDX_INVENTORY 100       // Maximum amount of Inventory
#define MAX_IDX_CATEGORY 10         // Maximum amount of Category
#define MAX_IDX_TRANSACTION 100000  // Maximum amount of Transaction (Count when item changed)
#define MAX_IDX_PURCHASE 100000     // Maximum amount of Purchase (Count when checkout)
#define MAX_IDX_CUSTOMER 100        // Maximum amount of Customer
#define MAX_IDX_PROMOTION 1000      // Maximum amount of Promotion

#define MAX_LNG_ID 20               // Maximum length of ID
#define MAX_LNG_TEXT 50             // Maximum length of Normal Text
#define MAX_LNG_SCREEN 140          // Maximum length of (Text on) Screen's width
#define MAX_LNG_TOKEN 255           // Maximum length of Token

// Path to Database file
const char *personnelDatabaseFile = "Database/personnel.db";
const char *inventoryDatabaseFile = "Database/inventory.db";
const char *categoryDatabaseFile = "Database/category.db";
const char *transactionDatabaseFile = "Database/transaction.db";
const char *purchaseDatabaseFile = "Database/purchase.db";
const char *customerDatabaseFile = "Database/customer.db";
const char *promotionDatabaseFile = "Database/promotion.db";
const char *settingDatabaseFile = "Database/setting.db";

// Database structure

// 01. PERSONNEL
typedef struct
{
    char id[MAX_LNG_ID];
    char firstname[MAX_LNG_TEXT];
    char lastname[MAX_LNG_TEXT];
    int role; // 0 = Manager | 1 = Marketing | 2 = Sale
    char username[MAX_LNG_TEXT];
    char password[MAX_LNG_TEXT];
    char barcode_token[MAX_LNG_TOKEN]; // For use a barcode authentication
} PERSONNEL;

// 02. INVENTORY
typedef struct
{
    char id[MAX_LNG_ID];
    char name[MAX_LNG_SCREEN];
    double price;
    double profit; // Profit per item
    char categoryId[MAX_LNG_ID]; // Category ID
    unsigned int remain; //Stock left in inventory
} INVENTORY;

// 03. CATEGORY
typedef struct
{
    char id[MAX_LNG_ID];
    char name[MAX_LNG_TEXT];
} CATEGORY;

// 04. TRANSACTION
typedef struct
{
    char id[MAX_LNG_ID];
    char purchaseId[MAX_LNG_ID];
    char inventoryId[MAX_LNG_ID];
} TRANSACTION;

// 05. PURCHASE
typedef struct
{
    char id[MAX_LNG_ID];
    double totalPrice;
    char customerId[MAX_LNG_ID];
    char personnelId[MAX_LNG_ID]; // Cashier
    time_t datetime; // Epoch timestamp
} PURCHASE;

// 06. CUSTOMER
typedef struct
{
  char id[MAX_LNG_ID];
  char firstname[MAX_LNG_TEXT];
  char lastname[MAX_LNG_TEXT];
  char gender; // 'F' = Female | 'M' = Male
  double point;
  double totalBuy;
} CUSTOMER;

// 07. PROMOTION
typedef struct
{
    char id[MAX_LNG_ID];
    double price;
    int status; // 1 = active | 0 = used (exprired)
} PROMOTION;

// 08. SETTINGS
typedef struct
{
    char storeName[MAX_LNG_SCREEN];
    char storeAddress[MAX_LNG_SCREEN];
    double priceToPoint; // When you pay N Baht, you'll receive `N * priceToPoint` points.
    double pointToPrice; // `pointToPrice` point is equal to 1 Baht.
} SETTING;

// Record Counter
typedef struct{
    unsigned int personnel;
    unsigned int inventory;
    unsigned int category;
    unsigned int transaction;
    unsigned int purchase;
    unsigned int customer;
    unsigned int promotion;

} RECORDCOUNT;

// SESSION Collector
typedef struct{
  PERSONNEL merchant;                             // For store user's information

} SESSION;


PERSONNEL Personnel[MAX_IDX_PERSONNEL];           // Declare the Personnel table
INVENTORY Inventory[MAX_IDX_INVENTORY];           // Declare the Inventory table
CATEGORY Category[MAX_IDX_CATEGORY];              // Declare the Category table
TRANSACTION Transaction[MAX_IDX_TRANSACTION];     // Declare the Transaction table
PURCHASE Purchase[MAX_IDX_PURCHASE];              // Declare the Purchase table
CUSTOMER Customer[MAX_IDX_CUSTOMER];              // Declare the Customer table
PROMOTION Promotion[MAX_IDX_PROMOTION];           // Declare the Promotion table
SETTING Setting;                                  // Declare the Setting table

RECORDCOUNT RecordCount;                          // Declare the Record Counter
SESSION Session;                                  // Declare the Session Collector

/*-----------------------------------------------------------------------------
Declare all the Options switching functions*/
void switchHub();               // For moving to the selection of the functions
void inventorySwitchHub ();               // For moving to the selection of the functions
void categorySwitchHub ();               // For moving to the selection of the functions
void transactionSwitchHub ();               // For moving to the selection of the functions
void purchaseSwitchHub ();               // For moving to the selection of the functions
void customerSwitchHub ();               // For moving to the selection of the functions
void promotionSwitchHub ();               // For moving to the selection of the functions
void settingsSwitchHub ();               // For moving to the selection of the functions

/*-----------------------------------------------------------------------------
Declare all the gimmicks functions, which will be separate program from the original. No I/O*/
void terminate();               // For save and stop the program
void screenAdjust();            // For calculating the screen size to the optimum size
void screenClear();             // For refreshing the screen to the new one

/*-----------------------------------------------------------------------------
Declare all the gimmicks functions*/
void bannerFullBorder();											// Prints a full 140 character full of :
void bannerBlankBorder();											// Prints a :: + 136 charaacter space + ::
void bannerBlankBorderTextCen(char *text);								// Prints a :: + + 134 character space + + :: (Center Align)
void bannerBlankBorderTextCen(char *text);								// Prints a :: + + 134 character space + + :: (Left Align)
void banner(char *bannerLine1, char *bannerLine2, char *bannerLine3, char *bannerLine4);	// Prints banner with configurable character
void bannerInverse(char *bannerLine1, char *bannerLine2, char *bannerLine3, char *bannerLine4);	// Prints banner (with POS logo in the right) with configurable character
void bannerUserInput(); 											// Asks for input from user

/*-----------------------------------------------------------------------------
Declare all the database file !!fetch!! functions*/

void initDatabase();            									// For Database Initialization
void personnelDatabase();       									// For Personnel Database
void inventoryDatabase();       									// For Inventory Database
void categoryDatabase();        									// For Category Database
void transactionDatabase();     									// For Transaction Database
void purchaseDatabase();        									// For Purchase Database
void customerDatabase();        									// For Customer Database
void promotionDatabase();       									// For Promotion Database
void settingDatabase();         									// For Setting Database

/*-----------------------------------------------------------------------------
Declare all the database file >>Read>> functions*/

void personnelFileRead();       // For Personnel Database
void inventoryFileRead();       // For Inventory Database
void categoryFileRead();        // For Category Database
void transactionFileRead();     // For Transaction Database
void purchaseFileRead();        // For Purchase Database
void customerFileRead();        // For Customer Database
void promotionFileRead();       // For Promotion Database
void settingFileRead();         // For Setting Database

/*-----------------------------------------------------------------------------
Declare all the database file <<Write<< functions*/
void personnelFileWrite();       // For Personnel Database
void inventoryFileWrite();       // For Inventory Database
void categoryFileWrite();        // For Category Database
void transactionFileWrite();     // For Transaction Database
void purchaseFileWrite();        // For Purchase Database
void customerFileWrite();        // For Customer Database
void promotionFileWrite();       // For Promotion Database
void settingFileWrite();         // For Setting Database

/*-----------------------------------------------------------------------------
Declare all the other database functions*/
int isFileExist(const char *filename);  // For check a file exist. If the file is exist then return 1 otherwise return 0
unsigned int tail(unsigned int table);  // Return the first empty index of the list (For insert new record)
void intToString(char *str, int number); // Convert from integer to string

/*-----------------------------------------------------------------------------
Declare all the interface functions*/

/*-----------------------------------------------------------------------------
Declare all the Personnel Database can do*/
void personnelSelectById(char *id, char *firstname, char *lastname, int role, char *username, char *password, char *barcode_token);  // To use: personnelSelectById(id, firstname, lastname, &role, username, password, barcode_token);
void personnelInsert(char *id, char *firstname, char *lastname, int role, char *username, char *password, char *barcode_token);
void personnelUpdateFirstname(char *id, char *firstname);
void personnelUpdateLastname(char *id, char *lastname);
void personnelUpdateRole(char *id, int role);
void personnelUpdatePassword(char *id, char *password);
void personnelDelete(char *id);

/*-----------------------------------------------------------------------------
Declare all the Inventory Database can do*/
void inventorySelectById(char *id, char *name, double *price, double *profit, char *categoryId, unsigned int *remain);              // To use: inventorySelectById(id, name, &price, &profit, categoryId, &remain);
void inventoryInsert(char *id, char *name, double price, double profit, char *categoryId, unsigned int remain);
void inventoryUpdateName(char *id, char *name);
void inventoryUpdatePrice(char *id, double price);
void inventoryUpdateProfit(char *id, double profit);
void inventoryUpdateCategory(char *id, char *categoryId);
void inventoryUpdateRemain(char *id, unsigned int remain);
void inventoryDelete(char *id);

void inventoryAddInterface ();

void inventoryModifyInterface ();

void inventoryRemoveInterface ();

/*-----------------------------------------------------------------------------
Declare all the Category Database can do*/
void categorySelectById(char *id, char *name);
void categoryInsert(char *id, char *name);
void categoryUpdateName(char *id, char *name);
void categoryDelete(char *id);

/*-----------------------------------------------------------------------------
Declare all the Transaction Database can do*/
void transactionSelectById(char *id, char *purchaseId, char *inventoryId);
void transactionInsert(char *id, char *purchaseId, char *inventoryId);

/*-----------------------------------------------------------------------------
Declare all the Purchase Database can do*/
void purchaseSelectById(char *id, double *totalPrice, char *customerId, char *personnelId, time_t *datetime);                       // To use: purchaseSelectById(id, &totalPrice, customerId, personnelId, &datetime);
void purchaseInsert(char *id, double totalPrice, char *customerId, char *personnelId, time_t datetime);

/*-----------------------------------------------------------------------------
Declare all the Customer Database can do*/
void customerSelectById(char *id, char *firstname, char *lastname, char *gender, double *point, double *totalBuy);                  // To use: customerSelectById(id, firstname, lastname, &gender, &point, &totalBuy);
void customerInsert(char *id, char *firstname, char *lastname, char gender, double point, double totalBuy);
void customerUpdateFirstname(char *id, char *firstname);
void customerUpdateLastname(char *id, char *lastname);
void customerUpdateGender(char *id, char gender);
void customerUpdatePoint(char *id, double point);
void customerUpdatetotalBuy(char *id, double totalBuy);
void customerDelete(char *id);

/*-----------------------------------------------------------------------------
Declare all the Promotion Database can do*/
void promotionSelectById(char *id, double *price, int *status);                                                                     // To use: promotionSelectById(id, &price, &status);
void promotionInsert(char *id, double price, int status);
void promotionUpdatePrice(char *id, double price);
void promotionUpdateStatus(char *id, int status);
void promotionDelete(char *id);

/*-----------------------------------------------------------------------------
Declare all the Setting Database can do*/
void settingSelectById(char *id);
void settingUpdateStoreName(char *storeName);
void settingUpdateAddress(char *storeAddress);
void settingUpdatePriceToPoint(double priceToPoint);
void settingUpdatePointToPrice(double pointToPrice);

/*-----------------------------------------------------------------------------
Declare all the forecast function can do*/
void monthlyForecast();
void quarterForecast();
void annualForecast();

void forecastResults();
void forecastProgram();

void forecastPrint();

/*-----------------------------------------------------------------------------
Decease what the seller can do*/
void cashierInterface();

/*-----------------------------------------------------------------------------
Declares all the authentication functions and interface*/
void authenticate(char username, char password);            // For signing in
void deauthenticate();          // For signing out
//
void authInterface();           // For sign in interface
void authInterfaceComplete();   // For complete sign in interface
void authInterfaceFailed();     // For non - complete sign in interface (Error from cancel)
void authInterfaceError();      // For non - complete sign in interface (Other type of error)

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
   :: ██╔══██╗██╔═══██╗██╔════╝ :: Welcome to the POS System program.									                                     ::
   :: ██████╔╝██║   ██║███████╗ :: Please feel free to look around...									                                     ::
   :: ██╔═══╝ ██║   ██║╚════██║ :: Created by the 1st year student of Information Technology Ladkrabang.									 ::
   :: ██║     ╚██████╔╝███████║ :: Redistribution or copies are not allowed. No commercial use is allowed.									 ::
   :: ╚═╝      ╚═════╝ ╚══════╝ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

      Lists of the team members
      Kunanon Srisuntiroj      @sagelga    		59070022    UI Team
      Thanawat Laodkaew        @skydddoogg 		59070071    Background Work Team
      Noppanut Ploywong        @noppanut15 		59070082    Background Work Team
      Vasanchai Prakobkij      @59070156   		59070156    Background Work Team
  
 */
