/* 
 * File:   newClass.cpp
 * Author: kaungsanphyoe
 * 
 * Created on February 11, 2014, 4:02 PM
 */

#include "GeneralManager.h"

bool GeneralManager::createHolidayPackage()
{
    
}

bool GeneralManager::updateHolidayPackage()
{
    
}

bool GeneralManager::deleteHolidayPackage()
{
    
}

bool GeneralManager::createStaff()
{
    string staffID, firstName, lastName, userName, password;
    int staffLevel;
    
    cout  << "Enter  First Name: ";
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
    
    //enter code for sql comments
}

bool GeneralManager::editStaff()
{
    string staffName;
    cout << "Enter the name of staff to Edit: " << endl;
    cin >> staffName;
    
    //db comment to Edit staff from DB one entry by entry
}

bool GeneralManager::deleteStaff()
{
    string staffName;
    cout << "Enter the name of staff to delete: " << endl;
    cin >> staffName;
    
    //db comment to delete staff from DB
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
    cout << "Enter your option : ";   
    cin >> gmselect;
    
    switch(gmselect)
    {
        case 'a':
            break;
        case 'b':
            break;
        case 'c':
            break;
        case 'd':
            break;
        case 'e':
            break;
        case 'f':
            break;
        default:
            break;
                        
    }
}