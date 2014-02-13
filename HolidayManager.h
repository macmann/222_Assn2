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
        static bool deleteClientAccount(string nric);
        
        //check holiday per run 
        //if no more space, the client will be in waiting list
        static bool checkSpace();
        static bool processBooking();
        static void HMmenu();
};

#endif	/* HOLIDAYMANAGER_H */

