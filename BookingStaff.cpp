/* 
 * File:   BookingStaff.cpp
 * Author: kaungsanphyoe
 *
 * Created on February 11, 2014, 5:10 PM
 */

#include "BookingStaff.h"

bool BookingStaff::processBooking()
{
    string tempBkRef, tempstatus;
    int selector;
    char * sqlviewBookings;
    sqlviewBookings = sqlite3_mprintf("SELECT * FROM Booking WHERE bookingStatus='Pending' ;");
    HolidayPackageSystem::displayRecord(sqlviewBookings);
    
    cout << "Enter the booking reference no to process: " ;
    cin >> tempBkRef;
    
    char * sqlchangeBookingsStatus;
    
    cout << "Choose the status to update " << endl;
    cout << "1) Checked" << endl;
    cout << "2) Invalid/Incomplete" << endl;
    cout << "Enter your option: " ; 
    cin >> selector;
    
    if(selector == 1)
        tempstatus = "Checked";
    else
        tempstatus = "Invalid";
    
    sqlchangeBookingsStatus = sqlite3_mprintf("UPDATE Booking set bookingStatus = '%q' where bookingReferenceNo='%q';", tempstatus.c_str() ,tempBkRef.c_str());
    HolidayPackageSystem::executeRecord(sqlchangeBookingsStatus); 
    
    char * sqlViewUpdateBookingsStatus;
    sqlViewUpdateBookingsStatus = sqlite3_mprintf("SELECT * FROM Booking where bookingReferenceNO='%q';", tempBkRef.c_str());
    HolidayPackageSystem::displayRecord(sqlViewUpdateBookingsStatus);
}

bool BookingStaff::createClientAccount()
{
    //        "streetName TEXT," \
        "town TEXT," \
        "city TEXT," \
        "postalCode TEXT);" \//
    
    string nric, email, password, firstName, lastName, streetName, town, city, postalCode;
    int staffLevel = 5;
    
    cout  << "Enter First Name: ";
    cin >> firstName;
    
    cout << "Enter Last Name : ";
    cin >>  lastName;
    
    cout << "Enter email: " ;
    cin >> email;
    
    cout << "Enter password: " ;
    cin >> password;
    
    cout << "Enter your NRIC : ";
    cin >> nric;
    
    cout << "Enter street name: ";
    cin >> streetName;
    
    cout << "Town: " << endl;
    cin >> town;
    
    cout << "City: " << endl;
    cin >> city;
    
    cout << "postalCode : " ;
    cin >> postalCode;

    char * sqlAddclient;

    /*    "NRIC TEXT PRIMARY KEY," \
        "email TEXT NOT NULL," \
        "password TEXT NOT NULL," \
        "clientFirstName TEXT," \
        "clientLastName TEXT," \
        "streetName TEXT," \
        "town TEXT," \
        "city TEXT," \
        "postalCode TEXT);" \*/
    
    sqlAddclient = sqlite3_mprintf("INSERT INTO Client VALUES ('%q', '%q', '%q', '%q', '%q', '%q', '%q', '%q', '%q' )" ,
                  nric.c_str(), email.c_str(), password.c_str(), firstName.c_str(), lastName.c_str(),
                  streetName.c_str(), town.c_str(), city.c_str(), postalCode.c_str()); 

    HolidayPackageSystem::executeRecord(sqlAddclient);
}

void BookingStaff::BSMenu()
{
    char bsselect;
    
    cout << "\n\n===========================" << endl;
    cout << "*** Booking Staff Menu ****" << endl;
    cout << "===========================" << endl;
    cout << "a) View Forms Submitted by Clients" << endl;
    cout << "b) Create Client Accounts" << endl;
    cout << "c) Edit Client Accounts" << endl;
    cout << "x) Logout" << endl;
    cout << "Enter your option : ";   
    cin >> bsselect;
    
    switch(bsselect)
    {
        case 'a': 
            processBooking();
            BSMenu();
            break;
        case 'b':
            createClientAccount();
            BSMenu();
            break;
        case 'c':
            BSMenu();
            break;
        case 'x' : 
            break;
        default:
            break;
                        
    }
}