#include "person.h"

#include <boost/date_time/gregorian/gregorian_types.hpp>
#include <boost/date_time/gregorian/parsers.hpp>

namespace gtree
{
const std::string& Person::firstName() const
{
    return firstName_;
}

const std::string& Person::lastName() const
{
    return lastName_;
}

const std::string& Person::location() const
{
    return location_;
}

const Person::Date& Person::dateOfBirth() const
{
    return dateOfBirth_;
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

