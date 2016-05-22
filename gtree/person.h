#pragma once

#include <string>

namespace gtree
{
/*!
 * \class Person
 * \brief
 */
class Person
{
public:
    Person( std::string firstName
          , std::string lastName
          , std::string location
          , std::string dateOfBirth
          );

    const std::string& firstName()   const noexcept;
    const std::string& lastName()    const noexcept;
    const std::string& location()    const noexcept;
    const std::string& dateOfBirth() const noexcept;
private: // fields
    const std::string firstName_;
    const std::string lastName_;
    const std::string location_;
    const std::string dateOfBirth_;
}; // class Person
} // namespace gtree

