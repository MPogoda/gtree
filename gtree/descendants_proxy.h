#pragma once

#include "fwd.h"
#include "person.h"

#include <unordered_map>
#include <stack>

namespace gtree
{
/*!
 * \class DescendantsProxy
 * \brief
 */
class DescendantsProxy
{
public:
    /*!
     * \class ConstIterator
     * \brief
     */
    class ConstIterator
    {
    public:
        explicit ConstIterator( PersonConstPtr person );

        ConstIterator();

        PersonConstPtr operator*() const;

        ConstIterator& operator++();

        bool operator==( const ConstIterator& other ) const noexcept;
        bool operator!=( const ConstIterator& other ) const noexcept;
    private: // fields
        PersonConstPtr current_;

        // person -> next_child_to_visit
        using VisitedMap = std::unordered_map< PersonConstPtr, PersonSet::const_iterator >;
        VisitedMap visited_;

        using Stack = std::stack< PersonConstPtr >;
        Stack stack_;
        bool isEnd_;
    }; // class ConstIterator

    ConstIterator begin() const;
    ConstIterator end() const;
    explicit DescendantsProxy( PersonConstPtr person );
private: // fields
    const PersonConstPtr person_;
}; // class DescendantsProxy
} // namespace gtree

