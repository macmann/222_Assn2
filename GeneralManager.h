/* 
 * File:   GeneralManager.h
 * Author: vera
 *
 * Created on February 8, 2014, 9:58 PM
 */

#ifndef GENERALMANAGER_H
#define	GENERALMANAGER_H

#include "Staff.h"

class GeneralManager : public Staff {
public:
        static bool createHolidayPackage();
        static int createHolidayPackageSQL(string , string , string , string , float , int );
        
        static bool updateHolidayPackage();
        
        static bool deleteHolidayPackage();
        static int deleteHolidayPackageSQL(string);

        static bool createStaff();
        static int createStaffSQL(string, string, string, string, int);

        static bool editStaff();
        
        static bool deleteStaff();
        static bool deleteStaffSQL(string);
        
        static void GMmenu();
        static bool viewStatistic();
};

#endif	/* GENERALMANAGER_H */

