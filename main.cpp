/* 
 * File:   main.cpp
 * Author: kaungsanphyoe
 * Reference Example code used from http://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
 *
 * Created on February 5, 2014, 12:09 AM
 */

#include "HolidayPackageSystem.h"
#include "DBInitialization.h"


int main(int argc, char* argv[])
{
    int selector; 
    HolidayPackageSystem h;
    
    while(1)
    {
        cout << "CSCI 222, Test Menu for Database Creation and Reading" << endl;
        cout << "1) Create DB Called User" << endl;
        cout << "2) Insert Data to User DB" << endl;
        cout << "Enter your option: ";
        cin >> selector;
   

        switch (selector)
        {
            case 1: createTable();
                    break;
            case 2: insertRecord();
                    break;
            case 3: readTable();
                    break;
            case 4: editRecord();
                    break;
            case 5: h.autoID ("Staff");
        }
     }

   return 0;
}


