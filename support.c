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

time_t toEpochTime(int date, int month, int year, int hour, int minute, int second){
    struct tm timeinfo = {0};
    time_t result = 0;
    timeinfo.tm_sec = second;
    timeinfo.tm_min = minute;
    timeinfo.tm_hour = hour;
    timeinfo.tm_mday = date;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_year = year - 1900;

    result = mktime(&timeinfo);
    return result;
}

void toDateMonthYear(time_t epochTime, int *date, int *month, int *year){

    struct tm * timeinfo;
    timeinfo = localtime (&epochTime);

    *date = timeinfo->tm_mday;
    *month = timeinfo->tm_mon + 1;
    *year = timeinfo->tm_year + 1900;
}

time_t nDayRollbackToDateMonthYear(int date, int month, int year, int nDayRollback){

    struct tm timeinfo = {0};
    time_t result = 0;
    timeinfo.tm_sec = 59;
    timeinfo.tm_min = 59;
    timeinfo.tm_hour = 23;
    timeinfo.tm_mday = date - nDayRollback;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_year = year - 1900;

    result = mktime(&timeinfo);
    return result;
}

time_t nMonthRollbackToDateMonthYear(int date, int month, int year, int nMonthRollback){

    struct tm timeinfo = {0};
    time_t result = 0;
    timeinfo.tm_sec = 59;
    timeinfo.tm_min = 59;
    timeinfo.tm_hour = 23;
    timeinfo.tm_mday = date;
    timeinfo.tm_mon = month - 1 - nMonthRollback;
    timeinfo.tm_year = year - 1900;

    result = mktime(&timeinfo);
    return result;
}

int isTimeInRange(time_t timestamp, time_t start, time_t end){
    if(timestamp < start)
        return -1;  // Starting point is in the future
    else if(timestamp > end)
        return 1;   // Endpoint is in the past
    return 0;   // The time is in this range
}

int superscanf(char *input){

    char temp[MAX_LNG_SCREEN];
    int i, len;
    fseek(stdin,0,SEEK_END);
    fgets (temp, sizeof(temp), stdin);
    if(temp[0] == '\n'){
        return 0;
    }
    else{
        i = 0;
        while(temp[i] != '\n'){
            input[i] = temp[i];
            i++;
        }
        input[i] = '\0';
        return 1;
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