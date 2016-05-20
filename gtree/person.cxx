#include "person.h"

#include <boost/date_time/gregorian/gregorian_types.hpp>
#include <boost/date_time/gregorian/parsers.hpp>

namespace gtree
{
std::string Person::firstName() const
{
    return "Bob";
}

std::string Person::lastName() const
{
    return "Smith";
}

Person::Date Person::dateOfBirth() const
{
    return boost::gregorian::day_clock::local_day();
}

Person::Person( const std::string& firstName
              , const std::string& lastName
              ,       Date         dateOfBirth )
    : firstName_{ firstName }
    , lastName_{ lastName }
    , dateOfBirth_{ std::move( dateOfBirth ) }
{
}

Person::Person( const std::string& firstName
              , const std::string& lastName
              , const std::string& dateOfBirth )
    : Person{ firstName, lastName, boost::gregorian::from_simple_string( dateOfBirth ) }
{
}
} // namespace gtree

