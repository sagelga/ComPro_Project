// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void purchaseSwitchHub () {
}

int purchaseSelectById(unsigned int id, double *totalPrice, double *totalDiscount, char *customerId, char *personnelId, time_t *timestamp){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.purchase;
    for(int i = 0; i < numberOfRecords; i++){
        if(Purchase[i].id == id){
            // Return all values back by reference
            *totalPrice = Purchase[i].totalPrice;
            *totalDiscount = Purchase[i].totalDiscount;
            strcpy(customerId, Purchase[i].customerId);
            strcpy(personnelId, Purchase[i].personnelId);
            *timestamp = Purchase[i].timestamp;

            return 1;   // Found a record
        }
    }
    return 0;           // Not found the given `id` in the records
}

void purchaseInsert(double totalPrice, double totalDiscount, char *customerId, char *personnelId){
    int tailIndex = RecordCount.purchase;

    Purchase[tailIndex].id = tailIndex;    // Auto-increment
    Purchase[tailIndex].totalPrice = totalPrice;
    Purchase[tailIndex].totalDiscount = totalDiscount;
    strcpy(Purchase[tailIndex].customerId, customerId);
    strcpy(Purchase[tailIndex].personnelId, personnelId);
    Purchase[tailIndex].timestamp = time(NULL);     // Current time as time_t (Epoch format)

    RecordCount.purchase++;    // Update the amount of records

    purchaseFileWrite();       // Save to a Database file
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