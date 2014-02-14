/* 
 * File:   Client.h
 * Author: vera
 *
 * Created on February 8, 2014, 10:14 PM
 */

#ifndef CLIENT_H
#define	CLIENT_H

#include "HolidayPackageSystem.h"

class Client {
private:
    string NRIC;
    string email;
    string password;
    string clientFirstName;
    string clientLastName;
    string streetName;
    string town;
    string city;
    string postalCode;
    
public:
    
    int login();
    void cMenu();
    bool submitBooking();
    bool editBooking();
    bool cancelBooking();
};


#endif	/* CLIENT_H */

