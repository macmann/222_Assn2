
/* 
 * File:   FinanceManager.cpp
 * Author: vera
 *
 * Created on February 11, 2014, 5:10 PM
 */

#include "FinanaceManager.h"
float deposit, price;
string startDate, bookingDate;

void FinanceManager::fmMenu() {
    char option;
    string nric;
    
    while (true) {
        cout << "\n\n** Finance Office Staff Menu **" << endl;
        cout << "a) View Confirmed Payments" << endl;
        cout << "b) View Confirmed Payments of a Client" << endl;
        cout << "c) View Cancelled Bookings" << endl;
        cout << "d) View Cancelled Bookings of a Client" << endl;
        cout << "e) View Payment Required Bookings" << endl;
        cout << "f) View Payment Required Bookings of a Client" << endl;
        cout << "g) Process Booking" << endl;
        cout << "i) Exit" << endl;
        cout << "Enter your option : ";   
        cin >> option;

        if (option  == 'g') 
            processBooking();
        else if (option == 'b' || option == 'd' || option =='f') {
            cout << "Enter client NRIC to view: ";
            cin >> nric;

            if (option == 'b')
                viewConfirmedBooking(nric);
            else if (option == 'd')
                viewCancelledBooking(nric);
            else if (option == 'f') 
                viewPaymentRequiredBooking(nric);    
        }
        else if (option == 'a' || option == 'c' || option == 'e'){
            if (option == 'a')
                viewConfirmedBooking();
            else if (option == 'c')
                viewCancelledBooking();
            else if (option == 'e')
                viewPaymentRequiredBooking();
        }
        else 
            break;
    }
}


//view all the clients who made payment 
bool FinanceManager::viewConfirmedBooking() { 
  
    HolidayPackageSystem::displayRecord("SELECT * FROM Booking WHERE BookingStatus = 'Confirmed';");
    cout << endl;
    
    return true;
}

//view all the clients who cancelled bookings
bool FinanceManager::viewCancelledBooking() {
    HolidayPackageSystem::displayRecord("SELECT * FROM Booking WHERE BookingStatus = 'Cancelled';");  
    cout << endl;
    
    return true;
}

//view all the clients who need to make payment 
bool FinanceManager::viewPaymentRequiredBooking() {
    HolidayPackageSystem::displayRecord("SELECT * FROM Booking WHERE BookingStatus = 'Payment';");
    cout << endl;
    
    return true;
}

//view a specific client who already made payment
bool FinanceManager::viewConfirmedBooking(string NRIC) {
    char * sql = sqlite3_mprintf("SELECT * FROM Booking WHERE BookingStatus = 'Confirmed' AND NRIC = '%s';"
    , NRIC.c_str());

    HolidayPackageSystem::displayRecord(sql);
    cout << endl;
    
    return true;
 }  

//view a specific client who cancelled bookings
bool FinanceManager::viewCancelledBooking(string NRIC) {
    
    char * sql = sqlite3_mprintf("SELECT * FROM Booking WHERE BookingStatus = 'Cancelled' AND NRIC = '%s';"
    , NRIC.c_str());
    
    HolidayPackageSystem::displayRecord(sql);
    
    cout << endl;
    
    return true;
}

//view a specific client who needs to make payment
bool FinanceManager::viewPaymentRequiredBooking(string NRIC) {
    char * sql = sqlite3_mprintf("SELECT * FROM Booking WHERE BookingStatus = 'Payment' AND NRIC = '%s';"
    , NRIC.c_str());
    
    HolidayPackageSystem::displayRecord(sql);
    
    cout << endl;
    
    return true;
}
        
//update booking status to confirmed after client made payment
//and compute the penalty the client liable to pay after cancelled
void FinanceManager::processBooking() {
    int option;
    string bookingRefNo;
    
    cout << "(1) Update booking status to confirm" << endl;
    cout << "(2) Compute penalty for the client who cancelled the booking" << endl;
    cout << "Select option: ";
    cin >> option;
    
    switch(option) {
        case 1: {
            HolidayPackageSystem::displayRecord("SELECT * FROM Booking WHERE BookingStatus = 'Payment';");
            
            cout << "Enter booking reference no to confirm payment: ";
            cin >> bookingRefNo;
            confirmBooking(bookingRefNo);
            break;
        }
        case 2: {
            HolidayPackageSystem::displayRecord("SELECT * FROM Booking WHERE BookingStatus = 'Cancelled';");
            
            cout << "Enter booking reference no to compute penalty: ";
            cin >> bookingRefNo;
            calculatePenalty(bookingRefNo); 
        } 
    } 
}

//confirm booking by BookingRefNo
//update the spacePerHRun if the booking status is confirmed
bool FinanceManager::confirmBooking(string bookingRefNo) {
    
    char returnVal;
    
    char * sql = sqlite3_mprintf("UPDATE Booking SET BookingStatus = 'Confirmed' WHERE BookingRefNo = '%s' AND BookingStatus = 'Payment';", bookingRefNo.c_str());
    HolidayPackageSystem::executeRecord(sql);  
    
    //update the spacePerHRun in HolidayRun
    //the total number of clients who can book that package will be reduced by 1
    //when the payment is confirmed
    char * sqlUpdate = sqlite3_mprintf("UPDATE HolidayRun SET spacePerHRun = (spacePerHRun - 1) WHERE HolidayRunID = (SELECT HolidayRunID FROM Booking WHERE BookingRefNo = '%s');"
    ,bookingRefNo.c_str());
    returnVal = HolidayPackageSystem::executeRecord(sqlUpdate);  
    
  //  cout << "\nHoliday Run" << endl;
 //   HolidayPackageSystem::displayRecord("select * from holidayrun;");
    return returnVal;
}


float FinanceManager::calculatePenalty(string bookingRefNo) {

   sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    int monthDifference, dateDifference;
    int intSMonth, intBMonth, intSDate, intBDate;
    string startMonth, bookingMonth, sDate, bDate;
 

   /* Open database */
   rc = sqlite3_open("holiday.db", &db);
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }
   
   /* Execute SQL statement */
   //Retrieve deposit, holiday price and start date of a client with bookingRefNo
   //from tables named Holiday Run and Booking which status is cancelled
   const char * sql = sqlite3_mprintf("SELECT Deposit, HolidayPrice, StartDate, BookingDate FROM Booking INNER JOIN HolidayRun "\
                            "ON Booking.HolidayRunID = HolidayRun.HolidayRunID WHERE BookingRefNo = '%s'"\
                            " AND BookingStatus = 'Cancelled'", bookingRefNo.c_str());
   
   rc = sqlite3_exec(db, sql, retrieveData, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }
   else {

        startMonth = startDate.substr(3,2);
        bookingMonth = bookingDate.substr(3,2);

        stringstream buffer (startMonth);
        buffer >> intSMonth;
        stringstream buffer2 (bookingMonth);
        buffer2 >> intBMonth;

        monthDifference = intSMonth - intBMonth;

        sDate = startDate.substr(0,2);
        bDate = bookingDate.substr(0,2);

        stringstream buffer3 (sDate);
        buffer3 >> intSDate;
        stringstream buffer4 (bDate);
        buffer4 >> intBDate;
        
        if (monthDifference == 1) {
            intBDate = 30 + intBDate;
            
            dateDifference = intBDate - intSDate;  
        }
        else if (monthDifference == 0) 
            dateDifference = intSDate - intBDate;
        
        cout << "\nCancelled date: " << bookingDate << endl;
        cout << "Holiday package start date: " << startDate << endl;
        
        if (monthDifference <= 1) {
            if (dateDifference <= 14) {
                cout << "The trip is in less than 2 weeks!" << endl;
                cout << "The client is liable to pay half the cost of the holiday $" << (price/2) << " and deposit $" << deposit << endl;

            }
            else if (dateDifference <= 28) {
                cout << "The trip is in less than 4 weeks!" << endl;
                 cout << "The client is liable to pay the deposit $" << deposit << endl;
            }
        }
        else
            cout << "Refund deposit $" << deposit << " to the client" << endl;

    } 
   sqlite3_close(db);
   
   cout << endl;
    
    return true;
}

//call back method to retrieve deposit , holiday package price, start date and booking date
int FinanceManager::retrieveData (void *arg, int argc, char **argv, char **azColName) {
    string strDeposit = argv [0];
    string strPrice = argv [1];
    startDate = argv [2];
    bookingDate = argv [3];
    
    stringstream buffer (strDeposit);
    buffer >> deposit;
    stringstream buffer2 (strPrice);
    buffer2 >> price;
    
    return 0;
}


