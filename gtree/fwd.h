#pragma once

#include <memory>
#include <unordered_set>

namespace gtree
{
class Person;
class Tree;
class DescendantsProxy;

using PersonPtr      = std::shared_ptr< Person >;
using PersonConstPtr = std::shared_ptr< const Person >;
using PersonSet      = std::unordered_set< PersonPtr >;
} // namespace gtree

