#pragma once

#include "searchable_tree_bag.hpp"
#include "searchable_array_bag.hpp"

class set
{
    private:
        searchable_bag &bag;
    public:
        //set() : bag() {}
        set(searchable_bag& src) : bag(src) {}

        ~set()
        {
            bag.clear();
        }

        void insert(int val)
        {
            if (!bag.has(val))
                bag.insert(val);
        }

        void insert(int *array, int size)
        {
            for (int i = 0; i < size; i++)
            {
                if (!bag.has(array[i]))
                    bag.insert(array[i]);
            }
        }

        void print() const
        {
            bag.print();
        }

        void clear()
        {
            bag.clear();
        }

        bool has(int val) const
        {
            return bag.has(val);
        }

        searchable_bag &get_bag() const
        {
            return bag;
        }
};
