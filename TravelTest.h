


#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#define ITERATION3
#define ITERATION2
#define ITERATION1


class TravelTest : public CppUnit::TestFixture
{
    
    CPPUNIT_TEST_SUITE (TravelTest);
    #if defined ITERATION1
    CPPUNIT_TEST (testLogin);
    #endif
    #if defined ITERATION2
    CPPUNIT_TEST (clienttestLogin);
    CPPUNIT_TEST (GMdeletePackage);
    CPPUNIT_TEST (GMaddPackage);
    #endif
    #if defined ITERATION1
    CPPUNIT_TEST (GMdeleteStaff);
    CPPUNIT_TEST (GMaddStaff);
    #endif
    #if defined ITERATION3
    CPPUNIT_TEST (FSconfirmBooking);
    CPPUNIT_TEST (HMprocessBooking);
    CPPUNIT_TEST (BSprocessBooking);
    #endif
    CPPUNIT_TEST_SUITE_END ();
private:
   //  Stock Stk;
public:

protected:
        #if defined ITERATION1
 	void testLogin();
        #endif
        #if defined ITERATION2
        void clienttestLogin();
        void GMaddPackage();
        void GMdeletePackage();
#endif
        #if defined ITERATION1
        void GMaddStaff();
        void GMdeleteStaff();
        #endif
        #if defined ITERATION3
        void FSconfirmBooking();
        void HMprocessBooking();
        void BSprocessBooking();
        #endif
};

