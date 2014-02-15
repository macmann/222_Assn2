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
    
    cout << "Choose the status to update " << endl;
    cout << "1) Checked" << endl;
    cout << "2) Invalid/Incomplete" << endl;
    cout << "Enter your option: " ; 
    cin >> selector;
    
    if(selector == 1)
        tempstatus = "Checked";
    else
        tempstatus = "Invalid";
    
    processBookingSQL(tempBkRef, tempstatus);
    
}

bool BookingStaff::processBookingSQL(string tempBkRef, string tempstatus)
{
    char * sqlchangeBookingsStatus;
    sqlchangeBookingsStatus = sqlite3_mprintf("UPDATE Booking set bookingStatus = '%q' where BookingRefNo='%q';", tempstatus.c_str() ,tempBkRef.c_str());
    HolidayPackageSystem::executeRecord(sqlchangeBookingsStatus); 
    
    char * sqlViewUpdateBookingsStatus;
    sqlViewUpdateBookingsStatus = sqlite3_mprintf("SELECT * FROM Booking where BookingRefNo='%q';", tempBkRef.c_str());
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
    cin.ignore();
    getline(cin, streetName);
    
    cout << "Town: " << endl;
    cin.ignore();
    getline(cin, town);
    
    cout << "City: " << endl;
    cin.ignore();
    getline(cin, city);
    
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
    
    cout << "Created Client Account Successfully" << endl;
}

bool BookingStaff::editClientAccount()
{
    HolidayPackageSystem::displayRecord("SELECT * FROM Client");
    
    string cNRIC;
    cout << "Enter the Client NRIC to Edit: " ;
    cin >> cNRIC;
    
     char selectEdit;
     
     string editPassword;
     string editFirstName, editLastNam, editEmail;
     bool breakLoop = false;
     char * sqlEditPwd, * sqlEditFN, * sqlEditLN, * sqlEditEmail;
         
    while(1)
    {
        cout << "\n\nSelect which Field would u like to edit" << endl; 
        cout << "a) Password" << endl; 
        cout << "b) First name" << endl; 
        cout << "c) Last name" << endl; 
        cout << "d) Email" << endl; 
        cout << "X) Exit" << endl; 
               
        cout << "Enter your option: ";
        cin >> selectEdit;
/*
        "CREATE TABLE Client(" \
        "NRIC TEXT PRIMARY KEY," \
        "Email TEXT NOT NULL," \
        "Password TEXT NOT NULL," \
        "ClientFirstName TEXT," \
        "ClientLastName TEXT," \
        "StreetName TEXT," \
        "Town TEXT," \
        "City TEXT," \
        "PostalCode TEXT);" \*/

        switch (selectEdit)
        {
             case 'a':
                     cout <<"Enter New Password : ";
                     cin >> editPassword;
                     sqlEditPwd = sqlite3_mprintf("UPDATE Client set Password = '%q' where NRIC='%q';", editPassword.c_str() ,cNRIC.c_str());
                     HolidayPackageSystem::executeRecord(sqlEditPwd); 
                 break;
             case 'b':
                     cout <<"Enter New First name : ";
                     cin >> editFirstName;
                     sqlEditFN = sqlite3_mprintf("UPDATE Client set ClientFirstName = '%q' where NRIC='%q';", editFirstName.c_str() ,cNRIC.c_str());
                     HolidayPackageSystem::executeRecord(sqlEditFN); 
                 break;
             case 'c':
                     cout <<"Enter New Last name : ";
                     cin >> editLastNam;
                     sqlEditLN = sqlite3_mprintf("UPDATE Client set ClientLastName = '%q' where NRIC='%q';", editLastNam.c_str() ,cNRIC.c_str());
                     HolidayPackageSystem::executeRecord(sqlEditLN); 
                 break;
             case 'd':
                     cout <<"Enter New Email : ";
                     cin >> editEmail;
                     sqlEditEmail = sqlite3_mprintf("UPDATE Client set Email = '%q' where NRIC=%q;", editEmail.c_str() , cNRIC.c_str());
                     HolidayPackageSystem::executeRecord(sqlEditEmail); 
                 break;
            case 'x' :
                breakLoop = true;
                 break;
        }
        
        if(breakLoop == true)
            break;
        
        cout <<"Record updated successfully" << endl; 
    }
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
            editClientAccount();
            BSMenu();
            break;
        case 'x' : 
            break;
        default:
            break;
                        
    }
}