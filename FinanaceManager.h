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
        void fmMenu();
        bool viewConfirmedBooking();
        bool viewCancelledBooking();
        bool viewPaymentRequiredBooking();
        bool viewConfirmedBooking(string); 
        bool viewCancelledBooking(string);
        bool viewPaymentRequiredBooking(string);
        void processBooking();
        bool confirmBooking(string);
        float calculatePenalty(string);
        static int retrieveData(void *arg, int argc, char **argv, char **azColName);
};

#endif	/* FINANACEMANAGER_H */

