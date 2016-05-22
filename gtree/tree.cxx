#include "tree.h"
#include "person.h"

namespace gtree
{
Tree::PersonPtr Tree::createPerson( std::string firstName, std::string lastName
                                  , std::string location, std::string dateOfBirth)
{
    return Person::create( std::move( firstName ), std::move( lastName )
                         , std::move( location ), std::move( dateOfBirth ) );
}
} // namespace gtree

