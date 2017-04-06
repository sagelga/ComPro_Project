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

void settingDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(settingDatabaseFile)){
        fopen(settingDatabaseFile, "w");
    }
}

void settingFileRead(){
    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer

    fp = fopen(settingDatabaseFile, "r");

    fscanf(fp, "%[^\t]\t%[^\t]\t%lf\t%lf", Setting.storeName, Setting.storeAddress, &Setting.priceToPoint, &Setting.pointToPrice);
    fclose(fp);

    // For debugging
    // printf(">>>> %s--%s--%lf--%lf\n", Setting.storeName, Setting.storeAddress, Setting.priceToPoint, Setting.pointToPrice);
}

void settingFileWrite(){
    // Save all of the settings to a database file
    FILE *fp;               // File Pointer

    fp = fopen(settingDatabaseFile, "w+");

    fprintf(fp, "%s\t%s\t%lf\t%lf\n", Setting.storeName, Setting.storeAddress, Setting.priceToPoint, Setting.pointToPrice);
    fclose(fp);
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