
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
    cout << "** Finance Manager Menu **" << endl;
    cout << "a) View Pending Payments" << endl;
    cout << "b) View Cancelled Bookings" << endl;
    cout << "Enter your option : ";   
    cin >> fmselect;
    
    switch(fmselect)
    {
        case 'a': 
            break;
        case 'b':
            break;
        default:
            break;
                        
    }
}