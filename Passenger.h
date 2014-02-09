/* 
 * File:   Passenger.h
 * Author: vera
 *
 * Created on February 8, 2014, 10:21 PM
 */

#ifndef PASSENGER_H
#define	PASSENGER_H

#include <iostream>
using namespace std;

class Passenger {
private:
    string passengerNRIC;
    string passengerFirstName;
    string passengerLastName;
    
public:
    string getPassengerNRIC();
    void setPassengerNRIC(string);
    string getPassengerFirstName();
    void setPassengerFirstName(string);
    string getPassengerLastName();
    void setPassengerLastName(string);
    
};


#endif	/* PASSENGER_H */

