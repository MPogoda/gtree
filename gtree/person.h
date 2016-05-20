#pragma once

#include <string>

#include <boost/date_time/gregorian/greg_date.hpp>

namespace gtree
{
/*!
 * \class Person
 * \brief
 */
class Person
{
public:
    using Date = boost::gregorian::date;

    Person( std::string firstName
          , std::string lastName
          , std::string location
          , const std::string& dateOfBirth
          );
    Person( std::string firstName
          , std::string lastName
          , std::string location
          , Date        dateOfBirth
          );

    const std::string& firstName() const;
    const std::string& lastName() const;
    const std::string& location() const;
    const Date&        dateOfBirth() const;
private: // fields
    const std::string firstName_;
    const std::string lastName_;
    const std::string location_;
    const Date        dateOfBirth_;
}; // class Person
} // namespace gtree

