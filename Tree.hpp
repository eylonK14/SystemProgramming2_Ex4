//@author eylony1403@gmail.com

#pragma once

#include <iostream>
#include "Node.hpp"
#include "Iterators.hpp"

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

    void add_sub_node(Node<T>* parent, Node<T>* child)
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

    // ----------------- Iterators -----------------

    // InOrderIterator

    InOrderIterator<T> begin_in_order()
    {
        return InOrderIterator<T>(_root);
    }

    InOrderIterator<T> end_in_order()
    {
        return InOrderIterator<T>(nullptr);
    }

    // PreOrderIterator
    
    PreOrderIterator<T> begin_pre_order()
    {
        return PreOrderIterator<T>(_root);
    }

    PreOrderIterator<T> end_pre_order()
    {
        return PreOrderIterator<T>(nullptr);
    }

    // PostOrderIterator

    PostOrderIterator<T> begin_post_order()
    {
        return PostOrderIterator<T>(_root);
    }

    PostOrderIterator<T> end_post_order()
    {
        return PostOrderIterator<T>(nullptr);
    }

private:
    Node<T>* _root;
};