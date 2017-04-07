// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void categorySwitchHub (){
}

int categorySelectById(unsigned int id, char *name){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.category;
    for(int i = 0; i < numberOfRecords; i++){
        if(Category[i].id == id){
            // Return all values back by reference
            strcpy(name, Category[i].name);

            return 1;   // Found a record
        }
    }
    return 0;           // Not found the given `id` in the records
}

int categoryInsert(char *name){
    int tailIndex = RecordCount.category;

    // To comfirm that `name` is unique
    for(int i = 0; i < tailIndex; i++){
        if(strcmp(Inventory[i].name, name) == 0)
            return 0;   // Error: Category name already exists
    }

    Category[tailIndex].id = tailIndex; // Auto-increment 
    strcpy(Category[tailIndex].name, name);

    RecordCount.category++;    // Update the amount of records

    categoryFileWrite();       // Save to a Database file
    return 1;                  // Operation Success
}

int categoryUpdateName(unsigned int id, char *name){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.category;
    for(int i = 0; i < numberOfRecords; i++){
        if(Category[i].id == id){
            strcpy(Category[i].name, name);
            categoryFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int categoryDelete(unsigned int id){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.category;
    for(int i = 0; i < numberOfRecords; i++){
        if(Category[i].id == id){
            while(i < numberOfRecords - 1){
                Category[i] = Category[i+1];
                i++;
            }
            RecordCount.category--;    // Update the amount of records
            categoryFileWrite();       // Save to a Database file
            return 1;                  // Record successfully deleted
        }
    }
    return 0;   // Not found the given `id` in the records
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