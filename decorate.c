// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void screenAdjust(){
    screenClear ();
    char text1[107] = "";
    char text2[107] = "  This is the initiation of the POS Systems!";
    char text3[107] = "  The program screen size is optimized for 140 x 40 pixel terminal";
    char text4[107] = "";
    banner(text1, text2, text3, text4);
    
    for (int i = 0;i<3;i++)
        bannerBlankBorder();
    
    bannerBlankBorderTextCen("Please configure the terminal screen to optimum size.");
    
    for (int i = 0;i<27;i++)
        bannerBlankBorder();
    
    bannerBlankBorderTextCen("Type 'Y' to continue...");
    bannerFullBorder();

    bannerUserInput();
    char flags;
    scanf(" %c",&flags);
    flags = toupper(flags);

    switch (flags){

        case('Y'):
            screenClear();
            authInterface();
            return;

        case('N'):
            screenClear();
            terminate();
            return;

        default:
            screenClear();
            screenAdjust();
            return;
    }
}

void terminate(){
    // Type in the text that will be displayed after the user wants to terminate the program
    screenClear();

    bannerFullBorder();
    bannerBlankBorderTextCen("You about to terminate the POS system...");
    bannerFullBorder();

    printf("Shutting the program down.... Please be patient!\n");
    printf("Have a good luck. Bye Bye!\n");
    delay (5);
    screenClear ();
    exit(0);
} 


void screenClear(){
    // This function will clean the screen, and the other function will reprint the page.
    system("clear");
}

void banner(char *bannerLine1, char *bannerLine2, char *bannerLine3, char *bannerLine4){
    // This function will print out the official banner.
    printf(":: ██████╗  ██████╗ ███████╗ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf(":: ██╔══██╗██╔═══██╗██╔════╝ :: %-105s ::\n", bannerLine1);
    printf(":: ██████╔╝██║   ██║███████╗ :: %-105s ::\n", bannerLine2);
    printf(":: ██╔═══╝ ██║   ██║╚════██║ :: %-105s ::\n", bannerLine3);
    printf(":: ██║     ╚██████╔╝███████║ :: %-105s ::\n", bannerLine4);
    printf(":: ╚═╝      ╚═════╝ ╚══════╝ :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
}

void bannerInverse(char *bannerLine1, char *bannerLine2, char *bannerLine3, char *bannerLine4){
    // This function will print out the official banner.
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ██████╗  ██████╗ ███████╗ ::\n");
    printf(":: %105s :: ██╔══██╗██╔═══██╗██╔════╝ ::\n", bannerLine1);
    printf(":: %105s :: ██████╔╝██║   ██║███████╗ ::\n", bannerLine2);
    printf(":: %105s :: ██╔═══╝ ██║   ██║╚════██║ ::\n", bannerLine3);
    printf(":: %105s :: ██║     ╚██████╔╝███████║ ::\n", bannerLine4);
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ╚═╝      ╚═════╝ ╚══════╝ ::\n");
}

void bannerFullBorder(){
    for ( int i = 0; i < 14; i++ )
        printf ("::::::::::");
    printf("\n");
}

void bannerBlankBorderTextCen(char *text){
    int length = strlen(text) - 1;  // Remove the terminal '\0'
    int pad = (length >= 134) ? 0 : ((134 - length) / 2);

    printf(":: %*s%s%*s ::\n", pad," ",text,133-pad-length," ");
}

void bannerBlankBorderText(char *text){
    printf(":: %134s ::\n", text);
}

void bannerBlankBorder(){
    printf(":: %134s ::\n", "");
}

void bannerUserInput(){
    printf("\n>>> ");
}

void bannerFullBorderSection(){
    printf(":: ______________________________________________________________________________________________________________________________________ ::\n");
}

void delay (int interval) {
    // This function will stop all threads from executing everything. Please be cautious about this...
        sleep (interval-1); // Stopping all threads from executing something for x seconds.
    screenClear ();
    sleep(1);
}