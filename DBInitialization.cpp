/* 
 * File:   DBInitialization.cpp
 * Author: kaungsanphyoe
 *
 * Created on February 11, 2014, 5:10 PM
 */

#include "DBInitialization.h"

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
        "StaffID TEXT PRIMARY KEY," \
        "StaffFirstName TEXT NOT NULL," \
        "StaffLastName TEXT NOT NULL," \
        "StaffUserName TEXT NOT NULL," \
        "StaffPassword TEXT NOT NULL," \
        "StaffLevel TEXT NOT NULL);" \

        "CREATE TABLE Destination(" \
        "DestinationCode TEXT PRIMARY KEY," \
        "DestinationName TEXT NOT NULL);" \

        "CREATE TABLE HolidayPackage(" \
        "HolidayID TEXT PRIMARY KEY," \
        "HolidayType TEXT NOT NULL," \
        "DestinationCode TEXT," \
        "FOREIGN KEY (destinationCode) REFERENCES Destination (destinationCode));" \

        "CREATE TABLE Client(" \
        "NRIC TEXT PRIMARY KEY," \
        "Email TEXT NOT NULL," \
        "Password TEXT NOT NULL," \
        "ClientFirstName TEXT," \
        "ClientLastName TEXT," \
        "StreetName TEXT," \
        "Town TEXT," \
        "City TEXT," \
        "PostalCode TEXT);" \

        "CREATE TABLE HolidayRun(" \
        "HolidayRunID TEXT NOT NULL," \
        "HolidayID TEXT," \
        "DestinationCode TEXT," \
        "StartDate TEXT NOT NULL," \
        "EndDate TEXT NOT NULL," \
        "HolidayPrice REAL," \
        "SpacePerHRun INT," \
        "PRIMARY KEY (holidayrunID)," \
        "FOREIGN KEY (destinationCode) REFERENCES Destination (destinationCode)," \
        "FOREIGN KEY (holidayID) REFERENCES HolidayPackage (holidayID));" \
        
        "CREATE TABLE Booking(" \
        "BookingRefNo TEXT PRIMARY KEY," \
        "BookingDate TEXT NOT NULL," \
        "BookingStatus TEXT NOT NULL," \
        "Deposit REAL," \
        "SpecialRequirement TEXT," \
        "HolidayrunID TEXT NOT NULL," \
        "NRIC TEXT NOT NULL," \
        "FOREIGN KEY (holidayrunID) REFERENCES HolidayRun (holidayrunID)," \
        "FOREIGN KEY (NRIC) REFERENCES Booking (NRIC));";
   
   
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, HolidayPackageSystem::callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
   fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Table created successfully\n");
   }
   sqlite3_close(db);
}

void insertRecord()
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

        "INSERT INTO HolidayRun VALUES ('R001', 'H002', 'D001', '09/02/2014', '11/02/2014', 3000, 50);" \
        "INSERT INTO HolidayRun VALUES ('R002', 'H002', 'D002', '01/03/2014', '03/03/2014', 3500, 30);" \
        "INSERT INTO HolidayRun VALUES ('R003', 'H003', 'D003', '01/04/2014', '28/03/2014', 20000, 60);" \
        "INSERT INTO HolidayRun VALUES ('R004', 'H002', 'D001', '16/02/2014', '01/03/2014', 7000, 40);" \

        "INSERT INTO Client VALUES ('G1111111K', 'vera@gmail.com', 'vera123', 'Vera', 'Aung', 'Clementi Ave St', 'Clementi', 'Singapore', 'SG111111');";
        "INSERT INTO Client VALUES ('S12345678S', 'kaung@gmail.com', 'kaung', 'Kaung', 'San Phyoe', 'Lan Bay St', 'La Har Pyin', 'Nay Pyi Taw', 'M234567');" \

        "INSERT INTO Booking VALUES('B00001', '09/02/2014', 'Waiting', 200, '-', 'R001', 'G12345678K');" \
        "INSERT INTO Booking VALUES('B00002', '07/02/2014', 'Confirmed', 500, '-', 'R002', 'S12345678D');" \
        "INSERT INTO Booking VALUES('B00003', '07/02/2014', 'Checked', 500, '-', 'R002', 'S12345678D');" \
        "INSERT INTO Booking VALUES('B00004', '07/02/2014', 'Complete', 500, '-', 'R004', 'S12345678D');" \
        "INSERT INTO Booking VALUES('B00005', '07/02/2014', 'Complete', 900, '-', 'R003', 'S12345678D');";


   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, HolidayPackageSystem::callback, 0, &zErrMsg);
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
   sql = "SELECT * from Staff;";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, HolidayPackageSystem::callback, (void*)data, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
       cout << "rc: " << rc << endl;
       //printf(stdout, ":D");
     // fprintf(stdout, "Operation done successfully\n");
   }
   sqlite3_close(db);
}

void editRecord()
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
   rc = sqlite3_exec(db, sql, HolidayPackageSystem::callback, (void*)data, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Operation done successfully\n");
   }
   sqlite3_close(db);
}