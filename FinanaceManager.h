/* 
 * File:   FinanaceManager.h
 * Author: vera
 *
 * Created on February 8, 2014, 10:04 PM
 */

#ifndef FINANACEMANAGER_H
#define	FINANACEMANAGER_H

#include "Staff.h"

class FinanceManager: public Staff {
    public:
        static void fmMenu();
        static bool viewConfirmedBooking();
        static bool viewCancelledBooking();
        static bool viewPaymentRequiredBooking();
        static bool viewConfirmedBooking(string); 
        static bool viewCancelledBooking(string);
        static bool viewPaymentRequiredBooking(string);
        static void processBooking();
        static bool confirmBooking(string);
        float calculatePenalty(string);
        static int retrieveData(void *arg, int argc, char **argv, char **azColName);
};

#endif	/* FINANACEMANAGER_H */
