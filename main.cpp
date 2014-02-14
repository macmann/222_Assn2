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


int main(int argc, char* argv[])
{
    int selector; 
    int menuValue;
    HolidayPackageSystem h;
    
    while(1)
    {
        cout << "Holiday Package Management System" << endl;
        cout << "=================================" << endl;
        cout << "1) Login as Staff" << endl;
        cout << "2) Login as Client" << endl;
        cout << "3) Admin Tool: DB Start Initialization" << endl;
        cout << "Enter your option: ";
        cin >> selector;
   

        switch (selector)
        {
            case 1: 
                    menuValue = Staff::login(1);
                    if(menuValue == 1)
                        GeneralManager::GMmenu();
                    else if(menuValue == 2)
                        HolidayManager::HMmenu();
                    else if(menuValue == 3)
                        BookingStaff::BSMenu();
                    else if(menuValue == 4)
                        FinanceManager::FMMenu();
                    else if(menuValue == -1)
                        cout << "Login Unsuccessful! Please try again!" << endl;
                    break;
            case 2: 
                    menuValue = Staff::login(2);
                     if(menuValue == 5)
                         cout << "Client Menu to wait for Vera Commit" << endl;
                        //GeneralManager::GMmenu();
                     else if(menuValue == -1)
                        cout << "Login Unsuccessful! Please try again!" << endl;
                    break;
            case 3: createTable();
                    insertRecord();    
                    break;
            case 4: readTable();
                    break;
            case 5: h.autoID ("Staff");
        }
     }

   return 0;
}


