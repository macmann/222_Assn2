


#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>


class TravelTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE (TravelTest);
    CPPUNIT_TEST (testLogin);
    CPPUNIT_TEST_SUITE_END ();
private:
   //  Stock Stk;
public:

protected:
 	void testLogin();
};

