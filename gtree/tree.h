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

private:
    using StringIndex = std::unordered_map< std::string, PersonPtr >;
public:
    class EqualRange
    {
    public:
        explicit EqualRange( std::pair< StringIndex::const_iterator, StringIndex::const_iterator >&& eq_range );

        const StringIndex::const_iterator& begin() const noexcept;
        const StringIndex::const_iterator& end() const noexcept;
    private:
        const StringIndex::const_iterator begin_;
        const StringIndex::const_iterator end_;
    }; // class EqualRange
    EqualRange searchByFirstName( const std::string& key ) const;
    EqualRange searchByLastName( const std::string& key ) const;
    EqualRange searchByLocation( const std::string& key ) const;
    EqualRange searchByDateOfBirth( const std::string& key ) const;
private: // fields
    const PersonPtr root_;

    StringIndex firstNameIndex_;
    StringIndex lastNameIndex_;
    StringIndex dateOfBirthIndex_;
    StringIndex locationIndex_;
}; // class Tree
} // namespace gtree

