//
// Created by Kunanon Srisuntiroj on 4/6/2017 AD.
//
#include <stdio.h>              // Pretty much the basic things
#include <string.h>             // Compares strings and other kind of stuff
#include <math.h>               // Calculate difficult 7-years-old Math
#include <stdlib.h>             // IDK what that will do, but I added it anyways...
#include <time.h>               // Synchronize and manage the time between program and you
#include <ctype.h>              // Compares the string to type of string
#include <unistd.h>             // Use access() to check a file is exist

int main () {
    int interval = 10;
    for ( int delays = interval; delays > 0; --delays ) {
        int percentage = (delays / interval) * 50;
        for ( percentage > 0; percentage-- ) {
            printf ("|");
        }
        printf ("\n");
        sleep (1); // Stopping all threads from executing something for x seconds.
    }
}