#include "person.h"

#include <exception>
#include <iostream>

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

PersonSet Person::parents() const
{
    PersonSet result{}; result.reserve( 2 );

    if (auto pt1 = parent1_.lock()) {
        result.emplace( pt1 );

        if (auto pt2 = parent2_.lock()) {
            result.emplace( pt2 );
        }
    }

    return result;
}

void Person::setParents( PersonPtr parent1, PersonPtr parent2 )
{
    if (!parent1 || !parent2) {
        throw std::invalid_argument{ "Parents shouldn't be empty!" };
    }

    if ((parent1.get() == this) || (parent2.get() == this)) {
        throw std::invalid_argument{ "Person cannot be parent to themself!" };
    }

    for (const auto& a : descendants()) {
        if ((parent1 == a) || (parent2 == a)) {
            throw std::invalid_argument{ "Person cannot be parent to their ascendant!" };
        }
    }

    setParentsUnsafe( std::move( parent1 ), std::move( parent2 ) );
}

void Person::setParentsUnsafe( PersonPtr parent1, PersonPtr parent2 )
{
    if (const auto p =  parent1_.lock()) {
        p->rmChild( shared_from_this() );
    }

    if (const auto p =  parent2_.lock()) {
        p->rmChild( shared_from_this() );
    }

    parent1_ = parent1;
    parent2_ = parent2;

    parent1->addChild( shared_from_this() );
    parent2->addChild( shared_from_this() );
}

const PersonSet& Person::children() const
{
    return children_;
}

void Person::addChild( PersonPtr&& child )
{
    children_.emplace( child );
}

void Person::rmChild( const PersonPtr& child )
{
    children_.erase( child );
}

DescendantsProxy Person::descendants() const
{
    return DescendantsProxy{ shared_from_this() };
}

std::ostream& operator<<( std::ostream& out, const Person& person )
{
    out << "Person{ firstName: \"" << person.firstName()
        << "\", lastName: \"" << person.lastName()
        << "\", location: \"" << person.location()
        << "\", dateOfBirth: \"" << person.dateOfBirth() << "\"}";
    return out;
}
} // namespace gtree

