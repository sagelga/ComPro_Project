// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void oneDayReport(int date, int month, int year){
	int numberOfTransactionRecords = RecordCount.transaction;
	int numberOfCategoryRecords = RecordCount.category;

	time_t startTime = toEpochTime(date, month, year, 0, 0, 0);   // From: dd/mm/yyyy 00:00:00
	time_t endTime = toEpochTime(date, month, year, 23, 59, 59);  // To:   dd/mm/yyyy 23:59:59
	
	int i;

	double price;				// Buffer
	double profit;				// Buffer
	unsigned int categoryId;	// Buffer

	char trash[MAX_LNG_TEXT];	// Don't really want
	unsigned int trash2;		// Don't really want

	for(i = 0; i < numberOfCategoryRecords; i++){
		// Initail the values
		strcpy(RevenueByCategory[i].categoryName, Category[i].name);
		RevenueByCategory[i].totalPrice = 0;
		RevenueByCategory[i].totalProfit = 0;
	}

	i = 0;
	while(i < numberOfTransactionRecords && isTimeInRange(Transaction[i].timestamp, startTime, endTime) <= 0){

		if(inventorySelectById(Transaction[i].inventoryId, trash, &price, &profit, &categoryId, &trash2)){
			// If the record is found
			RevenueByCategory[categoryId].totalPrice += price;
			RevenueByCategory[categoryId].totalProfit += profit;
		}
		i++;
	}

}

void multipleDayReport(int fromDate, int fromMonth, int fromYear, int toDate, int toMonth, int toYear){
	int numberOfTransactionRecords = RecordCount.transaction;
	int numberOfCategoryRecords = RecordCount.category;

	time_t startTime = toEpochTime(fromDate, fromMonth, fromYear, 0, 0, 0);   // From: dd/mm/yyyy 00:00:00
	time_t endTime = toEpochTime(toDate, toMonth, toYear, 23, 59, 59);  	  // To:   dd/mm/yyyy 23:59:59
	
	int i;

	double price;				// Buffer
	double profit;				// Buffer
	unsigned int categoryId;	// Buffer

	char trash[MAX_LNG_TEXT];	// Don't really want
	unsigned int trash2;		// Don't really want

	for(i = 0; i < numberOfCategoryRecords; i++){
		// Initail the values
		strcpy(RevenueByCategory[i].categoryName, Category[i].name);
		RevenueByCategory[i].totalPrice = 0;
		RevenueByCategory[i].totalProfit = 0;
	}

	i = 0;
	while(i < numberOfTransactionRecords && isTimeInRange(Transaction[i].timestamp, startTime, endTime) <= 0){

		if(inventorySelectById(Transaction[i].inventoryId, trash, &price, &profit, &categoryId, &trash2)){
			// If the record is found
			RevenueByCategory[categoryId].totalPrice += price;
			RevenueByCategory[categoryId].totalProfit += profit;
		}
		i++;
	}
}

void nextnDayReport(int fromDate, int fromMonth, int fromYear, int nDay){
	int numberOfTransactionRecords = RecordCount.transaction;
	int numberOfCategoryRecords = RecordCount.category;

	time_t startTime = toEpochTime(fromDate, fromMonth, fromYear, 0, 0, 0);  		 // From: dd/mm/yyyy 00:00:00
	time_t endTime = toEpochTime(fromDate + nDay, fromMonth, fromYear, 23, 59, 59);  // To:   dd/mm/yyyy 23:59:59
	
	int i;

	double price;				// Buffer
	double profit;				// Buffer
	unsigned int categoryId;	// Buffer

	char trash[MAX_LNG_TEXT];	// Don't really want
	unsigned int trash2;		// Don't really want

	for(i = 0; i < numberOfCategoryRecords; i++){
		// Initail the values
		strcpy(RevenueByCategory[i].categoryName, Category[i].name);
		RevenueByCategory[i].totalPrice = 0;
		RevenueByCategory[i].totalProfit = 0;
	}

	i = 0;
	while(i < numberOfTransactionRecords && isTimeInRange(Transaction[i].timestamp, startTime, endTime) <= 0){

		if(inventorySelectById(Transaction[i].inventoryId, trash, &price, &profit, &categoryId, &trash2)){
			// If the record is found
			RevenueByCategory[categoryId].totalPrice += price;
			RevenueByCategory[categoryId].totalProfit += profit;
		}
		i++;
	}
}

void nextnMonthReport(int fromDate, int fromMonth, int fromYear, int nMonth){
	int numberOfTransactionRecords = RecordCount.transaction;
	int numberOfCategoryRecords = RecordCount.category;

	time_t startTime = toEpochTime(fromDate, fromMonth, fromYear, 0, 0, 0);  		 	// From: dd/mm/yyyy 00:00:00
	time_t endTime = toEpochTime(fromDate, fromMonth + nMonth, fromYear, 23, 59, 59);   // To:   dd/mm/yyyy 23:59:59
	
	int i;

	double price;				// Buffer
	double profit;				// Buffer
	unsigned int categoryId;	// Buffer

	char trash[MAX_LNG_TEXT];	// Don't really want
	unsigned int trash2;		// Don't really want

	for(i = 0; i < numberOfCategoryRecords; i++){
		// Initail the values
		strcpy(RevenueByCategory[i].categoryName, Category[i].name);
		RevenueByCategory[i].totalPrice = 0;
		RevenueByCategory[i].totalProfit = 0;
	}

	i = 0;
	while(i < numberOfTransactionRecords && isTimeInRange(Transaction[i].timestamp, startTime, endTime) <= 0){

		if(inventorySelectById(Transaction[i].inventoryId, trash, &price, &profit, &categoryId, &trash2)){
			// If the record is found
			RevenueByCategory[categoryId].totalPrice += price;
			RevenueByCategory[categoryId].totalProfit += profit;
		}
		i++;
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