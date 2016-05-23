#include "tree.h"
#include "person.h"

namespace gtree
{
Tree::Tree()
    : root_{ Person::create( {}, {}, {}, {}, {}) }
{
}

Tree::PersonPtr Tree::createPerson( std::string firstName, std::string lastName
                                  , std::string location, std::string dateOfBirth)
{
    return Person::create( std::move( firstName ), std::move( lastName )
                         , std::move( location ), std::move( dateOfBirth )
                         , root_ );
}

const Tree::PersonPtr& Tree::root() const noexcept
{
    return root_;
}
} // namespace gtree

