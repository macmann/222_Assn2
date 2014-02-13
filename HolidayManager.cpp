#include "HolidayManager.h"

bool HolidayManager::deleteClientAccount(string nric)
{
    
};

bool HolidayManager::checkSpace()
{
    
}

bool HolidayManager::processBooking()
{
    string tempBkRef, tempstatus;
    int selector;
    char * sqlviewBookings;
    sqlviewBookings = sqlite3_mprintf("SELECT * FROM Booking WHERE bookingStatus='Checked' ;");
    HolidayPackageSystem::displayRecord(sqlviewBookings);
    
    cout << "Enter the booking reference no to process: " ;
    cin >> tempBkRef;
    
    char * sqlchangeBookingsStatus;
    
    cout << "Choose the status to update " << endl;
    cout << "1) Ready for Payment" << endl;
    cout << "2) Waiting List" << endl;
    cout << "Enter your option: " ; 
    cin >> selector;
    
    if(selector == 1)
        tempstatus = "Payment";
    else
        tempstatus = "Waiting";
    
    sqlchangeBookingsStatus = sqlite3_mprintf("UPDATE Booking set bookingStatus = '%q' where bookingReferenceNo='%q';", tempstatus.c_str() ,tempBkRef.c_str());
    HolidayPackageSystem::insertRecord(sqlchangeBookingsStatus); 
    
    char * sqlViewUpdateBookingsStatus;
    sqlViewUpdateBookingsStatus = sqlite3_mprintf("SELECT * FROM Booking where bookingReferenceNO='%q';", tempBkRef.c_str());
    HolidayPackageSystem::displayRecord(sqlViewUpdateBookingsStatus);
}

void HolidayManager::HMmenu()
{
    char hmselect;
    cout << "** Holiday Manager Menu **" << endl;
    cout << "a) View and Process Forms" << endl;
    cout << "b) Delete Client Account" << endl;
    cout << "c) List Customer on Holiday Package" << endl;
    cout << "x) Log out" << endl;
    cout << "Enter your option : ";   
    cin >> hmselect;
    
    switch(hmselect)
    {
        case 'a':
            processBooking();
            HMmenu();
            break;
        case 'b':
            HMmenu();
            break;
        case 'c':
            HMmenu();
            break;
        case 'x':
            break;
                        
    }
}