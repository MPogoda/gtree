#include "person.h"

namespace gtree
{
const std::string& Person::firstName() const noexcept
{
    return firstName_;
}

const std::string& Person::lastName() const noexcept
{
    return lastName_;
}

const std::string& Person::location() const noexcept
{
    return location_;
}

const std::string& Person::dateOfBirth() const noexcept
{
    return dateOfBirth_;
}

Person::Person( std::string firstName
              , std::string lastName
              , std::string location
              , std::string dateOfBirth )
    : firstName_{ std::move( firstName ) }
    , lastName_{ std::move( lastName ) }
    , location_{ std::move( location ) }
    , dateOfBirth_{ std::move( dateOfBirth ) }
{
}
} // namespace gtree

