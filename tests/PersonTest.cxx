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

    BOOST_AUTO_TEST_CASE( CheckSimpleHierarchy )
    {
        using gtree::Tree;

        Tree tree{};
        const auto p = tree.createPerson( "Paul", "McCartney", "Liverpool", "1942-Jun-18" );

        do {
            const auto ps = p->parents();
            BOOST_REQUIRE_EQUAL( ps.size(), 1 );

            const auto& parent = ps.front();
            BOOST_CHECK_EQUAL( parent->isRoot(), true );
        } while (0);

        const auto mother = tree.createPerson( "Mary", "Patricia", "", "1909" );
        do {
            const auto ps = mother->parents();
            BOOST_REQUIRE_EQUAL( ps.size(), 1 );

            const auto& parent = ps.front();
            BOOST_CHECK_EQUAL( parent->isRoot(), true );
        } while (0);

        const auto father = tree.createPerson( "James", "McCartney", "", "1902" );
        do {
            const auto ps = father->parents();
            BOOST_REQUIRE_EQUAL( ps.size(), 1 );

            const auto& parent = ps.front();
            BOOST_CHECK_EQUAL( parent->isRoot(), true );
        } while (0);

        p->setParents( mother, father );
        do {
            const auto ps = p->parents();
            BOOST_REQUIRE_EQUAL( ps.size(), 2 );

            const auto& parent1 = ps.front();
            BOOST_CHECK_EQUAL( parent1->isRoot(), false );
            const auto& parent2 = ps.back();
            BOOST_CHECK_EQUAL( parent2->isRoot(), false );
        } while (0);
    }

BOOST_AUTO_TEST_SUITE_END();
} // namespace gtree_test
