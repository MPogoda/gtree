#include "tree.h"
#include "person.h"

namespace gtree
{
Tree::Tree()
    : root_{ Person::create( {}, {}, {}, {}, {}) }
{
}

PersonPtr Tree::createPerson( std::string firstName, std::string lastName
                            , std::string location, std::string dateOfBirth)
{
    auto result = Person::create( firstName, lastName, location, dateOfBirth, root_ );

    firstNameIndex_.emplace( std::move( firstName ), result );
    lastNameIndex_.emplace( std::move( lastName ), result );
    locationIndex_.emplace( std::move( location ), result );
    dateOfBirthIndex_.emplace( std::move( dateOfBirth ), result );

    return result;
}

const PersonPtr& Tree::root() const noexcept
{
    return root_;
}
} // namespace gtree

