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

void displayCategory(int page){
    screenClear ();
    int allPage = (int)ceil(RecordCount.category/34)+1;
    bannerFullBorder();
    printf("::          ID           | Category Name                                                                                                  ::\n");
    bannerFullBorder();

    if (page == allPage)
    {
        for (int i = (page-1)*34; i < RecordCount.category; ++i)
        {
            printf("::           %u           | %-110s ::\n", Category[i].id, Category[i].name);
        }
        //display remaining line as bannerBlankBorder()
        for (int i = 0; i < 34-(RecordCount.category%34); ++i)
        {
            printf("::                       |                                                                                                                ::\n");
        }
    }
    else
    {
        for (int i = (page-1)*34; i < page*34/*(34*page)*/; ++i)
        {
            printf(":: %u | %s ::\n", Category[i].id, Category[i].name);
        }
    }

    bannerBlankBorderTextCen("Enter Page/Enter 'B' to back to Inventory Menu");
    printf("::                                                       <<  <  ( Page %d of %d ) > >>                                                      ::\n", page, allPage);
    bannerFullBorder();

}

void categoryDatabaseInterface(){
    char handling;
    int pageIn;
    displayCategory(1);
    for (int i = 0; i >= 0; ++i)
    {
        scanf(" %c", &handling);
        if ((handling == 'B') || (handling == 'b'))
        {
            screenClear ();
            inventorySwitchHub ();
        }
        else
        {
            pageIn = (int)handling - 48;
            displayCategory(pageIn);
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