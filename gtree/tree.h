#pragma once

#include "fwd.h"

namespace gtree
{
/*!
 * \class Tree
 * \brief
 */
class Tree
{
public:
    PersonPtr createPerson( std::string firstName
                          , std::string lastName
                          , std::string location
                          , std::string dateOfBirth
                          );

    Tree();

    const PersonPtr& root() const noexcept;
private: // fields
    const PersonPtr root_;
}; // class Tree
} // namespace gtree

