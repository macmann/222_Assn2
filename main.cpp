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


int main(int argc, char* argv[])
{
    int selector; 
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
                    Staff::login(1);
                    
                    break;
            case 2: 
                    break;
            case 3: createTable();
                    insertRecord();    
                    break;
            case 4: editRecord();
                    break;
            case 5: h.autoID ("Staff");
        }
     }

   return 0;
}


