


#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>


class TravelTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE (TravelTest);
    CPPUNIT_TEST (testLogin);
    CPPUNIT_TEST (clienttestLogin);
    CPPUNIT_TEST (GMdeletePackage);
    CPPUNIT_TEST (GMaddPackage);
    CPPUNIT_TEST (GMdeleteStaff);
    CPPUNIT_TEST (GMaddStaff);
    CPPUNIT_TEST (FSconfirmBooking);
    CPPUNIT_TEST (HMprocessBooking);
    CPPUNIT_TEST (BSprocessBooking);
    CPPUNIT_TEST_SUITE_END ();
private:
   //  Stock Stk;
public:

protected:
 	void testLogin();
        void clienttestLogin();
        void GMaddPackage();
        void GMdeletePackage();
        void GMaddStaff();
        void GMdeleteStaff();
        void FSconfirmBooking();
        void HMprocessBooking();
        void BSprocessBooking();
};

