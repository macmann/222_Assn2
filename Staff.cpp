/* 
 * File:   Staff.cpp
 * Author: kaungsanphyoe
 * 
 * Created on February 11, 2014, 4:02 PM
 */

#include "Staff.h"

string dbUsername, dbPassword;
int staffLVL;

int Staff::login(int selector)
{
    string stfUsr, stfPwd;
    int authenticateValue = -1;

    cout << "Enter Staff username or NRIC : " ;
    cin >> stfUsr;
    
    cout << "Enter password: ";
    cin >> stfPwd;
    
    
    switch (selector)
    {
        case 1: 
            char * sqlAuth;
            sqlAuth = sqlite3_mprintf("SELECT * FROM Staff WHERE staffUserName='%q'", stfUsr.c_str()); 
            readRecord(sqlAuth);
            if(stfPwd == dbPassword)
                authenticateValue = staffLVL;
            break;
        case 2:
             char * sqlAuthClient;
            sqlAuthClient = sqlite3_mprintf("SELECT * FROM Client WHERE NRIC='%q'", stfUsr.c_str()); 
            clientreadRecord(sqlAuthClient);
            if(stfPwd == dbPassword)
                authenticateValue = 5;
            break;
        default:
            break;
    }
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

int Staff::clientAuthenticate (void *NotUsed, int argc, char **argv, char **azColName){
 
    dbUsername = argv[0];
    dbPassword = argv[2];    
    
    return 0;
}

void Staff::clientreadRecord(const char* sql) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   /* Open database */
   rc = sqlite3_open("holiday.db", &db); 
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, clientAuthenticate, 0, &zErrMsg);   
 
   sqlite3_close(db);
}