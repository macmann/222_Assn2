#include "Client.h"

void Client::cMenu() {
    char option;
    
    cout << "** Client Menu **" << endl;
    cout << "a) Submit Booking\nb) Edit Booking\nc) Cancel Booking\n";
    cout << "Enter your option : ";   
    cin >> option;
}

bool Client::submitBooking() {
    string holidayRunID, specialRequirement;
    string  bookingRefNo, bookingDate = "";
    float deposit;
    
    string sqlCommand = "SELECT holidayRunID, holidayType, destinationName, startDate, endDate,  holidayPrice "\
"FROM HolidayPackage INNER JOIN HolidayRun ON HolidayPackage.holidayID = HolidayRun.holidayID "\
"INNER JOIN Destination ON HolidayPackage.destinationCode = Destination.destinationCode;";
    const char *sql = sqlCommand.c_str();
    HolidayPackageSystem::displayRecord(sql);
    
    cout << "Choose holiday package ID: ";
    cin >> holidayRunID;
    cout << "Enter deposit: ";
    cin >> deposit;
    cout << "Enter special treatment: ";
    cin.ignore();
    getline(cin, specialRequirement);
    
    time_t now;
    time ( &now );
    char buffer [20];
    struct tm * Date = localtime(&now);
    
    //  Convert current time to (DDMMYY)  
    strftime (buffer,20,"%d/%m/%Y",Date);
    bookingDate = buffer;
    
    //retrieve new ID for Booking
    bookingRefNo = HolidayPackageSystem::autoID ("Booking");
    
    char * sql1 = sqlite3_mprintf("INSERT INTO Booking VALUES ('%q', '%q', '%q', '%f', '%q', '%q', 'G1111111K');" 
    ,bookingRefNo.c_str(), bookingDate.c_str(), "Pending", deposit, specialRequirement.c_str(), holidayRunID.c_str());
   
     HolidayPackageSystem::executeRecord(sql1);
      
     cout << endl;
}


bool Client::editBooking() {
    int option; 
    float deposit;
    string bookingRefNo, editedValue, sqlCommand1, sqlCommand2;
    char *sqlUpdate;
    //string sqlCommand = "SELECT * FROM Booking WHERE NRIC = " + NRIC;
    
    sqlCommand1 = "SELECT * FROM Booking WHERE NRIC = 'G1111111K'";
    const char * sql = sqlCommand1.c_str();
    HolidayPackageSystem::displayRecord(sql);
    
    cout << "Select by Booking Reference No: ";
    cin >> bookingRefNo;
    
    cout << "(1) Deposit\n(2) Special Requirement\n(3) Holiday Package\n";
    cout << "Select element to be edited : ";
    cin >> option;
    
    if (option == 1 || option == 2) {
        cout << "Enter new value: ";
        cin.ignore();
        getline(cin, editedValue);

        switch(option) {
            case 1: {
                stringstream ss (editedValue);
                ss >> deposit;
                
                sqlUpdate = sqlite3_mprintf("UPDATE Booking Deposit = '%f' WHERE bookingReferenceNo = '%s';"
                , deposit, bookingRefNo.c_str());
                break;
                }
            case 2: {
                sqlUpdate = sqlite3_mprintf("UPDATE Booking specialRequirement = '%s' WHERE bookingReferenceNo = '%s';"
                , editedValue.c_str(), bookingRefNo.c_str());
                break;
                }
            }
    }
    else if (option == 3) {
        
        sqlUpdate = sqlite3_mprintf("UPDATE Booking holidayRunID = '%s' WHERE bookingReferenceNo = '%s';"
        , editedValue.c_str(), bookingRefNo.c_str());

    }
    HolidayPackageSystem::executeRecord (sqlUpdate);
}
    

bool cancelBooking() {
    
}
