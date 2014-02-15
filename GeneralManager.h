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
        static bool deleteHolidayPackageSQL(string);

        static bool createStaff();
        static bool editStaff();
        static bool deleteStaff();
        static void GMmenu();
        static bool viewStatistic();
};

#endif	/* GENERALMANAGER_H */

