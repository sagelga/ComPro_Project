// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"
#include "string.h"
#include "ctype.h"

void customerSwitchHub () {
    screenClear ();
    bannerFullBorder();
    bannerBlankBorderTextCen ("Customer Database");
    bannerFullBorder();

    for (int i = 0;i<2;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("What do you want to do?");

    bannerBlankBorder ();

    bannerBlankBorderTextCen ("1. Create new customer ID");
    bannerBlankBorderTextCen ("2. Preview customer database");
    bannerBlankBorderTextCen ("3. Delete customer metadata from the database");
    bannerBlankBorderTextCen ("4. Update existed customer");

    for (int i = 0;i<24;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("ALTERNATE RESPONSE  |  Type 'B' to back");
    bannerFullBorder ();

    bannerUserInput ();
    char flag;
    scanf(" %c", &flag);

    switch(toupper(flags)){

        case ('1'):
            customerInsertInterface();
            break;

        case ('2'):
            customerSelectInterface();
            break;

        case ('3'):
            customerDeleteInterface();
            break;

        case ('4'):
            customerUpdateInterface();
            break;

        case ('B'):
            switchHub ();

        default:
            customerSwitchHub ();
            return;

    }
}

void customerInsertInterface(){
    screenClear ();
    bannerFullBorder();
    bannerBlankBorderTextCen ("Customer Database");
    bannerFullBorder();

    bannerBlankBorderTextCen ("Create new Customer ID");

    bannerFullBorderSection ();
    bannerBlankBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Insert in form");
    bannerBlankBorderTextCen ("Form: ID");
    bannerBlankBorderTextCen ("Firstname");
    bannerBlankBorderTextCen ("Lastname");
    bannerBlankBorderTextCen ("Gender(M/F)");
    bannerBlankBorderTextCen (" ");
    bannerBlankBorderTextCen ("Ex: 1234567891012");
    bannerBlankBorderTextCen ("Prayut");
    bannerBlankBorderTextCen ("Chun-O-Char");
    bannerBlankBorderTextCen ("M");
    bannerBlankBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Insert CustomerID Below");

    for (int i = 0;i<17;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
    bannerFullBorder ();

    bannerUserInput ();
    char id[MAX_LNG_ID], name[MAX_LNG_TEXT], lastname[MAX_LNG_TEXT], gender, buffer[140] ,checker;
    int genderCheck;
    while (1){
        scanf("%s", id);
        if (strcmp(id, "B") == 0 || strcmp(id, "b") == 0 ){
            customerSwitchHub();
            break;
        }
        else if (strcmp(id, "N") == 0 || strcmp(id, "n") == 0 ){
            terminate();
            break;
        }
        else{
            //------------------After Input--------------------
            //---------------------ID--------------------------
            screenClear ();
            sprintf(buffer, "%s", id);
            bannerFullBorder();
            bannerBlankBorderTextCen ("Customer Database");
            bannerFullBorder();
    
            bannerBlankBorderTextCen ("Insert Customer");
            bannerFullBorderSection ();
            bannerBlankBorder ();
            bannerBlankBorder ();
            bannerBlankBorderTextCen ("Customer Firstname ?");
            bannerBlankBorderTextCen (buffer);
    
            for (int i = 0;i<28;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
            bannerFullBorder ();

            bannerUserInput ();
    
            //---------------------FirstName--------------------------
            scanf("%s", name);
            sprintf(buffer, "%s %s", id, name);
            screenClear ();
            bannerFullBorder();
            bannerBlankBorderTextCen ("Customer Database");
            bannerFullBorder();

            bannerBlankBorderTextCen ("Insert Customer");

            bannerFullBorderSection ();
            bannerBlankBorder ();
            bannerBlankBorder ();
            bannerBlankBorderTextCen ("Customer Lastname ?");
            bannerBlankBorderTextCen (buffer);
    
            for (int i = 0;i<28;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
            bannerFullBorder ();
    
            bannerUserInput ();

            //---------------------LastName--------------------------
            scanf("%s", lastname);
            sprintf(buffer, "%s %s %s", id, name, lastname);
            screenClear ();
            bannerFullBorder();
            bannerBlankBorderTextCen ("Customer Database");
            bannerFullBorder();

            bannerBlankBorderTextCen ("Insert Customer");

            bannerFullBorderSection ();
            bannerBlankBorder ();
            bannerBlankBorder ();
            bannerBlankBorderTextCen ("Customer Gender ?");
            bannerBlankBorderTextCen (buffer);
            bannerBlankBorderTextCen ("M = Male || F = Female");
    
            for (int i = 0;i<27;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
            bannerFullBorder ();
    
            bannerUserInput ();

            //---------------------Gender--------------------------
            scanf(" %c", &gender);
            screenClear ();
            bannerFullBorder();
            bannerBlankBorderTextCen ("Customer Database");
            bannerFullBorder();

            bannerBlankBorderTextCen ("Insert Customer");

            bannerFullBorderSection ();
            bannerBlankBorder ();
            bannerBlankBorder ();
            bannerBlankBorderTextCen ("Form");
            if (gender == 'F' || gender == 'f'){
                sprintf(buffer, "%s %s %s Female", id, name, lastname);
            }
            if (gender == 'M' || gender == 'm'){
                sprintf(buffer, "%s %s %s Male", id, name, lastname);
            }
            bannerBlankBorderTextCen (buffer);
            bannerBlankBorder ();
            bannerBlankBorderTextCen ("Are you sure to Insert this customer ?");
            bannerBlankBorderTextCen ("Type 'Y' to Yes || 'N' to No");
    
            for (int i = 0;i<25;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
            bannerFullBorder ();

            bannerUserInput ();
            scanf(" %c", &checker);

            //
            if (checker == 'y' || checker == 'Y'){
                if (customerInsert(id, name, lastname, toupper(gender))){
                    screenClear ();
                    bannerFullBorder();
                    bannerBlankBorderTextCen ("Customer Database");
                    bannerFullBorder();
        
                    bannerBlankBorderTextCen ("Insert Customer");
        
                    bannerFullBorderSection ();
                    bannerBlankBorder ();
                    bannerBlankBorder ();
                    bannerBlankBorderTextCen ("Insert Success");
                    if (gender == 'F' || gender == 'f'){
                        sprintf(buffer, "%s %s %s Female", id, name, lastname);
                    }
                    if (gender == 'M' || gender == 'm'){
                        sprintf(buffer, "%s %s %s Male", id, name, lastname);
                    }
                    bannerBlankBorderTextCen (buffer);
                    bannerBlankBorderTextCen ("_____________________");
                    bannerBlankBorderTextCen ("Insert Next Customer Or Type 'B' to Back");
        
                    for (int i = 0;i<26;i++)
                        bannerBlankBorder ();
                    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                    bannerFullBorder ();

                    bannerUserInput ();
                }
                else{
                    screenClear ();
                    bannerFullBorder();
                    bannerBlankBorderTextCen ("Customer Database");
                    bannerFullBorder();
        
                    bannerBlankBorderTextCen ("Insert Customer");
        
                    bannerFullBorderSection ();
                    bannerBlankBorder ();
                    bannerBlankBorder ();
                    bannerBlankBorderTextCen ("Insert not Successful");
                    bannerBlankBorderTextCen ("Please check your customer ID");
                    bannerBlankBorderTextCen (id);
                    bannerBlankBorderTextCen ("was repeatedly");
                    bannerBlankBorderTextCen ("_____________________");
                    bannerBlankBorderTextCen ("Insert Next Customer Or Type 'B' to Back");
        
                    for (int i = 0;i<24;i++)
                        bannerBlankBorder ();
                    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                    bannerFullBorder ();

                    bannerUserInput ();

                }
            }
            else{
                customerInsertInterface();
            }
        }
    }
}

void customerSelectInterface(){
    //sky create
    screenClear ();
    bannerFullBorder();
    bannerBlankBorderTextCen ("Customer Database");
    bannerFullBorder();

    bannerBlankBorderTextCen ("Select Customer");

    for (int i = 0;i<2;i++)
        bannerBlankBorder ();
    bannerFullBorderSection ();
    bannerBlankBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type Customer ID:");

    for (int i = 0;i<26;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
    bannerFullBorder ();

    bannerUserInput ();
    char id[MAX_LNG_ID];
    scanf("%s", id);
    if (strcmp(id, "B") == 0 || strcmp(id, "b") == 0 ){
            customerSwitchHub();
        }
        else if (strcmp(id, "N") == 0 || strcmp(id, "n") == 0 ){
            terminate();
        }
        else{
            // customerSelectById(id);
        }
}

void customerDeleteInterface(){
    screenClear ();
    bannerFullBorder();
    bannerBlankBorderTextCen ("Customer Database");
    bannerFullBorder();

    bannerBlankBorderTextCen ("Delete Customer");

    bannerFullBorderSection ();
    bannerBlankBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type Customer ID");

    for (int i = 0;i<29;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
    bannerFullBorder ();

    bannerUserInput ();
    char id[MAX_LNG_ID], name[MAX_LNG_TEXT], lastname[MAX_LNG_TEXT], gender, buffer[140], flag;
    double point, totalbuy;
    while (1){
        scanf("%s", id);
        if (strcmp(id, "B") == 0 || strcmp(id, "b") == 0 ){
            customerSwitchHub();
        }
        else if (strcmp(id, "N") == 0 || strcmp(id, "n") == 0 ){
            terminate();
        }
        else{
            if (customerSelectById(id, name, lastname, &gender, &point, &totalbuy)){
                screenClear ();
                sprintf(buffer, "%s %s %s %c %lf %lf", id, name, lastname, gender, point, totalbuy);
                bannerFullBorder();
                bannerBlankBorderTextCen ("Customer Database");
                bannerFullBorder();

                bannerBlankBorderTextCen ("Delete Customer");

                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorder ();
                bannerBlankBorderTextCen ("Are you sure to delete ?");
                bannerBlankBorderTextCen (buffer);
                bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'Y' to comfirm || Type 'N' to Discard");

                for (int i = 0;i<26;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                bannerUserInput ();
                scanf(" %c", &flag);
                if (flag == 'Y' || flag == 'y'){
                    customerDelete(id);
                    screenClear ();
                    bannerFullBorder();
                    bannerBlankBorderTextCen ("Customer Database");
                    bannerFullBorder();
            
                    bannerBlankBorderTextCen ("Delete Customer");
            
                    bannerFullBorderSection ();
                    bannerBlankBorder ();
                    bannerBlankBorder ();
                    bannerBlankBorderTextCen ("Delete Success");
                    bannerBlankBorderTextCen ("Type Next CustomerID Or Type 'B' to Back");
            
                    for (int i = 0;i<28;i++)
                        bannerBlankBorder ();
                    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                    bannerFullBorder ();

                    bannerUserInput ();
                }
                else{
                    screenClear ();
                    customerDeleteInterface();
                }
            }
            else{
                screenClear ();
                bannerFullBorder();
                bannerBlankBorderTextCen ("Customer Database");
                bannerFullBorder();
            
                bannerBlankBorderTextCen ("Delete Customer");
            
                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorder ();
                bannerBlankBorderTextCen ("CustomerID dosen't exist.");
                bannerBlankBorderTextCen ("Type Next CustomerID Or Type 'B' to Back");
            
                for (int i = 0;i<28;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                bannerUserInput ();
            }
            
        }
    }
}

void customerUpdateInterface(){
    screenClear ();
    bannerFullBorder();
    bannerBlankBorderTextCen ("Customer Database");
    bannerFullBorder();

    bannerBlankBorderTextCen ("Update Customer");

    bannerFullBorderSection ();
    bannerBlankBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type customerID");

    for (int i = 0;i<29;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
    bannerFullBorder ();
    bannerUserInput ();
    char id[MAX_LNG_ID], name[MAX_LNG_TEXT], lastname[MAX_LNG_TEXT], gender, buffer[140], flag[MAX_LNG_TEXT], genderChanged[2];
    double point, totalbuy;
    while (1){
        scanf("%s", id);
        if (strcmp(id, "B") == 0 || strcmp(id, "b") == 0 ){
            customerSwitchHub();
        }
        else if (strcmp(id, "N") == 0 || strcmp(id, "n") == 0 ){
            terminate();
        }
        else{
            if (customerSelectById(id, name, lastname, &gender, &point, &totalbuy)){
                screenClear ();
                sprintf(buffer, "%s %s %s %c", id, name, lastname, gender);
                bannerFullBorder();
                bannerBlankBorderTextCen ("Customer Database");
                bannerFullBorder();

                bannerBlankBorderTextCen ("Update Customer");

                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorder ();
                bannerBlankBorderTextCen ("Customer Profile");
                bannerBlankBorderTextCen (buffer);
                bannerBlankBorderTextCen (" ");
                bannerBlankBorderTextCen ("Type another name to change customer name");
                bannerBlankBorderTextCen ("Press Enter to set by default");

                for (int i = 0;i<25;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();
                bannerUserInput ();

                printf("(%s) >>> ", name);
                if (superscanf(flag) != 0)
                    customerUpdateFirstname(id, flag);
                printf("(%s) >>> ", lastname);
                if (superscanf(flag) != 0)
                    customerUpdateLastname(id, flag);
                printf("(%c) >>> ", gender);
                if (superscanf(genderChanged) != 0)
                    customerUpdateGender(id, toupper(genderChanged[0]));
                
                screenClear ();
                bannerFullBorder();
                bannerBlankBorderTextCen ("Customer Database");
                bannerFullBorder();
            
                bannerBlankBorderTextCen ("Update Customer");
            
                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorder ();
                customerSelectById(id, name, lastname, &gender, &point, &totalbuy);
                sprintf(buffer, "%s %s %s %c", id, name, lastname, gender);
                bannerBlankBorderTextCen ("Customer has been updated");
                bannerBlankBorderTextCen (buffer);
                bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type Next CustomerID to Update Or Type 'B' to Back");
            
                for (int i = 0;i<26;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                bannerUserInput ();
            
            }
            else{
                screenClear ();
                bannerFullBorder();
                bannerBlankBorderTextCen ("Customer Database");
                bannerFullBorder();
            
                bannerBlankBorderTextCen ("Update Customer");
            
                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorder ();
                bannerBlankBorderTextCen ("CustomerID dosen't exist.");
                bannerBlankBorderTextCen ("Type Next CustomerID Or Type 'B' to Back");
            
                for (int i = 0;i<28;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                bannerUserInput ();
            }
            
        }
    }
}



int customerSelectById(char *id, char *firstname, char *lastname, char *gender, double *point, double *totalBuy){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            // Return all values back by reference
            strcpy(firstname, Customer[i].firstname);
            strcpy(lastname, Customer[i].lastname);
            *gender = Customer[i].gender;
            *point = Customer[i].point;
            *totalBuy = Customer[i].totalBuy;

            return 1;   // Found a record
        }
    }
    return 0;           // Not found the given `id` in the records
}

int customerInsert(char *id, char *firstname, char *lastname, char gender){
    int tailIndex = RecordCount.customer;

    // To comfirm that `id` is unique
    for(int i = 0; i < tailIndex; i++){
        if(strcmp(Customer[i].id, id) == 0)
            return 0;   // Error: Customer ID already exists
    }

    strcpy(Customer[tailIndex].id, id);
    strcpy(Customer[tailIndex].firstname, firstname);
    strcpy(Customer[tailIndex].lastname, lastname);
    Customer[tailIndex].gender = gender;
    Customer[tailIndex].point = 0;          // Initail value
    Customer[tailIndex].totalBuy = 0;       // Initail value

    RecordCount.customer++;    // Update the amount of records

    customerFileWrite();       // Save to a Database file
    return 1;                  // Operation Success
}

int customerUpdateFirstname(char *id, char *firstname){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            strcpy(Customer[i].firstname, firstname);
            customerFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int customerUpdateLastname(char *id, char *lastname){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            strcpy(Customer[i].lastname, lastname);
            customerFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int customerUpdateGender(char *id, char gender){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            Customer[i].gender = gender;
            customerFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int customerUpdatePoint(char *id, double point){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            Customer[i].point = point;
            customerFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int customerUpdatetotalBuy(char *id, double totalBuy){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            Customer[i].totalBuy = totalBuy;
            customerFileWrite();    // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int customerDelete(char *id){
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.customer;
    for(int i = 0; i < numberOfRecords; i++){
        if(strcmp(Customer[i].id, id) == 0){
            while(i < numberOfRecords - 1){
                Customer[i] = Customer[i+1];
                i++;
            }
            RecordCount.customer--;    // Update the amount of records
            customerFileWrite();       // Save to a Database file
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