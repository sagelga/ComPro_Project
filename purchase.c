// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void purchaseDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(purchaseDatabaseFile)){
        fopen(purchaseDatabaseFile, "w");
    }
}

void purchaseFileRead(){

    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer

    int i = 0;
    fp = fopen(purchaseDatabaseFile, "r");

    while(fscanf(fp, "%u\t%lf\t%s\t%s\t%lu", &Purchase[i].id, &Purchase[i].totalPrice, Purchase[i].customerId, Purchase[i].personnelId, &Purchase[i].timestamp) != EOF){
        i++;
    }

    RecordCount.purchase = i;          // Save a number of records to the Record Counter
    fclose(fp);

    // For debugging
    // i--;
    // printf(">>>> %u\t%lf\t%s\t%s\t%lu\n", Purchase[i].id, Purchase[i].totalPrice, Purchase[i].customerId, Purchase[i].personnelId, Purchase[i].timestamp);
}

void purchaseFileWrite(){
    // Save all of the records to a database file
    FILE *fp;                   // File Pointer
    int numberOfRecords;        // Number of the records in a table

    numberOfRecords = RecordCount.purchase;
    fp = fopen(purchaseDatabaseFile, "w+");

    for(int i = 0; i < numberOfRecords; i++)
        fprintf(fp, "%u\t%lf\t%s\t%s\t%lu\n", Purchase[i].id, Purchase[i].totalPrice, Purchase[i].customerId, Purchase[i].personnelId, Purchase[i].timestamp);

    fclose(fp);
}

int purchaseSelectById(unsigned int id, double *totalPrice, char *customerId, char *personnelId, time_t *timestamp){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.purchase;
    for(int i = 0; i < numberOfRecords; i++){
        if(Purchase[i].id == id){
            // Return all values back by reference
            *totalPrice = Purchase[i].totalPrice;
            strcpy(customerId, Purchase[i].customerId);
            strcpy(personnelId, Purchase[i].personnelId);
            *timestamp = Purchase[i].timestamp;

            return 1;   // Found a record
        }
    }
    return 0;           // Not found the given `id` in the records
}

void purchaseInsert(double totalPrice, char *customerId, char *personnelId){
    int tailIndex = RecordCount.purchase;

    Purchase[tailIndex].id = tailIndex;    // Auto-increment
    Purchase[tailIndex].totalPrice = totalPrice;
    strcpy(Purchase[tailIndex].customerId, customerId);
    strcpy(Purchase[tailIndex].personnelId, personnelId);
    Purchase[tailIndex].timestamp = time(NULL);     // Current time as time_t (Epoch format)

    RecordCount.purchase++;    // Update the amount of records

    purchaseFileWrite();       // Save to a Database file
}

void purchaseSwitchHub () {
}
