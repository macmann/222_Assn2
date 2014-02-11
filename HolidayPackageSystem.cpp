#include "HolidayPackageSystem.h"

bool isTitleCreated = false;
int rowCount;

int HolidayPackageSystem::callback (void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int HolidayPackageSystem::countRow (void *NotUsed, int argc, char **argv, char **azColName){
 
    string strRowCount;
    strRowCount = argv[0];
   
    stringstream ss (strRowCount);
    ss >> rowCount;
    
   return 0;
}

int HolidayPackageSystem::display (void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   
   if (!isTitleCreated) {
       for (i = 0; i < argc; i++)
            cout << azColName [i] << "\t";
        isTitleCreated = true;
        printf("\n");
   }
   
   for (i = 0; i < argc; i++) 
       cout << argv [i] << "\t"; 
  
   printf("\n");
   return 0;
}

string HolidayPackageSystem::autoID (string tableName){
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   const char* data = "Row count function called";
   string autoID = "";
   
   /* Open database */
   rc = sqlite3_open("holiday.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else
      fprintf(stderr, "Opened database successfully\n");
   
   /* Create SQL statement */   
   string sqlCommand = "SELECT count(*) from " + tableName + ";";

   const char * sql = sqlCommand.c_str();

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, HolidayPackageSystem::countRow, (void*)data, &zErrMsg);
   
   rowCount += 1;
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);

   }else{
       autoID = tableName.at(0);
   
       stringstream ss;
       ss << rowCount;

       string str = ss.str();

       if (tableName.compare("Staff") == 0) {
            string ID = "0000";
            
            autoID += ID.substr(str.size()) + str;
       }
       else if (tableName.compare("Destination") == 0 || tableName.compare("HolidayPackage") == 0) {
            string ID = "000";
            
            autoID += ID.substr(str.size()) + str;
       }
       else if (tableName.compare("Booking") == 0) {

            string bookingID = "000000000";
            
            autoID += bookingID.substr(str.size()) + str;
       }        
       
         cout << autoID << endl; 
   }
   sqlite3_close(db);
   
   return autoID;
}

void HolidayPackageSystem::insertRecord(const char* sql) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;

   /* Open database */
   rc = sqlite3_open("holiday.db", &db);
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }
   else 
      fprintf(stderr, "Opened database successfully\n");
 
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else
      fprintf(stdout, "The record is added successfully\n");
   
   sqlite3_close(db);
}

void HolidayPackageSystem::displayRecord(const char* sql) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;

   /* Open database */
   rc = sqlite3_open("holiday.db", &db);
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }
   else 
      fprintf(stderr, "Opened database successfully\n");
 
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, display, 0, &zErrMsg);
   isTitleCreated = false;
     
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else
      fprintf(stdout, "The record is added successfully\n");
   
   sqlite3_close(db);
}