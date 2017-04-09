// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

/*-----------------------------------------------------------------------------
Declare all the global variables here*/
const char *monthName[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                             "October", "November", "December"};

void oneDayReport (int date, int month, int year) {
    int numberOfTransactionRecords = RecordCount.transaction;
    int numberOfCategoryRecords = RecordCount.category;

    time_t startTime = toEpochTime (date, month, year, 0, 0, 0);   // From: dd/mm/yyyy 00:00:00
    time_t endTime = toEpochTime (date, month, year, 23, 59, 59);  // To:   dd/mm/yyyy 23:59:59

    int i;

    for ( i = 0; i < numberOfCategoryRecords; i++ ) {
        // Initial the values
        strcpy (RevenueByCategory[i].categoryName, Category[i].name);
        RevenueByCategory[i].totalPrice = 0;
        RevenueByCategory[i].totalProfit = 0;
    }

    for ( i = 0;
          i < numberOfTransactionRecords && isTimeInRange (Transaction[i].timestamp, startTime, endTime) <= 0; i++ ) {
        if ( isTimeInRange (Transaction[i].timestamp, startTime, endTime) == 0 ) {
            // If the record is in the time range
            RevenueByCategory[Transaction[i].inventoryCategoryId].totalPrice += Transaction[i].inventoryPrice;
            RevenueByCategory[Transaction[i].inventoryCategoryId].totalProfit += Transaction[i].inventoryProfit;
        }
    }

}

void multipleDayReport (int fromDate, int fromMonth, int fromYear, int toDate, int toMonth, int toYear) {
    int numberOfTransactionRecords = RecordCount.transaction;
    int numberOfCategoryRecords = RecordCount.category;

    time_t startTime = toEpochTime (fromDate, fromMonth, fromYear, 0, 0, 0);   // From: dd/mm/yyyy 00:00:00
    time_t endTime = toEpochTime (toDate, toMonth, toYear, 23, 59, 59);  // To:   dd/mm/yyyy 23:59:59

    int i;

    for ( i = 0; i < numberOfCategoryRecords; i++ ) {
        // Initail the values
        strcpy (RevenueByCategory[i].categoryName, Category[i].name);
        RevenueByCategory[i].totalPrice = 0;
        RevenueByCategory[i].totalProfit = 0;
    }

    for ( i = 0;
          i < numberOfTransactionRecords && isTimeInRange (Transaction[i].timestamp, startTime, endTime) <= 0; i++ ) {
        if ( isTimeInRange (Transaction[i].timestamp, startTime, endTime) == 0 ) {
            // If the record is in the time range
            RevenueByCategory[Transaction[i].inventoryCategoryId].totalPrice += Transaction[i].inventoryPrice;
            RevenueByCategory[Transaction[i].inventoryCategoryId].totalProfit += Transaction[i].inventoryProfit;
        }
    }
}

void nextnDayReport (int fromDate, int fromMonth, int fromYear, int nDay) {
    int numberOfTransactionRecords = RecordCount.transaction;
    int numberOfCategoryRecords = RecordCount.category;

    time_t startTime = toEpochTime (fromDate, fromMonth, fromYear, 0, 0, 0);         // From: dd/mm/yyyy 00:00:00
    time_t endTime = toEpochTime (fromDate + nDay, fromMonth, fromYear, 23, 59, 59);  // To:   dd/mm/yyyy 23:59:59

    int i;

    for ( i = 0; i < numberOfCategoryRecords; i++ ) {
        // Initail the values
        strcpy (RevenueByCategory[i].categoryName, Category[i].name);
        RevenueByCategory[i].totalPrice = 0;
        RevenueByCategory[i].totalProfit = 0;
    }

    for ( i = 0;
          i < numberOfTransactionRecords && isTimeInRange (Transaction[i].timestamp, startTime, endTime) <= 0; i++ ) {
        if ( isTimeInRange (Transaction[i].timestamp, startTime, endTime) == 0 ) {
            // If the record is in the time range
            RevenueByCategory[Transaction[i].inventoryCategoryId].totalPrice += Transaction[i].inventoryPrice;
            RevenueByCategory[Transaction[i].inventoryCategoryId].totalProfit += Transaction[i].inventoryProfit;
        }
    }
}

void nextnMonthReport (int fromDate, int fromMonth, int fromYear, int nMonth) {
    int numberOfTransactionRecords = RecordCount.transaction;
    int numberOfCategoryRecords = RecordCount.category;

    time_t startTime = toEpochTime (fromDate, fromMonth, fromYear, 0, 0, 0);            // From: dd/mm/yyyy 00:00:00
    time_t endTime = toEpochTime (fromDate, fromMonth + nMonth, fromYear, 23, 59, 59);   // To:   dd/mm/yyyy 23:59:59

    int i;

    for ( i = 0; i < numberOfCategoryRecords; i++ ) {
        // Initail the values
        strcpy (RevenueByCategory[i].categoryName, Category[i].name);
        RevenueByCategory[i].totalPrice = 0;
        RevenueByCategory[i].totalProfit = 0;
    }

    for ( i = 0;
          i < numberOfTransactionRecords && isTimeInRange (Transaction[i].timestamp, startTime, endTime) <= 0; i++ ) {
        if ( isTimeInRange (Transaction[i].timestamp, startTime, endTime) == 0 ) {
            // If the record is in the time range
            RevenueByCategory[Transaction[i].inventoryCategoryId].totalPrice += Transaction[i].inventoryPrice;
            RevenueByCategory[Transaction[i].inventoryCategoryId].totalProfit += Transaction[i].inventoryProfit;
        }
    }
}


void monthlyReport (unsigned int year) {
    int numberOfPurchaseRecords = RecordCount.purchase;
    int numberOfMonth = 12;

    time_t startTime = toEpochTime (1, 1, year, 0, 0, 0);            // From: 01/01/yyyy 00:00:00
    time_t endTime = toEpochTime (31, 12, year, 23, 59, 59);   // To:   31/12/yyyy 23:59:59

    time_t purchaseTime;
    int monthIndex;

    int i;
    struct tm *timeinfo;

    for ( i = 0; i < numberOfMonth; i++ ) {
        // Initail the values
        strcpy (RevenueByMonth[i].monthName, monthName[i]);
        RevenueByMonth[i].totalPrice = 0;
        RevenueByMonth[i].totalProfit = 0;
    }

    for ( i = 0; i < numberOfPurchaseRecords; i++ ) {
        if ( isTimeInRange (Purchase[i].timestamp, startTime, endTime) == 0 ) {
            // If the record is in the time range
            purchaseTime = Purchase[i].timestamp;
            timeinfo = localtime (&purchaseTime);

            monthIndex = timeinfo->tm_mon;
            RevenueByMonth[monthIndex].totalPrice += Purchase[i].totalPrice;
            RevenueByMonth[monthIndex].totalProfit += Purchase[i].totalProfit;
        }
    }
}


void personnelSaleReport (unsigned int year) {
    int numberOfPersonnelRecords = RecordCount.personnel;
    int numberOfPurchaseRecords = RecordCount.purchase;

    time_t startTime = toEpochTime (1, 1, year, 0, 0, 0);            // From: 01/01/yyyy 00:00:00
    time_t endTime = toEpochTime (31, 12, year, 23, 59, 59);   // To:   31/12/yyyy 23:59:59

    int i, j;

    for ( i = 0; i < numberOfPersonnelRecords; i++ ) {
        // Initializing the information of each record
        strcpy (RevenueByPersonnel[i].id, Personnel[i].id);
        strcpy (RevenueByPersonnel[i].firstname, Personnel[i].firstname);
        strcpy (RevenueByPersonnel[i].lastname, Personnel[i].lastname);
        RevenueByPersonnel[i].totalPrice = 0;
        RevenueByPersonnel[i].totalProfit = 0;

        for ( j = 0;
              j < numberOfPurchaseRecords && isTimeInRange (Purchase[j].timestamp, startTime, endTime) <= 0; j++ ) {
            if ( strcmp (Personnel[i].id, Purchase[j].personnelId) == 0 &&
                 isTimeInRange (Purchase[j].timestamp, startTime, endTime) == 0 ) {
                RevenueByPersonnel[i].totalPrice += Purchase[j].totalPrice;
                RevenueByPersonnel[i].totalProfit += Purchase[j].totalProfit;
            }
        }
    }
}

int checkErrorIn = 0; //State for Error.
void reportSwitchHub(){
	screenClear();
	bannerFullBorder();
	bannerBlankBorderTextCen("Check Report");
	bannerFullBorder();
	if (checkErrorIn)
	{
		for (int i = 0; i < 3; ++i)
		{
			bannerBlankBorder();
		}
		bannerBlankBorderTextCen("Invalid input. Please try again !!!!");
		for (int i = 0; i < 10; ++i)
		{
			bannerBlankBorder();
		}
	}
	else
	{
		for (int i = 0; i < 14; ++i)
		{
			bannerBlankBorder();
		}
	}
	bannerBlankBorderTextCen("Choose a report");
	bannerBlankBorder();
	bannerBlankBorderTextCen("1. One day report");
	bannerBlankBorderTextCen("2. Monthly report");
	bannerBlankBorderTextCen("3. Personnel sale report");
	bannerBlankBorderTextCen("4. Multiple day report");
	for (int i = 0; i < 14; ++i)
	{
		bannerBlankBorder();
	}
	bannerBlankBorderTextCen ("  Enter 'N' to quit   |      ALTERNATE RESPONSE      |   Enter 'B' to back to main menu");
	bannerFullBorder();

	/*-----User input------*/
	char UserIn;
	printf(">>> ");
	scanf(" %c", &UserIn);
	switch (UserIn){
		case ('1'):
			checkErrorIn = 0;
			OneDayReportInputProcess();
			break;

		case ('2'):
			checkErrorIn = 0;
			MonthlyReportInterface();
			break;

		case ('3'):
			checkErrorIn = 0;
			PersonnelSaleReportInputProcess();
			break;

		case ('4'):
			checkErrorIn = 0;
			//MultipleDayReportInterface();
			break;

		case ('N'):
			terminate();
			break;

		case ('n'):
			terminate();
			break;

		case ('B'):
			checkErrorIn = 0;
			switchHub();
			break;

		case ('b'):
			checkErrorIn = 0;
			switchHub();
			break;

		default:
			checkErrorIn = 1;
			reportSwitchHub();
	}
}

void OneDayReportInputProcess () {
    /*-----Initial interface-----*/
    screenClear ();
    bannerFullBorder ();
    bannerBlankBorderTextCen ("One Day Report");
    bannerFullBorder ();
    for ( int i = 0; i < 17; ++i ) {
        bannerBlankBorder ();
    }
    bannerBlankBorderTextCen ("Please enter date...");
    bannerBlankBorderTextCen ("Example --> 07/03/2017");
    for ( int i = 0; i < 17; ++i ) {
        bannerBlankBorder ();
    }
    bannerFullBorder ();
    /*--------------------------*/
    int dateIN, monthIN, yearIN;
    //Input
    printf (">>> ");
    scanf (" %d/%d/%d", &dateIN, &monthIN, &yearIN);
    //Process
    oneDayReport (dateIN, monthIN, yearIN);
    OneDayReportInterface ();
}

void displayOneDayReport (int page) {
    screenClear ();
    int allPage = (int) ceil (RecordCount.category / 34) + 1;
    bannerFullBorder ();
    printf (":: %-68s |             Revenue            |              Profit            ::\n", "Category Name");
    bannerFullBorder ();

    if ( page == allPage ) {
        for ( int i = (page - 1) * 34; i < RecordCount.category; ++i ) {
            printf (":: %-68s | %30.2lf | %30.2lf ::\n", RevenueByCategory[i].categoryName,
                    RevenueByCategory[i].totalPrice, RevenueByCategory[i].totalProfit);
        }
        for ( int i = 0; i < 34 - (RecordCount.category % 34); ++i ) {
            printf ("::                                                                      |                                |                                ::\n");
        }
    } else {
        for ( int i = (page - 1) * 34; i < page * 34/*(34*page)*/; ++i ) {
            printf (":: %-68s | %30.2lf | %30.2lf ::\n", RevenueByCategory[i].categoryName,
                    RevenueByCategory[i].totalPrice, RevenueByCategory[i].totalProfit);
        }
    }
    bannerBlankBorderTextCen ("'N' to enter new date | Enter Page(e.g. 1, 2, 3) | 'B' to Check Report Menu |");
    printf ("::                                                       <<  <  ( Page %d of %d ) > >>                                                      ::\n",
            page, allPage);
    bannerFullBorder ();
}

void OneDayReportInterface () {
    char handling;
    int pageIn = 1, CheckPage;
    displayOneDayReport (1);
    for ( int i = 0; i >= 0; ++i ) {
        printf (">>> ");
        scanf (" %c", &handling);
        if ((handling == 'B') || (handling == 'b')) {
            reportSwitchHub ();
        } else if ((handling == 'N') || (handling == 'n')) {
            OneDayReportInputProcess ();
        } else if ( isdigit (handling)) {
            CheckPage = (int) handling - 48;
            if ((CheckPage <= ((int) ceil (RecordCount.category / 34) + 1)) && (CheckPage >= 1)) {
                pageIn = (int) handling - 48;
                displayOneDayReport (pageIn);
            } else {
                displayOneDayReport (pageIn);
                printf ("Oops! Page not found, Please enter correct page: ");
            }
        } else {
            displayOneDayReport (pageIn);
            printf ("Oops! Input is valided, Please enter correctly: ");
        }
    }
}

/*---------------------------------------------------------------Monthly Report----------------------------------------------------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void displayMonthlyReport();
void displayMonthlyReport(){
	screenClear();
	bannerFullBorder();
	printf(":: %-68s |             Revenue            |              Profit            ::\n", "Month");
	bannerFullBorder();
	for (int i = 0; i < 12; ++i)
	{
		printf(":: %-68s | %30.2lf | %30.2lf ::\n", RevenueByMonth[i].monthName, RevenueByMonth[i].totalPrice, RevenueByMonth[i].totalProfit);
	}
	for (int i = 0; i < 23; ++i)
	{
		printf("::                                                                      |                                |                                ::\n");
	}
	bannerBlankBorderTextCen("'B' to Check Report Menu ");
	bannerFullBorder();
}

void MonthlyReportInterface(){
	screenClear();
	unsigned int year;
	for (int i = 0; i >= 0; ++i)
	{
		printf("Enter year: ");
		scanf("%u", &year);
		monthlyReport(year);
		displayMonthlyReport();
	}
}

/*---------------------------------------------------------------Personnel Report----------------------------------------------------------------------*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PersonnelSaleReportInputProcess(){
	/*-----Initial interface-----*/
	screenClear();
	bannerFullBorder();
	bannerBlankBorderTextCen("Personeel Sale Report");
	bannerFullBorder();
	for (int i = 0; i < 17; ++i)
	{
		bannerBlankBorder();
	}
	bannerBlankBorderTextCen("Please enter year...");
	bannerBlankBorderTextCen("Example --> 2017");
	for (int i = 0; i < 17; ++i)
	{
		bannerBlankBorder();
	}
	bannerFullBorder();
	/*--------------------------*/
	unsigned int year;
	//Input
	printf(">>> ");
	scanf("%u", &year);
	//Process
	personnelSaleReport(year);
	PersonnelSaleReportInterface();
}

void displayPersonnelSaleReport(int page){
	screenClear();
	int allPage = (int)ceil(RecordCount.personnel/34)+1;
	bannerFullBorder();
	//printf(":: %-68s |             Revenue            |              Profit            ::\n", "Month");
	bannerFullBorder();
	if (page == allPage)
	{
		for (int i = (page-1)*34; i < RecordCount.personnel; ++i)
		{
			printf(":: %s | %s | %s | %lf | %lf ::\n", RevenueByPersonnel[i].id, RevenueByPersonnel[i].firstname, RevenueByPersonnel[i].lastname, RevenueByPersonnel[i].totalPrice, RevenueByPersonnel[i].totalProfit);
			//bannerBlankBorder();
		}
		//display remaining line as bannerBlankBorder()
		for (int i = 0; i < 34-(RecordCount.personnel%34); ++i)
		{
			printf("::                                                                                                                                        ::\n");
		}
	}
	else
	{
		for (int i = (page-1)*34; i < page*34/*(34*page)*/; ++i)
		{
			printf(":: %s | %s | %s | %lf | %lf ::\n", RevenueByPersonnel[i].id, RevenueByPersonnel[i].firstname, RevenueByPersonnel[i].lastname, RevenueByPersonnel[i].totalPrice, RevenueByPersonnel[i].totalProfit);
			//bannerBlankBorder();
		}
	}
	bannerBlankBorderTextCen("'N' to enter new year | Enter Page | 'B' to back to Check Reoport Menu");
	printf("::                                                       <<  <  ( Page %d of %d ) > >>                                                      ::\n", page, allPage);
	bannerFullBorder();
}

void PersonnelSaleReportInterface(){
	screenClear();
	char handling;
	int pageIn = 1, CheckPage;
	displayPersonnelSaleReport(1);
	for (int i = 0; i >= 0; ++i)
	{
		printf(">>> ");
		scanf(" %c", &handling);
		if ((handling == 'B') || (handling == 'b'))
		{
			reportSwitchHub();
		}
		else if ((handling == 'N') || (handling == 'n'))
		{
			PersonnelSaleReportInputProcess();
		}
		else if (isdigit(handling))
		{
			CheckPage = (int)handling - 48;
			if ((CheckPage <= ((int)ceil(RecordCount.category/34)+1)) && (CheckPage >= 1))
			{
				pageIn = (int)handling - 48;
				displayPersonnelSaleReport(pageIn);
			}
			else
			{
				displayPersonnelSaleReport(pageIn);
				printf("Oops! Page not found, Please enter correct page: ");
			}
		}
		else
		{
			displayPersonnelSaleReport(pageIn);
			printf("Oops! Input is valided, Please enter correctly: ");
		}
	}
}
/*
void monthlyForecast(){
	
}

void quarterForecast(){
	
}

void annualForecast(){
	
}


*/

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