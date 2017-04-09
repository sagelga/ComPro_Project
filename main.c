// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

/*---------------------------------------------------------------------------*/
int main () { // This program will run first. POS Interface configuration will be called, and ready to work.
    screenClear ();
    initDatabase ();
    //screenAdjust();
    switchHub ();
    return 0;
}

void switchHub () {

    screenClear ();

    char text[140];
    char text1[140];

    if ( Session.user.role == 0 ) {
        strcpy (text1, "admin");
    } else if ( Session.user.role == 1 ) {
        strcpy (text1, "manager");
    } else if ( Session.user.role == 2 ) {
        strcpy (text1, "sale");
    }


    sprintf (text, "Welcome back %s as %s!", Session.user.firstname,text1);

    bannerInverse (text, "", "", Setting.storeName);

    bannerBlankBorderTextCen ("What do you want to do?");
    bannerBlankBorder ();

    //These choice will be removed, when the program detects the permission level.
    bannerBlankBorderTextCen ("1. Go to POS System");
    bannerBlankBorderTextCen ("2. Check Inventory");
    bannerBlankBorderTextCen ("3. Check Customer");
    bannerBlankBorderTextCen ("4. Check Promotion");
    bannerBlankBorderTextCen ("5. Check Personnel");
    bannerBlankBorderTextCen ("6. Check Report");
    bannerBlankBorderTextCen ("7. Sales Forecasting");
    bannerBlankBorderTextCen ("8. Settings");
    bannerBlankBorder ();

    for ( int i = 21; i > 0; i-- )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("  Type 'Q' to quit  |  Type in your response  |  Type 'B' to logoff");
    bannerFullBorder ();
    bannerUserInput ();

    char flags;
    scanf (" %c", &flags);

    screenClear ();

    switch ( toupper (flags)) {
        case ('1'): // Sign In / Sign Out
            cashierInterface ();
            break;

        case ('2'):// Go to POS Systems Interface (for cashier)
            inventorySwitchHub ();
            break;

        case ('3'):// Go to check Inventory Database
            customerSwitchHub ();
            break;

        case ('4'):
            promotionSwitchHub ();
            break;

        case ('5'):
           // personnelSwitchHub ();
            break;

        case ('6'):
            reportSwitchHub ();
            break;

        case ('7'):
           // forecastSwitchHub ();
            break;

        case ('8'):
            settingsSwitchHub ();
            break;

        case ('Q'):
            terminate ();
            break;

        case ('B'):
            deauthenticate ();
            break;

        default:
            // The input is invalid. Trying to route back to ask for a valid input
            switchHub ();
    }
}

void switchHubManager () { // Copies the item from the switchHub()
}

void switchHubSales () { // Copies the item from the switchHub()
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