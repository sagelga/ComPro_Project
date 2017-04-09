// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void promotionSwitchHub () {
    screenClear ();
    bannerFullBorder();
    bannerBlankBorderTextCen ("Promotion Database");
    bannerFullBorder();

    bannerBlankBorderTextCen ("What do you want to do?");

    for (int i = 0;i<2;i++)
        bannerBlankBorder ();
    bannerFullBorderSection ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("1. Create a new promotion");
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("2. View all promotion in database");
    bannerBlankBorderTextCen ("3. Delete promotion from database");
    bannerBlankBorderTextCen ("4. Update promotion metadata");

    for (int i = 0;i<23;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
    bannerFullBorder ();

    bannerUserInput ();
    char flag;
    scanf(" %c", &flag);

    switch(flag){

        case ('1'):
            promotionInsertInterface();
            break;

        case ('2'):
            promotionSelectInterface();
            break;

        case ('3'):
            promotionDeleteInterface();
            break;

        case ('4'):
            promotionUpdateInterface();
            break;

        case ('b'):
            switchHub ();
        case ('B'):
            switchHub ();

        case ('n'):
            terminate ();
        case ('N'):
            terminate ();

        default:
            promotionSwitchHub ();
            return;

    }
}

void promotionInsertInterface(){
    screenClear ();
    bannerFullBorder();
    bannerBlankBorderTextCen ("Promotion Database");
    bannerFullBorder();

    bannerBlankBorderTextCen ("Insert Promotion");

    for (int i = 0;i<2;i++)
        bannerBlankBorder ();
    bannerFullBorderSection ();
    bannerBlankBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Insert in form");
    bannerBlankBorderTextCen ("Form: ID");
    bannerBlankBorderTextCen ("Price");
    bannerBlankBorderTextCen (" ");
    bannerBlankBorderTextCen ("Ex: 1234567891012");
    bannerBlankBorderTextCen ("100");

    for (int i = 0;i<21;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
    bannerFullBorder ();

    bannerUserInput ();
    char id[MAX_LNG_ID], buffer[140];
    double price;
    while (1){
        scanf("%s", id);
        if (strcmp(id, "B") == 0 || strcmp(id, "b") == 0 ){
            promotionSwitchHub();
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
            bannerFullBorder();
            bannerBlankBorderTextCen ("Promotion Database");
            bannerFullBorder();
    
            bannerBlankBorderTextCen ("Insert Promotion");
    
            for (int i = 0;i<2;i++)
                bannerBlankBorder ();
            bannerFullBorderSection ();
            bannerBlankBorder ();
            bannerBlankBorder ();
            bannerBlankBorderTextCen ("Promotion ID");
            bannerBlankBorderTextCen (id);
            bannerBlankBorderTextCen ("_____________________");
    
            for (int i = 0;i<24;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
            bannerFullBorder ();

            bannerUserInput ();
    
            //---------------------Price--------------------------
            scanf("%lf", &price);
            sprintf(buffer, "%lf", price);
            screenClear ();
            bannerFullBorder();
            bannerBlankBorderTextCen ("Promotion Database");
            bannerFullBorder();

            bannerBlankBorderTextCen ("Insert Promotion");

            for (int i = 0;i<2;i++)
                bannerBlankBorder ();
            bannerFullBorderSection ();
            bannerBlankBorder ();
            bannerBlankBorder ();
            bannerBlankBorderTextCen ("Promotion ID");
            bannerBlankBorderTextCen (id);
            bannerBlankBorderTextCen ("_____________________");
            bannerBlankBorderTextCen ("Price");
            bannerBlankBorderTextCen (buffer);
            bannerBlankBorderTextCen ("_____________________");
    
            for (int i = 0;i<21;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
            bannerFullBorder ();
    
            bannerUserInput ();
            if (promotionInsert(id, price)){
                screenClear ();
                bannerFullBorder();
                bannerBlankBorderTextCen ("Promotion Database");
                bannerFullBorder();

                bannerBlankBorderTextCen ("Insert Promotion");

                for (int i = 0;i<2;i++)
                    bannerBlankBorder ();
                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorder ();
                sprintf(buffer, "ID: %s Price: %lf", id, price);
                bannerBlankBorderTextCen ("Insert Promotion Success");
                bannerBlankBorderTextCen ("_____________________");
                bannerBlankBorder ();
                bannerBlankBorderTextCen (buffer);
                bannerBlankBorderTextCen ("_____________________");
                bannerBlankBorder ();
                bannerBlankBorderTextCen ("Insert Next PromotionID or Type 'B' to Back");
        
                for (int i = 0;i<20;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();
        
                bannerUserInput ();
            }
            else{
                screenClear ();
                bannerFullBorder();
                bannerBlankBorderTextCen ("Promotion Database");
                bannerFullBorder();

                bannerBlankBorderTextCen ("Insert Promotion");

                for (int i = 0;i<2;i++)
                    bannerBlankBorder ();
                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorder ();
                sprintf(buffer, "ID: %s", id);
                bannerBlankBorderTextCen ("Can't Insert Promotion");
                bannerBlankBorderTextCen ("_____________________");
                bannerBlankBorder ();
                bannerBlankBorderTextCen (buffer);
                bannerBlankBorder ();
                bannerBlankBorderTextCen ("This PromotionID was duplicated");
                bannerBlankBorderTextCen ("Insert Next PromotionID or Type 'B' to Back");
        
                for (int i = 0;i<20;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();
        
                bannerUserInput ();
            }
            
        }
    }
}

void promotionSelectInterface(){

}

void promotionDeleteInterface(){
    screenClear ();
    bannerFullBorder();
    bannerBlankBorderTextCen ("Promotion Database");
    bannerFullBorder();

    bannerBlankBorderTextCen ("Delete Promotion");

    for (int i = 0;i<2;i++)
        bannerBlankBorder ();
    bannerFullBorderSection ();
    bannerBlankBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type Promotion ID");

    for (int i = 0;i<26;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
    bannerFullBorder ();

    bannerUserInput ();
    char id[MAX_LNG_ID], buffer[140], flag, statusShow[MAX_LNG_ID];
    double price;
    int status;
    while (1){
        scanf("%s", id);
        if (strcmp(id, "B") == 0 || strcmp(id, "b") == 0 ){
            promotionSwitchHub();
        }
        else if (strcmp(id, "N") == 0 || strcmp(id, "n") == 0 ){
            terminate();
        }
        else{
            if (promotionSelectById(id, &price, &status)){
                screenClear ();
                if (status == 1)
                    strcpy(statusShow, "Active");
                else
                    strcpy(statusShow, "Used");
                bannerFullBorder();
                bannerBlankBorderTextCen ("Promotion Database");
                bannerFullBorder();

                bannerBlankBorderTextCen ("Delete Promotion");

                for (int i = 0;i<2;i++)
                    bannerBlankBorder ();
                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorder ();
                bannerBlankBorderTextCen ("Are you sure to delete ?");
                sprintf(buffer, "ID: %s", id);
                bannerBlankBorderTextCen (buffer);
                sprintf(buffer, "Price: %lf", price);
                bannerBlankBorderTextCen (buffer);
                sprintf(buffer, "Status: %s", statusShow);
                bannerBlankBorderTextCen (buffer);
                bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'Y' to comfirm || Type 'N' to Discard");

                for (int i = 0;i<20;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                bannerUserInput ();
                scanf(" %c", &flag);
                if (flag == 'Y' || flag == 'y'){
                    promotionDelete(id);
                    screenClear ();
                    bannerFullBorder();
                    bannerBlankBorderTextCen ("Promotion Database");
                    bannerFullBorder();
            
                    bannerBlankBorderTextCen ("Delete Promotion");
            
                    for (int i = 0;i<2;i++)
                        bannerBlankBorder ();
                    bannerFullBorderSection ();
                    bannerBlankBorder ();
                    bannerBlankBorder ();
                    bannerBlankBorderTextCen ("Delete Success");
                    bannerBlankBorderTextCen ("Type Next PromotionID Or Type 'B' to Back");
            
                    for (int i = 0;i<25;i++)
                        bannerBlankBorder ();
                    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                    bannerFullBorder ();

                    bannerUserInput ();
                }
                else{
                    screenClear ();
                    promotionDeleteInterface();
                }
            }
            else{
                screenClear ();
                bannerFullBorder();
                bannerBlankBorderTextCen ("Promotion Database");
                bannerFullBorder();
            
                bannerBlankBorderTextCen ("Delete Promotion");
            
                for (int i = 0;i<2;i++)
                    bannerBlankBorder ();
                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorder ();
                bannerBlankBorderTextCen ("PromotionID dosen't exist.");
                bannerBlankBorderTextCen ("Type Next PromotionID Or Type 'B' to Back");
            
                for (int i = 0;i<25;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                bannerUserInput ();
            }
            
        }
    }
}

void promotionUpdateInterface(){
    screenClear ();
    bannerFullBorder();
    bannerBlankBorderTextCen ("Promotion Database");
    bannerFullBorder();

    bannerBlankBorderTextCen ("Update Promotion");

    for (int i = 0;i<2;i++)
        bannerBlankBorder ();
    bannerFullBorderSection ();
    bannerBlankBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type PromotionID");

    for (int i = 0;i<25;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
    bannerFullBorder ();
    bannerUserInput ();
    char id[MAX_LNG_ID], buffer[140], flag[100], statusShow[MAX_LNG_ID];
    double price;
    int status;
    while (1){
        scanf("%s", id);
        if (strcmp(id, "B") == 0 || strcmp(id, "b") == 0 ){
            promotionSwitchHub();
        }
        else if (strcmp(id, "N") == 0 || strcmp(id, "n") == 0 ){
            terminate();
        }
        else{
            if (promotionSelectById(id, &price, &status)){
                screenClear ();
                if (status == 1)
                    strcpy(statusShow, "Active");
                else
                    strcpy(statusShow, "Used");
                bannerFullBorder();
                bannerBlankBorderTextCen ("Promotion Database");
                bannerFullBorder();

                bannerBlankBorderTextCen ("Update Promotion");

                for (int i = 0;i<2;i++)
                    bannerBlankBorder ();
                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorder ();
                bannerBlankBorderTextCen ("Promotion");
                sprintf(buffer, "ID: %s", id);
                bannerBlankBorderTextCen (buffer);
                sprintf(buffer, "Price: %lf", price);
                bannerBlankBorderTextCen (buffer);
                sprintf(buffer, "Status: %s", statusShow);
                bannerBlankBorderTextCen (buffer);
                bannerBlankBorderTextCen (" ");
                bannerBlankBorderTextCen ("Type newprice || Press Enter to set by default");

                for (int i = 0;i<21;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                printf("(%lf) >>> ", price);
                if (superscanf(flag) != 0)
                    promotionUpdatePrice(id, atof(flag));

                screenClear ();
                bannerFullBorder();
                bannerBlankBorderTextCen ("Promotion Database");
                bannerFullBorder();
            
                bannerBlankBorderTextCen ("Update Promotion");
            
                for (int i = 0;i<2;i++)
                    bannerBlankBorder ();
                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorder ();
                promotionSelectById(id, &price, &status);
                sprintf(buffer, "%s %lf %s", id, price, statusShow);
                bannerBlankBorderTextCen ("Promotion has been updated");
                bannerBlankBorderTextCen (buffer);
                bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type Next PromotionID to Update Or Type 'B' to Back");
            
                for (int i = 0;i<23;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                bannerUserInput ();
            
            }
            else{
                screenClear ();
                bannerFullBorder();
                bannerBlankBorderTextCen ("Promotion Database");
                bannerFullBorder();
            
                bannerBlankBorderTextCen ("Update Promotion");
            
                for (int i = 0;i<2;i++)
                    bannerBlankBorder ();
                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorder ();
                bannerBlankBorderTextCen ("PromotionID dosen't exist.");
                bannerBlankBorderTextCen ("Type Next PromotionID Or Type 'B' to Back");
            
                for (int i = 0;i<25;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                bannerUserInput ();
            }
            
        }
    }
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