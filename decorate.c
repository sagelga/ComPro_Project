// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void screenAdjust () {
    screenClear ();

    bannerCenBorder ("", "", "", "POS Version : 1.0");

    for ( int i = 0; i < 3; i++ )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Please configure the terminal screen to optimum size.");
    bannerBlankBorderTextCen ("Optimal screen size : 140 x 40 character");
    for ( int i = 0; i < 23; i++ )
        bannerBlankBorder ();

    if (errorResponse == 1){
        bannerBlankBorderTextCen ("Invalid response. Please try again.");
    } else{
        bannerBlankBorder ();
    }

    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'Q' to quit  |  Type in your response  |  Type 'Y' to continue");
    bannerFullBorder ();

    bannerUserInput ();
    char flags;
    scanf (" %c", &flags);
    errorResponse = 0;

    switch ( toupper (flags)) {

        case ('Y'):
            authInterface ();
            return;

        case ('Q'):
            terminate ();
            return;

        default:
            errorResponse = 1;
            screenAdjust ();
            return;
    }
}

void terminate () {
    // Type in the text that will be displayed after the user wants to terminate the program
    screenClear ();

    bannerFullBorder ();
    bannerBlankBorderTextCen ("You about to terminate the POS system...");
    bannerFullBorder ();

    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Shutting the program down....");
    bannerBlankBorderTextCen ("Saving Context");

    for (int i = 34;i>0;i--)
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Have a good luck. Bye Bye!");
    bannerFullBorder ();


    delay (3);
    screenClear ();
    exit (0);
}


void screenClear () {
    // This function will clean the screen, and the other function will reprint the page.
    system ("clear");
}

void banner (char *bannerLine1, char *bannerLine2, char *bannerLine3, char *bannerLine4) {
    // This function will print out the official banner.
    printf (":: ██████╗  ██████╗ ███████╗ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf (":: ██╔══██╗██╔═══██╗██╔════╝ :: %-105s ::\n", bannerLine1);
    printf (":: ██████╔╝██║   ██║███████╗ :: %-105s ::\n", bannerLine2);
    printf (":: ██╔═══╝ ██║   ██║╚════██║ :: %-105s ::\n", bannerLine3);
    printf (":: ██║     ╚██████╔╝███████║ :: %-105s ::\n", bannerLine4);
    printf (":: ╚═╝      ╚═════╝ ╚══════╝ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
}

void bannerInverse (char *bannerLine1, char *bannerLine2, char *bannerLine3, char *bannerLine4) {
    // This function will print out the official banner.
    printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ██████╗  ██████╗ ███████╗ ::\n");
    printf (":: %105s :: ██╔══██╗██╔═══██╗██╔════╝ ::\n", bannerLine1);
    printf (":: %105s :: ██████╔╝██║   ██║███████╗ ::\n", bannerLine2);
    printf (":: %105s :: ██╔═══╝ ██║   ██║╚════██║ ::\n", bannerLine3);
    printf (":: %105s :: ██║     ╚██████╔╝███████║ ::\n", bannerLine4);
    printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ╚═╝      ╚═════╝ ╚══════╝ ::\n");
}

void bannerCen () {
    // This function will print out the official banner.
    printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ██████╗  ██████╗ ███████╗ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ██╔══██╗██╔═══██╗██╔════╝ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ██████╔╝██║   ██║███████╗ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ██╔═══╝ ██║   ██║╚════██║ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ██║     ╚██████╔╝███████║ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ╚═╝      ╚═════╝ ╚══════╝ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
}

void bannerCenBorder (char *bannerLine1, char *bannerLine2, char *bannerLine3, char *bannerLine4) {
    // This function will print out the official banner.
    printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ██████╗  ██████╗ ███████╗ ::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf (":: %-54s ██╔══██╗██╔═══██╗██╔════╝ %53s ::\n", bannerLine1, bannerLine2);
    printf ("::                                                        ██████╔╝██║   ██║███████╗                                                       ::\n");
    printf ("::                                                        ██╔═══╝ ██║   ██║╚════██║                                                       ::\n");
    printf (":: %-54s ██║     ╚██████╔╝███████║ %53s ::\n", bannerLine3, bannerLine4);
    printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ╚═╝      ╚═════╝ ╚══════╝ ::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
}

void bannerCenStrikethrough (char *bannerLine1, char *bannerLine2, char *bannerLine3, char *bannerLine4) {
    // This function will print out the official banner.
    printf ("::                                                        ██████╗  ██████╗ ███████╗                                                        ::\n");
    printf ("::%55s  ██╔══██╗██╔═══██╗██╔════╝ %55s::\n", bannerLine1, bannerLine2);
    printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ██████╔╝██║   ██║███████╗ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ██╔═══╝ ██║   ██║╚════██║ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf ("::%55s ██║     ╚██████╔╝███████║ %55s::\n", bannerLine3, bannerLine4);
    printf ("::                                                        ╚═╝      ╚═════╝ ╚══════╝                                                        ::\n");
}

void bannerFullBorder () {
    for ( int i = 0; i < 14; i++ )
        printf ("::::::::::");
    printf ("\n");
}

void bannerBlankBorderTextCen (char *text) {
    int length = strlen (text) - 1;  // Remove the terminal '\0'
    int pad = (length >= 134) ? 0 : ((134 - length) / 2);

    printf (":: %*s%s%*s ::\n", pad, " ", text, 133 - pad - length, " ");
}

void bannerBlankBorderText (char *text) {
    printf (":: %134s ::\n", text);
}

void bannerBlankBorderTextLeft (char *text) {
    printf (":: %-134s ::\n", text);
}

void bannerBlankBorder () {
    printf (":: %134s ::\n", "");
}

void bannerUserInput () {
    printf ("\n>>> ");
}

void bannerFullBorderSection () {
    printf (":: ______________________________________________________________________________________________________________________________________ ::\n");
}

void delay (int interval) {
    // This function will stop all threads from executing everything. Please be cautious about this...
    if ( interval < 30 ) {// Avoiding excessive delay time.
        sleep (interval);
    }
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