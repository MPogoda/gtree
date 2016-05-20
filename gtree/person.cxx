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

std::string Person::location() const
{
    return "Kyiv";
}

Person::Date Person::dateOfBirth() const
{
    return boost::gregorian::day_clock::local_day();
}

Person::Person( std::string firstName
              , std::string lastName
              , std::string location
              , Date        dateOfBirth )
    : firstName_{ std::move( firstName ) }
    , lastName_{ std::move( lastName ) }
    , location_{ std::move( location ) }
    , dateOfBirth_{ std::move( dateOfBirth ) }
{
}

Person::Person( std::string firstName
              , std::string lastName
              , std::string location
              , const std::string& dateOfBirth )
    : Person{ std::move( firstName )
            , std::move( lastName )
            , std::move( location )
            , boost::gregorian::from_simple_string( dateOfBirth ) }
{
}
} // namespace gtree

