#include "TravelTest.h"
#include "Staff.h"
#include "Client.h"
#include "GeneralManager.h"
#include "FinanaceManager.h"
#include "HolidayManager.h"
#include "BookingStaff.h"

#define ITERATION3
#define ITERATION2
#define ITERATION1

using namespace std;
CPPUNIT_TEST_SUITE_REGISTRATION (TravelTest);

Client c;
FinanceManager fm;

#if defined ITERATION1

void TravelTest::testLogin()
{
    CPPUNIT_ASSERT_EQUAL(Staff::login("james", "james123"),1);
    cout << "Login Successful with correct username and password (GM)" << endl;
    
    CPPUNIT_ASSERT_EQUAL(Staff::login("terence", "terence123"),2);
    cout << "Login Successful with correct username and password (HM)" << endl;
     
    CPPUNIT_ASSERT_EQUAL(Staff::login("mary", "mary123"),3);
    cout << "Login Successful with correct username and password (BS)" << endl;
    
    CPPUNIT_ASSERT_EQUAL(Staff::login("sharon", "sharon123"),4);
    cout << "Login Successful with correct username and password (FS)" << endl;
    
    CPPUNIT_ASSERT_EQUAL(Staff::login(" ", " "),-1);
    cout << "Login without username and password (Fail)" << endl;
    
    CPPUNIT_ASSERT_EQUAL(Staff::login("xxxx", "xxxx"),-1);
    cout << "Login without invalid username and invalid password " << endl;
    
    CPPUNIT_ASSERT_EQUAL(Staff::login("james123", "james"),-1);
    cout << "Login without swapped username and password" << endl;

    CPPUNIT_ASSERT_EQUAL(Staff::login("james", "terence123"),-1);
    cout << "Login without swapped username and password across different accounts" << endl;

    cout << "Test 1)Staff Login tested" << endl;
}

#endif

#if defined ITERATION2

void TravelTest::clienttestLogin()
{
    CPPUNIT_ASSERT_EQUAL(c.login("G1111111K", "vera123"),5);
    CPPUNIT_ASSERT_EQUAL(c.login("S12345678S", "kaung"),5);

    CPPUNIT_ASSERT_EQUAL(c.login(" ", " "),-1);
    CPPUNIT_ASSERT_EQUAL(c.login("xxxx", "xxxx"),-1);
    CPPUNIT_ASSERT_EQUAL(c.login("james", "xxxx"),-1);
    CPPUNIT_ASSERT_EQUAL(c.login("james", "terence123"),-1);

    cout << "Test 2)Client Login tested" << endl;
}

void TravelTest::GMdeletePackage()
{
    GeneralManager::deleteHolidayPackageSQL("R007");
    CPPUNIT_ASSERT_EQUAL(HolidayPackageSystem::executeRecord("SELECT * FROM HolidayRun WHERE HolidayRunID='R007';"), 0);
    cout << "Test 3)Delete Holiday Run Tested" << endl;

}

void TravelTest::GMaddPackage()
{
        GeneralManager::createHolidayPackageSQL("D022", "H001", "12/02/14", "20/02/14", 200, 30);       
        CPPUNIT_ASSERT_EQUAL(HolidayPackageSystem::executeRecord("SELECT * FROM HolidayRun WHERE DestinationCode='D022';"), 1);
        cout << "Test 4)Add Holiday Run Tested" << endl;
}
#endif


#if defined ITERATION1

void TravelTest::GMdeleteStaff()
{
    GeneralManager::deleteStaffSQL("S0004");
    CPPUNIT_ASSERT_EQUAL(HolidayPackageSystem::executeRecord("SELECT * FROM Staff WHERE StaffID='S0004';"), 1);
    cout << "Test 5)Delete Staff Tested" << endl;

}


void TravelTest::GMaddStaff()
{
        GeneralManager::createStaffSQL("Sharon", "Lee", "sharon", "sharon123", 4);       
        CPPUNIT_ASSERT_EQUAL(HolidayPackageSystem::executeRecord("SELECT * FROM Staff WHERE StaffUserName='sharon';"), 1);
        cout << "Test 6)Add Staff Tested" << endl;
}

#endif

#if defined ITERATION3

void TravelTest::FSconfirmBooking()
{
        CPPUNIT_ASSERT_EQUAL(fm.confirmBooking("B00011"), true);
        cout << "Test 7)Finance Staff confirm Booking Tested" << endl;

}

void TravelTest::HMprocessBooking()
{
        HolidayManager::ProcessBookingSQL("Payment", "B00005");        
        CPPUNIT_ASSERT_EQUAL(HolidayPackageSystem::executeRecord("SELECT * FROM Booking where bookingStatus='Payment' AND BookingRefNo='B0005'"), 1);
        cout << "Test 8)Holiday Manager Update Booking Status Tested" << endl;
}

void TravelTest::BSprocessBooking()
{
        BookingStaff::processBookingSQL("Checked", "B00001");
        CPPUNIT_ASSERT_EQUAL(HolidayPackageSystem::executeRecord("SELECT * FROM Booking where bookingStatus='Checked' AND BookingRefNo='B0001'"), 1);
        cout << "Test 9)Booking Staff Update Booking Status Tested" << endl;
}
#endif