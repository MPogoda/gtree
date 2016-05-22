#include "person.h"

#include <exception>

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
    , parent2_{ root }
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

bool Person::isRoot() const noexcept
{
    return parent1_.expired() && parent2_.expired();
}

Person::Persons Person::parents() const
{
    Persons result{}; result.reserve( 2 );

    if (auto pt1 = parent1_.lock()) {
        result.emplace_back( pt1 );

        if (auto pt2 = parent2_.lock()) {
            if (pt1 != pt2) {
                result.emplace_back( std::move( pt2 ) );
            }
        }
    }

    return result;
}

void Person::setParents( PersonPtr parent1, PersonPtr parent2 )
{
    if (!parent1 || !parent2) {
        throw std::invalid_argument{ "Parents shouldn't be empty!" };
    }
    parent1_ = parent1;
    parent2_ = parent2;
}

Person::Persons Person::children() const
{
    return { std::begin( children_ ), std::end( children_ ) };
}
} // namespace gtree

