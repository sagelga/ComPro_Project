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

    /* Please remove these area if you have completed the beta testing

    if (Session.user.role == 0){
        screenClear ();
    }
    else if (Session.user.role == 1){
        switchHubManager ();
     } else if (Session.user.role == 2){
        switchHubSales ();
    }
    else{
        bannerFullBorder ();
        bannerBlankBorderTextCen ("We cannot checked your credential. Please and log in again....");
        bannerFullBorder ();

        delay (5);

        deauthenticate ();
    }
*/

    char text1[140];
    strcpy (text1, "Welcome back ");
    strcat (text1, Session.user.username);
    strcat (text1, "!");

    bannerInverse(text1, "", "", "You are now connected to the POS system");

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

    for (int i = 20;i>0;i--)
        bannerBlankBorder();

    bannerBlankBorderTextCen ("  Type 'N' to quit  |  Type in your response  |  Type 'B' to logoff");
    bannerFullBorder();
    bannerUserInput();

    char flags;
    scanf(" %c", &flags);

    screenClear ();

    switch (flags) {
        case ('1'): // Sign In / Sign Out
            cashierInterface ();

        case ('2'):// Go to POS Systems Interface (for cashier)
            inventorySwitchHub ();

        case ('3'):// Go to check Inventory Database
            customerSwitchHub ();

        case ('4'):
            categorySwitchHub ();

        case ('5'):
            promotionSwitchHub ();

        case ('6'):
            purchaseDatabase ();

        case ('7'):
            transactionSwitchHub ();

        case ('8'):
            settingsSwitchHub ();

        case ('9'):
           // reportSwitchHub();

        case ('n'):
            terminate();
        
        case ('N'):
            terminate();

        case ('b'):
            deauthenticate ();

        case ('B'):
            deauthenticate ();

        default:
            // The input is invalid. Trying to route back to ask for a valid input
            printf("Your input is invalid. Please try again.\n\n\n");
            switchHub();
    }
}

void switchHubManager() { // Copies the item from the switchHub()
}

void switchHubSales() { // Copies the item from the switchHub()
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