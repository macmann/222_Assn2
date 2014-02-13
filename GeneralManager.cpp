/* 
 * File:   newClass.cpp
 * Author: kaungsanphyoe
 * 
 * Created on February 11, 2014, 4:02 PM
 */

#include "GeneralManager.h"

bool GeneralManager::createHolidayPackage()
{
    string destCdoe, HRCode, sD, eD;
    float price;
    int spr;
    cout  << "Please choice the destination!" << endl;
    
    char * sqlDestination;
    sqlDestination = sqlite3_mprintf("SELECT * FROM Destination ;");
    HolidayPackageSystem::displayRecord(sqlDestination);
    
    cout <<"Enter Destination Code : ";
    cin >> destCdoe;
    
    cout << "Choose the Holiday Run" << endl;
    
    char * sqlHolidayRun;
    sqlHolidayRun = sqlite3_mprintf("SELECT * FROM  HolidayPackage ;");
    HolidayPackageSystem::displayRecord(sqlHolidayRun);
    
    cout <<"Enter Holiday Run Code : ";
    cin >> HRCode;
    
    cout << "Enter start date: ";
    cin >> sD;
    
    cout << "Enter end date: " ;
    cin >> eD;
    
    cout << "Enter price: " ;
    cin >> price;
    
    cout << "space per run: " ;
    cin >> spr;
    
    char * sqladdHolidayPkg;
    sqladdHolidayPkg = sqlite3_mprintf("INSERT INTO HolidayRun VALUES ('R999','%q' , '%q', '%q', '%q', '%f', '%i')"  
            , HRCode.c_str(), destCdoe.c_str(), sD.c_str(), eD.c_str(), price, spr); 
   
    HolidayPackageSystem::insertRecord(sqladdHolidayPkg);
    HolidayPackageSystem::displayRecord("SElECT * FROM HolidayRun WHERE holidayrunID='R999';");
}

bool GeneralManager::updateHolidayPackage()
{
    
}

bool GeneralManager::deleteHolidayPackage()
{
    string HRID;
    cout << "Enter the name of HolidayRun ID  to delete: " ;
    cin >> HRID;
       
    char * sqldelHR;
    sqldelHR = sqlite3_mprintf("DELETE FROM HolidayRun WHERE holidayrunID='%q'" , HRID.c_str()); 
    
    HolidayPackageSystem::insertRecord(sqldelHR);
}

bool GeneralManager::createStaff()
{
    string staffID, firstName, lastName, userName, password;
    int staffLevel;
    
    cout  << "Enter First Name: ";
    cin >> firstName;
    
    cout << "Enter Last Name : ";
    cin >>  lastName;
    
    cout << "Enter Username: " ;
    cin >> userName;
    
    cout << "Enter password: " ;
    cin >> password;
    
    cout << "Please select from the following." << endl;
    cout << "1) General Manager" << endl;
    cout << "2) Holiday Manager" << endl;
    cout << "3) Booking Staff" << endl;
    cout << "4) Finance Manager" << endl;
    cout << "Enter your choice: " ; 
    cin >> staffLevel;
    
    string newID = HolidayPackageSystem::autoID("Staff");
        char * sqlAddstaff;

    sqlAddstaff = sqlite3_mprintf("INSERT INTO Staff VALUES ('%q', '%q', '%q', '%q', '%q', '%i')" ,
                  newID.c_str(), firstName.c_str(), lastName.c_str(), userName.c_str(), password.c_str(), staffLevel); 

    HolidayPackageSystem::insertRecord(sqlAddstaff);
}

bool GeneralManager::editStaff()
{
    string staffID;
    cout << "Enter the name of staff to Edit: " ;
    cin >> staffID;
    
    //db comment to Edit staff from DB one entry by entry
}

bool GeneralManager::deleteStaff()
{
    string staffID;
    cout << "Enter the name of staff to delete: " ;
    cin >> staffID;
       
    char * sqldelstaff;
    sqldelstaff = sqlite3_mprintf("DELETE FROM Staff WHERE staffID='%q'" , staffID.c_str()); 
    
    HolidayPackageSystem::insertRecord(sqldelstaff);
}

void GeneralManager::GMmenu()
{
    char gmselect;
    
    cout << "** GM Menu **" << endl;
    cout << "a) Create Holiday Package" << endl;
    cout << "b) Update Holiday Package" << endl;
    cout << "c) Delete Holiday Package" << endl;
    cout << "d) Create Staff Accounts" << endl;
    cout << "e) Edit Staff Accounts" << endl;
    cout << "f) Delete Staff Accounts" << endl;
    cout << "x) Log Out" << endl;
    cout << "Enter your option : ";   
    cin >> gmselect;
    
    switch(gmselect)
    {
        case 'a':
           createHolidayPackage();
           GMmenu();
            break;
        case 'b':
            GMmenu();
            break;
        case 'c':
            deleteHolidayPackage();
            GMmenu();
            break;
        case 'd':
            createStaff();
            GMmenu();
            break;
        case 'e':
            GMmenu();
            break;
        case 'f':
            deleteStaff(); 
            GMmenu();
            break;
        case 'x':          
            break;
        default:
            break;
                        
    }
}