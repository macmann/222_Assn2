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
        static bool createClientAccount();
        static bool editClientAccount();
        static bool processBooking();
        static bool processBookingSQL(string, string);
        static void BSMenu();
};

#endif	/* BOOKINGSTAFF_H */

