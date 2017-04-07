// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void cashierInterface () {//Interface that will ask for customer ID
    screenClear ();

    banner ("Signing in as", Session.user.username, "", "");

    bannerBlankBorder ();

    char text;
    strcpy(text, "Welcome! My name is ");
    strcat(text, Session.user.firstname);
    strcat(text, " ");
    strcat(text, Session.user.lastname);
    bannerBlankBorderTextCen (text);

    bannerBlankBorder ();

    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Please type in your member ID");

    for (int i = 28;i>0;i--)
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("  Type 'N' to quit  |  Press ENTER to skip  |  Type 'B' to back  ");
    bannerFullBorder ();
    bannerUserInput ();

    // Recieves input + let user type in the member ID or type N or type ENTER or type B

    /* Call this if the input is not N or B -> */ cashierInterfaceInventory ();
}

void cashierInterfaceInventory(){// Interface that will remove the item from the database
}

void cashierInterfaceDiscount(){// Interface that will ask for discount (voucher and points)
}

void cashierInterfaceResult(){// Interface that will show the total (just like the receipt)
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