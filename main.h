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

/*-----------------------------------------------------------------------------
Declare all the global variables here*/
char username[140] = "Default"; // Username cannot go further than 140, as the maximum border size is 140.
int userPermission = 0; // 0 = Not sign-in | 1 = Sales | 2 = Manager | 3 = Admin
char storeName[140] = "Default";
char storeAddress[140] = "Default";

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
void logDatabase();             // For Log Database
void transactionDatabase();     // For Transaction Database
void customerDatabase();        // For Customer Database
void promotionDatabase();       // For Promotion Database
void settingDatabase();         // For Setting Database

/*-----------------------------------------------------------------------------
Declare all the database file >>Read>> functions*/

void personnelFileRead(int keyID, char name, char nameMeta, double value, double accuValue);       // For Personnel Database
void inventoryFileRead();       // For Inventory Database
void categoryFileRead();        // For Category Database
void logFileRead();             // For Log Database
void transactionFileRead();     // For Transaction Database
void customerFileRead();        // For Customer Database
void promotionFileRead();       // For Promotion Database
void settingFileRead();         // For Setting Database

/*-----------------------------------------------------------------------------
Declare all the database file <<Write<< functions*/
void personnelFileWrite(int keyID, char name, char nameMeta, double value, double accuValue);       // For Personnel Database
void inventoryFileWrite();       // For Inventory Database
void categoryFileWrite();        // For Category Database
void logFileWrite();             // For Log Database
void transactionFileWrite();     // For Transaction Database
void customerFileWrite();        // For Customer Database
void promotionFileWrite();       // For Promotion Database
void settingFileWrite();         // For Setting Database

/*-----------------------------------------------------------------------------
Declare all the database call functions*/

/*-----------------------------------------------------------------------------
Declare all the interface functions*/

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
        Please. No bug. No crash. No interruption.         */

