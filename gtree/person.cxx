#include "person.h"

#include <boost/date_time/gregorian/gregorian_types.hpp>

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
} // namespace gtree

