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

Tree::EqualRange::EqualRange( std::pair< StringIndex::const_iterator, StringIndex::const_iterator >&& eq_range )
    : begin_{ std::move( eq_range.first ) }
    , end_{ std::move( eq_range.second ) }
{
}

const Tree::StringIndex::const_iterator& Tree::EqualRange::begin() const noexcept
{
    return begin_;
}

const Tree::StringIndex::const_iterator& Tree::EqualRange::end() const noexcept
{
    return end_;
}

Tree::EqualRange Tree::searchByFirstName( const std::string& key ) const
{
    return EqualRange{ firstNameIndex_.equal_range( key ) };
}

Tree::EqualRange Tree::searchByLastName( const std::string& key ) const
{
    return EqualRange{ lastNameIndex_.equal_range( key ) };
}

Tree::EqualRange Tree::searchByLocation( const std::string& key ) const
{
    return EqualRange{ locationIndex_.equal_range( key ) };
}

Tree::EqualRange Tree::searchByDateOfBirth( const std::string& key ) const
{
    return EqualRange{ dateOfBirthIndex_.equal_range( key ) };
}
} // namespace gtree

