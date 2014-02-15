
/* 
 * File:   FinanceManager.cpp
 * Author: kaungsanphyoe
 *
 * Created on February 11, 2014, 5:10 PM
 */

#include "FinanaceManager.h"

bool FinanceManager::viewCancelledBooking()
{
    char * sqlviewBookings;
    sqlviewBookings = sqlite3_mprintf("SELECT * FROM Booking WHERE bookingStatus='Cancel' ;");
    HolidayPackageSystem::displayRecord(sqlviewBookings);
}

bool FinanceManager::processBooking()
{
    string tempBkRef, tempstatus;
    int selector;
    char * sqlviewBookings;
    sqlviewBookings = sqlite3_mprintf("SELECT * FROM Booking WHERE bookingStatus='Payment' ;");
    HolidayPackageSystem::displayRecord(sqlviewBookings);
    
    cout << "Enter the booking reference no to process: " ;
    cin >> tempBkRef;
    
    char * sqlchangeBookingsStatus;
    
    cout << "Choose the status to update " << endl;
    cout << "1) Confirm Booking" << endl;
    cout << "2) Cancel Booking" << endl;
    cout << "Enter your option: " ; 
    cin >> selector;
    
    if(selector == 1)
        tempstatus = "Confirmed";
    else
        tempstatus = "Cancel";
    
    cout << endl;
    
    sqlchangeBookingsStatus = sqlite3_mprintf("UPDATE Booking set bookingStatus = '%q' where BookingRefNo='%q';", tempstatus.c_str() ,tempBkRef.c_str());
    HolidayPackageSystem::executeRecord(sqlchangeBookingsStatus); 
    
    char * sqlViewUpdateBookingsStatus;
    sqlViewUpdateBookingsStatus = sqlite3_mprintf("SELECT * FROM Booking where BookingRefNo='%q';", tempBkRef.c_str());
    HolidayPackageSystem::displayRecord(sqlViewUpdateBookingsStatus);
    
    cout << "\nBooking status updated!" << endl;
}

void FinanceManager::FMMenu()
{
    char fmselect;
    
    cout << "\n\n===========================" << endl;
    cout << "*** Finance Manager Menu **" << endl;
    cout << "===========================" << endl;

    cout << "a) View Pending Payments" << endl;
    cout << "b) View Cancelled Bookings" << endl;
    cout << "x) Logout" << endl;
    cout << "Enter your option : ";   
    cin >> fmselect;
    
    switch(fmselect)
    {
        case 'a': 
            processBooking();
            FMMenu();
            break;
        case 'b':
            viewCancelledBooking();
            FMMenu();
            break;
        case 'x': 
            break;
        default:
            break;
                        
    }
}