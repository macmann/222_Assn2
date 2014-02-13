
/* 
 * File:   FinanceManager.cpp
 * Author: kaungsanphyoe
 *
 * Created on February 11, 2014, 5:10 PM
 */

#include "FinanaceManager.h"

void FinanceManager::FMMenu()
{
    char fmselect;
    
    cout << "===========================" << endl;
    cout << "*** Finance Manager Menu **" << endl;
    cout << "===========================" << endl;

    cout << "a) View Pending Payments" << endl;
    cout << "b) View Cancelled Bookings" << endl;
    cout << "x) Logout" << endl;
    cout << "Enter your option : ";   
    cin >> fmselect;
    
    switch(fmselect)
    {
        case 'a': 
            FMMenu();
            break;
        case 'b':
            FMMenu();
            break;
        case 'x': 
            break;
        default:
            break;
                        
    }
}