void transactionDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(transactionDatabaseFile)){
        fopen(transactionDatabaseFile, "w");
    }
}

void transactionFileRead(){

    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer

    int i = 0;
    fp = fopen(transactionDatabaseFile, "r");

    while(fscanf(fp, "%u\t%u\t%s\t%lu", &Transaction[i].id, &Transaction[i].purchaseId, Transaction[i].inventoryId, &Transaction[i].timestamp) != EOF){
        i++;
    }

    RecordCount.transaction = i;          // Save a number of records to the Record Counter
    fclose(fp);

    // For debugging
    // i--;
    // printf(">>>> %u-%u-%s-%lu\n", Transaction[i].id, Transaction[i].purchaseId, Transaction[i].inventoryId, Transaction[i].timestamp);
}

void transactionFileWrite(){
    // Save all of the records to a database file
    FILE *fp;                   // File Pointer
    int numberOfRecords;        // Number of the records in a table

    numberOfRecords = RecordCount.transaction;
    fp = fopen(transactionDatabaseFile, "w+");

    for(int i = 0; i < numberOfRecords; i++)
        fprintf(fp, "%u\t%u\t%s\t%lu\n", Transaction[i].id, Transaction[i].purchaseId, Transaction[i].inventoryId, Transaction[i].timestamp);

    fclose(fp);
}

int transactionSelectById(unsigned int id, unsigned int *purchaseId, char *inventoryId, time_t *timestamp){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.transaction;
    for(int i = 0; i < numberOfRecords; i++){
        if(Transaction[i].id == id){
            // Return all values back by reference
            *purchaseId = Transaction[i].purchaseId;
            strcpy(inventoryId, Transaction[i].inventoryId);
            *timestamp = Transaction[i].timestamp;

            return 1;   // Found a record
        }
    }
    return 0;           // Not found the given `id` in the records
}

void transactionInsert(unsigned int purchaseId, char *inventoryId){
    int tailIndex = RecordCount.transaction;

    Transaction[tailIndex].id = tailIndex;  // Auto-increment 
    Transaction[tailIndex].purchaseId = purchaseId;
    strcpy(Transaction[tailIndex].inventoryId, inventoryId);
    Transaction[tailIndex].timestamp = time(NULL);  // Current time as time_t (Epoch format)

    RecordCount.transaction++;    // Update the amount of records

    transactionFileWrite();       // Save to a Database file
}

void transactionSwitchHub () {
}