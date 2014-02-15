/* 
 * File:   main.cpp
 * Author: kaungsanphyoe
 * Reference Example code used from http://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
 *
 * Created on February 5, 2014, 12:09 AM
 */

#include "HolidayPackageSystem.h"
#include "DBInitialization.h"
#include "HolidayManager.h"
#include "GeneralManager.h"
#include "BookingStaff.h"
#include "FinanaceManager.h"
#include "Client.h"
#include "TestMain.h"
//#include <windows.h>

int main(int argc, char* argv[])
{
//    ShellExecute(NULL, "open", "http://.net",
 //               NULL, NULL, SW_SHOWNORMAL);
    TestMain test;
    string stfUsr, stfPwd;
    string clientNRIC, clientPwd;
    int selector; 
    int menuValue;
    HolidayPackageSystem h;
    FinanceManager fm;
    Client c;
    
    while(1)
    {
        cout << "SmartTravel Booking Management System" << endl;
        cout << "=================================" << endl;
        cout << "1) Login as Staff" << endl;
        cout << "2) Login as Client" << endl;
        cout << "3) Admin Tool: DB Start Initialization" << endl;
        cout << "4) Admin Tool: CPPUnit Test" << endl;
        cout << "Enter your option: ";
        cin >> selector;
   

        switch (selector)
        {
            case 1: 
                    cout << "Enter username : " ;
                    cin >> stfUsr;

                    cout << "Enter password: ";
                    cin >> stfPwd;
                    
                    menuValue = Staff::login(stfUsr, stfPwd);
                    if(menuValue == 1)
                        GeneralManager::GMmenu();
                    else if(menuValue == 2)
                        HolidayManager::HMmenu();
                    else if(menuValue == 3)
                        BookingStaff::BSMenu();
                    else if(menuValue == 4)
                        fm.fmMenu();
                    else if(menuValue == -1)
                        cout << "Login Unsuccessful! Please try again!" << endl;
                    break;
            case 2: 
                    cout << "Enter NRIC : " ;
                    cin >> clientNRIC;

                    cout << "Enter password: ";
                    cin >> clientPwd;

                    menuValue = c.login(clientNRIC, clientPwd);
                     if(menuValue == 5)
                         c.cMenu();
                     else if(menuValue == -1)
                        cout << "Login Unsuccessful! Please try again!" << endl;
                    break;
            case 3: createTable();
                    insertRecord();    
                    break; 
            case 4: 
                    test.testmain();
                    break;
            default:
                break;
        }
     }

   return 0;
}


