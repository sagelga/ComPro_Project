// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void settingsSwitchHub () {
    screenClear ();
    bannerFullBorder();
    bannerBlankBorderTextCen ("Settings");
    bannerFullBorder();

    bannerBlankBorderTextCen ("What do you want to do?");

    for (int i = 0;i<2;i++)
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Authentication");
    bannerFullBorderSection ();
    bannerBlankBorderTextCen ("1. Change Username");
    bannerBlankBorderTextCen ("2. Change Password");

    for (int i = 0;i<2;i++)
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Storefront");
    bannerFullBorderSection ();
    bannerBlankBorderTextCen ("3. Change store name");
    bannerBlankBorderTextCen ("4. Change store address");

    for (int i = 0;i<21;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
    bannerFullBorder ();

    bannerUserInput ();
    char flag;
    scanf(" %c", &flag);

    switch(flag){

        case ('1'):
            return;

        case ('2'):
            return;

        case ('3'):
            return;

        case ('4'):
            return;

        case ('b'):
            switchHub ();
        case ('B'):
            switchHub ();

        case ('n'):
            terminate ();
        case ('N'):
            terminate ();

        default:
            settingsSwitchHub ();
            return;

    }
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