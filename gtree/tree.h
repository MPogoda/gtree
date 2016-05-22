#pragma once

#include <memory>

namespace gtree
{
class Person;
/*!
 * \class Tree
 * \brief
 */
class Tree
{
public:
    using PersonPtr = std::shared_ptr< Person >;
    PersonPtr createPerson( std::string firstName
                          , std::string lastName
                          , std::string location
                          , std::string dateOfBirth
                          );
private: // functions
private: // fields
}; // class Tree
} // namespace gtree

