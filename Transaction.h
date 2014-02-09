/* 
 * File:   Transaction.h
 * Author: vera
 *
 * Created on February 8, 2014, 10:29 PM
 */

#ifndef TRANSACTION_H
#define	TRANSACTION_H

#include <iostream>
using namespace std;

class Transaction {
private:
    string bookingReferenceNo;
    string transactionDate;
    float totalAmount;
    
public:
    string getTransactionDate();
    void setTransactionDate(string);
    float getTotalAmount();
    void setTotalAmount(float);
};

#endif	/* TRANSACTION_H */

