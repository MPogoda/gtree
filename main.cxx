#include <gtree/tree.h>
#include <gtree/person.h>

#include <iostream>
#include <unordered_set>

gtree::Tree createTree();
std::unordered_set< gtree::PersonConstPtr > findDescendantsFrom( const gtree::Tree& tree
                                                               , const std::string& ascendant
                                                               , const std::string& descendant );

int main(int /* argc */, char * /* argv */[])
{
    auto tree = createTree();

    const auto result = findDescendantsFrom( tree, "Bob", "Will" );
    std::cout << "Found following Wills as descendants from Bob\n";

    for (const auto& will : result) {
        std::cout << *will << '\n';
    }

    return 0;
}

gtree::Tree createTree()
{
    gtree::Tree tree{};
    const auto albert1 = tree.createPerson( "Albert", "of Saxe-Coburg & Gotha", "England", "1819" );
    const auto victoria1 = tree.createPerson( "Victoria", "", "England", "1819" );
    const auto victoria2 = tree.createPerson( "Victoria", "", "England", "1840" );
    const auto alice = tree.createPerson( "Alice", "", "England", "1843" );
    const auto alfred = tree.createPerson( "Alfred", "Duke of Edinburgh", "England", "1844" );
    const auto helena = tree.createPerson( "Helena", "", "England", "1846" );
    const auto alexandra1 = tree.createPerson( "Alexandra", "of Denmark", "England", "1844" );
    const auto edward1 = tree.createPerson( "Edward", "VII", "England", "1841" );
    const auto louise1 = tree.createPerson( "Louise", "", "England", "1848" );
    const auto arthur = tree.createPerson( "Arthur", "Duke of Connaught", "England", "1850" );
    const auto leopold = tree.createPerson( "Leopold", "Duke of Albany", "England", "1853" );
    const auto beatrice1 = tree.createPerson( "Beatrice", "", "England", "1857" );
    const auto albert2 = tree.createPerson( "Albert", "Duke of Clarence", "England", "1864" );
    const auto louise2 = tree.createPerson( "Louise", "", "England", "1867" );
    const auto victoria3 = tree.createPerson( "Victoria", "", "England", "1868" );
    const auto maud = tree.createPerson( "Maud", "", "England", "1869" );
    const auto john1 = tree.createPerson( "John", "", "England", "1871" );
    const auto george1 = tree.createPerson( "George", "V", "England", "1865" );
    const auto mary1 = tree.createPerson( "Mary", "of Teck", "England", "1867" );
    const auto edward2 = tree.createPerson( "Edward", "VII", "England", "1894" );
    const auto george2 = tree.createPerson( "George", "VI", "England", "1895" );
    const auto elizabeth1 = tree.createPerson( "Elizabeth", "Bowes-Lyon", "England", "1900" );
    const auto mary2 = tree.createPerson( "Mary", "", "England", "1897" );
    const auto henry1 = tree.createPerson( "Henry", "Duke of Gloucester", "England", "1900" );
    const auto george3 = tree.createPerson( "George", "Duke of Kent", "England", "1902" );
    const auto john2 = tree.createPerson( "John", "", "England", "1905" );
    const auto elizabeth2 = tree.createPerson( "Elizabeth", "II", "England", "1925" );
    const auto phillip = tree.createPerson( "Phillip", "Duke of Edinburgh", "England", "1921" );
    const auto margaret = tree.createPerson( "Margaret", "", "England", "1930" );
    const auto richard = tree.createPerson( "Richard", "Duke of Gloucester", "England", "1944" );
    const auto edward3 = tree.createPerson( "Edward", "Duke of Kent", "England", "1935" );
    const auto charles = tree.createPerson( "Charles", "", "England", "1948" );
    const auto diana = tree.createPerson( "Diana", "", "England", "1961" );
    const auto camilla = tree.createPerson( "Camilla", "Duchess of Cornwall", "England", "1947" );
    const auto anne = tree.createPerson( "Anne", "", "England", "1950" );
    const auto mark = tree.createPerson( "Mark", "Phillips", "England", "1948" );
    const auto timothy = tree.createPerson( "Timothy", "Laurence", "England", "1955" );
    const auto andrew = tree.createPerson( "Andrew", "", "England", "1960" );
    const auto sarah = tree.createPerson( "Sarah", "Duchess of York", "England", "1959" );
    const auto edward4 = tree.createPerson( "Edward", "Earl of Essex", "England", "1964" );
    const auto sophie = tree.createPerson( "Sophie", "Countess of Wessex", "England", "1965" );
    const auto michael = tree.createPerson( "Michael", "of Kent", "England", "1942" );
    const auto alexandra2 = tree.createPerson( "Alexandra", "of Kent", "England", "1936" );
    const auto william = tree.createPerson( "William", "", "England", "1982" );
    const auto henry2 = tree.createPerson( "Henry", "", "England", "1984" );
    const auto peter = tree.createPerson( "Peter", "Phillips", "England", "1977" );
    const auto zara = tree.createPerson( "Zara", "Phillips", "England", "1981" );
    const auto beatrice2 = tree.createPerson( "Beatrice", "", "England", "1988" );
    const auto eugenie = tree.createPerson( "Eugenie", "", "England", "1990" );
    const auto louise3 = tree.createPerson( "Louise", "", "England", "2003" );
    const auto viscount = tree.createPerson( "Viscount", "Severn", "England", "2007" );

        victoria2->setParentsUnsafe( albert1, victoria1 );
        alice->setParentsUnsafe( albert1, victoria1 );
        alfred->setParentsUnsafe( albert1, victoria1 );
        helena->setParentsUnsafe( albert1, victoria1 );
        edward1->setParentsUnsafe( albert1, victoria1 );
        louise1->setParentsUnsafe( albert1, victoria1 );
        arthur->setParentsUnsafe( albert1, victoria1 );
        leopold->setParentsUnsafe( albert1, victoria1 );
        beatrice1->setParentsUnsafe( albert1, victoria1 );

        albert2->setParentsUnsafe( edward1, alexandra1 );
        louise2->setParentsUnsafe( edward1, alexandra1 );
        victoria3->setParentsUnsafe( edward1, alexandra1 );
        maud->setParentsUnsafe( edward1, alexandra1 );
        john1->setParentsUnsafe( edward1, alexandra1 );
        george1->setParentsUnsafe( edward1, alexandra1 );

        edward2->setParentsUnsafe( george1, mary1 );
        george2->setParentsUnsafe( george1, mary1 );
        mary2->setParentsUnsafe( george1, mary1 );
        henry1->setParentsUnsafe( george1, mary1 );
        george3->setParentsUnsafe( george1, mary1 );
        john2->setParentsUnsafe( george1, mary1 );

        elizabeth2->setParentsUnsafe( george2, elizabeth1 );
        margaret->setParentsUnsafe( george2, elizabeth1 );

        richard->setParentsUnsafe( henry1, tree.root() );

        edward3->setParentsUnsafe( george3, tree.root() );
        michael->setParentsUnsafe( george3, tree.root() );
        alexandra2->setParentsUnsafe( george3, tree.root() );

        charles->setParentsUnsafe( elizabeth2, phillip );
        anne->setParentsUnsafe( elizabeth2, phillip );
        andrew->setParentsUnsafe( elizabeth2, phillip );
        edward4->setParentsUnsafe( elizabeth2, phillip );

        william->setParentsUnsafe( charles, diana );
        henry2->setParentsUnsafe( charles, diana );

        peter->setParentsUnsafe( anne, mark );
        zara->setParentsUnsafe( anne, mark );

        beatrice2->setParentsUnsafe( andrew, sarah );
        eugenie->setParentsUnsafe( andrew, sarah );

        louise3->setParentsUnsafe( edward4, sophie );
        viscount->setParentsUnsafe( edward4, sophie );

    const auto p1 = tree.createPerson( "Bob", "1", "Somewhere", "1902" );
    const auto p2 = tree.createPerson( "Bob", "2", "Somewhere", "1903" );
    const auto p3 = tree.createPerson( "Bob", "3", "Somewhere", "1904" );
    const auto p4 = tree.createPerson( "Bob", "4", "Somewhere", "1905" );
    const auto p5 = tree.createPerson( "Bob", "5", "Somewhere", "1906" );
    const auto p6 = tree.createPerson( "Will", "1", "Somewhere", "1902" );
    const auto p7 = tree.createPerson( "Will", "2", "Somewhere", "1903" );
    const auto p8 = tree.createPerson( "Will", "3", "Somewhere", "1904" );
    const auto p9 = tree.createPerson( "Will", "4", "Somewhere", "1905" );
    const auto p0 = tree.createPerson( "Will", "5", "Somewhere", "1906" );

    p1->setParents( tree.root(), victoria2 );
    p6->setParents( tree.root(), victoria2 );

    p7->setParents( tree.root(), p1 );
    p8->setParents( tree.root(), p7 );
    p2->setParents( tree.root(), p8 );

    elizabeth1->setParents( tree.root(), p3 );
    p4->setParents( tree.root(), mary2 );

    p5->setParents( tree.root(), john2 );

    p9->setParents( zara, tree.root() );
    p0->setParents( zara, tree.root() );
    return tree;
}

std::unordered_set< gtree::PersonConstPtr > findDescendantsFrom( const gtree::Tree& tree
                                                               , const std::string& ascendant
                                                               , const std::string& descendant )
{
    std::unordered_set< gtree::PersonConstPtr > result{};

    for (const auto& bob : tree.searchByFirstName( ascendant )) {
        // std::cout << "Bob: " << *bob.second << '\n';
        for (const auto& d : bob.second->descendants()) {
            // std::cout << '\t' << *d << '\n';
            if (d->firstName() == descendant) {
                result.emplace( d );
            }
        }
    }

    return result;
}

