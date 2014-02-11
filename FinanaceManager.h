/* 
 * File:   FinanaceManager.h
 * Author: vera
 *
 * Created on February 8, 2014, 10:04 PM
 */

#ifndef FINANACEMANAGER_H
#define	FINANACEMANAGER_H

#include "Staff.h"

class FinanceManager: public Staff {
    public:
        //still don't know need or not
        int processPayment();
        bool processBooking();
        //check full amount the client need to pay
        //deposit included
        float checkTotalAmount();
        //check the blance the client need to pay
        //deposit excluded
        float checkBalance();
        
        static void FMMenu();
};

#endif	/* FINANACEMANAGER_H */

