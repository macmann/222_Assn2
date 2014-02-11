/* 
 * File:   Staff.h
 * Author: vera
 *
 * Created on February 8, 2014, 9:52 PM
 */

#ifndef STAFF_H
#define	STAFF_H

#include <iostream>
using namespace std;

class Staff {
private:
    string staffID;
    string staffFirstName;
    string staffLastName;
    string staffUserName;
    string staffPassword;
    int staffLevel;
    
public:
    string getStaffID();
    string getStaffPassword();
    void changePassword(string pw);
    //will return staff level
    static int login(int);
    //will view according to booking status (waiting, confirmed, etc.)
    void viewBooking();
};

#endif	/* STAFF_H */

