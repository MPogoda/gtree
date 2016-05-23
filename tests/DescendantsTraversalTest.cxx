#include <boost/test/unit_test.hpp>

#include <gtree/fwd.h>
#include <gtree/person.h>
#include <gtree/tree.h>

#include <unordered_map>

namespace gtree_test
{
using gtree::Tree;
using gtree::PersonConstPtr;
using gtree::PersonPtr;

struct HierarchyFixture
{
    HierarchyFixture()
        : tree{}
        , albert1{ tree.createPerson( "Albert", "of Saxe-Coburg & Gotha", "England", "1819" ) }
        , victoria1{ tree.createPerson( "Victoria", "", "England", "1819" ) }
        , victoria2{ tree.createPerson( "Victoria", "", "England", "1840" ) }
        , alice{ tree.createPerson( "Alice", "", "England", "1843" ) }
        , alfred{ tree.createPerson( "Alfred", "Duke of Edinburgh", "England", "1844" ) }
        , helena{ tree.createPerson( "Helena", "", "England", "1846" ) }
        , alexandra1{ tree.createPerson( "Alexandra", "of Denmark", "England", "1844" ) }
        , edward1{ tree.createPerson( "Edward", "VII", "England", "1841" ) }
        , louise1{ tree.createPerson( "Louise", "", "England", "1848" ) }
        , arthur{ tree.createPerson( "Arthur", "Duke of Connaught", "England", "1850" ) }
        , leopold{ tree.createPerson( "Leopold", "Duke of Albany", "England", "1853" ) }
        , beatrice1{ tree.createPerson( "Beatrice", "", "England", "1857" ) }
        , albert2{ tree.createPerson( "Albert", "Duke of Clarence", "England", "1864" ) }
        , louise2{ tree.createPerson( "Louise", "", "England", "1867" ) }
        , victoria3{ tree.createPerson( "Victoria", "", "England", "1868" ) }
        , maud{ tree.createPerson( "Maud", "", "England", "1869" ) }
        , john1{ tree.createPerson( "John", "", "England", "1871" ) }
        , george1{ tree.createPerson( "George", "V", "England", "1865" ) }
        , mary1{ tree.createPerson( "Mary", "of Teck", "England", "1867" ) }
        , edward2{ tree.createPerson( "Edward", "VII", "England", "1894" ) }
        , george2{ tree.createPerson( "George", "VI", "England", "1895" ) }
        , elizabeth1{ tree.createPerson( "Elizabeth", "Bowes-Lyon", "England", "1900" ) }
        , mary2{ tree.createPerson( "Mary", "", "England", "1897" ) }
        , henry1{ tree.createPerson( "Henry", "Duke of Gloucester", "England", "1900" ) }
        , george3{ tree.createPerson( "George", "Duke of Kent", "England", "1902" ) }
        , john2{ tree.createPerson( "John", "", "England", "1905" ) }
        , elizabeth2{ tree.createPerson( "Elizabeth", "II", "England", "1925" ) }
        , phillip{ tree.createPerson( "Phillip", "Duke of Edinburgh", "England", "1921" ) }
        , margaret{ tree.createPerson( "Margaret", "", "England", "1930" ) }
        , richard{ tree.createPerson( "Richard", "Duke of Gloucester", "England", "1944" ) }
        , edward3{ tree.createPerson( "Edward", "Duke of Kent", "England", "1935" ) }
        , charles{ tree.createPerson( "Charles", "", "England", "1948" ) }
        , diana{ tree.createPerson( "Diana", "", "England", "1961" ) }
        , camilla{ tree.createPerson( "Camilla", "Duchess of Cornwall", "England", "1947" ) }
        , anne{ tree.createPerson( "Anne", "", "England", "1950" ) }
        , mark{ tree.createPerson( "Mark", "Phillips", "England", "1948" ) }
        , timothy{ tree.createPerson( "Timothy", "Laurence", "England", "1955" ) }
        , andrew{ tree.createPerson( "Andrew", "", "England", "1960" ) }
        , sarah{ tree.createPerson( "Sarah", "Duchess of York", "England", "1959" ) }
        , edward4{ tree.createPerson( "Edward", "Earl of Essex", "England", "1964" ) }
        , sophie{ tree.createPerson( "Sophie", "Countess of Wessex", "England", "1965" ) }
        , michael{ tree.createPerson( "Michael", "of Kent", "England", "1942" ) }
        , alexandra2{ tree.createPerson( "Alexandra", "of Kent", "England", "1936" ) }
        , william{ tree.createPerson( "William", "", "England", "1982" ) }
        , henry2{ tree.createPerson( "Henry", "", "England", "1984" ) }
        , peter{ tree.createPerson( "Peter", "Phillips", "England", "1977" ) }
        , zara{ tree.createPerson( "Zara", "Phillips", "England", "1981" ) }
        , beatrice2{ tree.createPerson( "Beatrice", "", "England", "1988" ) }
        , eugenie{ tree.createPerson( "Eugenie", "", "England", "1990" ) }
        , louise3{ tree.createPerson( "Louise", "", "England", "2003" ) }
        , viscount{ tree.createPerson( "Viscount", "Severn", "England", "2007" ) }
    {
        victoria2->setParents( albert1, victoria1 );
        alice->setParents( albert1, victoria1 );
        alfred->setParents( albert1, victoria1 );
        helena->setParents( albert1, victoria1 );
        edward1->setParents( albert1, victoria1 );
        louise1->setParents( albert1, victoria1 );
        arthur->setParents( albert1, victoria1 );
        leopold->setParents( albert1, victoria1 );
        beatrice1->setParents( albert1, victoria1 );

        albert2->setParents( edward1, alexandra1 );
        louise2->setParents( edward1, alexandra1 );
        victoria3->setParents( edward1, alexandra1 );
        maud->setParents( edward1, alexandra1 );
        john1->setParents( edward1, alexandra1 );
        george1->setParents( edward1, alexandra1 );

        edward2->setParents( george1, mary1 );
        george2->setParents( george1, mary1 );
        mary2->setParents( george1, mary1 );
        henry1->setParents( george1, mary1 );
        george3->setParents( george1, mary1 );
        john2->setParents( george1, mary1 );

        elizabeth2->setParents( george2, elizabeth1 );
        margaret->setParents( george2, elizabeth1 );

        richard->setParents( henry1, tree.root() );

        edward3->setParents( george3, tree.root() );
        michael->setParents( george3, tree.root() );
        alexandra2->setParents( george3, tree.root() );

        charles->setParents( elizabeth2, phillip );
        anne->setParents( elizabeth2, phillip );
        andrew->setParents( elizabeth2, phillip );
        edward4->setParents( elizabeth2, phillip );

        william->setParents( charles, diana );
        henry2->setParents( charles, diana );

        peter->setParents( anne, mark );
        zara->setParents( anne, mark );

        beatrice2->setParents( andrew, sarah );
        eugenie->setParents( andrew, sarah );

        louise3->setParents( edward4, sophie );
        viscount->setParents( edward4, sophie );
    }

    Tree tree;
    PersonPtr albert1;
    PersonPtr victoria1;
    PersonPtr victoria2;
    PersonPtr alice;
    PersonPtr alfred;
    PersonPtr helena;
    PersonPtr alexandra1;
    PersonPtr edward1;
    PersonPtr louise1;
    PersonPtr arthur;
    PersonPtr leopold;
    PersonPtr beatrice1;
    PersonPtr albert2;
    PersonPtr louise2;
    PersonPtr victoria3;
    PersonPtr maud;
    PersonPtr john1;
    PersonPtr george1;
    PersonPtr mary1;
    PersonPtr edward2;
    PersonPtr george2;
    PersonPtr elizabeth1;
    PersonPtr mary2;
    PersonPtr henry1;
    PersonPtr george3;
    PersonPtr john2;
    PersonPtr elizabeth2;
    PersonPtr phillip;
    PersonPtr margaret;
    PersonPtr richard;
    PersonPtr edward3;
    PersonPtr charles;
    PersonPtr diana;
    PersonPtr camilla;
    PersonPtr anne;
    PersonPtr mark;
    PersonPtr timothy;
    PersonPtr andrew;
    PersonPtr sarah;
    PersonPtr edward4;
    PersonPtr sophie;
    PersonPtr michael;
    PersonPtr alexandra2;
    PersonPtr william;
    PersonPtr henry2;
    PersonPtr peter;
    PersonPtr zara;
    PersonPtr beatrice2;
    PersonPtr eugenie;
    PersonPtr louise3;
    PersonPtr viscount;
}; // struct HierarchyFixture

BOOST_FIXTURE_TEST_SUITE( DescendantsTraversalTestSuite, HierarchyFixture )
    BOOST_AUTO_TEST_CASE( CheckQueenElizabethsDescendents )
    {
        std::unordered_map< PersonConstPtr, bool > visited{ { charles, false }
                                                     , { anne, false }
                                                     , { andrew, false }
                                                     , { edward4, false }
                                                     , { william, false }
                                                     , { henry2, false }
                                                     , { peter, false }
                                                     , { zara, false }
                                                     , { beatrice2, false }
                                                     , { eugenie, false }
                                                     , { louise3, false }
                                                     , { viscount, false }
        };

        for (const auto it : elizabeth2->descendants() ) {
            const auto s = visited.find( it );

            if (s == std::end( visited)) {
                BOOST_TEST_REQUIRE( false, "Unknown descendant!" );
            }

            BOOST_TEST( !s->second, "We shouldn't visit the same descendant twice!" );

            s->second = true;
        }

        for (const auto it : visited) {
            BOOST_TEST( it.second, "All Queen's descendants should be marked!" );
        }
    }
BOOST_AUTO_TEST_SUITE_END()
} // namespace gtree_test

