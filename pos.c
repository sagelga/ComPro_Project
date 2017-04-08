// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void cashierInterface () {//Interface that will ask for customer ID
    screenClear ();

    banner ("Signing in as", Session.user.username, "", "");

    bannerBlankBorder ();

    char text[140];
    strcpy(text, "Welcome! My name is ");
    strcat(text, Session.user.firstname);
    strcat(text, " ");
    strcat(text, Session.user.lastname);
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

    /* Call this if the input is not N or B -> */ cashierInterfaceInventory ();
}

void cashierInterfaceInventory(){// Interface that will remove the item from the database
    screenClear ();

    banner (Session.user.username,"is serving you today","Welcome!","<customer_username");

    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Item name                                  | Count | Price                |"); // Keep these on forever

    // Following by LAST 25 items that have been scanned....

    int subTotal;
    int tax;
    int total;
    int pointEarn;

    bannerBlankBorderText("Sub Total %.40f"); // Total Price - 7% (Shows only 2 significant point!!)
    bannerBlankBorderText ("Tax %.40f"); // VAT calculated from total price
    bannerBlankBorderText ("Total %.40f"); // Total Price
    bannerBlankBorder ();
    bannerBlankBorderText ("Points you will earned %.40f");

    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'Q' to quit  |  Press ENTER to finish  |  Type 'V' to void");
    bannerFullBorder ();
    bannerUserInput ();

    // Receives item ID -> Query on database -> Find a match (if stock = 0 means no match) -> Show a match -> Add price to the total -> Remove stock from DB of 1


    /* If done everything -> */ cashierInterfaceDiscount ();

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

    for (int i = 32; i>0;i--)
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Type 'Q' to quit  |  Type 'V' to void  |  Press ENTER to skip  |  Type '1' to use point  |  Type '2' to add more item");

    bannerFullBorder ();
    bannerUserInput ();


    /* If done everything -> */ cashierInterfaceResult ();
}

void cashierInterfaceResult(){// Interface that will show the total (just like the receipt)
    screenClear ();

    char text1[140];
    sprintf(text1, "Welcome %s", Session.user.username);

    char text2[140];
    sprintf(text2, "Member ID : %s", "<customer ID>");

    banner (Setting.storeName,Setting.storeAddress,text1,text2);

    bannerBlankBorderTextCen ("Item name                                  | Count | Price                |"); // Try to merge item (if possible)
    // Shows a total of 25 item at a time. Press ENTER to go to the next page
    bannerBlankBorderTextCen ("_______________________________________________________________");
    bannerBlankBorderText ("|----------Membership----------| |-----------Price-----------------");
    bannerBlankBorderText ("| Points you have : %f          | | Sub Total   : %f");
    bannerBlankBorderText ("| Points you earn : %f          | | VAT         : %f");
    bannerBlankBorderText ("|_______________________________| |___________________");
    bannerBlankBorderText ("| Total Points    : %f          | | Total       : %f");
    bannerBlankBorderTextCen ("_______________________________________________________________");
    bannerBlankBorderTextCen ("THANK YOU FOR SHOPPING AT < store_name >");
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'Q' to quit  |  Press ENTER to continue  |  Type 'V' to skip");

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