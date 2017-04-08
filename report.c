// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

/*-----------------------------------------------------------------------------
Declare all the global variables here*/
const char *monthName[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };


void oneDayReport(int date, int month, int year){
	int numberOfTransactionRecords = RecordCount.transaction;
	int numberOfCategoryRecords = RecordCount.category;

	time_t startTime = toEpochTime(date, month, year, 0, 0, 0);   // From: dd/mm/yyyy 00:00:00
	time_t endTime = toEpochTime(date, month, year, 23, 59, 59);  // To:   dd/mm/yyyy 23:59:59
	
	int i;

	for(i = 0; i < numberOfCategoryRecords; i++){
		// Initail the values
		strcpy(RevenueByCategory[i].categoryName, Category[i].name);
		RevenueByCategory[i].totalPrice = 0;
		RevenueByCategory[i].totalProfit = 0;
	}

	for(i = 0; i < numberOfTransactionRecords && isTimeInRange(Transaction[i].timestamp, startTime, endTime) <= 0; i++){
		if(isTimeInRange(Transaction[i].timestamp, startTime, endTime) == 0){
			// If the record is in the time range
			RevenueByCategory[Transaction[i].inventoryCategoryId].totalPrice += Transaction[i].inventoryPrice;
			RevenueByCategory[Transaction[i].inventoryCategoryId].totalProfit += Transaction[i].inventoryProfit;
		}
	}

}

void multipleDayReport(int fromDate, int fromMonth, int fromYear, int toDate, int toMonth, int toYear){
	int numberOfTransactionRecords = RecordCount.transaction;
	int numberOfCategoryRecords = RecordCount.category;

	time_t startTime = toEpochTime(fromDate, fromMonth, fromYear, 0, 0, 0);   // From: dd/mm/yyyy 00:00:00
	time_t endTime = toEpochTime(toDate, toMonth, toYear, 23, 59, 59);  // To:   dd/mm/yyyy 23:59:59
	
	int i;

	for(i = 0; i < numberOfCategoryRecords; i++){
		// Initail the values
		strcpy(RevenueByCategory[i].categoryName, Category[i].name);
		RevenueByCategory[i].totalPrice = 0;
		RevenueByCategory[i].totalProfit = 0;
	}

	for(i = 0; i < numberOfTransactionRecords && isTimeInRange(Transaction[i].timestamp, startTime, endTime) <= 0; i++){
		if(isTimeInRange(Transaction[i].timestamp, startTime, endTime) == 0){
			// If the record is in the time range
			RevenueByCategory[Transaction[i].inventoryCategoryId].totalPrice += Transaction[i].inventoryPrice;
			RevenueByCategory[Transaction[i].inventoryCategoryId].totalProfit += Transaction[i].inventoryProfit;
		}
	}
}

void nextnDayReport(int fromDate, int fromMonth, int fromYear, int nDay){
	int numberOfTransactionRecords = RecordCount.transaction;
	int numberOfCategoryRecords = RecordCount.category;

	time_t startTime = toEpochTime(fromDate, fromMonth, fromYear, 0, 0, 0);  		 // From: dd/mm/yyyy 00:00:00
	time_t endTime = toEpochTime(fromDate + nDay, fromMonth, fromYear, 23, 59, 59);  // To:   dd/mm/yyyy 23:59:59
	
	int i;

	for(i = 0; i < numberOfCategoryRecords; i++){
		// Initail the values
		strcpy(RevenueByCategory[i].categoryName, Category[i].name);
		RevenueByCategory[i].totalPrice = 0;
		RevenueByCategory[i].totalProfit = 0;
	}

	for(i = 0; i < numberOfTransactionRecords && isTimeInRange(Transaction[i].timestamp, startTime, endTime) <= 0; i++){
		if(isTimeInRange(Transaction[i].timestamp, startTime, endTime) == 0){
			// If the record is in the time range
			RevenueByCategory[Transaction[i].inventoryCategoryId].totalPrice += Transaction[i].inventoryPrice;
			RevenueByCategory[Transaction[i].inventoryCategoryId].totalProfit += Transaction[i].inventoryProfit;
		}
	}
}

void nextnMonthReport(int fromDate, int fromMonth, int fromYear, int nMonth){
	int numberOfTransactionRecords = RecordCount.transaction;
	int numberOfCategoryRecords = RecordCount.category;

	time_t startTime = toEpochTime(fromDate, fromMonth, fromYear, 0, 0, 0);  		 	// From: dd/mm/yyyy 00:00:00
	time_t endTime = toEpochTime(fromDate, fromMonth + nMonth, fromYear, 23, 59, 59);   // To:   dd/mm/yyyy 23:59:59
	
	int i;

	for(i = 0; i < numberOfCategoryRecords; i++){
		// Initail the values
		strcpy(RevenueByCategory[i].categoryName, Category[i].name);
		RevenueByCategory[i].totalPrice = 0;
		RevenueByCategory[i].totalProfit = 0;
	}

	for(i = 0; i < numberOfTransactionRecords && isTimeInRange(Transaction[i].timestamp, startTime, endTime) <= 0; i++){
		if(isTimeInRange(Transaction[i].timestamp, startTime, endTime) == 0){
			// If the record is in the time range
			RevenueByCategory[Transaction[i].inventoryCategoryId].totalPrice += Transaction[i].inventoryPrice;
			RevenueByCategory[Transaction[i].inventoryCategoryId].totalProfit += Transaction[i].inventoryProfit;
		}
	}
}


void monthlyReport(unsigned int year){
	int numberOfPurchaseRecords = RecordCount.purchase;
	int numberOfMonth = 12;

	time_t startTime = toEpochTime(1, 1, year, 0, 0, 0);  		 	// From: 01/01/yyyy 00:00:00
	time_t endTime = toEpochTime(31, 12, year, 23, 59, 59);   // To:   31/12/yyyy 23:59:59
	
	time_t purchaseTime;
	int monthIndex;

	int i;
	struct tm *timeinfo;

	for(i = 0; i < numberOfMonth; i++){
		// Initail the values
		strcpy(RevenueByMonth[i].monthName, monthName[i]);
		RevenueByMonth[i].totalPrice = 0;
		RevenueByMonth[i].totalProfit = 0;
	}

	for(i = 0; i < numberOfPurchaseRecords; i++){
		if(isTimeInRange(Purchase[i].timestamp, startTime, endTime) == 0){
			// If the record is in the time range
			purchaseTime = Purchase[i].timestamp;
			timeinfo = localtime (&purchaseTime);

			monthIndex = timeinfo->tm_mon;
			RevenueByMonth[monthIndex].totalPrice += Purchase[i].totalPrice;
			RevenueByMonth[monthIndex].totalProfit += Purchase[i].totalProfit;
		}
	}
}   


void personnelSaleReport(unsigned int year){
	int numberOfPersonnelRecords = RecordCount.personnel;
	int numberOfPurchaseRecords = RecordCount.purchase;

	time_t startTime = toEpochTime(1, 1, year, 0, 0, 0);  		 	// From: 01/01/yyyy 00:00:00
	time_t endTime = toEpochTime(31, 12, year, 23, 59, 59);   // To:   31/12/yyyy 23:59:59

	int i, j;

	for(i = 0; i < numberOfPersonnelRecords; i++){
		// Initializing the information of each record
		strcpy(RevenueByPersonnel[i].id, Personnel[i].id);
		strcpy(RevenueByPersonnel[i].firstname, Personnel[i].firstname);
		strcpy(RevenueByPersonnel[i].lastname, Personnel[i].lastname);
		RevenueByPersonnel[i].totalPrice = 0;
		RevenueByPersonnel[i].totalProfit = 0;

		for(j = 0; j < numberOfPurchaseRecords && isTimeInRange(Purchase[j].timestamp, startTime, endTime) <= 0; j++){
			if(strcmp(Personnel[i].id, Purchase[j].personnelId) == 0 && isTimeInRange(Purchase[j].timestamp, startTime, endTime) == 0){
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
			//OneDayReportInterface();
			break;

		case ('2'):
			//MonthlyReportInterface();
			break;

		case ('3'):
			//PersonnelSaleReportInterface();
			break;

		case ('4'):
			//MultipleDayReportInterface();
			break;

		case ('N'):
			terminate();
			break;

		case ('n'):
			terminate();
			break;

		case ('B'):
			switchHub();
			break;

		case ('b'):
			switchHub();
			break;

		default:
			checkErrorIn = 1;
			reportSwitchHub();
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