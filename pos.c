// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void cashierInterface () {//Interface that will ask for customer ID
    screenClear ();

    banner ("Signing in as", Session.user.username, "", "");

    bannerBlankBorder ();

    char text[140];
    sprintf(text,"My name is %s %.1s. and I am your cashier",Session.user.firstname,Session.user.lastname);
    bannerBlankBorderTextCen (text);

    bannerBlankBorder ();

    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Please enter in your member ID");

    for (int i = 28;i>0;i--)
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Type 'Q' to quit  |  Press ENTER to skip  |  Type 'V' to back");
    bannerFullBorder ();
    bannerUserInput ();

    // Receives input + let user type in the member ID or type N or type ENTER or type B

    /* Call this if the input is not N or B -> */ delay (5); cashierInterfaceInventory ();
}

void cashierInterfaceInventory(){// Interface that will remove the item from the database
    screenClear ();

    banner (Session.user.firstname,"is serving you today","Welcome!","<customer_username>");

    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Item name                                  | Count | Price                |"); // Keep these on forever

    // Following by LAST 25 items that have been scanned....

    double subTotal = 0,tax = 0,total = 0,pointEarn = 0;

    char text[140];
    sprintf(text,"Sub Total %.2f",subTotal);
    bannerBlankBorderText(text); // Total Price - 7% (Shows only 2 significant point!!)

    char text2[140];
    sprintf(text,"Tax %.2f",tax);
    bannerBlankBorderText (text2); // VAT calculated from total price

    char text3[140];
    sprintf(text3,"Total %.2f",total);
    bannerBlankBorderText (text3); // Total Price

    bannerBlankBorder ();
    char text4[140];
    sprintf(text4,"Points you will earned %.2f",pointEarn);
    bannerBlankBorderText (text4);

    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'Q' to quit  |  Press ENTER to finish  |  Type 'V' to void");
    bannerFullBorder ();
    bannerUserInput ();

    // Receives item ID -> Query on database -> Find a match (if stock = 0 means no match) -> Show a match -> Add price to the total -> Remove stock from DB of 1


    /* If done everything -> */ delay (5); cashierInterfaceDiscount ();

}

void cashierInterfaceDiscount(){// Interface that will ask for discount (voucher and points)
    screenClear ();
    banner (Session.user.username,"is serving you today","Welcome!","<customer_username");

    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Do you have a voucher or discount?");
    bannerBlankBorder ();

    /* Remove this please */ double point;
    char text[140];
    sprintf(text, "You have %.2lf points", point);
    bannerBlankBorderTextCen (text);

    for (int i = 30; i>0;i--)
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Type 'Q' to quit  |  Type 'V' to void  |  Press ENTER to skip  |  Type '1' to use point  |  Type '2' to add more item");

    bannerFullBorder ();
    bannerUserInput ();


    /* If done everything -> */ delay (5); cashierInterfaceResult ();
}

void cashierInterfaceResult(){// Interface that will show the total (just like the receipt)
    screenClear ();

    char text[140];
    sprintf(text, "Member ID : %s", "<customer ID>");

    banner (Setting.storeName,Setting.storeAddress,"",text);

    double pointHave = 0,pointEarn = 0,pointTotal = 0;
    double subtotal = 0,vat = 0,priceTotal = 0;

    bannerBlankBorderTextCen ("Item name                                  | Count | Price                |"); // Try to merge item (if possible)
    // Shows a total of 25 item at a time. Press ENTER to go to the next page

    bannerFullBorder ();
    bannerBlankBorderText ("|----------Membership----------| |----------Purchase---------|");

    strcpy(text,"");
    sprintf(text,"| Points you have   : %.0f | | Sub Total   : %.2f |",pointHave,subtotal);
    bannerBlankBorderText (text);

    strcpy(text,"");
    sprintf(text,"| Points you earn   : %.0f | | VAT         : %.2f |",pointEarn,vat);
    bannerBlankBorderText (text);

    bannerBlankBorderText ("|______________________________| |____________________________________|");

    strcpy(text,"");
    sprintf(text,"| Total Points      : %.0f | | Total       : %.2f |",pointTotal,priceTotal);
    bannerBlankBorderText (text);

    bannerBlankBorderTextCen ("_______________________________________________________________");

    strcpy(text,"");
    sprintf(text,"THANK YOU FOR SHOPPING AT %s",Setting.storeName);
    bannerBlankBorderTextCen (text);

    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'Q' to quit  |  Press ENTER to continue  |  Type 'V' to skip");
    bannerFullBorder ();
    bannerUserInput ();

    /* If done everything -> */ delay (5); cashierInterface ();

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