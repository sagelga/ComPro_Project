/*      Hello. Do you know about trucks, right? - Donald Trump
 *      https://www.youtube.com/watch?v=oguvSPdtHQ8
 */

#ifndef MAIN_H_
#define MAIN_H_

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

/*-----------------------------------------------------------------------------
Declare all the global variables here*/

//-------------------------------------------------------------------------------------------------------
// # - File: AUTHENTICATE.c
//-------------------------------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------
Declares all the authentication functions and interface*/
int authenticateByUsername(char *username, char *password);    // For signing in (Return 1 = Success | 0 = Password Incorrect | -1 = User not found)
int authenticateByToken(char *barcodeToken);                   // For signing in (Return 1 = Success | 0 = Token Not found)
void deauthenticate();          // For signing out

void authInterface();           // For sign in interface
void authInterfaceComplete();   // For complete sign in interface
void authInterfaceFail();     // For non - complete sign in interface (Error from cancel)
void authInterfaceError();      // For non - complete sign in interface (Other type of error)

//-------------------------------------------------------------------------------------------------------
// # - File: SYSTEMCALL.c
//-------------------------------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------
Declare all the database file !!fetch!! functions*/

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

//-------------------------------------------------------------------------------------------------------
// # - File: PERSONNEL.c
//-------------------------------------------------------------------------------------------------------
// Database structure
typedef struct
{
  char id[MAX_LNG_ID];
  char firstname[MAX_LNG_TEXT];
  char lastname[MAX_LNG_TEXT];
  int role; // 0 = Manager | 1 = Marketing | 2 = Sale
  char username[MAX_LNG_TEXT];
  char password[MAX_LNG_TEXT];
  char barcodeToken[MAX_LNG_TOKEN]; // For use a barcode authentication
} PERSONNEL;

PERSONNEL Personnel[MAX_IDX_PERSONNEL];           // Declare the Personnel table

/*-----------------------------------------------------------------------------
Declare all the Personnel Database can do*/
/*
  Note: To use a function `personnelSelectById`
         - Pass the values by reference e.g. personnelSelectById(id, firstname, lastname, &role, username, password, barcodeToken);
        All of the `int` functions
         - If the function has an error (not found / duplicate) then return 0. So, if it success then return 1
*/
int personnelSelectById(char *id, char *firstname, char *lastname, int *role, char *username, char *password, char *barcodeToken);  // Retrieve the record by `id` (all values will return automatically by the concept of `pass by reference`)

int personnelInsert(char *id, char *firstname, char *lastname, int role, char *username, char *password, char *barcodeToken);   // Adding a new record to the database
int personnelUpdateFirstname(char *id, char *firstname);    // For modifying the `firstname` (Select the record by `id`)
int personnelUpdateLastname(char *id, char *lastname);      // For modifying the `lastname` (Select the record by `id`)
int personnelUpdateRole(char *id, int role);                // For modifying the `role` (Select the record by `id`)
int personnelUpdatePassword(char *id, char *password);      // For modifying the `password` (Select the record by `id`)
int personnelDelete(char *id);                              // Delete the record (Select by `id`)

void personnelSwitchHub();
void personnelInsertInterface();
void personnelSelectInterface();
void personnelDeleteInterface();
void personnelUpdateInterface();

//-------------------------------------------------------------------------------------------------------
// # - File: INVENTORY.c
//-------------------------------------------------------------------------------------------------------
// Database structure
typedef struct
{
  char id[MAX_LNG_ID];
  char name[MAX_LNG_SCREEN];
  double price;
  double profit; // Profit per item
  unsigned int categoryId; // Category ID
  unsigned int remain;

} INVENTORY;

INVENTORY Inventory[MAX_IDX_INVENTORY];           // Declare the Inventory table

/*-----------------------------------------------------------------------------
Declare all the Inventory Database can do*/
/*
  Note: To use a function `inventorySelectById`
         - Pass the values by reference e.g. inventorySelectById(id, name, &price, &profit, &categoryId, &remain);
        All of the `int` functions
         - If the function has an error (not found / duplicate) then return 0. So, if it success then return 1
*/
int inventorySelectById(char *id, char *name, double *price, double *profit, unsigned int *categoryId, unsigned int *remain); // Retrieve the record by `id` (all values will return automatically by the concept of `pass by reference`)

int inventoryInsert(char *id, char *name, double price, double profit, unsigned int categoryId, unsigned int remain);   // Adding a new record to the database
int inventoryUpdateName(char *id, char *name);                     // For modifying the `name` (Select the record by `id`)
int inventoryUpdatePrice(char *id, double price);                  // For modifying the `price` (Select the record by `id`)
int inventoryUpdateProfit(char *id, double profit);                // For modifying the `profit` (Select the record by `id`)
int inventoryUpdateCategory(char *id, unsigned int categoryId);    // For modifying the `categoryId` (Select the record by `id`)
int inventoryUpdateRemain(char *id, unsigned int remain);          // For modifying the `remain` (Select the record by `id`)
int inventoryDelete(char *id);                                     // Delete the record (Select by `id`)

void inventoryAdd();
void inventoryRemove();
void inventoryDatabaseInterface ();
void displayInventory(int page);


//-------------------------------------------------------------------------------------------------------
// # - File: CATEGORY.c
//-------------------------------------------------------------------------------------------------------
// Database structure
typedef struct
{
  unsigned int id;
  char name[MAX_LNG_TEXT];
} CATEGORY;

CATEGORY Category[MAX_IDX_CATEGORY];              // Declare the Category table

/*-----------------------------------------------------------------------------
Declare all the Category Database can do*/
/*
  Note: To use a function `categorySelectById`
         - Pass the values by reference e.g. categorySelectById(id, name);
        All of the `int` functions
         - If the function has an error (not found / duplicate) then return 0. So, if it success then return 1
*/
int categorySelectById(unsigned int id, char *name);  // Retrieve the record by `id` (all values will return automatically by the concept of `pass by reference`)

int categoryInsert(char *name);                               // Adding a new record to the database
int categoryUpdateName(unsigned int id, char *name);  // For modifying the `name` (Select the record by `id`)

void categoryDatabaseInterface();
void categoryAdd();
void displayCategory(int page);

//-------------------------------------------------------------------------------------------------------
// # - File: TRANSACTION.c
//-------------------------------------------------------------------------------------------------------
// Database structure
typedef struct
{
  unsigned int id;
  unsigned int purchaseId;
  char inventoryId[MAX_LNG_ID];
  char inventoryName[MAX_LNG_SCREEN];
  double inventoryPrice;
  double inventoryProfit; // Profit per item
  unsigned int inventoryCategoryId; // Category ID
  time_t timestamp; // Epoch timestamp

} TRANSACTION;

TRANSACTION Transaction[MAX_IDX_TRANSACTION];     // Declare the Transaction table

/*-----------------------------------------------------------------------------
Declare all the Transaction Database can do*/
/*
  Note: To use a function `transactionSelectById`
         - Pass the values by reference e.g. transactionSelectById(id, &purchaseId, &inventoryPrice, &inventoryProfit, &inventoryCategoryId, &timestamp);
        All of the `int` functions
         - If the function has an error (not found / duplicate) then return 0. So, if it success then return 1
*/
int transactionSelectById(unsigned int id, unsigned int *purchaseId, double *inventoryPrice, double *inventoryProfit, unsigned int *inventoryCategoryId, time_t *timestamp);   // Retrieve the record by `id` (all values will return automatically by the concept of `pass by reference`)

void transactionInsert(unsigned int purchaseId, char *inventoryId);      // Adding a new record to the database

//-------------------------------------------------------------------------------------------------------
// # - File: PURCHASE.c
//-------------------------------------------------------------------------------------------------------
// Database structure
typedef struct
{
  unsigned int id;
  double totalPrice;
  double totalDiscount;
  double totalProfit;
  char customerId[MAX_LNG_ID];
  char personnelId[MAX_LNG_ID]; // Cashier
  time_t timestamp; // Epoch timestamp
} PURCHASE;

PURCHASE Purchase[MAX_IDX_PURCHASE];              // Declare the Purchase table

/*-----------------------------------------------------------------------------
Declare all the Purchase Database can do*/
/*
  Note: To use a function `purchaseSelectById`
         - Pass the values by reference e.g. purchaseSelectById(id, &totalPrice, &totalDiscount, customerId, personnelId, &timestamp);
        All of the `int` functions
         - If the function has an error (not found / duplicate) then return 0. So, if it success then return 1
*/
int purchaseSelectById(unsigned int id, double *totalPrice, double *totalDiscount, double *totalProfit, char *customerId, char *personnelId, time_t *timestamp);    // Retrieve the record by `id` (all values will return automatically by the concept of `pass by reference`)

void purchaseInsert(double totalPrice, double totalDiscount, double totalProfit, char *customerId, char *personnelId);         // Adding a new record to the database

//-------------------------------------------------------------------------------------------------------
// # - File: CUSTOMER.c
//-------------------------------------------------------------------------------------------------------
// Database structure
typedef struct
{
  char id[MAX_LNG_ID];
  char firstname[MAX_LNG_TEXT];
  char lastname[MAX_LNG_TEXT];
  char gender; // 'F' = Female | 'M' = Male
  double point;
  double totalBuy;
} CUSTOMER;

CUSTOMER Customer[MAX_IDX_CUSTOMER];              // Declare the Customer table

/*-----------------------------------------------------------------------------
Declare all the Customer Database can do*/
/*
  Note: To use a function `customerSelectById`
         - Pass the values by reference e.g. customerSelectById(id, firstname, lastname, &gender, &point, &totalBuy);
        All of the `int` functions
         - If the function has an error (not found / duplicate) then return 0. So, if it success then return 1
*/
int customerSelectById(char *id, char *firstname, char *lastname, char *gender, double *point, double *totalBuy);   // Retrieve the record by `id` (all values will return automatically by the concept of `pass by reference`)

int customerInsert(char *id, char *firstname, char *lastname, char gender);         // Adding a new record to the database
int customerUpdateFirstname(char *id, char *firstname);     // For modifying the `firstname` (Select the record by `id`)
int customerUpdateLastname(char *id, char *lastname);       // For modifying the `lastname` (Select the record by `id`)
int customerUpdateGender(char *id, char gender);            // For modifying the `gender` (Select the record by `id`)
int customerUpdatePoint(char *id, double point);            // For modifying the `point` (Select the record by `id`)
int customerUpdatetotalBuy(char *id, double totalBuy);      // For modifying the `totalBuy` (Select the record by `id`)
int customerDelete(char *id);                               // Delete the record (Select by `id`)

//Update Selection
void customerInsertInterface();
void customerSelectInterface();
void customerDeleteInterface();

void customerUpdateInterface();

void displayCustomer(int page);

//-------------------------------------------------------------------------------------------------------
// # - File: PROMOTION.c
//-------------------------------------------------------------------------------------------------------
// Database structure
typedef struct
{
  char id[MAX_LNG_ID];
  double price;
  int status; // 1 = active | 0 = used (exprired)
} PROMOTION;

PROMOTION Promotion[MAX_IDX_PROMOTION];           // Declare the Promotion table

/*-----------------------------------------------------------------------------
Declare all the Promotion Database can do*/
/*
  Note: To use a function `promotionSelectById`
         - Pass the values by reference e.g. promotionSelectById(id, &price, &status);
        All of the `int` functions
         - If the function has an error (not found / duplicate) then return 0. So, if it success then return 1
*/
int promotionSelectById(char *id, double *price, int *status);    // Retrieve the record by `id` (all values will return automatically by the concept of `pass by reference`)

int promotionInsert(char *id, double price);                      // Adding a new record to the database
int promotionUpdatePrice(char *id, double price);                 // For modifying the `price` (Select the record by `id`)
int promotionUpdateStatus(char *id, int status);                  // For modifying the `status` (Select the record by `id`)
int promotionDelete(char *id);                                    // Delete the record (Select by `id`)

void promotionInsertInterface();
void promotionSelectInterface();
void promotionDeleteInterface();
void promotionUpdateInterface();

void displayPromotion(int page);

//-------------------------------------------------------------------------------------------------------
// # - File: SETTING.c
//-------------------------------------------------------------------------------------------------------
// Database structure
typedef struct
{
  char storeName[MAX_LNG_SCREEN];
  char storeAddress[MAX_LNG_SCREEN];
  double priceToPoint; // When you pay N Baht, you'll receive `N * priceToPoint` points.
  double pointToPrice; // `pointToPrice` point is equal to 1 Baht.
} SETTING;

SETTING Setting;                                  // Declare the Setting table

/*-----------------------------------------------------------------------------
Declare all the Setting Database can do*/
void settingUpdateStoreName(char *storeName);           // For modifying the `storeName`
void settingUpdateAddress(char *storeAddress);          // For modifying the `storeAddress`
void settingUpdatePriceToPoint(double priceToPoint);    // For modifying the `priceToPoint`
void settingUpdatePointToPrice(double pointToPrice);    // For modifying the `pointToPrice`
void settingUpdateUsernameInterface();

void settingUpdatePasswordInterface();
void settingUpdateStoreNameInterface();
void settingUpdateStoreAddressInterface();
void settingContributorList();
void settingCat();

//-------------------------------------------------------------------------------------------------------
// # - File: REPORT.c
//-------------------------------------------------------------------------------------------------------
// Report collect revenue by categery
struct REPORT1 {
  char categoryName[MAX_LNG_TEXT];
  double totalPrice;
  double totalProfit;

} RevenueByCategory[MAX_IDX_CATEGORY];

struct REPORT2 {
  char monthName[10];
  double totalPrice;
  double totalProfit;

} RevenueByMonth[12];

struct REPORT3 {
  char id[MAX_LNG_ID];
  char firstname[MAX_LNG_TEXT];
  char lastname[MAX_LNG_TEXT];
  double totalPrice;
  double totalProfit;

} RevenueByPersonnel[MAX_IDX_PERSONNEL];

struct FORECAST1 {
  char categoryName[MAX_LNG_TEXT];
  double totalPrice;
  double totalProfit;

} SaleForecastByCategory[MAX_IDX_CATEGORY], SaleForecastByCategoryTemp;

struct FORECAST2 {
  char monthName[10];
  double totalPrice;
  double totalProfit;

} SaleForecastByMonth, SaleForecastByMonthTemp;

/*-----------------------------------------------------------------------------
Declare all the the report function can do*/
// Report show by category
void oneDayReport(int date, int month, int year);  // Total of revenue on one day, result is store in a structure `RevenueByCategory`
void multipleDayReport(int fromDate, int fromMonth, int fromYear, int toDate, int toMonth, int toYear);    // Total of revenue from dd/mm/yyyy to dd/mm/yyyy, result is store in a structure `RevenueByCategory`
void nextnDayReport(int fromDate, int fromMonth, int fromYear, int nDay);     // Total of revenue from dd/mm/yyyy to next `N` day(s), result is store in a structure `RevenueByCategory`
void nextnMonthReport(int fromDate, int fromMonth, int fromYear, int nMonth); // Total of revenue from dd/mm/yyyy to next `N` month(s), result is store in a structure `RevenueByCategory`

void monthlyReport();                              // Total of revenue in yyyy year (show by monthly)
void personnelSaleReport();                        // Total of sale by each merchant
void reportSwitchHub();

void OneDayReportInterface();
void OneDayReportInputProcess();
void displayOneDayReport(int page);

void MonthlyReportInterface();
void MonthlyReportInputProcess ();
void displayMonthlyReport ();

void PersonnelSaleReportInterface();
void PersonnelSaleReportInputProcess();
void displayPersonnelSaleReport(int page);

void MultipleDayReportInterface();
void MultipleDayReportInputProcess();
void displayMultipleDayReport(int page);

/*-----------------------------------------------------------------------------
Declare all the forecast function can do*/

void tomorrowSaleForecast();
void nextMonthSaleForecast();

void forecastResults();
void forecastProgram();

void forecastPrint();

void forecastSwitchHub ();
void ShowTomorrowForecasting();
void ShowNextMonthForecasting();
void displayNextMonthForecasting();
void displayTomorrowForecasting(int page);
//

//-------------------------------------------------------------------------------------------------------
// # - File: SUPPORT.c
//-------------------------------------------------------------------------------------------------------

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

RECORDCOUNT RecordCount;                          // Declare the Record Counter

// SESSION Collector
typedef struct{
  int isLogedin;                                  // 1 = Loged-in | 0 = Not-Login (Guest)
  PERSONNEL user;                             // For store user's information

} SESSION;

SESSION Session;                                  // Declare the Session Collector

/*-----------------------------------------------------------------------------
Declare all the other database functions*/

int isFileExist(const char *filename);  // For check a file exist. If the file is exist then return 1 otherwise return 0
time_t toEpochTime(int date, int month, int year, int hour, int minute, int second);  // Convert time from Human-readable to Epoch Unix time format
void toDateMonthYear(time_t epochTime, int *date, int *month, int *year);  // Convert time from Epoch Unix time format to Human-readable
time_t nDayRollbackToDateMonthYear(int date, int month, int year, int nDayRollback); // This function will help to rollback for n-days from the dd/mm/yyyy that you given
time_t nMonthRollbackToDateMonthYear(int date, int month, int year, int nMonthRollback); // This function will help to rollback for n-months from the dd/mm/yyyy that you given
int isTimeInRange(time_t timestamp, time_t start, time_t end);  // Return 1 if the timestamp is in that range (From Start to End), if not return 0
int superscanf(char *input); // Addition form scanf() to detect Blankline; (Return 0 = Empty line | 1 = Has a input)

//-------------------------------------------------------------------------------------------------------
// # - File: DECORATE.c
//-------------------------------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------
Declare all the Options switching functions*/
void switchHub();                       // For moving to the selection of the functions
void switchHubManager();                       // For moving to the selection of the functions
void switchHubSales();                       // For moving to the selection of the functions


void inventorySwitchHub ();               // For moving to the selection of the functions
void customerSwitchHub ();               // For moving to the selection of the functions
void promotionSwitchHub ();               // For moving to the selection of the functions
void settingsSwitchHub ();               // For moving to the selection of the functions
void personnelSwitchHub ();

/*-----------------------------------------------------------------------------
Declare all the gimmicks functions, which will be separate program from the original. No I/O*/
void terminate();               // For save and stop the program
void screenAdjust();            // For calculating the screen size to the optimum size
void screenClear();             // For refreshing the screen to the new one
void delay (int interval);

/*-----------------------------------------------------------------------------
Declare all the gimmicks functions*/
void bannerFullBorder();                      // Prints a full 140 character full of :

void bannerBlankBorder();                     // Prints a :: + 136 charaacter space + ::
void bannerBlankBorderTextCen(char *text);                // Prints a :: + + 134 character space + + :: (Center Align)
void bannerBlankBorderText(char *text);                // Prints a :: + + 134 character space + + :: (Right Align)
void bannerBlankBorderTextLeft (char *text);

void banner(char *bannerLine1, char *bannerLine2, char *bannerLine3, char *bannerLine4);  // Prints banner with configurable character
void bannerInverse(char *bannerLine1, char *bannerLine2, char *bannerLine3, char *bannerLine4); // Prints banner (with POS logo in the right) with configurable character
void bannerCen();
void bannerCenBorder(char *bannerLine1, char *bannerLine2, char *bannerLine3, char *bannerLine4);
void bannerCenStrikethrough(char *bannerLine1, char *bannerLine2, char *bannerLine3, char *bannerLine4);

void bannerUserInput();                       // Asks for input from user

void bannerFullBorderSection ();

/*-----------------------------------------------------------------------------
Define what the sales report can do*/
void saleDatabaseInterface();
/*-----------------------------------------------------------------------------
Decease what the seller can do*/

void cashierInterface();
void cashierInterfaceInventory();
void cashierInterfaceDiscount();// Interface that will ask for discount (voucher and points)
void cashierInterfaceResult();// Interface that will show the total (just like the receipt)



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
      Kunanon Srisuntiroj      @sagelga         59070022
      Thanawat Laodkaew        @skydddoogg      59070071
      Noppanut Ploywong        @noppanut15      59070082
      Vasanchai Prakobkij      @59070156        59070156
      Weerakorn Pongpum                         59070163

 */

 #endif
