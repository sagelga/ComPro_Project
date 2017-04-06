// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void settingDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(settingDatabaseFile)){
        fopen(settingDatabaseFile, "w");
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

/*
void settingUpdatePriceToPoint(double priceToPoint){
    Setting.priceToPoint = priceToPoint;
    settingFileWrite();    // Save to a Database file
}

void settingUpdatePointToPrice(double pointToPrice){
    Setting.pointToPrice = pointToPrice;
    settingFileWrite();    // Save to a Database file
}
*/

