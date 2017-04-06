// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void customerSwitchHub () {
}

void customerDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(customerDatabaseFile)){
        fopen(customerDatabaseFile, "w");
    }
}

void customerFileRead(){
    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer

    int i = 0;
    fp = fopen(customerDatabaseFile, "r");

    while(fscanf(fp, "%s\t%[^\t]\t%[^\t]\t%c\t%lf\t%lf", Customer[i].id, Customer[i].firstname, Customer[i].lastname, &Customer[i].gender, &Customer[i].point, &Customer[i].totalBuy) != EOF){
        i++;
    }

    RecordCount.customer = i;          // Save a number of records to the Record Counter
    fclose(fp);

    // For debugging
    // i--;
    // printf(">>>> %s\t%s\t%s\t%c\t%lf\t%lf\n", Customer[i].id, Customer[i].firstname, Customer[i].lastname, Customer[i].gender, Customer[i].point, Customer[i].totalBuy);
}

void customerFileWrite(){
    // Save all of the records to a database file
    FILE *fp;                   // File Pointer
    int numberOfRecords;        // Number of the records in a table

    numberOfRecords = RecordCount.customer;
    fp = fopen(customerDatabaseFile, "w+");

    for(int i = 0; i < numberOfRecords; i++)
        fprintf(fp, "%s\t%s\t%s\t%c\t%lf\t%lf\n", Customer[i].id, Customer[i].firstname, Customer[i].lastname, Customer[i].gender, Customer[i].point, Customer[i].totalBuy);

    fclose(fp);
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

    // To confirm that `id` is unique
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

