/* 
 * File:   Booking.h
 * Author: vera
 *
 * Created on February 8, 2014, 10:25 PM
 */

#ifndef BOOKING_H
#define	BOOKING_H

#include <iostream>
using namespace std;

class Booking {
    string bookingReferenceNo;
    string bookingDate;
    string bookingStatus;
    float deposit;
    string specialRequirement;
    
public:
    string getBookingReferenceNo();
    string getBookingStatus();
    void setBookingStatus(string);
    float getDeposit();
    void setDeposit(float);
    string getSpecialRequirement();
    void setSpecialRequirement(string);
};

#endif	/* BOOKING_H */

