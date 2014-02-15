#include "TravelTest.h"
#include "Staff.h"
#include "Client.h"
#include "GeneralManager.h"
using namespace std;
CPPUNIT_TEST_SUITE_REGISTRATION (TravelTest);


void TravelTest::testLogin()
{
    CPPUNIT_ASSERT_EQUAL(Staff::login("james", "james123"),1);
    CPPUNIT_ASSERT_EQUAL(Staff::login("terence", "terence123"),2);
    CPPUNIT_ASSERT_EQUAL(Staff::login("mary", "mary123"),3);
    CPPUNIT_ASSERT_EQUAL(Staff::login("sharon", "sharon123"),4);
    CPPUNIT_ASSERT_EQUAL(Staff::login(" ", " "),-1);
    CPPUNIT_ASSERT_EQUAL(Staff::login("xxxx", "xxxx"),-1);
    CPPUNIT_ASSERT_EQUAL(Staff::login("james123", "james"),-1);
    CPPUNIT_ASSERT_EQUAL(Staff::login("james", "terence123"),-1);

    cout << "Test 1)Staff Login tested" << endl;
}

void TravelTest::clienttestLogin()
{
    CPPUNIT_ASSERT_EQUAL(Client::login("G1111111K", "vera123"),5);
    CPPUNIT_ASSERT_EQUAL(Client::login("S1234567S", "kaung123"),5);

    CPPUNIT_ASSERT_EQUAL(Client::login(" ", " "),-1);
    CPPUNIT_ASSERT_EQUAL(Client::login("xxxx", "xxxx"),-1);
    CPPUNIT_ASSERT_EQUAL(Client::login("james", "xxxx"),-1);
    CPPUNIT_ASSERT_EQUAL(Client::login("james", "terence123"),-1);

    cout << "Test 2)Client Login tested" << endl;
}



void TravelTest::GMdeletePackage()
{
    GeneralManager::deleteHolidayPackageSQL("R007");
    CPPUNIT_ASSERT_EQUAL(HolidayPackageSystem::executeRecord("SELECT * FROM HolidayRun WHERE HolidayRunID='R007';"), 0);
    cout << "Test 4)Delete Holiday Run Tested" << endl;

}


void TravelTest::GMaddPackage()
{
        GeneralManager::createHolidayPackageSQL("D022", "H001", "12/02/14", "20/02/14", 200, 30);       
        CPPUNIT_ASSERT_EQUAL(HolidayPackageSystem::executeRecord("SELECT * FROM HolidayRun WHERE DestinationCode='D022';"), 1);
        cout << "Test 3)Add Holiday Run Tested" << endl;
}


/*
// Test the existence of the Product
void POSTest::testSeachProduct()
{
    CPPUNIT_ASSERT_EQUAL(Stk.SearchProduct("001"),1);
    CPPUNIT_ASSERT_EQUAL(Stk.SearchProduct("002"),0);
    CPPUNIT_ASSERT_EQUAL(Stk.SearchProduct("003"),1);
        
    cout << " Test 1)testSearchProduct tested" << endl;
}

// Test the successful of adding product
void POSTest::testAddProduct()
{   
    Stk.AddProduct("011","Hero", "MobilePhone",
                    "HTC","890", "150");
    string toTest ="011:Hero:MobilePhone:HTC:890:150";
    CPPUNIT_ASSERT_EQUAL(Stk.SearchProduct(toTest),1);
    cout << " Test 2)testAddProduct tested" << endl;
}

// Test the successful of edit product information
void POSTest::testEditProduct()
{   
    Stk.EditStock("Window","Linux");
    CPPUNIT_ASSERT_EQUAL(Stk.SearchProduct("Linux"),1);
    cout << " Test 3)testEditProduct tested" << endl;
}

// Test the successful of delete a product
void POSTest::testDeleteProduct()
{   
    Stk.DeleteProduct("011");
    CPPUNIT_ASSERT_EQUAL(Stk.SearchProduct("011"),0);
    cout << " Test 4) testDeleteProduct tested" << endl;
}


*/
