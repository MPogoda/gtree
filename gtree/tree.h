#pragma once

#include "fwd.h"

#include <unordered_map>

namespace gtree
{
/*!
 * \class Tree
 * \brief
 */
class Tree
{
public:
    PersonPtr createPerson( std::string firstName
                          , std::string lastName
                          , std::string location
                          , std::string dateOfBirth
                          );

    Tree();

    const PersonPtr& root() const noexcept;

    auto searchByFirstName( const std::string& key ) const { return firstNameIndex_.equal_range( key ); }
    auto searchByLastName( const std::string& key ) const { return lastNameIndex_.equal_range( key ); }
    auto searchByLocation( const std::string& key ) const { return locationIndex_.equal_range( key ); }
    auto searchByDateOfBirth( const std::string& key ) const { return dateOfBirthIndex_.equal_range( key ); }
private: // fields
    const PersonPtr root_;

    using StringIndex = std::unordered_map< std::string, PersonPtr >;
    StringIndex firstNameIndex_;
    StringIndex lastNameIndex_;
    StringIndex dateOfBirthIndex_;
    StringIndex locationIndex_;
}; // class Tree
} // namespace gtree

