/* 
 * File:   Staff.h
 * Author: vera
 *
 * Created on February 8, 2014, 9:52 PM
 */

#ifndef STAFF_H
#define	STAFF_H

#include <iostream>
#include "HolidayPackageSystem.h"
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
       
    //will return staff level
    static int login(string, string);
    //will view according to booking status (waiting, confirmed, etc.)
    static void readRecord(const char* sql);
    static int Authenticate (void *NotUsed, int argc, char **argv, char **azColName);
  

};

#endif	/* STAFF_H */

