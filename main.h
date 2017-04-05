/* Welcome to the POS System program.
 * Please feel free to look around...
 * Created by the 1st year student of Information Technology Ladkrabang.
 * Redistribution or copies are not allowed. No commercial use is allowed.
 *
 * Thank you for participating.
 * The Team

 * ---------------------
 * Lists of the team members
 * Kunanon Srisuntiroj      @sagelga    59070022    UI Team
 * Thanawat Laodkaew        @skydddoogg 59070071    Background Work Team
 * Noppanut Ploywong        @noppanut15 59070082    Background Work Team
 *                          @59070156   59070156    Background Work Team
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
#include <unistd.h>             // Use access() to check a file is exist
/*-----------------------------------------------------------------------------
Define all the constant values here*/
#define MAX_IDX_PERSONNEL 10        // Maximum amount of Personnels
#define MAX_IDX_INVENTORY 100       // Maximum amount of Inventory
#define MAX_IDX_CATEGORY 10         // Maximum amount of Category
#define MAX_IDX_TRANSACTION 100000  // Maximum amount of Transaction
#define MAX_IDX_PURCHASE 100000     // Maximum amount of Purchase
#define MAX_IDX_CUSTOMER 100        // Maximum amount of Customer
#define MAX_IDX_PROMOTION 1000      // Maximum amount of Promotion

#define MAX_LNG_ID 20               // Maximum length of ID
#define MAX_LNG_TEXT 50             // Maximum length of Normal Text
#define MAX_LNG_SCREEN 140          // Maximum length of (Text on) Screen's width
#define MAX_LNG_TOKEN 255           // Maximum length of Token

/*-----------------------------------------------------------------------------
Declare all the global variables here*/

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
  unsigned int remain;

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
// 08. SETTING
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
Declare all the gimmicks functions, which will be separate program from the original. No I/O*/
void switchHub();               // For moving to the selection of the functions
void terminate();               // For save and stop the program
void screenAdjust();            // For calculating the screen size to the optimum size
void screenClear();             // For refreshing the screen to the new one
void settings();                // For setting up the screensize, default login scheme

/*-----------------------------------------------------------------------------
Declare all the gimmicks functions*/
void bannerFullBorder();
void bannerBlankBorder();
void bannerBlankBorderText(char *text);
void banner(char *bannerLine1, char *bannerLine2, char *bannerLine3, char *bannerLine4);

/*-----------------------------------------------------------------------------
Declare all the database file !!build!! functions*/

void initDatabase();            // For Database Initialization
void personnelDatabase();       // For Personnel Database
void inventoryDatabase();       // For Inventory Database
void categoryDatabase();        // For Category Database
void transactionDatabase();     // For Transaction Database
void purchaseDatabase();        // For Purchase Database
void customerDatabase();        // For Customer Database
void promotionDatabase();       // For Promotion Database
void settingDatabase();         // For Setting Database

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
/* 
  Note: To use a function `personnelSelectById`
         - Pass the values by reference e.g. personnelSelectById(id, firstname, lastname, &role, username, password, barcode_token); 
        All of the `int` functions
         - If the record is be found then return 1 otherwise, return 0
*/
int personnelSelectById(char *id, char *firstname, char *lastname, int role, char *username, char *password, char *barcode_token);  // Retrieve the record by `id` (all values will return automatically by the concept of `pass by reference`)

void personnelInsert(char *id, char *firstname, char *lastname, int role, char *username, char *password, char *barcode_token);   // Adding a new record to the database
int personnelUpdateFirstname(char *id, char *firstname);    // For modifying the `firstname` (Select the record by `id`)
int personnelUpdateLastname(char *id, char *lastname);      // For modifying the `lastname` (Select the record by `id`)
int personnelUpdateRole(char *id, int role);                // For modifying the `role` (Select the record by `id`)
int personnelUpdatePassword(char *id, char *password);      // For modifying the `password` (Select the record by `id`)
int personnelDelete(char *id);                              // Delete the record (Select by `id`)

/*-----------------------------------------------------------------------------
Declare all the Inventory Database can do*/
/* 
  Note: To use a function `inventorySelectById`
         - Pass the values by reference e.g. inventorySelectById(id, name, &price, &profit, categoryId, &remain);
        All of the `int` functions
         - If the record is be found then return 1 otherwise, return 0
*/
int inventorySelectById(char *id, char *name, double *price, double *profit, char *categoryId, unsigned int *remain); // Retrieve the record by `id` (all values will return automatically by the concept of `pass by reference`)

void inventoryInsert(char *id, char *name, double price, double profit, char *categoryId, unsigned int remain);   // Adding a new record to the database
int inventoryUpdateName(char *id, char *name);              // For modifying the `name` (Select the record by `id`)
int inventoryUpdatePrice(char *id, double price);           // For modifying the `price` (Select the record by `id`)
int inventoryUpdateProfit(char *id, double profit);         // For modifying the `profit` (Select the record by `id`)
int inventoryUpdateCategory(char *id, char *categoryId);    // For modifying the `categoryId` (Select the record by `id`)
int inventoryUpdateRemain(char *id, unsigned int remain);   // For modifying the `remain` (Select the record by `id`)
int inventoryDelete(char *id);                              // Delete the record (Select by `id`)

/*-----------------------------------------------------------------------------
Declare all the Category Database can do*/
/* 
  Note: To use a function `categorySelectById`
         - Pass the values by reference e.g. categorySelectById(id, name);
        All of the `int` functions
         - If the record is be found then return 1 otherwise, return 0
*/
int categorySelectById(char *id, char *name);               // Retrieve the record by `id` (all values will return automatically by the concept of `pass by reference`)

void categoryInsert(char *id, char *name);                  // Adding a new record to the database
int categoryUpdateName(char *id, char *name);               // For modifying the `name` (Select the record by `id`)
int categoryDelete(char *id);                               // Delete the record (Select by `id`)

/*-----------------------------------------------------------------------------
Declare all the Transaction Database can do*/
/* 
  Note: To use a function `transactionSelectById`
         - Pass the values by reference e.g. transactionSelectById(id, purchaseId, inventoryId);
        All of the `int` functions
         - If the record is be found then return 1 otherwise, return 0
*/
int transactionSelectById(char *id, char *purchaseId, char *inventoryId);   // Retrieve the record by `id` (all values will return automatically by the concept of `pass by reference`)

void transactionInsert(char *id, char *purchaseId, char *inventoryId);      // Adding a new record to the database

/*-----------------------------------------------------------------------------
Declare all the Purchase Database can do*/
/* 
  Note: To use a function `purchaseSelectById`
         - Pass the values by reference e.g. purchaseSelectById(id, &totalPrice, customerId, personnelId, &datetime);
        All of the `int` functions
         - If the record is be found then return 1 otherwise, return 0
*/
int purchaseSelectById(char *id, double *totalPrice, char *customerId, char *personnelId, time_t *datetime);    // Retrieve the record by `id` (all values will return automatically by the concept of `pass by reference`)

void purchaseInsert(char *id, double totalPrice, char *customerId, char *personnelId, time_t datetime);         // Adding a new record to the database

/*-----------------------------------------------------------------------------
Declare all the Customer Database can do*/
/* 
  Note: To use a function `customerSelectById`
         - Pass the values by reference e.g. customerSelectById(id, firstname, lastname, &gender, &point, &totalBuy);
        All of the `int` functions
         - If the record is be found then return 1 otherwise, return 0
*/
int customerSelectById(char *id, char *firstname, char *lastname, char *gender, double *point, double *totalBuy);   // Retrieve the record by `id` (all values will return automatically by the concept of `pass by reference`)

void customerInsert(char *id, char *firstname, char *lastname, char gender, double point, double totalBuy);         // Adding a new record to the database
int customerUpdateFirstname(char *id, char *firstname);     // For modifying the `firstname` (Select the record by `id`)
int customerUpdateLastname(char *id, char *lastname);       // For modifying the `lastname` (Select the record by `id`)
int customerUpdateGender(char *id, char gender);            // For modifying the `gender` (Select the record by `id`)
int customerUpdatePoint(char *id, double point);            // For modifying the `point` (Select the record by `id`)
int customerUpdatetotalBuy(char *id, double totalBuy);      // For modifying the `totalBuy` (Select the record by `id`)
int customerDelete(char *id);                               // Delete the record (Select by `id`)

/*-----------------------------------------------------------------------------
Declare all the Promotion Database can do*/
/* 
  Note: To use a function `promotionSelectById`
         - Pass the values by reference e.g. promotionSelectById(id, &price, &status);
        All of the `int` functions
         - If the record is be found then return 1 otherwise, return 0
*/
int promotionSelectById(char *id, double *price, int *status);    // Retrieve the record by `id` (all values will return automatically by the concept of `pass by reference`)

void promotionInsert(char *id, double price, int status);         // Adding a new record to the database
int promotionUpdatePrice(char *id, double price);                 // For modifying the `price` (Select the record by `id`)
int promotionUpdateStatus(char *id, int status);                  // For modifying the `status` (Select the record by `id`)
int promotionDelete(char *id);                                    // Delete the record (Select by `id`)

/*-----------------------------------------------------------------------------
Declare all the Setting Database can do*/
void settingUpdateStoreName(char *storeName);           // For modifying the `storeName`
void settingUpdateAddress(char *storeAddress);          // For modifying the `storeAddress`
void settingUpdatePriceToPoint(double priceToPoint);    // For modifying the `priceToPoint`
void settingUpdatePointToPrice(double pointToPrice);    // For modifying the `pointToPrice`

/*-----------------------------------------------------------------------------
Declare all the forecast function can do*/
/*
void monthlyForecast();
void quarterForecast();
void annualForecast();

void forecastResults();
void forecastProgram();

void forecastPrint();
*/

/*-----------------------------------------------------------------------------
Decease what the seller can do*/
/*
void cashierInterface();
*/

/*-----------------------------------------------------------------------------
Declares all the authentication functions and interface*/
void authenticateByUsername(char *username, char *password);    // For signing in
void authenticateByToken(char *token);                          // For signing in
void deauthenticate();          // For signing out
/*
void authInterface();           // For sign in interface
void authInterfaceComplete();   // For complete sign in interface
void authInterfaceFailed();     // For non - complete sign in interface (Error from cancel)
void authInterfaceError();      // For non - complete sign in interface (Other type of error)
*/
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

