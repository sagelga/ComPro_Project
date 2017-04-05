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
char username[140] = "Default"; 	// Username cannot go further than 140, as the maximum border size is 140.
int userPermission = 0; 			// 0 = Not sign-in | 1 = Sales | 2 = Manager | 3 = Admin
char storeName[140] = "Default";
char storeAddress[140] = "Default";

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


PERSONNEL Personnel[MAX_IDX_PERSONNEL];           // Declare the Personnel table
INVENTORY Inventory[MAX_IDX_INVENTORY];           // Declare the Inventory table
CATEGORY Category[MAX_IDX_CATEGORY];              // Declare the Category table
TRANSACTION Transaction[MAX_IDX_TRANSACTION];     // Declare the Transaction table
PURCHASE Purchase[MAX_IDX_PURCHASE];              // Declare the Purchase table
CUSTOMER Customer[MAX_IDX_CUSTOMER];              // Declare the Customer table
PROMOTION Promotion[MAX_IDX_PROMOTION];           // Declare the Promotion table
SETTING Setting;                                  // Declare the Setting table

RECORDCOUNT RecordCount;                          // Declare the Record Counter

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
Declare all the database file !!build!! functions*/

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

void personnelFileRead(int keyID, char name, char nameMeta, double value, double accuValue);       // For Personnel Database
void inventoryFileRead();       									// For Inventory Database
void categoryFileRead();        									// For Category Database
void transactionFileRead();     									// For Transaction Database
void purchaseFileRead();        									// For Purchase Database
void customerFileRead();        									// For Customer Database
void promotionFileRead();       									// For Promotion Database
void settingFileRead();         									// For Setting Database

/*-----------------------------------------------------------------------------
Declare all the database file <<Write<< functions*/
void personnelFileWrite(int keyID, char name, char nameMeta, double value, double accuValue);       // For Personnel Database
void inventoryFileWrite();       									// For Inventory Database
void categoryFileWrite();        									// For Category Database
void transactionFileWrite();     									// For Transaction Database
void purchaseFileWrite();        									// For Purchase Database
void customerFileWrite();        									// For Customer Database
void promotionFileWrite();       									// For Promotion Database
void settingFileWrite();         									// For Setting Database

/*-----------------------------------------------------------------------------
Declare all the database display functions*/

void initDatabaseInterface();            									// For Database Initialization
void personnelDatabaseInterface();       									// For Personnel Database
void inventoryDatabaseInterface();       									// For Inventory Database
void categoryDatabaseInterface();        									// For Category Database
void transactionDatabaseInterface();     									// For Transaction Database
void purchaseDatabaseInterface();        									// For Purchase Database
void customerDatabaseInterface();        									// For Customer Database
void promotionDatabaseInterface();       									// For Promotion Database
void settingDatabaseInterface();         									// For Setting Database

/*-----------------------------------------------------------------------------
Declare all the other database functions*/
int isFileExist(const char *filename);  // For check a file exist. If the file is exist then return 1 otherwise return 0
unsigned int tail(unsigned int table);  // Return the first empty index of the list (For insert new record)

/*-----------------------------------------------------------------------------
Declare all the admin tools*/
void adminAuthenticate(char adminID, char username);
void adminRoleAuth(char adminID, char username);
void adminRoleDeauth(char adminID, char username);
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
void SaleAdd();         // For adding the ID data from Database
void SaleModify();          // For modifying the ID data from Database
void SaleRemove();          //For removing the ID data from Database

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
void promotionAdd(int keyID, char name, char nameMeta, int values);            // For adding the ID data from Database
void promotionModify(int keyID, char name, char nameMeta, int values);         // For modifying the ID data from Database
void promotionRemove(int keyID, char name, char nameMeta, int values);         //For removing the ID data from Database

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
