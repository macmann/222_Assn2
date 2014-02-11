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
        bool createHolidayPackage();
        bool updateHolidayPackage();
        bool deleteHolidayPackage();
        bool createStaff();
        bool editStaff();
        bool deleteStaff();
        void GMmenu();
};

#endif	/* GENERALMANAGER_H */

