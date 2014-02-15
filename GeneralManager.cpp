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
    
    createHolidayPackageSQL(destCdoe, HRCode, sD, eD, price, spr);

    cout << "\n\nHoliday Run Package is added successfully" << endl;
}

int GeneralManager::createHolidayPackageSQL(string destCdoe, string HRCode, string sD, string eD, float price, int spr)
{
     string tempRecordID = HolidayPackageSystem::autoID("HolidayRun");
    
    char * sqladdHolidayPkg;
    sqladdHolidayPkg = sqlite3_mprintf("INSERT INTO HolidayRun VALUES ('%q','%q' , '%q', '%q', '%q', '%f', '%i')"  
          , tempRecordID.c_str(), HRCode.c_str(), destCdoe.c_str(), sD.c_str(), eD.c_str(), price, spr); 
   
    HolidayPackageSystem::executeRecord(sqladdHolidayPkg);
    
    char * sqladdHolidayPkg2;
    sqladdHolidayPkg2 = sqlite3_mprintf("SElECT * FROM HolidayRun WHERE holidayrunID='%q';", tempRecordID.c_str());
    HolidayPackageSystem::displayRecord(sqladdHolidayPkg2);
    
    return 1;
}

bool GeneralManager::updateHolidayPackage()
{
     char selectEdit;
     string HRIDedit;
     string HRCodeEdit, sDedit, eDEdit;
     float priceEdit;
     int sprEdit;
     bool breakLoop = false;
     char * sqlEditHC, * sqlEditSD, * sqlEditEC, * sqlEditHCprice, * sqlEditHCspr;
     
     HolidayPackageSystem::displayRecord("SELECT * FROM HolidayRun");
     
    cout << "\nEnter HolidayRun ID to Edit Holiday Package: " ;
    cin >> HRIDedit;
    
    while(1)
    {
        cout << "\n\nSelect which Field would u like to edit" << endl; 
        cout << "a) Holiday Package (Great/Small/Big Advanture" << endl; 
        cout << "b) Holiday Run Start date" << endl; 
        cout << "c) Holiday Run End date" << endl; 
        cout << "d) Holiday Run Price" << endl; 
        cout << "e) Holiday Run space per run" << endl; 
        cout << "X) Exit" << endl; 
               
        cout << "Enter your option: ";
        cin >> selectEdit;


        switch (selectEdit)
        {
             case 'a':
                     cout <<"Enter Holiday Run Code : ";
                     cin >> HRCodeEdit;
                     sqlEditHC = sqlite3_mprintf("UPDATE HolidayRun set holidayID = '%q' where holidayrunID='%q';", HRCodeEdit.c_str() ,HRIDedit.c_str());
                     HolidayPackageSystem::executeRecord(sqlEditHC); 
                 break;
             case 'b':
                     cout <<"Enter Holiday Run start Date : ";
                     cin >> sDedit;
                     sqlEditSD = sqlite3_mprintf("UPDATE HolidayRun set startDate = '%q' where holidayrunID='%q';", sDedit.c_str() ,HRIDedit.c_str());
                     HolidayPackageSystem::executeRecord(sqlEditSD); 
                 break;
             case 'c':
                     cout <<"Enter Holiday Run End Date : ";
                     cin >> eDEdit;
                     sqlEditEC = sqlite3_mprintf("UPDATE HolidayRun set endDate = '%q' where holidayrunID='%q';", eDEdit.c_str() ,HRIDedit.c_str());
                     HolidayPackageSystem::executeRecord(sqlEditEC); 
                 break;
             case 'd':
                     cout <<"Enter Holiday Run Price : ";
                     cin >> priceEdit;
                     sqlEditHCprice = sqlite3_mprintf("UPDATE HolidayRun set holidayPrice =%f where holidayrunID='%q';", priceEdit,HRIDedit.c_str());
                     HolidayPackageSystem::executeRecord(sqlEditHCprice); 
                 break;
             case 'e':                            
                     cout <<"Enter Holiday Space Per Run : ";
                     cin >> sprEdit;
                     sqlEditHCspr = sqlite3_mprintf("UPDATE HolidayRun set spacePerHRun =%i where holidayrunID='%q';", sprEdit ,HRIDedit.c_str());
                     HolidayPackageSystem::executeRecord(sqlEditHCspr); 
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

bool GeneralManager::deleteHolidayPackage()
{
    string HRID;
    cout << "Enter HolidayRun ID  to delete Holiday Package: " ;
    cin >> HRID;
       
    char * sqldelHR;
    sqldelHR = sqlite3_mprintf("DELETE FROM HolidayRun WHERE holidayrunID='%q'" , HRID.c_str()); 
    
    HolidayPackageSystem::executeRecord(sqldelHR);
    
    cout << "\n\nHoliday Run Package is deleted successfully" << endl;
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
    
    cout << "The staff ID issued to the new emplyee is : ";
    string newID = HolidayPackageSystem::autoID("Staff");
        char * sqlAddstaff;

    sqlAddstaff = sqlite3_mprintf("INSERT INTO Staff VALUES ('%q', '%q', '%q', '%q', '%q', '%i')" ,
                  newID.c_str(), firstName.c_str(), lastName.c_str(), userName.c_str(), password.c_str(), staffLevel); 

    HolidayPackageSystem::executeRecord(sqlAddstaff);
    
    cout << "\n\nStaff Account is added successfully" << endl;
}

bool GeneralManager::editStaff()
{
    HolidayPackageSystem::displayRecord("SELECT * FROM Staff");
    
    string staffID;
    cout << "Enter the StaffID staff to Edit: " ;
    cin >> staffID;
    
     char selectEdit;
     
     string editPassword;
     string editFirstName, editLastNam;
     int editLevel;
     bool breakLoop = false;
     char * sqlEditPwd, * sqlEditFN, * sqlEditLN, * sqlEditSL;
         
    while(1)
    {
        cout << "\n\nSelect which Field would u like to edit" << endl; 
        cout << "a) Password" << endl; 
        cout << "b) First name" << endl; 
        cout << "c) Last name" << endl; 
        cout << "d) Staff Level (1. GM, 2. HM, 3. BS, 4. FM)" << endl; 
        cout << "X) Exit" << endl; 
               
        cout << "Enter your option: ";
        cin >> selectEdit;


        switch (selectEdit)
        {
             case 'a':
                     cout <<"Enter New Password : ";
                     cin >> editPassword;
                     sqlEditPwd = sqlite3_mprintf("UPDATE Staff set staffPassword = '%q' where staffID='%q';", editPassword.c_str() ,staffID.c_str());
                     HolidayPackageSystem::executeRecord(sqlEditPwd); 
                 break;
             case 'b':
                     cout <<"Enter New First name : ";
                     cin >> editFirstName;
                     sqlEditFN = sqlite3_mprintf("UPDATE Staff set staffFirstName = '%q' where staffID='%q';", editFirstName.c_str() ,staffID.c_str());
                     HolidayPackageSystem::executeRecord(sqlEditFN); 
                 break;
             case 'c':
                     cout <<"Enter New Last name : ";
                     cin >> editLastNam;
                     sqlEditLN = sqlite3_mprintf("UPDATE Staff set staffLastName = '%q' where staffID='%q';", editLastNam.c_str() ,staffID.c_str());
                     HolidayPackageSystem::executeRecord(sqlEditLN); 
                 break;
             case 'd':
                     cout <<"Enter New staff Level : ";
                     cin >> editLevel;
                     sqlEditSL = sqlite3_mprintf("UPDATE Staff set staffLevel =%i where staffID='%q';", editLevel ,staffID.c_str());
                     HolidayPackageSystem::executeRecord(sqlEditSL); 
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

bool GeneralManager::deleteStaff()
{
    HolidayPackageSystem::displayRecord("SELECT * FROM Staff");
    int returnVal;
    
    string staffID;
    cout << "Enter the StaffID of staff to delete: " ;
    cin >> staffID;
       
    char * sqldelstaff;
    sqldelstaff = sqlite3_mprintf("DELETE FROM Staff WHERE staffID='%q'" , staffID.c_str()); 
    
    returnVal = HolidayPackageSystem::executeRecord(sqldelstaff);
    
    if(returnVal !=-1)
        cout << "\n\nStaff Account is deleted successfully" << endl;
    else
        cout << "Unexpected error occur, please contact the system admin!" << endl;
}

void GeneralManager::GMmenu()
{
    char gmselect;
    
    cout << "\n\n===========================" << endl;
    cout << "** General Manager Menu **" << endl;
    cout << "===========================" << endl;
    cout << "a) Create Holiday Package" << endl;
    cout << "b) Update Holiday Package" << endl;
    cout << "c) Delete Holiday Package" << endl;
    cout << "d) Create Staff Accounts" << endl;
    cout << "e) Edit Staff Accounts" << endl;
    cout << "f) Delete Staff Accounts" << endl;
    cout << "g) View Statistics" << endl;
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
            updateHolidayPackage();
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
            editStaff();
            GMmenu();
            break;
        case 'f':
            deleteStaff(); 
            GMmenu();
            break;
        case 'g':
            viewStatistic(); 
            GMmenu();
            break;
        case 'x':          
            break;
        default:
            break;
                        
    }
}

bool GeneralManager::viewStatistic()
{
    cout << "a) View Payment Complete Bookings" << endl;
    cout << "b) View Pending Payment Bookings" << endl;      
    cout << "c) View Waiting List Bookings" << endl;
    cout << "Enter your option: " ;
    
    char selectorVS;
    
    cin >> selectorVS;
    
    switch(selectorVS)
    {
        case 'a' :
            HolidayPackageSystem::displayRecord("SELECT * FROM BOOKING where BookingStatus='Complete'");
            break;
        case 'b' :
            HolidayPackageSystem::displayRecord("SELECT * FROM BOOKING where BookingStatus='Payment'");
            break;
        case 'c' :
            HolidayPackageSystem::displayRecord("SELECT * FROM BOOKING where BookingStatus='Waiting'");
            break;
        default:
            break;
    }
}
