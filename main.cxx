#include <gtree/tree.h>
#include <gtree/person.h>

#include <iostream>
#include <unordered_set>

gtree::Tree createTree();

int main(int /* argc */, char * /* argv */[])
{
    auto tree = createTree();

    std::unordered_set< gtree::PersonConstPtr > result{};

    for (const auto& bob : tree.searchByFirstName( "Bob" )) {
        for (const auto& d : bob.second->descendants()) {
            if (d->firstName() == "Will") {
                result.emplace( d );
            }
        }
    }

    std::cout << "Found following Wills as descendants from Bob\n";

    for (const auto& will : result) {
        std::cout << *will << '\n';
    }

    return 0;
}

gtree::Tree createTree()
{
    gtree::Tree tree{};

    return tree;
}
