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
         "staffLevel TEXT NOT NULL);";

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
         "INSERT INTO Staff VALUES ('S0004', 'Sharon', 'Lee', 'sharon', 'sharon123', 4);";
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
   sql = "SELECT * from Staff";

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