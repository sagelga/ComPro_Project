// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void promotionSwitchHub () {
    /*screenClear ();
    bannerFullBorder();
    bannerBlankBorderTextCen ("Customer Database");
    bannerFullBorder();

    bannerBlankBorderTextCen ("What do you want to do?");

    for (int i = 0;i<2;i++)
        bannerBlankBorder ();
    bannerFullBorderSection ();
    bannerBlankBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("1. Insert");
    bannerBlankBorderTextCen ("2. Select");
    bannerBlankBorderTextCen ("3. Delete");
    bannerBlankBorderTextCen ("4. Update");

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
    char id[MAX_LNG_ID];
    double price;
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
    
            //---------------------FirstName--------------------------
            scanf("%s", name);
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
            bannerBlankBorderTextCen ("Promotion Firstname");
            bannerBlankBorderTextCen (name);
            bannerBlankBorderTextCen ("_____________________");
    
            for (int i = 0;i<21;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
            bannerFullBorder ();
    
            bannerUserInput ();

            //---------------------LastName--------------------------
            scanf("%s", lastname);
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
            bannerBlankBorderTextCen ("Customer ID");
            bannerBlankBorderTextCen (id);
            bannerBlankBorderTextCen ("_____________________");
            bannerBlankBorderTextCen ("Customer Firstname");
            bannerBlankBorderTextCen (name);
            bannerBlankBorderTextCen ("_____________________");
            bannerBlankBorderTextCen ("Customer Lastname");
            bannerBlankBorderTextCen (lastname);
            bannerBlankBorderTextCen ("_____________________");
    
            for (int i = 0;i<18;i++)
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

            for (int i = 0;i<2;i++)
                bannerBlankBorder ();
            bannerFullBorderSection ();
            bannerBlankBorder ();
            bannerBlankBorder ();
            bannerBlankBorderTextCen ("Customer ID");
            bannerBlankBorderTextCen (id);
            bannerBlankBorderTextCen ("_____________________");
            bannerBlankBorderTextCen ("Customer Firstname");
            bannerBlankBorderTextCen (name);
            bannerBlankBorderTextCen ("_____________________");
            bannerBlankBorderTextCen ("Customer Lastname");
            bannerBlankBorderTextCen (lastname);
            bannerBlankBorderTextCen ("_____________________");
            bannerBlankBorderTextCen ("Customer Gender");
            if (gender == 'F' || gender == 'f'){
                bannerBlankBorderTextCen ("F");
                genderCheck == 0;
            }
            if (gender == 'M' || gender == 'm'){
                bannerBlankBorderTextCen ("M");
                genderCheck == 1;
            }
    
            for (int i = 0;i<16;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
            bannerFullBorder ();

            bannerUserInput ();

            //
            if (customerInsert(id, name, lastname, gender)){
                screenClear ();
                bannerFullBorder();
                bannerBlankBorderTextCen ("Customer Database");
                bannerFullBorder();
    
                bannerBlankBorderTextCen ("Insert Customer");
    
                for (int i = 0;i<2;i++)
                    bannerBlankBorder ();
                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorder ();
                bannerBlankBorderTextCen ("Insert Success");
                bannerBlankBorderTextCen (id);
                bannerBlankBorderTextCen (name);
                bannerBlankBorderTextCen (lastname);
                if (genderCheck){
                    bannerBlankBorderTextCen ("Male");
                }
                else{
                    bannerBlankBorderTextCen ("Female");
                }
                bannerBlankBorderTextCen ("_____________________");
                bannerBlankBorderTextCen ("Insert Next Customer Or Type 'B' to Back");
    
                for (int i = 0;i<20;i++)
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
    
                for (int i = 0;i<2;i++)
                    bannerBlankBorder ();
                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorder ();
                bannerBlankBorderTextCen ("Insert not Successful");
                bannerBlankBorderTextCen ("Please check your customer ID");
                bannerBlankBorderTextCen (id);
                bannerBlankBorderTextCen ("was repeatedly");
                bannerBlankBorderTextCen ("_____________________");
                bannerBlankBorderTextCen ("Insert Next Customer Or Type 'B' to Back");
    
                for (int i = 0;i<21;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                bannerUserInput ();

            }
        }
    }*/
}

/*void promotionSelectInterface(){

}

void promotionDeleteInterface(){

}

void promotionUpdateInterface(){

}*/

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