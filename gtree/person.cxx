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
              , std::string dateOfBirth
              , std::weak_ptr< Person > root )
    : firstName_{ std::move( firstName ) }
    , lastName_{ std::move( lastName ) }
    , location_{ std::move( location ) }
    , dateOfBirth_{ std::move( dateOfBirth ) }
    , parent1_{ root }
    , parent2_{ std::move( root ) }
{
}

namespace
{
// Hack to enable usage of std::make_shared< Person >()
struct PublicPerson : Person
{
    template < typename... Args >
    PublicPerson( Args&&... args )
        : Person{ std::forward< Args >( args )... }
    {
    }
}; // struct PublicPerson
} // namespace

std::shared_ptr< Person > Person::create( std::string firstName
                                        , std::string lastName
                                        , std::string location
                                        , std::string dateOfBirth
                                        , std::weak_ptr< Person > root )
{
    return std::make_shared< PublicPerson >( std::move( firstName )
                                           , std::move( lastName )
                                           , std::move( location )
                                           , std::move( dateOfBirth )
                                           , std::move( root ) );
}
} // namespace gtree

