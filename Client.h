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
    
    static int login();
    static void cMenu();
    static bool submitBooking();
    static bool editBooking();
    static bool cancelBooking();
       // for client
    static void clientReadRecord(const char* sql);
    static int clientAuthenticate (void *NotUsed, int argc, char **argv, char **azColName);
};


#endif	/* CLIENT_H */

