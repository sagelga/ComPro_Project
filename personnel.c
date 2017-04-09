// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

int personnelSelectById (char *id, char *firstname, char *lastname, int *role, char *username, char *password,
                         char *barcodeToken) {
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for ( int i = 0; i < numberOfRecords; i++ ) {
        if ( strcmp (Personnel[i].id, id) == 0 ) {
            // Return all values back by reference
            strcpy (firstname, Personnel[i].firstname);
            strcpy (lastname, Personnel[i].lastname);
            *role = Personnel[i].role;
            strcpy (username, Personnel[i].username);
            strcpy (password, Personnel[i].password);
            strcpy (barcodeToken, Personnel[i].barcodeToken);
            return 1;   // Found a record
        }
    }
    return 0;           // Not found the given `id` in the records
}

int personnelInsert (char *id, char *firstname, char *lastname, int role, char *username, char *password,
                     char *barcodeToken) {
    int tailIndex = RecordCount.personnel;

    // To comfirm that `id`, `username` and `barcodeToken` is unique
    for ( int i = 0; i < tailIndex; i++ ) {
        if ( strcmp (Personnel[i].id, id) == 0 || strcmp (Personnel[i].username, username) == 0 ||
             strcmp (Personnel[i].barcodeToken, barcodeToken) == 0 )
            return 0;   // Error: Some field already exists
    }

    strcpy (Personnel[tailIndex].id, id);
    strcpy (Personnel[tailIndex].firstname, firstname);
    strcpy (Personnel[tailIndex].lastname, lastname);
    Personnel[tailIndex].role = role;
    strcpy (Personnel[tailIndex].username, username);
    strcpy (Personnel[tailIndex].password, password);
    strcpy (Personnel[tailIndex].barcodeToken, barcodeToken);

    RecordCount.personnel++;    // Update the amount of records

    personnelFileWrite ();       // Save to a Database file
    return 1;   // Operation Success
}

int personnelUpdateFirstname (char *id, char *firstname) {
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for ( int i = 0; i < numberOfRecords; i++ ) {
        if ( strcmp (Personnel[i].id, id) == 0 ) {
            strcpy (Personnel[i].firstname, firstname);
            personnelFileWrite ();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int personnelUpdateLastname (char *id, char *lastname) {
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for ( int i = 0; i < numberOfRecords; i++ ) {
        if ( strcmp (Personnel[i].id, id) == 0 ) {
            strcpy (Personnel[i].lastname, lastname);
            personnelFileWrite ();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int personnelUpdateRole (char *id, int role) {
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for ( int i = 0; i < numberOfRecords; i++ ) {
        if ( strcmp (Personnel[i].id, id) == 0 ) {
            Personnel[i].role = role;
            personnelFileWrite ();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int personnelUpdatePassword (char *id, char *password) {
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for ( int i = 0; i < numberOfRecords; i++ ) {
        if ( strcmp (Personnel[i].id, id) == 0 ) {
            strcpy (Personnel[i].password, password);
            personnelFileWrite ();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int personnelDelete (char *id) {
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for ( int i = 0; i < numberOfRecords; i++ ) {
        if ( strcmp (Personnel[i].id, id) == 0 ) {
            while ( i < numberOfRecords - 1 ) {
                Personnel[i] = Personnel[i + 1];
                i++;
            }
            RecordCount.personnel--;    // Update the amount of records
            personnelFileWrite ();   // Save to a Database file
            return 1;               // Record successfully deleted
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