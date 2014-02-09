/* 
 * File:   Client.h
 * Author: vera
 *
 * Created on February 8, 2014, 10:14 PM
 */

#ifndef CLIENT_H
#define	CLIENT_H

#include <iostream>
using namespace std;

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
    string getNRIC();
    void setNRIC(string);
    string getEmail();
    void setEmail(string);
    string getPassword();
    void setPassword(string);
    string getClientFirstName();
    void setClientFirstName(string);
    string getClientLastName();
    void setClientLastName(string);
    string getAddress();
    void setAddress(string sName, string town, string city, string code);
    int login();
    void submitBooking();
    void editBooking();
    bool cancelBooking();
    
};


#endif	/* CLIENT_H */

