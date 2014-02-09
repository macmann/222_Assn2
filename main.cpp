/* 
 * File:   main.cpp
 * Author: kaungsanphyoe
 * Reference Example code used from http://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
 *
 * Created on February 5, 2014, 12:09 AM
 */
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <iostream>
#include <string>

using namespace std;

void createTable();
void insertTabale();
void readTable();
void editTable();

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main(int argc, char* argv[])
{
    int selector; 
    
    while(1)
    {
        cout << "CSCI 222, Test Menu for Database Creation and Reading" << endl;
        cout << "1) Create DB Called User" << endl;
        cout << "2) Insert Data to User DB" << endl;
        cout << "3) Read Data from User DB" << endl;
        cout << "Enter your option: ";
        cin >> selector;
   

        switch (selector)
        {
            case 1: createTable();
                    break;
            case 2: insertTabale();
                    break;
            case 3: readTable();
                    break;
            case 4: editTable();
                    break;
        }
     }

   return 0;
}


void createTable()
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int  rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("holiday.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stdout, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "CREATE TABLE Staff("  \
         "staffID TEXT PRIMARY KEY," \
         "staffFirstName TEXT NOT NULL," \
         "staffLastName TEXT NOT NULL," \
         "staffUserName TEXT NOT NULL," \
         "staffPassword TEXT NOT NULL," \
         "staffLevel TEXT NOT NULL);" \
                                        
         "CREATE TABLE Destination(" \
         "destinationCode TEXT PRIMARY KEY," \
        "destinationName TEXT NOT NULL);" \

        "CREATE TABLE HolidayPackage(" \
        "holidayID TEXT PRIMARY KEY," \
        "holidayType TEXT NOT NULL," \
        "destinationCode TEXT," \
        "FOREIGN KEY (destinationCode) REFERENCES Destination (destinationCode));" \

        "CREATE TABLE HolidayRun(" \
        "holidayID TEXT," \
        "startDate TEXT NOT NULL," \
        "endDate TEXT NOT NULL," \
        "holidayPrice REAL," \
        "spacePerHRun INT," \
        "PRIMARY KEY (holidayID, startDate, endDate)," \
        "FOREIGN KEY (holidayID) REFERENCES HolidayPackage (holidayID));" \


        "CREATE TABLE Client(" \
        "NRIC TEXT PRIMARY KEY," \
        "email TEXT NOT NULL," \
        "password TEXT NOT NULL," \
        "clientFirstName TEXT," \
        "clientLastName TEXT," \
        "streetName TEXT," \
        "town TEXT," \
        "city TEXT," \
        "postalCode TEXT);" \

        "CREATE TABLE Booking(" \
        "bookingReferenceNo TEXT PRIMARY KEY," \
        "bookingDate TEXT NOT NULL," \
        "bookingStatus TEXT NOT NULL," \
        "deposit REAL," \
        "specialRequirement TEXT," \
        "holidayID TEXT NOT NULL," \
        "startDate TEXT NOT NULL," \
        "endDate TEXT NOT NULL," \
        "NRIC TEXT NOT NULL," \
        "FOREIGN KEY (holidayID, startDate, endDate) REFERENCES HolidayRun (holidayID, startDate, endDate)," \
        "FOREIGN KEY (NRIC) REFERENCES Booking (NRIC));" \

        "CREATE TABLE Passenger(" \
        "passengerNRIC TEXT PRIMARY KEY," \
        "passengerFirstName TEXT," \
        "passengerLastName TEXT," \
        "bookingReferenceNo TEXT," \
        "FOREIGN KEY (bookingReferenceNo) REFERENCES Booking (bookingReferenceNo));" \

        "CREATE TABLE TRANS(" \
        "bookingReferenceNo TEXT," \
        "transactionDate TEXT," \
        "totalAmount REAL," \
        "PRIMARY KEY (bookingReferenceNo, transactionDate),"
        "FOREIGN KEY (bookingReferenceNo) REFERENCES Booking (bookingReferenceNo));" ;
/*
        "CREATE TABLE Transaction(" \
        "bookingReferenceNo TEXT NOT NULL," \
        "transactionDate TEXT NOT NULL," \
        "totalAmount REAL," \
        "PRIMARY KEY (bookingReferenceNo, transactionDate),";
        "FOREIGN KEY (bookingReferenceNo) REFERENCES Booking (bookingReferenceNo) );";*/
           
   
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
   fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Table created successfully\n");
   }
   sqlite3_close(db);
}

void insertTabale()
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("holiday.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "INSERT INTO Staff VALUES ('S0001', 'James', 'Tan', 'james', 'james123', 1);" \
         "INSERT INTO Staff VALUES ('S0002',  'Terence', 'Choo', 'terence', 'terence123', 2);"\
         "INSERT INTO Staff VALUES ('S0003', 'Mary', 'Khoo', 'mary', 'mary123', 3);"\
         "INSERT INTO Staff VALUES ('S0004', 'Sharon', 'Lee', 'sharon', 'sharon123', 4);" \

        "INSERT INTO Destination VALUES ('D001', 'Korea');" \
        "INSERT INTO Destination VALUES ('D002', 'Japan');" \
        "INSERT INTO Destination VALUES ('D003', 'Hawaii');" \

        "INSERT INTO HolidayPackage VALUES ('H001', 'Great Adventure', 'D002');" \
        "INSERT INTO HolidayPackage VALUES ('H002', 'Small Adventure', 'D001');" \
        "INSERT INTO HolidayPackage VALUES ('H003', 'Big Adventure', 'D003');" \

        "INSERT INTO HolidayRun VALUES ('H002', '09/02/2014', '11/02/2014', 3000, 50);" \
        "INSERT INTO HolidayRun VALUES ('H002', '01/03/2014', '03/03/2014', 3500, 30);" \
        "INSERT INTO HolidayRun VALUES ('H003', '01/04/2014', '28/03/2014', 20000, 60);" \
        "INSERT INTO HolidayRun VALUES ('H002', '16/02/2014', '01/03/2014', 7000, 40);" \


        "INSERT INTO Client VALUES ('G12345678K', 'vera@gmail.com', 'vera123', 'Vera', 'Aung', 'Clementi St', 'Clementi', 'Singapore', 'S120111');" \
        "INSERT INTO Client VALUES ('S12345678D', 'kristy@gmail.com', 'kristy123', 'Kristy', 'Win', 'Punggol St', 'Punggol', 'Singapore', 'S234567');" \


        "INSERT INTO Booking VALUES('RF00000012', '09/02/2014', 'Waiting', 200, '-', 'H003', '01/04/2014', '28/04/2014', 'G12345678K');" \
        "INSERT INTO Booking VALUES('RF00000009', '07/02/2014', 'Confirmed', 500, '-', 'H002', '01/03/2014', '03/03/2014', 'S12345678D');" \


        "INSERT INTO Passenger VALUES ('A12345678K', 'Jasmine', 'Tan', 'RF00000009');" \
        "INSERT INTO Passenger VALUES ('S12345678D', 'Kristy', 'Win', 'RF00000009');" \

        "INSERT INTO TRANS VALUES ('RF00000009', '07/02/2014', 7000);";


   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Records created successfully\n");
   }
   sqlite3_close(db);
}


void readTable()
{
    
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   const char* data = "Callback function called";

   /* Open database */
   rc = sqlite3_open("holiday.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "SELECT * from TRANS";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Operation done successfully\n");
   }
   sqlite3_close(db);
}

void editTable()
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   const char* data = "Callback function called";

   /* Open database */
   rc = sqlite3_open("holiday.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create merged SQL statement */
   
   char s[20] = "teststring";
   
   sql = sqlite3_mprintf("UPDATE Staff set staffPassword = '%q' where staffID='S0001'; " \ 
         "SELECT * from Staff", s);
 //  sql = "UPDATE Staff set staffPassword = 'test' where staffID='S0001'; " \ 
  //       "SELECT * from Staff";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Operation done successfully\n");
   }
   sqlite3_close(db);
}