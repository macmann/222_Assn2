/* 
 * File:   Staff.cpp
 * Author: kaungsanphyoe
 * 
 * Created on February 11, 2014, 4:02 PM
 */

#include "Staff.h"

string dbUsername, dbPassword;
int staffLVL;

int Staff::login(string stfUsr, string stfPwd)
{
    int authenticateValue = -1;
    
    char * sqlAuth;
    sqlAuth = sqlite3_mprintf("SELECT * FROM Staff WHERE staffUserName='%q'", stfUsr.c_str()); 
    readRecord(sqlAuth);
    if(stfPwd == dbPassword)
        authenticateValue = staffLVL;

    return authenticateValue;
}


//temp codes

int Staff::Authenticate (void *NotUsed, int argc, char **argv, char **azColName){
 
    string tempStaffLevel;
    dbUsername = argv[3];
    dbPassword = argv[4];
    tempStaffLevel = argv[5];
    
    stringstream ss (tempStaffLevel);
    ss >> staffLVL;
    return 0;
}

void Staff::readRecord(const char* sql) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   /* Open database */
   rc = sqlite3_open("holiday.db", &db); 
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, Authenticate, 0, &zErrMsg);   
 
   sqlite3_close(db);
}
