/* 
 * File:   HolidayPackageSystem.h
 * Author: vera
 *
 * Created on February 10, 2014, 9:41 PM
 */

#ifndef HOLIDAYPACKAGESYSTEM_H
#define	HOLIDAYPACKAGESYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>

using namespace std;

class HolidayPackageSystem {
public:
    static int callback (void *NotUsed, int argc, char **argv, char **azColName);
    static int countRow (void *NotUsed, int argc, char **argv, char **azColName);
    string autoID (string tableName);
};

#endif	/* HOLIDAYPACKAGESYSTEM_H */

