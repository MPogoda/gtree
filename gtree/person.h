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

    std::string firstName() const;
    std::string lastName() const;
    Date        dateOfBirth() const;
private: // functions
private: // fields
}; // class Person
} // namespace gtree

