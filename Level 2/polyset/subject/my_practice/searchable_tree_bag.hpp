#pragma once
#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag
{
    public:
        searchable_tree_bag() : tree_bag(), searchable_bag() {}
        searchable_tree_bag(const searchable_tree_bag &src) : tree_bag(src) {}
        searchable_tree_bag &operator=(const searchable_tree_bag& src)
        {
            if (this != &src)
                tree_bag::operator=(src);
            return *this;
        }
        ~searchable_tree_bag() {}

        bool has(int val) const
        {
            node *current = tree;
            while (current)
            {
                if (current->value == val)
                    return true;
                else if (current->value < val)
                    current = current->r;
                else
                    current = current->l;
            }
            return false;
        }
};