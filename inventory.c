void inventorySwitchHub () {

    bannerBlankBorderTextCen ("What are you going to do?");
    bannerBlankBorder ();
    bannerBlankBorderText("Inventory");
    bannerFullBorderSection ();
    bannerBlankBorderTextCen ("1. Check the database");
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("2. Add inventory data to the database");
    bannerBlankBorderTextCen ("3. Edit inventory data from the database");
    bannerBlankBorderTextCen ("4. Removing inventory from the database");

    for (int i = 0;i<2;i++)
        bannerFullBorder ();

    bannerBlankBorderText ("Category");
    bannerFullBorderSection ();
    bannerBlankBorderTextCen ("5. Check the category database");
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("6. Add new category to the database");
    bannerBlankBorderTextCen ("7. Edit category from the database");
    bannerBlankBorderTextCen ("8. Remove category from the database");

    for ( int i = 0; i < 25; i++ ) {
        bannerBlankBorder ();
    }
    bannerBlankBorderTextCen ("or type 'N' to return back to the hub");
    bannerFullBorder ();
    bannerUserInput ();

    char userInput;
    scanf (" %c", &userInput);

    switch ( userInput ) {
        case ('1'):
            inventoryDatabaseInterface ();
            return;
        case ('2'):
            inventoryAddInterface ();
            return;
        case ('3'):
            return;
        case ('4'):
            inventoryModifyInterface ();
            return;
        case ('5'):
            return;
        case ('6'):
            inventoryRemoveInterface ();
            return;
        default:
            printf ("Your input is invalid. Please try again...");
            inventorySwitchHub ();
            return;
    }
}

void inventoryDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(inventoryDatabaseFile)){
        fopen(inventoryDatabaseFile, "w");
    }
}

void inventoryFileRead(){
    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer

    int i = 0;
    fp = fopen(inventoryDatabaseFile, "r");

    while(fscanf(fp, "%s\t%[^\t]\t%lf\t%lf\t%u\t%u", Inventory[i].id, Inventory[i].name, &Inventory[i].price, &Inventory[i].profit, &Inventory[i].categoryId, &Inventory[i].remain) != EOF){
        i++;
    }

    RecordCount.inventory = i;          // Save a number of records to the Record Counter
    fclose(fp);

    // For debuging
    // i--;
    // printf(">>>> %s\t%s\t%lf\t%lf\t%u\t%u\n", Inventory[i].id, Inventory[i].name, Inventory[i].price, Inventory[i].profit, Inventory[i].categoryId, Inventory[i].remain);
}

void inventoryFileWrite(){
    // Save all of the records to a database file
    FILE *fp;                   // File Pointer
    int numberOfRecords;        // Number of the records in a table

    numberOfRecords = RecordCount.inventory;
    fp = fopen(inventoryDatabaseFile, "w+");

    for(int i = 0; i < numberOfRecords; i++)
        fprintf(fp, "%s\t%s\t%lf\t%lf\t%u\t%u\n", Inventory[i].id, Inventory[i].name, Inventory[i].price, Inventory[i].profit, Inventory[i].categoryId, Inventory[i].remain);

    fclose(fp);
}

void inventoryDatabaseInterface(){

    numberOfRecords = RecordCount.personnel;
    fp = fopen(personnelDatabaseFile, "w+");

    for(int i = 0; i < numberOfRecords; i++)
        fprintf(fp, "%s\t%s\t%s\t%d\t%s\t%s\t%s\n", Personnel[i].id, Personnel[i].firstname, Personnel[i].lastname, Personnel[i].role, Personnel[i].username, Personnel[i].password, Personnel[i].barcodeToken);

    fclose(fp);
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

void inventoryAddInterface () {
    bannerBlankBorderTextCen ("Inventory in mode 'ADD'");
}

void inventoryModifyInterface () {
}

void inventoryRemoveInterface () {
}