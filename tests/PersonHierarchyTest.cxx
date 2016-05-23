#include <boost/test/unit_test.hpp>

#include <gtree/person.h>
#include <gtree/tree.h>

#include <exception>

namespace gtree_test
{
using gtree::Tree;
using PersonPtr = gtree::Tree::PersonPtr;

struct PaulFixture
{
    PaulFixture()
        : tree{}
        , paul{ tree.createPerson( "Paul", "McCartney", "Liverpool", "1942-Jun-18" ) }
        , mother{ tree.createPerson( "Mary", "Patricia", "", "1909" ) }
        , father{ tree.createPerson( "James", "McCartney", "", "1902" ) }
    {
        paul->setParents( mother, father );
    }

    Tree tree;
    PersonPtr paul;
    PersonPtr mother;
    PersonPtr father;
}; // struct PaulFixture

BOOST_FIXTURE_TEST_SUITE( PersonHierarchyTestSuite, PaulFixture )
    BOOST_AUTO_TEST_CASE( CheckInitialPropertiesOfTestSuite )
    {
        BOOST_CHECK_EQUAL( paul->firstName(), "Paul" );
        BOOST_CHECK_EQUAL( paul->lastName(), "McCartney" );
        BOOST_CHECK_EQUAL( paul->location(), "Liverpool" );
        BOOST_CHECK_EQUAL( paul->dateOfBirth(), "1942-Jun-18" );
        BOOST_TEST( !paul->isRoot() );

        BOOST_CHECK_EQUAL( mother->firstName(), "Mary" );
        BOOST_CHECK_EQUAL( mother->lastName(), "Patricia" );
        BOOST_CHECK_EQUAL( mother->location(), "" );
        BOOST_CHECK_EQUAL( mother->dateOfBirth(), "1909" );
        BOOST_TEST( !mother->isRoot() );

        BOOST_CHECK_EQUAL( father->firstName(), "James" );
        BOOST_CHECK_EQUAL( father->lastName(), "McCartney" );
        BOOST_CHECK_EQUAL( father->location(), "" );
        BOOST_CHECK_EQUAL( father->dateOfBirth(), "1902" );
        BOOST_TEST( !father->isRoot() );

        do {
            const auto ps = paul->parents();
            BOOST_REQUIRE_EQUAL( ps.size(), 2 );
            const auto& parent1 = *ps.cbegin();
            BOOST_TEST( !parent1->isRoot() );
            const auto& parent2 = *std::next( ps.cbegin() );
            BOOST_TEST( !parent2->isRoot() );

            BOOST_TEST( ((parent1 == father) || (parent2 == father)));
            BOOST_TEST( ((parent1 == mother) || (parent2 == mother)));
            BOOST_TEST( parent1 != parent2 );
        } while (0);

        do {
            const auto ps = mother->parents();
            BOOST_REQUIRE_EQUAL( ps.size(), 1 );
            BOOST_TEST( (*ps.cbegin())->isRoot() );
        } while (0);

        do {
            const auto ps = father->parents();
            BOOST_REQUIRE_EQUAL( ps.size(), 1 );
            BOOST_TEST( (*ps.cbegin())->isRoot() );
        } while (0);
    }

    BOOST_AUTO_TEST_CASE( CheckThatPaulHasNoChildren )
    {
        const auto children = paul->children();

        BOOST_TEST( children.empty() );
    }

    BOOST_AUTO_TEST_CASE( CheckThatPaulParentsHaveOneChild)
    {
        do {
            const auto children = father->children();

            BOOST_REQUIRE_EQUAL( children.size(), 1 );

            const auto child = *children.cbegin();

            BOOST_CHECK_EQUAL( child, paul );
        } while (0);

        do {
            const auto children = mother->children();

            BOOST_REQUIRE_EQUAL( children.size(), 1 );

            const auto child = *children.cbegin();

            BOOST_CHECK_EQUAL( child, paul );
        } while (0);
    }

    BOOST_AUTO_TEST_CASE( CheckThatPaulParentsHaveTwoChildren )
    {
        const auto michael = tree.createPerson( "Michael", "McCartney", "Liverpool", "1944-Jan-07" );
        michael->setParents( father, mother );

        do {
            const auto children = father->children();

            BOOST_REQUIRE_EQUAL(  children.size(), 2 );

            const auto child1 = *children.cbegin();
            const auto child2 = *std::next( children.cbegin() );

            BOOST_TEST( ((child1 == paul) || (child2 == paul)) );
            BOOST_TEST( ((child1 == michael) || (child2 == michael)) );
            BOOST_TEST( child1 != child2 );
        } while (0);

        do {
            const auto children = mother->children();

            BOOST_REQUIRE_EQUAL(  children.size(), 2 );

            const auto child1 = *children.cbegin();
            const auto child2 = *std::next( children.cbegin() );

            BOOST_TEST( ((child1 == paul) || (child2 == paul)) );
            BOOST_TEST( ((child1 == michael) || (child2 == michael)) );
            BOOST_TEST( child1 != child2 );
        } while (0);
    }

    BOOST_AUTO_TEST_CASE( CheckThatPaulParentsIsBeingUpdated )
    {
        const auto father2 = tree.createPerson( "dummyFather", "", "", "" );

        paul->setParents( mother, father2 );

        const auto parents = paul->parents();

        BOOST_REQUIRE_EQUAL( parents.size(), 2 );
        const auto p1 = *parents.cbegin();
        const auto p2 = *std::next( parents.cbegin() );

        BOOST_TEST( ((p1 == father2) || (p2 == father2)) );
        BOOST_TEST( ((p1 == mother) || (p2 == mother)) );
        BOOST_REQUIRE_NE( p1, p2 );
    }

    BOOST_AUTO_TEST_CASE( CheckThatPaulParentsChildrenIsBeingUpdated )
    {
        const auto father2 = tree.createPerson( "dummyFather", "", "", "" );

        paul->setParents( mother, father2 );

        do {
            const auto children = mother->children();

            BOOST_REQUIRE_EQUAL( children.size(), 1 );
            BOOST_REQUIRE_EQUAL( *children.cbegin(), paul );
        } while (0);
        do {
            const auto children = father2->children();

            BOOST_REQUIRE_EQUAL( children.size(), 1 );
            BOOST_REQUIRE_EQUAL( *children.cbegin(), paul );
        } while (0);
        do {
            const auto children = father->children();

            BOOST_TEST( children.empty() );
        } while (0);
    }
BOOST_AUTO_TEST_SUITE_END()
} // namespace gtree_test

