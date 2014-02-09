/* 
 * File:   HolidayPackage.h
 * Author: vera
 *
 * Created on February 8, 2014, 10:07 PM
 */

#ifndef HOLIDAYPACKAGE_H
#define	HOLIDAYPACKAGE_H

#include <iostream>
using namespace std;

class HolidayPackage {
private:
    string holidayID;
    string holidayType;
    
public:
    string getHolidayPackageID();
    void setHolidayPackageID(string id);
    string getHolidayType();
    void setHolidayType(string type);
};

#endif	/* HOLIDAYPACKAGE_H */

