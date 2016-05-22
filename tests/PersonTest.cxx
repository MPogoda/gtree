#include <boost/test/unit_test.hpp>

#include <gtree/person.h>
#include <gtree/tree.h>

namespace gtree_test
{
BOOST_AUTO_TEST_SUITE(PersonTestSuite)
    BOOST_AUTO_TEST_CASE( CreatingPersonWithStringDate )
    {
        using gtree::Tree;

        Tree tree{};
        const auto p = tree.createPerson( "Bob", "Dylan", "Duluth", "1941-May-24" );

        BOOST_CHECK_EQUAL( p->firstName(), "Bob" );
        BOOST_CHECK_EQUAL( p->lastName(), "Dylan" );
        BOOST_CHECK_EQUAL( p->location(), "Duluth" );
        BOOST_CHECK_EQUAL( p->dateOfBirth(), "1941-May-24" );
        BOOST_CHECK_EQUAL( p->isRoot(), false );
    }

    BOOST_AUTO_TEST_CASE( CheckParentsOfOnlyPersonInTree )
    {
        using gtree::Tree;

        Tree tree{};
        const auto p = tree.createPerson( "Bob", "Dylan", "Duluth", "1941-May-24" );

        const auto ps = p->parents();
        BOOST_REQUIRE_EQUAL( ps.size(), 1 );

        const auto& parent = ps.front();
        BOOST_CHECK_EQUAL( parent->isRoot(), true );
    }

BOOST_AUTO_TEST_SUITE_END();
} // namespace gtree_test
