#include "HolidayManager.h"

bool HolidayManager::deleteClientAccount()
{
    string tempNRIC;
    cout << "Enter the NRIC of the client to delete: ";
    cin >> tempNRIC;
    
    char * sqldelclient;
    sqldelclient = sqlite3_mprintf("DELETE FROM Client WHERE NRIC='%q'" , tempNRIC.c_str()); 
    
    HolidayPackageSystem::executeRecord(sqldelclient);
    
    cout << "Client account is deleted successfully!" << endl;
};

bool HolidayManager::checkSpace()
{
    string HrID;
    cout  << "Enter the Holday Run ID to Check: " ;
    cin >> HrID;
    
    char * sqlViewClientonPackage;
    sqlViewClientonPackage = sqlite3_mprintf("SELECT * FROM Booking where HolidayrunID='%q';", HrID.c_str());
    HolidayPackageSystem::displayRecord(sqlViewClientonPackage);

}

bool HolidayManager::processBooking()
{
    string tempBkRef, tempstatus;
    int selector;
    char * sqlviewBookings;
    sqlviewBookings = sqlite3_mprintf("SELECT * FROM Booking WHERE BookingStatus='Checked' ;");
    HolidayPackageSystem::displayRecord(sqlviewBookings);
    
    cout << "Enter the booking reference no to process: " ;
    cin >> tempBkRef;
    
    
    cout << "Choose the status to update " << endl;
    cout << "1) Ready for Payment" << endl;
    cout << "2) Waiting List" << endl;
    cout << "Enter your option: " ; 
    cin >> selector;
    
    if(selector == 1)
        tempstatus = "Payment";
    else
        tempstatus = "Waiting";
    
    ProcessBookingSQL(tempstatus, tempBkRef);
    
    cout << "\nBooking status updated!" << endl;
}

int HolidayManager::ProcessBookingSQL(string tempstatus, string tempBkRef) 
{
    int returnVal; 
    char * sqlchangeBookingsStatus;
    sqlchangeBookingsStatus = sqlite3_mprintf("UPDATE Booking set bookingStatus = '%q' where BookingRefNo='%q';", tempstatus.c_str() ,tempBkRef.c_str());
    returnVal = HolidayPackageSystem::executeRecord(sqlchangeBookingsStatus); 
    
    char * sqlViewUpdateBookingsStatus;
    sqlViewUpdateBookingsStatus = sqlite3_mprintf("SELECT * FROM Booking where BookingRefNo='%q';", tempBkRef.c_str());
    HolidayPackageSystem::displayRecord(sqlViewUpdateBookingsStatus);
    
    return returnVal;
}

void HolidayManager::HMmenu()
{
    char hmselect;
    
    cout << "\n\n===========================" << endl;
    cout << "** Holiday Manager Menu ***" << endl;
    cout << "===========================" << endl;
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
            deleteClientAccount;
            HMmenu();
            break;
        case 'c':
            checkSpace();
            HMmenu();
            break;
        case 'd' :
             HolidayPackageSystem::displayRecord("SELECT * FROM Booking;");
             break;
        case 'x':
            break;
                        
    }
}