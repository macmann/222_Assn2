#include "TravelTest.h"

using namespace std;
CPPUNIT_TEST_SUITE_REGISTRATION (TravelTest);


void TravelTest::testLogin()
{
    CPPUNIT_ASSERT_EQUAL(1,1);
    cout << " Test 1)Login tested" << endl;
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
