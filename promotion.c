void promotionSwitchHub () {
}

void promotionDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(promotionDatabaseFile)){
        fopen(promotionDatabaseFile, "w");
    }
}

void promotionFileRead(){
    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer

    int i = 0;
    fp = fopen(promotionDatabaseFile, "r");

    while(fscanf(fp, "%s\t%lf\t%d", Promotion[i].id, &Promotion[i].price, &Promotion[i].status) != EOF){
        i++;
    }

    RecordCount.promotion = i;          // Save a number of records to the Record Counter
    fclose(fp);

    // For debugging
    // i--;
    // printf(">>>> %s\t%lf\t%d\n", Promotion[i].id, Promotion[i].price, Promotion[i].status);
}

void promotionFileWrite(){
    // Save all of the records to a database file
    FILE *fp;                   // File Pointer
    int numberOfRecords;        // Number of the records in a table

    numberOfRecords = RecordCount.promotion;
    fp = fopen(promotionDatabaseFile, "w+");

    for(int i = 0; i < numberOfRecords; i++)
        fprintf(fp, "%s\t%lf\t%d\n", Promotion[i].id, Promotion[i].price, Promotion[i].status);

    fclose(fp);
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