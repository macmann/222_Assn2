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
    
    int login(string, string);
    void cMenu();
    void submitBooking();
    bool submitBooking (string, float, string);
    void editBooking();
    bool editBooking(int, string, string);
    void cancelBooking();
    bool cancelBooking(string);
    void clientReadRecord(const char* sql);
    static int clientAuthenticate (void *NotUsed, int argc, char **argv, char **azColName);
};


#endif	/* CLIENT_H */
