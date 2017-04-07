// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void promotionSwitchHub () {
}

int promotionSelectById(char *id, double *price, int *status){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.promotion;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Promotion[i].id, id) == 0){
            // Return all values back by reference
            *price = Promotion[i].price;
            *status = Promotion[i].status;

            return 1;   // Found a record
        }
    }
    return 0;           // Not found the given `id` in the records
}

int promotionInsert(char *id, double price){
    int tailIndex = RecordCount.promotion;

    // To comfirm that `id` is unique
    for(int i = 0; i < tailIndex; i++){
        if(strcmp(Promotion[i].id, id) == 0)
            return 0;   // Error: Barcode ID already exists
    }

    strcpy(Promotion[tailIndex].id, id);
    Promotion[tailIndex].price = price;
    Promotion[tailIndex].status = 1;        // Initail Value (1 = Active)

    RecordCount.promotion++;                // Update the amount of records

    promotionFileWrite();                   // Save to a Database file
    return 1;                   // Operation Success
}

int promotionUpdatePrice(char *id, double price){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.promotion;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Promotion[i].id, id) == 0){
            Promotion[i].price = price;
            promotionFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int promotionUpdateStatus(char *id, int status){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.promotion;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Promotion[i].id, id) == 0){
            Promotion[i].status = status;
            promotionFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int promotionDelete(char *id){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.promotion;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Promotion[i].id, id) == 0){
            while(i < numberOfRecords - 1){
                Promotion[i] = Promotion[i+1];
                i++;
            }
            RecordCount.promotion--;    // Update the amount of records
            promotionFileWrite();       // Save to a Database file
            return 1;                  // Record successfully deleted
        }
    }
    return 0;   // Not found the given `id` in the records
}
