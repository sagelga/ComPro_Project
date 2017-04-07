// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void customerSwitchHub () {
}

int customerSelectById(char *id, char *firstname, char *lastname, char *gender, double *point, double *totalBuy){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            // Return all values back by reference
            strcpy(firstname, Customer[i].firstname);
            strcpy(lastname, Customer[i].lastname);
            *gender = Customer[i].gender;
            *point = Customer[i].point;
            *totalBuy = Customer[i].totalBuy;

            return 1;   // Found a record
        }
    }
    return 0;           // Not found the given `id` in the records
}

int customerInsert(char *id, char *firstname, char *lastname, char gender){
    int tailIndex = RecordCount.customer;

    // To comfirm that `id` is unique
    for(int i = 0; i < tailIndex; i++){
        if(strcmp(Customer[i].id, id) == 0)
            return 0;   // Error: Customer ID already exists
    }

    strcpy(Customer[tailIndex].id, id);
    strcpy(Customer[tailIndex].firstname, firstname);
    strcpy(Customer[tailIndex].lastname, lastname);
    Customer[tailIndex].gender = gender;
    Customer[tailIndex].point = 0;          // Initail value
    Customer[tailIndex].totalBuy = 0;       // Initail value

    RecordCount.customer++;    // Update the amount of records

    customerFileWrite();       // Save to a Database file
    return 1;                  // Operation Success
}

int customerUpdateFirstname(char *id, char *firstname){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            strcpy(Customer[i].firstname, firstname);
            customerFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int customerUpdateLastname(char *id, char *lastname){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            strcpy(Customer[i].lastname, lastname);
            customerFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int customerUpdateGender(char *id, char gender){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            Customer[i].gender = gender;
            customerFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int customerUpdatePoint(char *id, double point){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            Customer[i].point = point;
            customerFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int customerUpdatetotalBuy(char *id, double totalBuy){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            Customer[i].totalBuy = totalBuy;
            customerFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int customerDelete(char *id){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            while(i < numberOfRecords - 1){
                Customer[i] = Customer[i+1];
                i++;
            }
            RecordCount.customer--;    // Update the amount of records
            customerFileWrite();       // Save to a Database file
            return 1;                  // Record successfully deleted
        }
    }
    return 0;   // Not found the given `id` in the records
}