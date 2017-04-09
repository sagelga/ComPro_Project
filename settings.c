// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void settingsSwitchHub () {
    screenClear ();
    bannerFullBorder ();
    bannerBlankBorderTextCen ("Settings");
    bannerFullBorder ();

    bannerBlankBorderTextCen ("What do you want to do?");

    for ( int i = 0; i < 2; i++ )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Authentication");
    bannerFullBorderSection ();
    bannerBlankBorderTextCen ("1. Change Username");
    bannerBlankBorderTextCen ("2. Change Password");

    for ( int i = 0; i < 2; i++ )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Storefront");
    bannerFullBorderSection ();
    bannerBlankBorderTextCen ("3. Change store name");
    bannerBlankBorderTextCen ("4. Change store address");

    for ( int i = 0; i < 2; i++ )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Credits");
    bannerFullBorderSection ();
    bannerBlankBorderTextCen ("5. List of contributors");
    bannerBlankBorderTextCen ("6. Cat dance");

    for ( int i = 0; i < 15; i++ )
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
    bannerFullBorder ();

    bannerUserInput ();
    char flag;
    scanf (" %c", &flag);

    switch ( toupper(flag) ) {

        case ('1'):
            return;

        case ('2'):
            return;

        case ('3'):
            return;

        case ('4'):
            return;

        case ('5'):
            settingContributorList ();
        case ('B'):
            switchHub ();

        case ('N'):
            terminate ();

        default:
            settingsSwitchHub ();
            return;

    }
}

void settingUpdateUsernameInterface(){

}

void settingUpdatePasswordInterface(){

}


void settingUpdateStoreNameInterface(){
}

void settingUpdateStoreAddressInterface(){
}

void settingContributorList(){
    screenClear ();

    bannerCenBorder ("Educational purpose only","Redistribution of project is not allowed","Created by the 1st year student IT KMITL 14","POS Version 1.0");
    bannerBlankBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Lists of team members");
    bannerFullBorderSection ();
    bannerBlankBorderTextCen ("Kunanon   Srisuntiroj   @sagelga      59070022");
    bannerBlankBorderTextCen ("Thanawat  Laodkaew      @skydddoogg   59070071");
    bannerBlankBorderTextCen ("Noppanut  Ploywong      @noppanut15   59070082");
    bannerBlankBorderTextCen ("Vasanchai Prakobkij     @59070156     59070156");
    bannerBlankBorderTextCen ("Weerakorn Pongpum                     59070163");

    for (int i = 2;i>0;i--)
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Over 5000 lines of pure C language has been neatly crafted with love and passion <3");
    bannerBlankBorderTextCen ("See our GitHub Repository : https://github.com/sagelga/ComPro_Project");

    for (int i = 19;i>0;i--)
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Redirecting you back in 10 seconds...");
    bannerFullBorder ();

    delay (10);

    // Show picture of us in ASCII ;)
}

void settingCat(){

}
void settingUpdateStoreName (char *storeName) {
    strcpy (Setting.storeName, storeName);
    settingFileWrite ();    // Save to a Database file

}

void settingUpdateAddress (char *storeAddress) {
    strcpy (Setting.storeAddress, storeAddress);
    settingFileWrite ();    // Save to a Database file
}

void settingUpdatePriceToPoint (double priceToPoint) {
    Setting.priceToPoint = priceToPoint;
    settingFileWrite ();    // Save to a Database file
}

void settingUpdatePointToPrice (double pointToPrice) {
    Setting.pointToPrice = pointToPrice;
    settingFileWrite ();    // Save to a Database file
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