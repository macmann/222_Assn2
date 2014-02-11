#include "Client.h"

//string Client::getNRIC() 
//void Client::setNRIC(string);
//string Client::getEmail();
//void Client::setEmail(string);
//string Client::getPassword();
//void Client::setPassword(string);
//string Client::getClientFirstName();
//void Client::setClientFirstName(string);
//string Client::getClientLastName();
//void Client::setClientLastName(string);
//string Client::getAddress();
//void Client::setAddress(string sName, string town, string city, string code);

int Client::login() {
    
}

void Client::submitBooking() {
    string holidayID = "", firstName, lastName, specialRequirement = "", nric = "";
    string bookingRefNo = "", bookingDate = "";
    int option = 0;
    float deposit;
    char addNext;
    
    cout << "Choose holiday package by ID: ";
    cin >> holidayID;
    
    cout << "Enter deposit: ";
    cin >> deposit;
    cout << "Enter special treatment: ";
    getline(cin, specialRequirement);
    
    time_t now;
    time ( &now );
    char buffer [20];
    struct tm * Date = localtime(&now);
    
    //  Convert current time to (DDMMYY)  
    strftime (buffer,20,"%d%b%y",Date);
    bookingDate = buffer;
    
    //retrieve new ID for Booking
    bookingRefNo = HolidayPackageSystem::autoID ("Booking");
    
    cout << "Booking ID " << bookingRefNo;
    
    char * sql1 = sqlite3_mprintf("INSERT INTO Booking VALUES ('%q', '%q', '%q', '%f', '%q', 'H003', '01/04/2014', '28/04/2014', 'G12345678K');"
         ,bookingRefNo.c_str(), bookingDate.c_str(), "Pending", deposit, specialRequirement.c_str());
   
     HolidayPackageSystem::insertRecord(sql1);
     
    cout << " 1) Book for yourself\n"\
            " 2) Book for yourself and others\n"\
            " 3) Book for others\n";
    cout << "Choose option: ";
    cin >> option;
    
    /*display client info*/
    if (option == 1 || option == 2) {
        //displayClientInfo();
    }

    /*add passenger info then to Passenger table*/
    if (option == 2 || option == 3) {
        while (true) {
            cout << "Enter passenger NRIC: ";
            cin >> nric;
            cout << "Enter passenger first name: ";
            cin >> firstName;
            cout << "Enter passenger last name:";
            getline(cin, lastName);

            string sqlCommand2 = "INSERT INTO Passenger VALUES ('nric', 'firstName', 'lastName', " + bookingRefNo + ");";
            const char * sql2 = sqlCommand2.c_str();
             
            HolidayPackageSystem::insertRecord(sql2);
            
            cout << "Add more passenger? [y/n]: ";
            cin >> addNext;

            if(addNext == 'n' || addNext == 'N') {
                break;
            }  
            
        }
    }   
    
}

void editBooking();
bool cancelBooking();
