// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void authInterface () {
    screenClear ();
    bannerFullBorder ();
    bannerBlankBorderTextCen ("Sign in to the System");
    bannerFullBorder();
    bannerBlankBorderTextCen ("Please type in your username");
    for (int i = 0;i<34;i++)
        bannerBlankBorder();
    bannerFullBorder();

    char username[130]; // Copy data to SESSION struct;
    bannerUserInput();
    scanf("%s",username); // Then save to session struct

    screenClear ();

    bannerFullBorder ();
    bannerBlankBorderTextCen ("Sign in to the System");
    bannerFullBorder();

    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Welcome back");
    bannerBlankBorderTextCen (username);

    for (int i = 0;i<31;i++)
        bannerBlankBorder();
    bannerBlankBorderTextCen("Please type in your password");
    bannerFullBorder();
    bannerUserInput();

    char password[130];
    scanf("%s",password);

    screenClear();
    // If the username and the password is matched from the database -> Call authInterfaceComplete();
    // If the username and the password is not matched from the database -> Call authInterfaceFail();
    // If these were interrupt -> Call authInterfaceError();
    if (authenticateByUsername(username, password) == 1)
    {
        authInterfaceComplete();
    }
    else if (authenticateByUsername(username, password) == 0)
    {
        authInterfaceFail();
    }
    else
    {
        authInterfaceError();
    }

    // In case of BETA TEST only     Calling -> authInterfaceComplete ();
}

void authInterfaceComplete(){
    bannerFullBorder();
    bannerBlankBorderTextCen ("Your login is now complete. We are now proceeding you to the program");
    bannerFullBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("██████╗  ██████╗ ███████╗");
    bannerBlankBorderTextCen ("██╔══██╗██╔═══██╗██╔════╝");
    bannerBlankBorderTextCen ("██████╔╝██║   ██║███████╗");
    bannerBlankBorderTextCen ("██╔═══╝ ██║   ██║╚════██║");
    bannerBlankBorderTextCen ("██║     ╚██████╔╝███████║");
    bannerBlankBorderTextCen ("╚═╝      ╚═════╝ ╚══════╝");
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Welcome back! <username>");
    for ( int i = 0; i < 26; i++ ) {
        bannerBlankBorder ();
    }
    bannerBlankBorderTextCen ("Redirecting you to POS system in 5 seconds...");
    bannerFullBorder ();
    delay (5);
    // If user are admin (0) -> Redirect to switchHub();
    // If user are manager (1) -> Redirect to switchHubManager();
    // If user are sales (2) -> Redirect to switchHubSale();

    /* During this betq test only (assuming all user are admin) ->*/ switchHub ();
}

void authInterfaceFail () {
    bannerFullBorder ();
    bannerBlankBorderTextCen ("Your login credentials is incorrect.");
    bannerFullBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("We are redirecting you try again. If you wish to do that, type anything to continue");
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("or type 'N' to exit the program");

    for ( int i = 0; i < 32; i++ )
        bannerBlankBorder ();

    bannerFullBorder ();
    bannerUserInput ();
    char flag;
    scanf (" %c", &flag);

    switch (flag) {

        case ('N'):
            terminate ();
            return;

        case ('n'):
            terminate ();
            return;

        default:
            screenClear();
            authInterface ();
            return;
    }
    // If user type anything (except N or n) program will not be terminate + rerouting to login page again
    // If user type 'N' or 'n' program will be rerouting to terminate(); and they can shut the program down...
}

void authInterfaceError () {
    bannerFullBorder ();
    bannerBlankBorderTextCen ("Oops!");
    bannerFullBorder ();

    bannerBlankBorderTextCen ("The username that you have type are not in the system...");
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Please try again or contact an administrator if this happens too many times");
    for ( int i = 0; i < 32; i++ )
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Redirect to sign in...");
    bannerFullBorder ();

    delay (6);
    authInterface ();

    // Program will delay for 10 seconds, and will be redirect back to login page...
}

int authenticateByUsername(char *username, char *password){
	int numberOfRecords;    // Number of the records in a table
	numberOfRecords = RecordCount.personnel;

	for(int i = 0; i < numberOfRecords; i++){
		if(strcmp(Personnel[i].username, username) == 0){
			if(strcmp(Personnel[i].password, password) == 0){
				// Save user's information on the Session
				Session.user = Personnel[i];
				Session.isLogedin = 1;
				return 1;   // Login success
			}
			else
				return 0;   // Password incorrect
		}
	}
	return -1;  // User Not found
}

int authenticateByToken(char *barcodeToken){
	int numberOfRecords;    // Number of the records in a table
	numberOfRecords = RecordCount.personnel;

	for(int i = 0; i < numberOfRecords; i++){
		if(strcmp(Personnel[i].barcodeToken, barcodeToken) == 0){
			// Save user's information on the Session
			Session.user = Personnel[i];
			Session.isLogedin = 1;
			return 1;
		}
	}
	return 0;
}

void deauthenticate(){
	Session.isLogedin = 0;
}


