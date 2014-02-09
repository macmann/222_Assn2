/* 
 * File:   HolidayRun.h
 * Author: vera
 *
 * Created on February 8, 2014, 10:12 PM
 */

#ifndef HOLIDAYRUN_H
#define	HOLIDAYRUN_H

#include <iostream>
using namespace std;

class HolidayRun {
private:
    string holidayID;
    string startDate;
    string endDate;
    float holidayPrice;
    int spacePerHRun;
    
public:
    string getHolidayID();
    string getStartDate();
    void setStartDate(string);
    string getEndDate();
    void setEndDate(string);
    float getHolidayPrice();
    void setHolidayPrice(float);
    int getSpacePerHRun();
    void setSpacePerHRun(int);
};

#endif	/* HOLIDAYRUN_H */

