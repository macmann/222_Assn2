#include "Client.h"

string dbUsernameClient, dbPasswordClient;

void Client::cMenu() {
    char option;
    while (option != 'd') {
        cout << "\n\n=================" << endl;
        cout << "** Client Menu **" << endl;
        cout << "=================" << endl;

        cout << "a) Submit Booking\nb) Edit Booking\nc) Cancel Booking\nd) Exit\n";
        cout << "Enter your option : ";   
        cin >> option;

        switch (option)
        {
            case 'a':
                submitBooking();
                break;
            case 'b':
                editBooking();
                break;
            case 'c':
                cancelBooking();
                break;
        }
    }
}

//client submit booking interface
void Client::submitBooking() {
    string holidayRunID, specialRequirement;
    float deposit;
    
    //join 3 tables to allow user to select holiday package
    string sqlCommand = "SELECT holidayRunID, holidayType, destinationName, startDate, endDate,  holidayPrice "\
    "FROM HolidayPackage INNER JOIN HolidayRun ON HolidayPackage.holidayID = HolidayRun.holidayID "\
    "INNER JOIN Destination ON HolidayPackage.destinationCode = Destination.destinationCode;";
    
    //display the info to allow user to choose holiday package
    const char *sql = sqlCommand.c_str();
    HolidayPackageSystem::displayRecord(sql);
    
    cout << "Choose holiday package ID: ";
    cin >> holidayRunID;
    cout << "Enter deposit: ";
    cin >> deposit;
    cout << "Enter special treatment: ";
    cin.ignore();
    getline(cin, specialRequirement);
    
    submitBooking(holidayRunID, deposit, specialRequirement);
    
}

//add records to booking table 
bool Client::submitBooking(string holidayRunID, float deposit, string specialRequirement) {
    string  bookingRefNo, bookingDate = "";
    time_t now;
    time ( &now );
    char buffer [20];
    struct tm * Date = localtime(&now);
    
    //  Convert current time to (DDMMYY)  
    strftime (buffer,20,"%d/%m/%Y",Date);
    bookingDate = buffer;
    
    //retrieve new ID for Booking
    bookingRefNo = HolidayPackageSystem::autoID ("Booking");
    
    char * sql1 = sqlite3_mprintf("INSERT INTO Booking VALUES ('%q', '%q', '%q', '%f', '%q', '%q', '%q');" 
    ,bookingRefNo.c_str(), bookingDate.c_str(), "Pending", deposit, specialRequirement.c_str(), holidayRunID.c_str(), dbUsernameClient.c_str());
   
     HolidayPackageSystem::executeRecord(sql1);
     cout << "The booking is submitted successfully!" << endl;
     return true;
     
}

//interface of edit booking for client
void Client::editBooking() {
    int option; 
    string bookingRefNo, editedValue;
    
    char * sql = sqlite3_mprintf("SELECT * FROM Booking WHERE NRIC = '%q' AND BookingStatus <> 'Confirmed';", dbUsernameClient.c_str());
    HolidayPackageSystem::displayRecord(sql);
    
    cout << "Select Booking Reference No: ";
    cin >> bookingRefNo;
    
    cout << "(1) Deposit\n(2) Special Requirement\n(3) Holiday Package\n";
    cout << "Select element to be edited : ";
    cin >> option;
    
    cout << "Enter new value: ";
    cin.ignore();
    getline(cin, editedValue);
    
    editBooking(option, bookingRefNo, editedValue);
}

//update the data the clients edited to table
bool Client::editBooking (int option, string bookingRefNo, string editedValue) {
    float deposit;
    char *sqlUpdate;
    
    if (option == 1 || option == 2) {

        switch(option) {
            case 1: {
                stringstream ss (editedValue);
                ss >> deposit;
                
                sqlUpdate = sqlite3_mprintf("UPDATE Booking SET Deposit = '%f' WHERE bookingRefNo = '%s';"
                , deposit, bookingRefNo.c_str());
                break;
               }
            case 2: {
                sqlUpdate = sqlite3_mprintf("UPDATE Booking SET specialRequirement = '%s' WHERE bookingRefNo = '%s';"
                , editedValue.c_str(), bookingRefNo.c_str());
                break;
               }
            }
    }
    else if (option == 3) {
        
        sqlUpdate = sqlite3_mprintf("UPDATE Booking SET holidayRunID = '%s' WHERE bookingRefNo = '%s';"
        , editedValue.c_str(), bookingRefNo.c_str());

    }
    
    HolidayPackageSystem::executeRecord (sqlUpdate);
    char * sql = sqlite3_mprintf("SELECT * FROM Booking WHERE NRIC = '%q' AND BookingStatus <> 'Confirmed';", dbUsernameClient.c_str());
    HolidayPackageSystem::displayRecord(sql);
    return true;
}
    
//cancel booking interface
void Client::cancelBooking() {
    string bookingRefNo;
    
    char * sql = sqlite3_mprintf("SELECT * FROM Booking WHERE NRIC = '%q';", dbUsernameClient.c_str());
    HolidayPackageSystem::displayRecord(sql);
    
    cout << "Select Booking Reference No: ";
    cin >> bookingRefNo;
    cancelBooking(bookingRefNo);

}

//allow client to cancel booking
bool Client::cancelBooking(string bookingRefNo) {
    
    time_t now;
    time ( &now );
    char buffer [20];
    struct tm * Date = localtime(&now);
    
    //  Convert current time to (DDMMYY)  
    strftime (buffer,20,"%d/%m/%Y",Date);
    string bookingDate = buffer;
  
    //when the booking is cancelled, the booking date is also updated to the date 
    //the booking is cancelled so that the Finance Manager will be able to compute
    //the penalty the client has to pay
    char *sqlUpdate = sqlite3_mprintf("UPDATE Booking SET BookingStatus = 'Cancelled', BookingDate = '%s' WHERE bookingRefNo = '%s';"
    ,bookingDate.c_str(), bookingRefNo.c_str());

    HolidayPackageSystem::executeRecord (sqlUpdate);
    char * sql = sqlite3_mprintf("SELECT * FROM Booking WHERE NRIC = '%q';", dbUsernameClient.c_str());
    HolidayPackageSystem::displayRecord(sql);
}


int Client::login() {
     string clientNRIC, clientPwd;
    int authenticateValue = -1;

    cout << "Enter NRIC : " ;
    cin >> clientNRIC;
    
    cout << "Enter password: ";
    cin >> clientPwd;
    
        char * sqlAuthClient;
            sqlAuthClient = sqlite3_mprintf("SELECT * FROM Client WHERE NRIC='%q'", clientNRIC.c_str()); 
            clientReadRecord(sqlAuthClient);
            if(clientPwd == dbPasswordClient)
                authenticateValue = 5;
            
     return authenticateValue;
}

//retrieve the client user name and password
int Client::clientAuthenticate (void *NotUsed, int argc, char **argv, char **azColName){
 
    dbUsernameClient = argv[0];
    dbPasswordClient = argv[2];    
    
    return 0;
}

void Client::clientReadRecord(const char* sql) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   /* Open database */
   rc = sqlite3_open("holiday.db", &db); 
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, clientAuthenticate, 0, &zErrMsg);   
 
   sqlite3_close(db);
}