#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/***
	General
*/

void init();
void clear_scr();
void header();

/***
	S1: Warehouse management
*/

void Warehouse();

/***
	S2: Customer management
*/

void Customer();

/***
	S3: Account management
*/
void Account();

/***
	S4: Promotion management
*/
void Promotion();

/***
	S5: Report

*/
void Report();

/***
	S6: Sale Forcasting

*/
void Forcast();

/***
	S7: Settings

*/
void Settings();

/***
	S8: Sale System

*/
void Sale();

/***
	Main Function
*/

int main(){
	header();

	return 0;

}

/***
	General
*/

/* G1: Initialization */
void init(){
	clear_scr();
}

/* G2: Clear Screen */
void clear_scr(){
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

/* G3: Header with Logo */
void header(){
	init();
	printf("\n");
	printf("   ██████╗  ██████╗ ███████╗    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("   ██╔══██╗██╔═══██╗██╔════╝    ::%-160s::\n", "Test");
	printf("   ██████╔╝██║   ██║███████╗    ::%-160s::\n", "Test");
	printf("   ██╔═══╝ ██║   ██║╚════██║    ::%-160s::\n", "Test");
	printf("   ██║     ╚██████╔╝███████║    ::%-160s::\n", "Test");
	printf("   ╚═╝      ╚═════╝ ╚══════╝    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");

}


/***
	S1: Warehouse management
*/

void Warehouse(){
	// This is a main function of S1
}

/***
	S2: Customer management
*/

void Customer(){
	// This is a main function of S2
}

/***
	S3: Account management
		- Manager (Superuser)
		- Marketing
		- Sale
*/
void Account(){
	// This is a main function of S3

}

/***
	S4: Promotion management
*/
void Promotion(){
	// This is a main function of S4
}

/***
	S5: Report

*/
void Report(){
	// This is a main function of S5
}

/***
	S6: Sale Forcasting

*/
void Forcast(){
	// This is a main function of S6

}

/***
	S7: Settings

*/
void Settings(){
	// This is a main function of S7

}

/***
	S8: Sale System

*/
void Sale(){
	// This is a main function of S8

}

/***
	M1: Database Management
*/