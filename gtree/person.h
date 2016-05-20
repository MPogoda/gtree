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

    Person( const std::string& firstName
          , const std::string& lastName
          , const std::string& dateOfBirth
          );
    Person( const std::string& firstName
          , const std::string& lastName
          ,       Date         dateOfBirth
          );

    std::string firstName() const;
    std::string lastName() const;
    Date        dateOfBirth() const;
private: // fields
    const std::string firstName_;
    const std::string lastName_;
    const Date        dateOfBirth_;
}; // class Person
} // namespace gtree

