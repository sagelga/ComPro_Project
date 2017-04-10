// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"


int categorySelectById (unsigned int id, char *name) {
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.category;
    for ( int i = 0; i < numberOfRecords; i++ ) {
        if ( Category[i].id == id ) {
            // Return all values back by reference
            strcpy (name, Category[i].name);

            return 1;   // Found a record
        }
    }
    return 0;           // Not found the given `id` in the records
}

int categoryInsert (char *name) {
    int tailIndex = RecordCount.category;

    // To comfirm that `name` is unique
    for ( int i = 0; i < tailIndex; i++ ) {
        if ( strcmp (Inventory[i].name, name) == 0 )
            return 0;   // Error: Category name already exists
    }

    Category[tailIndex].id = tailIndex; // Auto-increment 
    strcpy (Category[tailIndex].name, name);

    RecordCount.category++;    // Update the amount of records

    categoryFileWrite ();       // Save to a Database file
    return 1;                  // Operation Success
}

int categoryUpdateName (unsigned int id, char *name) {
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.category;
    for ( int i = 0; i < numberOfRecords; i++ ) {
        if ( Category[i].id == id ) {
            strcpy (Category[i].name, name);
            categoryFileWrite ();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

void displayCategory (int page) {
    screenClear ();
    int allPage = (int) ceil (RecordCount.category / 32) + 1;
    bannerFullBorder ();
    printf ("::          ID           | Category Name                                                                                                  ::\n");
    bannerFullBorder ();

    if ( page == allPage ) {
        for ( int i = (page - 1) * 32; i < RecordCount.category; ++i ) {
            printf ("::           %u           | %-110s ::\n", Category[i].id, Category[i].name);
        }
        //display remaining line as bannerBlankBorder()
        for ( int i = 0; i < 32 - (RecordCount.category % 32); ++i ) {
            printf ("::                       |                                                                                                                ::\n");
        }
    } else {
        for ( int i = (page - 1) * 32; i < page * 32/*(32*page)*/; ++i ) {
            printf (":: %u | %s ::\n", Category[i].id, Category[i].name);
        }
    }

    bannerBlankBorderTextCen ("Enter Page Number | Type 'B' to back");
    printf ("::                                                       <<  <  ( Page %d of %d ) > >>                                                      ::\n",
            page, allPage);
    bannerFullBorder ();
    bannerUserInput ();
}

void categoryDatabaseInterface () {
    char handling;
    int pageIn;
    displayCategory (1);
    for ( int i = 0; i >= 0; ++i ) {
        scanf (" %c", &handling);
        if ((handling == 'B') || (handling == 'b')) {
            screenClear ();
            inventorySwitchHub ();
        } else {
            pageIn = (int) handling - 48;
            displayCategory (pageIn);
        }
    }
}

void categoryAdd () {
    screenClear ();
    char nameIN[MAX_LNG_TEXT];

    char handling;

    bannerFullBorder ();
    bannerBlankBorderTextCen ("Insert Category");
    bannerFullBorder ();
    for ( int i = 0; i < 33; ++i ) {
        bannerBlankBorder ();
    }
    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
    bannerFullBorder ();

    for (int i = 0; i >= 0; ++i)
    {
        printf("\n");
        printf ("Enter the Category name to add >>> ");
        scanf (" %[^\n]", nameIN);
        if ((strcmp(nameIN, "B") == 0) || (strcmp(nameIN, "b") == 0))
        {
            inventorySwitchHub ();
        }
        else if ((strcmp(nameIN, "N") == 0) || (strcmp(nameIN, "n") == 0))
        {
            terminate ();
        }
        else
        {
            if ( categoryInsert (nameIN)) {
                screenClear ();
                bannerFullBorder ();
                bannerBlankBorderTextCen ("Insert Category");
                bannerFullBorder ();
                for ( int i = 0; i < 16; ++i ) {
                    bannerBlankBorder ();
                }
                bannerBlankBorderTextCen ("Successful!!! The category has been inserted.");
                for ( int i = 0; i < 16; ++i ) {
                    bannerBlankBorder ();
                }
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();
            } else {
                screenClear ();
                bannerFullBorder ();
                for ( int i = 0; i < 17; ++i ) {
                    bannerBlankBorder ();
                }
                bannerBlankBorderTextCen ("Error!!! Category name already exists");
                for ( int i = 0; i < 17; ++i ) {
                    bannerBlankBorder ();
                }
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();
            }
        }
    }
}

void categoryEdit(){
    char bufferHead[140];
    sprintf(bufferHead, "%-60s|%s", "ID", "CategoryName");
    screenClear ();
    bannerFullBorder ();
    bannerBlankBorderTextCen ("Category Database");
    bannerFullBorder();
    bannerBlankBorder ();

    bannerBlankBorderTextLeft (bufferHead);
    bannerFullBorderSection ();
    bannerBlankBorder ();
    bannerBlankBorderTextLeft ("->");
    for (int i = 0;i<10;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type CategoryID");

    for (int i = 0;i<18;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
    bannerFullBorder ();
    bannerUserInput ();
    char id[MAX_LNG_TEXT], name[MAX_LNG_TEXT], buffer[MAX_LNG_TEXT], flag[MAX_LNG_TEXT];
    while ( 1 ) {
        scanf ("%s", id);
        if (tolower(id[0]) == 'b') {
            inventorySwitchHub();
        } else if (tolower(id[0]) == 'n') {
            terminate ();
        } else {
            if (categorySelectById(strtoul(id, NULL, 10), name)) {
                screenClear ();
                sprintf(buffer, "%-60s %s", id, name);
                bannerFullBorder();
                bannerBlankBorderTextCen ("Category Database");
                bannerFullBorder();
                bannerBlankBorder ();

                bannerBlankBorderTextLeft (bufferHead);
                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorderTextLeft (buffer);
                bannerBlankBorderTextCen (" ");

                for (int i = 0;i<28;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type another name to change category name... | Press Enter to set by default");
                bannerFullBorder ();
                bannerUserInput ();

                printf("Default CategoryName: (%s) >>> ", name);
                if (superscanf(flag) != 0)
                    categoryUpdateName(strtoul(id, NULL, 10), flag);
                
                screenClear ();
                bannerFullBorder ();
                bannerBlankBorderTextCen ("Category Database");
                bannerFullBorder();
                bannerBlankBorder ();

                bannerBlankBorderTextLeft (bufferHead);
                bannerFullBorderSection ();
                bannerBlankBorder ();
                categorySelectById(strtoul(id, NULL, 10), name);
                sprintf(buffer, "%-60s %s", id, name);
                bannerBlankBorderTextLeft (buffer);
                bannerBlankBorder ();
                bannerBlankBorderTextLeft ("->");
                for (int i=0;i<10;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Category has been updated");
                bannerBlankBorderTextCen ("Type Next CategoryID to Update Or Type 'B' to Back");
            
                for (int i = 0;i<15;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                bannerUserInput ();

            } else {
                screenClear ();
                bannerFullBorder ();
                bannerBlankBorderTextCen ("Category Database");
                bannerFullBorder();
                bannerBlankBorder ();

                bannerBlankBorderTextLeft (bufferHead);
                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorderTextLeft ("->");
                for (int i=0;i<10;i++)
                    bannerBlankBorder ();
                bannerBlankBorder ();
                bannerBlankBorderTextCen ("CategoryID dosen't exist.");
                bannerBlankBorderTextCen ("Type Next CategoryID Or Type 'B' to Back");
            
                for (int i = 0;i<16;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                bannerUserInput ();
            }

        }
    }
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