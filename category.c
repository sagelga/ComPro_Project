void categorySwitchHub (){
}

void categoryDatabase(){
    // Check a Database file existance, if it doesn't exist then create the new one.
    if(!isFileExist(categoryDatabaseFile)){
        fopen(categoryDatabaseFile, "w");
    }
}

void categoryFileRead(){
    // Fetch records form a Database file to the program memory
    FILE *fp;                           // File Pointer

    int i = 0;
    fp = fopen(categoryDatabaseFile, "r");

    while(fscanf(fp, "%u\t%[^\n]", &Category[i].id, Category[i].name) != EOF){
        i++;
    }

    RecordCount.category = i;          // Save a number of records to the Record Counter
    fclose(fp);

    // For debugging
    // i--;
    // printf(">>>> %u\t%s\n", Category[i].id, Category[i].name);
}

void categoryFileWrite(){
    // Save all of the records to a database file
    FILE *fp;                   // File Pointer
    int numberOfRecords;        // Number of the records in a table

    numberOfRecords = RecordCount.category;
    fp = fopen(categoryDatabaseFile, "w+");

    for(int i = 0; i < numberOfRecords; i++)
        fprintf(fp, "%u\t%s\n", Category[i].id, Category[i].name);

    fclose(fp);
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