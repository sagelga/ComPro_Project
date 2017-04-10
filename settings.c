// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void settingsSwitchHub () {
    screenClear ();

    bannerFullBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Settings Hub");
    bannerBlankBorder ();
    bannerFullBorder ();
    for ( int i = 0; i < 2; i++ )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("What do you want to do?");

    for ( int i = 0; i < 2; i++ )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Authentication");
    bannerBlankBorderTextCen ("--------------");
    bannerBlankBorderTextCen ("1. Change Password");

    for ( int i = 0; i < 2; i++ )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Storefront");
    bannerBlankBorderTextCen ("----------");
    bannerBlankBorderTextCen ("2. Change store name");
    bannerBlankBorderTextCen ("3. Change store address");

    for ( int i = 0; i < 2; i++ )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Customer Loyalty Promotion");
    bannerBlankBorderTextCen ("--------------------------");
    bannerBlankBorderTextCen ("4. Edit Point per Price conversion rate");
    bannerBlankBorderTextCen ("5. Edit Price per Point conversion rate");

    for ( int i = 0; i < 2; i++ )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Others");
    bannerBlankBorderTextCen ("------");
    bannerBlankBorderTextCen ("6. List of contributors");
    bannerBlankBorderTextCen ("7. cat.gif");

    for ( int i = 0; i < 3; i++ )
        bannerBlankBorder ();

    if ( errorResponse == 1 ) {
        bannerBlankBorderTextCen ("Invalid response. Please try again.");
    } else {
        bannerBlankBorder ();
    }

    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'Q' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
    bannerFullBorder ();

    bannerUserInput ();
    char flag;
    scanf (" %c", &flag);
    errorResponse = 0;

    switch ( toupper (flag)) {

        case ('1'):
            settingUpdatePasswordInterface ();
            return;

        case ('2'):
            settingUpdateStoreNameInterface ();
            return;

        case ('3'):
            settingUpdateStoreAddressInterface ();
            return;

        case ('4'):
            settingPointToPriceInterface ();
            return;

        case ('5'):
            settingPriceToPointInterface ();
            return;

        case ('6'):
            settingContributorList ();
            return;

        case ('7'):
            settingCat ();
            return;

        case ('B'):
            switchHub ();
            break;

        case ('Q'):
            terminate ();
            break;

        default:
            errorResponse = 1;
            settingsSwitchHub ();
            break;

    }
}

void settingUpdatePasswordInterface () {
    char oldPassword[MAX_LNG_TEXT], newPasswordBar1[MAX_LNG_TEXT], newPasswordBar2[MAX_LNG_TEXT], flag;
    char firstname[MAX_LNG_TEXT], lastname[MAX_LNG_TEXT], username[MAX_LNG_TEXT], password[MAX_LNG_TEXT], barcodeToken[MAX_LNG_TOKEN];
    int role;
    personnelSelectById (Session.user.id, firstname, lastname, &role, username, password, barcodeToken);
    screenClear ();
    bannerFullBorder ();
    bannerBlankBorderTextCen ("Settings");
    bannerFullBorder ();
    for ( int i = 0; i < 10; i++ )
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Please Type Old Password");
    bannerBlankBorder ();

    for ( int i = 0; i < 21; i++ )
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
    bannerFullBorder ();

    bannerUserInput ();
    scanf ("%s", oldPassword);
    while ( 1 ) {
        if ( strcmp (oldPassword, password) == 0 ) {
            //Enter First password
            screenClear ();
            bannerFullBorder ();
            bannerBlankBorderTextCen ("Settings");
            bannerFullBorder ();
            for ( int i = 0; i < 10; i++ )
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Your password was Correct");
            bannerBlankBorder ();

            for ( int i = 0; i < 21; i++ )
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Please type your new password...");
            bannerFullBorder ();

            bannerUserInput ();
            scanf ("%s", newPasswordBar1);

            //Enter Second password
            screenClear ();
            bannerFullBorder ();
            bannerBlankBorderTextCen ("Settings");
            bannerFullBorder ();
            for ( int i = 0; i < 10; i++ )
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Retype New Password");
            bannerBlankBorder ();

            for ( int i = 0; i < 21; i++ )
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Please type new password again...");
            bannerFullBorder ();

            bannerUserInput ();
            scanf ("%s", newPasswordBar2);

            if ( strcmp (newPasswordBar1, newPasswordBar2) == 0 ) {
                personnelUpdatePassword (Session.user.id, newPasswordBar1);
                screenClear ();
                bannerFullBorder ();
                bannerBlankBorderTextCen ("Settings");
                bannerFullBorder ();
                for ( int i = 0; i < 10; i++ )
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Change Password success");
                bannerBlankBorder ();

                for ( int i = 0; i < 21; i++ )
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                bannerUserInput ();
                scanf (" %c", &flag);
                if ( flag == 'b' || flag == 'B' ) {
                    settingsSwitchHub ();
                } else {
                    terminate ();
                }
            } else {
                screenClear ();
                bannerFullBorder ();
                bannerBlankBorderTextCen ("Settings");
                bannerFullBorder ();
                for ( int i = 0; i < 10; i++ )
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Password not same");
                bannerBlankBorderTextCen ("Please type same password");
                bannerBlankBorder ();

                for ( int i = 0; i < 20; i++ )
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                bannerUserInput ();
                scanf (" %c", &flag);
                if ( flag == 'b' || flag == 'B' ) {
                    settingsSwitchHub ();
                } else {
                    terminate ();
                }
            }
        } else {
            screenClear ();
            bannerFullBorder ();
            bannerBlankBorderTextCen ("Settings");
            bannerFullBorder ();
            for ( int i = 0; i < 10; i++ )
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Password was Incorrect !");
            bannerBlankBorder ();

            for ( int i = 0; i < 21; i++ )
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Please type your password again... | Type 'B' to back");
            bannerFullBorder ();

            bannerUserInput ();
            scanf ("%s", oldPassword);
            if ( tolower (oldPassword[0]) == 'b' && strlen (oldPassword) == 1 ) {
                settingsSwitchHub ();
            }
        }
    }
}

void settingUpdateStoreNameInterface () {
    char newstoreName[MAX_LNG_TEXT], flag;
    screenClear ();
    bannerFullBorder ();
    bannerBlankBorderTextCen ("Settings");
    bannerFullBorder ();
    for ( int i = 0; i < 10; i++ )
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Your current Storename");
    bannerBlankBorder ();
    bannerBlankBorderTextCen (Setting.storeName);
    bannerBlankBorder ();

    for ( int i = 0; i < 19; i++ )
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Please enter new storename | Type 'B' to Back");
    bannerFullBorder ();

    bannerUserInput ();
    scanf (" %[^\n]", newstoreName);
    if ( tolower (newstoreName[0]) == 'b' && strlen (newstoreName) == 1 ) {
        settingsSwitchHub ();
    } else {
        settingUpdateStoreName (newstoreName);
        screenClear ();
        bannerFullBorder ();
        bannerBlankBorderTextCen ("Settings");
        bannerFullBorder ();
        for ( int i = 0; i < 10; i++ )
            bannerBlankBorder ();
        bannerBlankBorderTextCen ("Your storename has been changed to");
        bannerBlankBorder ();
        bannerBlankBorderTextCen (newstoreName);
        bannerBlankBorder ();

        for ( int i = 0; i < 19; i++ )
            bannerBlankBorder ();
        bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
        bannerFullBorder ();
        bannerUserInput ();
        scanf (" %c", &flag);
        if ( tolower (flag) == 'b' ) {
            settingsSwitchHub ();
        } else {
            terminate ();
        }
    }
}

void settingUpdateStoreAddressInterface () {
    char newstoreAddress[MAX_LNG_TEXT], flag;
    screenClear ();
    bannerFullBorder ();
    bannerBlankBorderTextCen ("Settings");
    bannerFullBorder ();
    for ( int i = 0; i < 10; i++ )
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Your current StoreAddress");
    bannerBlankBorder ();
    bannerBlankBorderTextCen (Setting.storeAddress);
    bannerBlankBorder ();

    for ( int i = 0; i < 19; i++ )
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Please enter new storeaddress | Type 'B' to Back");
    bannerFullBorder ();

    bannerUserInput ();
    scanf (" %[^\n]", newstoreAddress);
    if ( tolower (newstoreAddress[0]) == 'b' && strlen (newstoreAddress) == 1 ) {
        settingsSwitchHub ();
    } else {
        settingUpdateAddress (newstoreAddress);
        screenClear ();
        bannerFullBorder ();
        bannerBlankBorderTextCen ("Settings");
        bannerFullBorder ();
        for ( int i = 0; i < 10; i++ )
            bannerBlankBorder ();
        bannerBlankBorderTextCen ("Your storeadress has been changed to");
        bannerBlankBorder ();
        bannerBlankBorderTextCen (newstoreAddress);
        bannerBlankBorder ();

        for ( int i = 0; i < 19; i++ )
            bannerBlankBorder ();
        bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
        bannerFullBorder ();
        bannerUserInput ();
        scanf (" %c", &flag);
        if ( tolower (flag) == 'b' ) {
            settingsSwitchHub ();
        } else {
            terminate ();
        }
    }
}

void settingContributorList () {
    screenClear ();

    bannerCenBorder ("Educational purpose only", "Redistribution of project is not allowed",
                     "Created by the 1st year student IT KMITL 14", "POS Version 1.0");
    bannerBlankBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Lists of team members");
    bannerFullBorderSection ();
    bannerBlankBorderTextCen ("Kunanon   Srisuntiroj   @sagelga      59070022");
    bannerBlankBorderTextCen ("Thanawat  Laodkaew      @skydddoogg   59070071");
    bannerBlankBorderTextCen ("Noppanut  Ploywong      @noppanut15   59070082");
    bannerBlankBorderTextCen ("Vasanchai Prakobkij     @59070156     59070156");
    bannerBlankBorderTextCen ("Weerakorn Pongpum                     59070163");

    for ( int i = 2; i > 0; i-- )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Over 5000 lines of pure C language has been neatly crafted with love and passion <3");
    bannerBlankBorderTextCen ("See our GitHub Repository : https://github.com/sagelga/ComPro_Project");

    for ( int i = 18; i > 0; i-- )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Redirecting you back in 10 seconds...");
    bannerFullBorder ();

    delay (10);
    settingsSwitchHub ();
}

void settingCat () {
    int i = 0;
    char text1[300] = "", text2[300] = "", text3[300] = "", text4[300] = "";

    for ( int i = 0; i < 88; i++ ) {
        screenClear ();

        bannerFullBorder ();

        for ( int k = 8; k > 0; k-- ) {
            strcpy (text1, " ");
            strcpy (text2, " ");
            strcpy (text3, " ");
            strcpy (text4, " ");

            for ( int j = i; j > 0; j-- ) {
                strcat (text1, "_");
            }
            strcat (text1, "━━━━___━*━___━━___━___*___━_*___┓╭━━━━━━━━━━━━╮");
            printf ("%s", text1);

            for ( int j = i; j > 0; j-- ) {
                strcat (text2, "_");
            }
            strcat (text2, "___━━__*_━━___━━___━━*____━━___┗┓|::::::^----^|");
            printf ("%s", text2);

            for ( int j = i; j > 0; j-- ) {
                strcat (text3, "_");
            }
            strcat (text3, "___━━___━━___━*━___━━____━━*___━┗|:::::|｡◕‿‿◕｡|");
            printf ("%s", text3);

            for ( int j = i; j > 0; j-- ) {
                strcat (text4, "_");
            }
            strcat (text4, "___━━___*━__━━_*___━━___*━━___*━━╰O--O---O--O ╯");
            printf ("%s", text4);

            bannerBlankBorder ();
        }

        bannerFullBorder ();
        i++;
        delay (1);
    }
}

void settingUpdateStoreName (char *storeName) {
    strcpy (Setting.storeName, storeName);
    settingFileWrite ();    // Save to a Database file
}

void settingUpdateAddress (char *storeAddress) {
    strcpy (Setting.storeAddress, storeAddress);
    settingFileWrite ();    // Save to a Database file
}

void settingPriceToPointInterface () {
    screenClear ();

    bannerFullBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Price to Point Conversion Rate");
    bannerBlankBorder ();
    bannerFullBorder ();

    for ( int i = 2; i > 0; i-- )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Your current conversion rate");
    bannerBlankBorder ();

    char text[140];
    sprintf (text, "1 baht you pay  ->   You earns %.2f point", Setting.priceToPoint);
    bannerBlankBorderTextCen (text);

    bannerBlankBorderTextCen ("________________");

    strcpy (text, " ");
    sprintf (text, "10 baht   ->   %.2f point", Setting.priceToPoint * 10);
    bannerBlankBorderTextCen (text);

    strcpy (text, " ");
    sprintf (text, "20 baht   ->   %.2f point", Setting.priceToPoint * 20);
    bannerBlankBorderTextCen (text);

    strcpy (text, " ");
    sprintf (text, "50 baht   ->   %.2f point", Setting.priceToPoint * 50);
    bannerBlankBorderTextCen (text);

    strcpy (text, " ");
    sprintf (text, "100 baht   ->   %.2f point", Setting.priceToPoint * 100);
    bannerBlankBorderTextCen (text);

    bannerBlankBorder ();

    if(completeMark == 0){
        bannerBlankBorder ();
    }
    else{
        bannerBlankBorderTextCen ("Change is now saved.");
    }

    for ( int i = 18; i > 0; i-- )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Would you like to change a conversion rate?");
    bannerBlankBorderTextCen ("Type 'Q' to stop   | Type 'Y' to continue  |   Type 'B' to back");
    bannerFullBorder ();
    bannerUserInput ();

    char flag;
    scanf (" %c", &flag);

    switch ( toupper(flag) ) {
        case ('Y'):
            screenClear ();

            bannerFullBorder ();
            bannerBlankBorder ();
            bannerBlankBorderTextCen ("Price to Point Conversion Rate");
            bannerBlankBorder ();
            bannerFullBorder ();

            for ( int i = 2; i > 0; i-- )
                bannerBlankBorder ();

            bannerBlankBorderTextCen ("Your current conversion rate");
            bannerBlankBorder ();

            char text[140];
            sprintf (text, "1 baht you pay  ->   You earns %.2f point", Setting.priceToPoint);
            bannerBlankBorderTextCen (text);

            bannerBlankBorderTextCen ("________________");

            strcpy (text, " ");
            sprintf (text, "10 baht   ->   %.2f point", Setting.priceToPoint * 10);
            bannerBlankBorderTextCen (text);

            strcpy (text, " ");
            sprintf (text, "20 baht   ->   %.2f point", Setting.priceToPoint * 20);
            bannerBlankBorderTextCen (text);

            strcpy (text, " ");
            sprintf (text, "50 baht   ->   %.2f point", Setting.priceToPoint * 50);
            bannerBlankBorderTextCen (text);

            strcpy (text, " ");
            sprintf (text, "100 baht   ->   %.2f point", Setting.priceToPoint * 100);
            bannerBlankBorderTextCen (text);

            for ( int i = 21; i > 0; i-- )
                bannerBlankBorder ();

            bannerBlankBorderTextCen ("What is your new convertion rate?");
            bannerFullBorder ();
            bannerUserInput ();

            // This will ask for new conversion rate
            double newConversionRate;
            scanf ("%lf",&newConversionRate);


            // New conversion rate displays
            screenClear ();

            bannerFullBorder ();
            bannerBlankBorder ();
            bannerBlankBorderTextCen ("Price to Point Conversion Rate");
            bannerBlankBorder ();
            bannerFullBorder ();

            for ( int i = 2; i > 0; i-- )
                bannerBlankBorder ();

            bannerBlankBorderTextCen ("Your current conversion rate");
            bannerBlankBorder ();

            strcpy (text, " ");
            sprintf (text, "1 baht   ->   %.2f (from %.2f) point", newConversionRate,Setting.priceToPoint);
            bannerBlankBorderTextCen (text);

            bannerBlankBorderTextCen ("________________");

            strcpy (text, " ");
            sprintf (text, "10 baht   ->   %.2f (from %.2f) point", newConversionRate * 10,Setting.priceToPoint * 10);
            bannerBlankBorderTextCen (text);

            strcpy (text, " ");
            sprintf (text, "20 baht   ->   %.2f (from %.2f) point", newConversionRate* 20,Setting.priceToPoint * 20);
            bannerBlankBorderTextCen (text);

            strcpy (text, " ");
            sprintf (text, "50 baht   ->   %.2f (from %.2f) point", newConversionRate* 50,Setting.priceToPoint * 50);
            bannerBlankBorderTextCen (text);

            strcpy (text, " ");
            sprintf (text, "100 baht   ->   %.2f (from %.2f) point", newConversionRate* 100,Setting.priceToPoint * 100);
            bannerBlankBorderTextCen (text);

            for ( int i = 20; i > 0; i-- )
                bannerBlankBorder ();

            bannerBlankBorderTextCen ("Do you want to save your change?");
            bannerBlankBorderTextCen ("Type 'Q' to stop  |  Type 'Y' to continue  |  Type 'B' to back");
            bannerFullBorder ();
            bannerUserInput ();

            char flag2;
            scanf(" %c",&flag2);
            errorResponse = 0;

            switch (toupper(flag2)){
                case ('Y'):
                    settingUpdatePriceToPoint (newConversionRate);

                    completeMark = 1;

                    settingPriceToPointInterface ();
                    return;

                case ('N'):
                    settingPriceToPointInterface ();
                    return;

                case ('B'):
                    settingPriceToPointInterface ();
                    return;

                case ('Q'):
                    terminate ();
                    return;
            }

        case ('B'):
            settingsSwitchHub ();
            return;

        case ('Q'):
            terminate ();
            return;

        default:
            errorResponse = 1;
            settingPriceToPointInterface ();
            return;
    }


}

void settingPointToPriceInterface () {

}

void settingUpdatePriceToPoint (double priceToPoint) {
    Setting.priceToPoint = priceToPoint;
    settingFileWrite ();    // Save to a Database file
}

void settingUpdatePointToPrice (double pointToPrice) {
    Setting.pointToPrice = pointToPrice;
    settingFileWrite ();    // Save to a Database file
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