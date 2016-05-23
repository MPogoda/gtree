#include "descendants_proxy.h"

#include <exception>

namespace gtree
{
DescendantsProxy::DescendantsProxy( PersonConstPtr person )
    : person_{ std::move( person ) }
{
}

DescendantsProxy::ConstIterator DescendantsProxy::begin() const
{
    return ConstIterator{ person_ };
}

DescendantsProxy::ConstIterator DescendantsProxy::end() const
{
    return ConstIterator{};
}

DescendantsProxy::ConstIterator::ConstIterator( PersonConstPtr person )
    : current_{ std::move( person ) }
    , visited_{ {current_, current_->children().cbegin() } }
    , isEnd_{ false }
{
    ++*this;
}

DescendantsProxy::ConstIterator::ConstIterator()
    : isEnd_{ true }
{
}

PersonConstPtr DescendantsProxy::ConstIterator::operator*() const
{
    if (isEnd_) throw std::out_of_range{ "Cannot dereference END iterator." };

    return current_;
}

DescendantsProxy::ConstIterator& DescendantsProxy::ConstIterator::operator++()
{
    if (isEnd_) throw std::out_of_range{ "Cannot increment past END iterator." };

    while (true) {
        // Test children
        const auto& children = current_->children();
        const auto visitedIt = visited_.find( current_ );
        const auto childIt = (visited_.cend() == visitedIt) ? children.cbegin() : visitedIt->second;


        if (visited_.cend() == visitedIt) {
            visited_[ current_ ] = children.cbegin();
        }

        if (children.cend() == childIt) {
            if (stack_.empty()) {
                isEnd_ = true;
                break;
            }
            current_ = stack_.top();
            stack_.pop();

            continue;
        }

        stack_.push( current_ );
        visited_[ current_ ] = std::next( childIt );

        current_ = *childIt;
        break;
    }

    return *this;
}

bool DescendantsProxy::ConstIterator::operator==( const ConstIterator& other ) const noexcept
{
    return (isEnd_ == other.isEnd_);
}

bool DescendantsProxy::ConstIterator::operator!=( const ConstIterator& other ) const noexcept
{
    return !(*this == other);
}
} // namespace gtree

