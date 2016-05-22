#pragma once

#include <memory>
#include <string>

namespace gtree
{
class Tree;
/*!
 * \class Person
 * \brief
 */
class Person
{
public:
    const std::string& firstName()   const noexcept;
    const std::string& lastName()    const noexcept;
    const std::string& location()    const noexcept;
    const std::string& dateOfBirth() const noexcept;
protected: // functions
    Person( std::string firstName
          , std::string lastName
          , std::string location
          , std::string dateOfBirth
          , std::weak_ptr< Person > root
          );

private: // functions
    static std::shared_ptr< Person > create( std::string firstName
                                           , std::string lastName
                                           , std::string location
                                           , std::string dateOfBirth
                                           , std::weak_ptr< Person > root
                                           );

private: // fields
    const std::string firstName_;
    const std::string lastName_;
    const std::string location_;
    const std::string dateOfBirth_;

    std::weak_ptr< Person > parent1_;
    std::weak_ptr< Person > parent2_;

    friend class Tree;
}; // class Person
} // namespace gtree

