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

int isTimeInRange(time_t timestamp, time_t start, time_t end){
    if(timestamp < start)
        return -1;  // Starting point is in the future
    else if(timestamp > end)
        return 1;   // Endpoint is in the past
    return 0;   // The time is in this range
}