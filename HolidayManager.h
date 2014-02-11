/* 
 * File:   HolidayManager.h
 * Author: vera
 *
 * Created on February 8, 2014, 10:00 PM
 */

#ifndef HOLIDAYMANAGER_H
#define	HOLIDAYMANAGER_H

#include "Staff.h"

class HolidayManager: public Staff {
    public:
        bool deleteClientAccount(string nric);
        
        //check holiday per run 
        //if no more space, the client will be in waiting list
        bool checkSpace();
        bool processBooking();
        static void HMmenu();
};

#endif	/* HOLIDAYMANAGER_H */

