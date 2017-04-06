// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

int isFileExist(const char *filename){
    if( access( filename, F_OK ) != -1 ) {
        // file exists
        return 1;
    } else {
        // file doesn't exist
        return 0;
    }
}

void intToString(char *str, int number){
    char buffer[200];
    sprintf(buffer, "%d", number);
    strcpy(str, buffer);
}