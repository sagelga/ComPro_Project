// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void inventorySwitchHub () {

    bannerFullBorder();
    bannerBlankBorderTextCen ("What are you going to do?");
    bannerBlankBorder ();
    bannerBlankBorderTextCen("Inventory");
    bannerFullBorderSection ();
    bannerBlankBorderTextCen ("1. Check the database");
    bannerBlankBorderTextCen ("2. Add inventory data to the database");
    bannerBlankBorderTextCen ("3. Edit inventory data from the database");
    bannerBlankBorderTextCen ("4. Removing inventory from the database");

    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Category");
    bannerFullBorderSection ();
    bannerBlankBorderTextCen ("5. Check the category database");
    bannerBlankBorderTextCen ("6. Add new category to the database");
    bannerBlankBorderTextCen ("7. Edit category from the database");

    for ( int i = 0; i < 23; i++ ) {
        bannerBlankBorder ();
    }
    bannerBlankBorderTextCen ("or type 'B' to return back to the hub");
    bannerFullBorder ();
    bannerUserInput ();

    char userInput;
    scanf (" %c", &userInput);

    switch ( toupper(userInput) ) {
        case ('1'):
            inventoryDatabaseInterface ();
            break;
        case ('2'):
            inventoryAdd();
            break;
        case ('3'):
            //inventoryEdit();
            break;
        case ('4'):
            inventoryRemove();
            break;
        case ('5'):
            categoryDatabaseInterface();
            break;
        case ('6'):
            categoryAdd();
            break;
        case ('7'):
            //categoryEdit();
            break;
        case ('B'):
            switchHub();
            break;
        default:
            printf ("Your input is invalid. Please try again...");
            inventorySwitchHub ();
    }
}

void inventoryAddInterface () {
}

void inventoryModifyInterface () {
}

void inventoryRemoveInterface () {
}

int inventorySelectById(char *id, char *name, double *price, double *profit, unsigned int *categoryId, unsigned int *remain){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.inventory;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Inventory[i].id, id) == 0){
            // Return all values back by reference
            strcpy(name, Inventory[i].name);
            *price = Inventory[i].price;
            *profit = Inventory[i].profit;
            *categoryId = Inventory[i].categoryId;
            *remain = Inventory[i].remain;

            return 1;   // Found a record
        }
    }
    return 0;           // Not found the given `id` in the records
}


int inventoryInsert(char *id, char *name, double price, double profit, unsigned int categoryId, unsigned int remain){
    int tailIndex = RecordCount.inventory;

    // To comfirm that `id` is unique
    for(int i = 0; i < tailIndex; i++){
        if(strcmp(Inventory[i].id, id) == 0)
            return 0;   // Error: Barcode ID already exists
    }

    strcpy(Inventory[tailIndex].id, id);
    strcpy(Inventory[tailIndex].name, name);
    Inventory[tailIndex].price = price;
    Inventory[tailIndex].profit = profit;
    Inventory[tailIndex].categoryId = categoryId;
    Inventory[tailIndex].remain = remain;

    RecordCount.inventory++;    // Update the amount of records

    inventoryFileWrite();       // Save to a Database file
    return 1;                   // Operation Success
}

int inventoryUpdateName(char *id, char *name){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.inventory;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Inventory[i].id, id) == 0){
            strcpy(Inventory[i].name, name);
            inventoryFileWrite();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int inventoryUpdatePrice(char *id, double price){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.inventory;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Inventory[i].id, id) == 0){
            Inventory[i].price = price;
            inventoryFileWrite();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int inventoryUpdateProfit(char *id, double profit){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.inventory;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Inventory[i].id, id) == 0){
            Inventory[i].profit = profit;
            inventoryFileWrite();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int inventoryUpdateCategory(char *id, unsigned int categoryId){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.inventory;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Inventory[i].id, id) == 0){
            Inventory[i].categoryId = categoryId;
            inventoryFileWrite();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int inventoryUpdateRemain(char *id, unsigned int remain){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.inventory;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Inventory[i].id, id) == 0){
            Inventory[i].remain = remain;
            inventoryFileWrite();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int inventoryDelete(char *id){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.inventory;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Inventory[i].id, id) == 0){
            while(i < numberOfRecords - 1){
                Inventory[i] = Inventory[i+1];
                i++;
            }
            RecordCount.inventory--;    // Update the amount of records
            inventoryFileWrite();   // Save to a Database file
            return 1;               // Record successfully deleted
        }
    }
    return 0;   // Not found the given `id` in the records
}

void displayInventory(int page){
    screenClear ();
    int allPage = (int)ceil(RecordCount.inventory/34)+1;
    bannerFullBorder();
    printf(":: ID             | Name                                               | Price      | Profit     | Category                  | In Stock   ::\n");
    bannerFullBorder();

    if (page == allPage)
    {
        for (int i = (page-1)*34; i < RecordCount.inventory; ++i)
        {
            printf(":: %-14s | %-50s | %10.2lf | %10.2lf | %-25s | %10u ::\n", Inventory[i].id, Inventory[i].name, Inventory[i].price, Inventory[i].profit, Category[Inventory[i].categoryId].name, Inventory[i].remain);
            //bannerBlankBorder();
        }
        //display remaining line as bannerBlankBorder()
        for (int i = 0; i < 34-(RecordCount.inventory%34); ++i)
        {
            printf("::                |                                                    |            |            |                           |            ::\n");
        }
    }
    else
    {
        for (int i = (page-1)*34; i < page*34/*(34*page)*/; ++i)
        {
            printf(":: %-14s | %-50s | %10.2lf | %10.2lf | %-25s | %10u ::\n", Inventory[i].id, Inventory[i].name, Inventory[i].price, Inventory[i].profit, Category[Inventory[i].categoryId].name, Inventory[i].remain);
            //bannerBlankBorder();
        }
    }

    bannerBlankBorderTextCen("Enter Page/Enter 'B' to back to Inventory Menu");
    printf("::                                                       <<  <  ( Page %d of %d ) > >>                                                      ::\n", page, allPage);
    bannerFullBorder();

}

void inventoryDatabaseInterface(){
    char handling;
    int pageIn = 1, CheckPage;
    displayInventory(1);
    for (int i = 0; i >= 0; ++i)
    {
        scanf(" %c", &handling);
        if ((handling == 'B') || (handling == 'b'))
        {
            screenClear ();
            inventorySwitchHub ();
        }
        else if (isdigit(handling))
        {
            CheckPage = (int)handling - 48;
            if ((CheckPage <= ((int)ceil(RecordCount.inventory/34)+1)) && (CheckPage >= 1))
            {
                pageIn = (int)handling - 48;
                displayInventory(pageIn);
            }
            else
            {
                displayInventory(pageIn);
                printf("Oops! Page not found, Please enter correct page: ");
            }
        }
        else
        {
            displayInventory(pageIn);
            printf("Oops! Input Error, Please enter correctly: ");
        }
    }
}

void inventoryAdd(){
    screenClear();

    char idIN[MAX_LNG_ID];
    char nameIN[MAX_LNG_SCREEN];
    double priceIN;
    double profitIN;
    unsigned int categoryIdIN;
    unsigned int remainIN;

    char handling;

    bannerFullBorder();
    bannerBlankBorderTextCen("Insert Inventory");
    bannerFullBorder();
    for (int i = 0; i < 36; ++i)
    {
        bannerBlankBorder();
    }
    bannerFullBorder();
    //Input
    printf("Enter the inventory ID: ");
    scanf("%s", idIN);
    printf("Enter the inventory name: ");
    scanf(" %[^\n]", nameIN);
    printf("Enter Price: ");
    scanf(" %lf", &priceIN);
    printf("Enter Profit: ");
    scanf(" %lf", &profitIN);
    printf("Enter Category ID: ");
    scanf(" %u", &categoryIdIN);
    printf("Enter number of this inventory: ");
    scanf(" %u", &remainIN);
    if (inventoryInsert(idIN, nameIN, priceIN, profitIN, categoryIdIN, remainIN))
    {
        screenClear();
        bannerFullBorder();
        bannerBlankBorderTextCen("Insert Inventory");
        bannerFullBorder();
        for (int i = 0; i < 16; ++i)
        {
            bannerBlankBorder();
        }
        bannerBlankBorderTextCen("Success!!! The inventory has been inserted.");
        bannerBlankBorderTextCen("<-- Enter A/b to add more inventory -->");
        bannerBlankBorderTextCen("<-- Enter B/b to back to Inventory&Category Menu -->");
        for (int i = 0; i < 17; ++i)
        {
            bannerBlankBorder();
        }
        bannerFullBorder();

        scanf(" %c", &handling);
        if ((handling == 'A') || (handling == 'a'))
        {
            inventoryAdd();
        }
        else if ((handling == 'B') || (handling == 'b'))
        {
            screenClear();
            inventorySwitchHub();
        }
        else
        {
            screenClear();
            bannerFullBorder();
            for (int i = 0; i < 17; ++i)
            {
                bannerBlankBorder();
            }
            bannerBlankBorderTextCen("Input Error!!!");
            bannerBlankBorderTextCen("|| Enter A/b to add more inventory ||");
            bannerBlankBorderTextCen("|| Enter B/b to back to Inventory&Category Menu ||");
            for (int i = 0; i < 18; ++i)
            {
                bannerBlankBorder();
            }
            bannerFullBorder();
            for (int i = 0; i >= 0; ++i)
            {
                scanf(" %c", &handling);
                if ((handling == 'b') || (handling == 'B'))
                {
                    screenClear();
                    inventorySwitchHub();
                }
                else if ((handling == 'A') || (handling == 'a'))
                {
                    inventoryAdd();
                }
                else
                {
                    screenClear();
                    bannerFullBorder();
                    for (int i = 0; i < 17; ++i)
                    {
                        bannerBlankBorder();
                    }
                    bannerBlankBorderTextCen("Input Error!!!");
                    bannerBlankBorderTextCen("|| Enter A/b to add more inventory ||");
                    bannerBlankBorderTextCen("|| Enter B/b to back to Inventory&Category Menu ||");
                    for (int i = 0; i < 18; ++i)
                    {
                        bannerBlankBorder();
                    }
                    bannerFullBorder();
                }
            }
        }
    }
    else
    {
        screenClear();
        bannerFullBorder();
        for (int i = 0; i < 18; ++i)
        {
            bannerBlankBorder();
        }
        bannerBlankBorderTextCen("Error!!! Barcode ID already exists.");
        bannerBlankBorderTextCen("Please enter B/b to back to Insert Inventory");
        for (int i = 0; i < 18; ++i)
        {
            bannerBlankBorder();
        }
        bannerFullBorder();
        scanf(" %c", &handling);
        if ((handling == 'b') || (handling == 'B'))
        {
            inventoryAdd();
        }
        else
        {
            screenClear();
            bannerFullBorder();
            for (int i = 0; i < 18; ++i)
            {
                bannerBlankBorder();
            }
            bannerBlankBorderTextCen("Input Error!!!");
            bannerBlankBorderTextCen("Please enter B/b to back to Insert Inventory.");
            for (int i = 0; i < 18; ++i)
            {
                bannerBlankBorder();
            }
            bannerFullBorder();
            for (int i = 0; i >= 0; ++i)
            {
                scanf(" %c", &handling);
                if ((handling == 'b') || (handling == 'B'))
                {
                    inventoryAdd();
                }
                else
                {
                    screenClear();
                    bannerFullBorder();
                    for (int i = 0; i < 18; ++i)
                    {
                        bannerBlankBorder();
                    }
                    bannerBlankBorderTextCen("Input Error!!!");
                    bannerBlankBorderTextCen("Please enter B/b to back to Insert Inventory.");
                    for (int i = 0; i < 18; ++i)
                    {
                        bannerBlankBorder();
                    }
                    bannerFullBorder();
                }
            }
        }
    }
}

void inventoryRemove(){
    screenClear();

    char idIN[MAX_LNG_ID];

    char handling;

    bannerFullBorder();
    bannerBlankBorderTextCen("Removing Inventory");
    bannerFullBorder();
    for (int i = 0; i < 36; ++i)
    {
        bannerBlankBorder();
    }
    bannerFullBorder();

    //Input
    printf("Enter the inventory ID to delete: ");
    scanf("%s", idIN);
    //Process
    if (inventoryDelete(idIN))
    {
        screenClear();
        bannerFullBorder();
        bannerBlankBorderTextCen("Removing Inventory");
        bannerFullBorder();
        for (int i = 0; i < 16; ++i)
        {
            bannerBlankBorder();
        }
        bannerBlankBorderTextCen("Success!!! The inventory has been deleted.");
        bannerBlankBorderTextCen("<-- Enter D/d to delete more inventory -->");
        bannerBlankBorderTextCen("<-- Enter B/b to back to Inventory&Category Menu -->");
        for (int i = 0; i < 17; ++i)
        {
            bannerBlankBorder();
        }
        bannerFullBorder();

        scanf(" %c", &handling);
        if ((handling == 'D') || (handling == 'd'))
        {
            inventoryRemove();
        }
        else if ((handling == 'B') || (handling == 'b'))
        {
            screenClear();
            inventorySwitchHub();
        }
        else
        {
            screenClear();
            bannerFullBorder();
            for (int i = 0; i < 17; ++i)
            {
                bannerBlankBorder();
            }
            bannerBlankBorderTextCen("Input Error!!!");
            bannerBlankBorderTextCen("|| Enter D/d to delete more inventory ||");
            bannerBlankBorderTextCen("|| Enter B/b to back to Inventory&Category Menu ||");
            for (int i = 0; i < 18; ++i)
            {
                bannerBlankBorder();
            }
            bannerFullBorder();
            for (int i = 0; i >= 0; ++i)
            {
                scanf(" %c", &handling);
                if ((handling == 'b') || (handling == 'B'))
                {
                    screenClear();
                    inventorySwitchHub();
                }
                else if ((handling == 'D') || (handling == 'd'))
                {
                    inventoryRemove();
                }
                else
                {
                    screenClear();
                    bannerFullBorder();
                    for (int i = 0; i < 17; ++i)
                    {
                        bannerBlankBorder();
                    }
                    bannerBlankBorderTextCen("Input Error!!!");
                    bannerBlankBorderTextCen("|| Enter D/d to deletd more inventory ||");
                    bannerBlankBorderTextCen("|| Enter B/b to back to Inventory&Category Menu ||");
                    for (int i = 0; i < 18; ++i)
                    {
                        bannerBlankBorder();
                    }
                    bannerFullBorder();
                }
            }
        }
    }
    else
    {
        screenClear();
        bannerFullBorder();
        for (int i = 0; i < 18; ++i)
        {
            bannerBlankBorder();
        }
        bannerBlankBorderTextCen("Error!!! The inventory ID doesn't exists.");
        bannerBlankBorderTextCen("Please enter B/b to back to Removing Inventory");
        for (int i = 0; i < 18; ++i)
        {
            bannerBlankBorder();
        }
        bannerFullBorder();
        scanf(" %c", &handling);
        if ((handling == 'b') || (handling == 'B'))
        {
            inventoryRemove();
        }
        else
        {
            screenClear();
            bannerFullBorder();
            for (int i = 0; i < 18; ++i)
            {
                bannerBlankBorder();
            }
            bannerBlankBorderTextCen("Input Error!!!");
            bannerBlankBorderTextCen("Please enter B/b to back to Removing Inventory.");
            for (int i = 0; i < 18; ++i)
            {
                bannerBlankBorder();
            }
            bannerFullBorder();
            for (int i = 0; i >= 0; ++i)
            {
                scanf(" %c", &handling);
                if ((handling == 'b') || (handling == 'B'))
                {
                    inventoryRemove();
                }
                else
                {
                    screenClear();
                    bannerFullBorder();
                    for (int i = 0; i < 18; ++i)
                    {
                        bannerBlankBorder();
                    }
                    bannerBlankBorderTextCen("Input Error!!!");
                    bannerBlankBorderTextCen("Please enter B/b to back to Removint Inventory.");
                    for (int i = 0; i < 18; ++i)
                    {
                        bannerBlankBorder();
                    }
                    bannerFullBorder();
                }
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