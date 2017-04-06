// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void personnelDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(personnelDatabaseFile)){
        fopen(personnelDatabaseFile, "w");
    }
}

void personnelFileRead(){
    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer

    int i = 0;
    fp = fopen(personnelDatabaseFile, "r");

    while(fscanf(fp, "%s\t%[^\t]\t%[^\t]\t%d\t%[^\t]\t%[^\t]\t%[^\n]", Personnel[i].id, Personnel[i].firstname, Personnel[i].lastname, &Personnel[i].role, Personnel[i].username, Personnel[i].password, Personnel[i].barcodeToken) != EOF){
        i++;
    }

    RecordCount.personnel = i;          // Save a number of records to the Record Counter
    fclose(fp);

    // For debuging
    // i--;
    // printf(">>>> %s-%s-%s-%d-%s-%s-%s\n", Personnel[i].id, Personnel[i].firstname, Personnel[i].lastname, Personnel[i].role, Personnel[i].username, Personnel[i].password, Personnel[i].barcodeToken);
}

void personnelFileWrite(){
}

int personnelSelectById(char *id, char *firstname, char *lastname, int *role, char *username, char *password, char *barcodeToken){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Personnel[i].id, id) == 0){
            // Return all values back by reference
            strcpy(firstname, Personnel[i].firstname);
            strcpy(lastname, Personnel[i].lastname);
            *role = Personnel[i].role;
            strcpy(username, Personnel[i].username);
            strcpy(password, Personnel[i].password);
            strcpy(barcodeToken, Personnel[i].barcodeToken);
            return 1;   // Found a record
        }
    }
    return 0;           // Not found the given `id` in the records
}

int personnelInsert(char *id, char *firstname, char *lastname, int role, char *username, char *password, char *barcodeToken){
    int tailIndex = RecordCount.personnel;

    // To comfirm that `id`, `username` and `barcodeToken` is unique
    for(int i = 0; i < tailIndex; i++){
        if(strcmp(Personnel[i].id, id) == 0 || strcmp(Personnel[i].username, username) == 0 || strcmp(Personnel[i].barcodeToken, barcodeToken) == 0)
            return 0;   // Error: Some field already exists
    }

    strcpy(Personnel[tailIndex].id, id);
    strcpy(Personnel[tailIndex].firstname, firstname);
    strcpy(Personnel[tailIndex].lastname, lastname);
    Personnel[tailIndex].role = role;
    strcpy(Personnel[tailIndex].username, username);
    strcpy(Personnel[tailIndex].password, password);
    strcpy(Personnel[tailIndex].barcodeToken, barcodeToken);

    RecordCount.personnel++;    // Update the amount of records

    personnelFileWrite();       // Save to a Database file
    return 1;   // Operation Success
}

int personnelUpdateFirstname(char *id, char *firstname){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Personnel[i].id, id) == 0){
            strcpy(Personnel[i].firstname, firstname);
            personnelFileWrite();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int personnelUpdateLastname(char *id, char *lastname){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Personnel[i].id, id) == 0){
            strcpy(Personnel[i].lastname, lastname);
            personnelFileWrite();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int personnelUpdateRole(char *id, int role){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Personnel[i].id, id) == 0){
            Personnel[i].role = role;
            personnelFileWrite();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int personnelUpdatePassword(char *id, char *password){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Personnel[i].id, id) == 0){
            strcpy(Personnel[i].password, password);
            personnelFileWrite();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int personnelDelete(char *id){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Personnel[i].id, id) == 0){
            while(i < numberOfRecords - 1){
                Personnel[i] = Personnel[i+1];
                i++;
            }
            RecordCount.personnel--;    // Update the amount of records
            personnelFileWrite();   // Save to a Database file
            return 1;               // Record successfully deleted
        }
    }
    return 0;   // Not found the given `id` in the records
}

