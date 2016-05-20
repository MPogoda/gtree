#include <boost/test/unit_test.hpp>

#include <gtree/person.h>

#include <boost/date_time/gregorian/gregorian_io.hpp>

namespace gtree_test
{
BOOST_AUTO_TEST_SUITE(PersonTestSuite)
    BOOST_AUTO_TEST_CASE( CreatingPersonWithStringDate )
    {
        using gtree::Person;
        namespace greg = boost::gregorian;

        const Person p{ "Bob", "Dylan", "Duluth", "1941-05-24" };

        BOOST_CHECK_EQUAL( p.firstName(), "Bob" );
        BOOST_CHECK_EQUAL( p.lastName(), "Dylan" );
        BOOST_CHECK_EQUAL( p.location(), "Duluth" );
        BOOST_CHECK_EQUAL( p.dateOfBirth(), Person::Date( 1941, greg::May, 24 ) );
    }

BOOST_AUTO_TEST_SUITE_END();
} // namespace gtree_test
