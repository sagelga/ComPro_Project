// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

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

/* 
void monthlyReport(){
	
}   

void personnelSaleReport(){
	
}   


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