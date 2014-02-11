/* 
 * File:   BookingStaff.h
 * Author: vera
 *
 * Created on February 8, 2014, 10:03 PM
 */

#ifndef BOOKINGSTAFF_H
#define	BOOKINGSTAFF_H

#include "Staff.h"

class BookingStaff: public Staff {
    public:
        bool createClientAccount();
        bool editClientAccount();
        bool processBooking();
        static void BSMenu();
};

#endif	/* BOOKINGSTAFF_H */

