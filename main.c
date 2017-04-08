// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

/*---------------------------------------------------------------------------*/
int main(){ // This program will run first. POS Interface configuration will be called, and ready to work.
    screenClear();
    initDatabase();
    //screenAdjust();
    switchHub ();
    return 0;
}

void switchHub() {
    screenClear ();
    char text1[140];
    strcpy (text1, "Welcome back ");
    strcpy (text1, Session.user.username);
    strcpy (text1, "!");
    char text3[107] = "You are now connected to the POS system";

    bannerInverse(text1, "", text3, "");

    bannerBlankBorderTextCen("What do you want to do?");
    bannerBlankBorder();

    //These choice will be removed, when the program detects the permission level.
    bannerBlankBorderTextCen ("1. Go to POS System");
    bannerBlankBorderTextCen ("2. Check Inventory/Category Database");
    bannerBlankBorderTextCen ("3. Check Customer Database");
    bannerBlankBorderTextCen ("4. Check Category Database");
    bannerBlankBorderTextCen ("5. Check Promotion Database");
    bannerBlankBorderTextCen ("6. Check Purchase Database");
    bannerBlankBorderTextCen ("7. Check Transaction Database");
    bannerBlankBorderTextCen ("8. Check Report");
    bannerBlankBorderTextCen ("9. Settings");
    bannerBlankBorder ();

    for (int i = 0;i<20;i++)
        bannerBlankBorder();

    bannerBlankBorderTextCen ("  Type 'N' to quit   |      ALTERNATE RESPONSE      |   Type 'B' to logoff");
    bannerFullBorder();
    bannerUserInput();

    char flags;
    scanf(" %c", &flags);

    screenClear ();

    switch (flags) {
        case ('1'): // Sign In / Sign Out
            cashierInterface ();
            return;

        case ('2'):// Go to POS Systems Interface (for cashier)
            inventorySwitchHub ();
            return;

        case ('3'):// Go to check Inventory Database
            customerSwitchHub ();
            return;

        case ('4'):
            categorySwitchHub ();
            return;

        case ('5'):
            promotionSwitchHub ();
            return;

        case ('6'):
            purchaseDatabase ();
            return;

        case ('7'):
            transactionSwitchHub ();
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

        case ('b'):
            deauthenticate ();
            return;

        case ('B'):
            deauthenticate ();
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
    bannerBlankBorderTextCen ("3. Check Inventory/Category Database");
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

    screenClear ();
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

    screenClear ();

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

/*
 *                                             All hail the god..
 *  -----------------------------------------------------------------------------------------------------------------------
 *  |      _=_      ||      _=_      ||      _=_      ||      _=_      ||      _=_      ||      _=_      ||      _=_      |
 *  |    q(-_-)p    ||    q(-_-)p    ||    q(-_-)p    ||    q(-_-)p    ||    q(-_-)p    ||    q(-_-)p    ||    q(-_-)p    |
 *  |    '_) (_`    ||    '_) (_`    ||    '_) (_`    ||    '_) (_`    ||    '_) (_`    ||    '_) (_`    ||    '_) (_`    |
 *  |    /__/  \    ||    /__/  \    ||    /__/  \    ||    /__/  \    ||    /__/  \    ||    /__/  \    ||    /__/  \    |
 *  |  _(<_   / )_  ||  _(<_   / )_  ||  _(<_   / )_  ||  _(<_   / )_  ||  _(<_   / )_  ||  _(<_   / )_  ||  _(<_   / )_  |
 *  | (__\_\_|_/__) || (__\_\_|_/__) || (__\_\_|_/__) || (__\_\_|_/__) || (__\_\_|_/__) || (__\_\_|_/__) || (__\_\_|_/__) |
 *  |---------------||---------------||---------------||---------------||---------------||---------------||---------------|
 *  |     Hello     ||     Hello     ||     Hello     ||     Hello     ||     Hello     ||     Hello     ||     Hello     |
 *  |     Monday    ||    Tuesday    ||   Wednesday   ||    Thursday   ||     Friday    ||    Saturday   ||     Sunday    |
 *  -----------------------------------------------------------------------------------------------------------------------
 *                                         Program bug best enemy
 *                                 Please. No bug. No crash. No interrupt.
 *  -----------------------------------------------------------------------------------------------------------------------
 */