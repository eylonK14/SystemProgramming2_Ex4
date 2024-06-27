//@author eylony1403@gmail.com

#pragma once

#include <iostream>
#include "Node.hpp"

#define BIN 2

template <typename T, int N = BIN>
class Tree
{

public:
    Tree()
    {
    }
    ~Tree()
    {
    }

    void add_root(Node<T>* root)
    {
        _root = root;
    }

    void add_sub_root(Node<T>* parent, Node<T>* child)
    {
        if (parent->get_children().size() >= N)
        {
            throw std::out_of_range("Parent has too many children");
        }

        parent->add_child(child);
    }

    Node<T>* get_root()
    {
        return _root;
    }

private:
    Node<T>* _root;
};