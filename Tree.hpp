//@author eylony1403@gmail.com

#pragma once

#include <iostream>
#include "Node.hpp"
#include "Iterators.hpp"

#define BIN 2

//Base functions for trees
template <typename T, int N = BIN>
class AnyTree
{

public:
    AnyTree()
    {
    }
    ~AnyTree()
    {
        BFSIterator<T> it = begin_bfs_scan();
        while (it != end_bfs_scan())
        {
            BFSIterator<T> temp = it;
            ++it;
            temp->get_children().clear(); // Clear children
        }
        _root = nullptr;
    }

    void add_root(Node<T> *root)
    {
        _root = root;
    }

    void add_sub_node(Node<T> *parent, Node<T> *child)
    {
        if (parent->get_children().size() >= N)
        {
            throw std::out_of_range("Parent has too many children");
        }

        parent->add_child(child);
    }

    Node<T> *get_root()
    {
        return _root;
    }

    // ----------------- Iterators -----------------

    // Iterator

    BFSIterator<T> begin()
    {
        return BFSIterator<T>(_root);
    }

    BFSIterator<T> end()
    {
        return BFSIterator<T>(nullptr);
    }

    // BFSIterator

    BFSIterator<T> begin_bfs_scan()
    {
        return BFSIterator<T>(_root);
    }

    BFSIterator<T> end_bfs_scan()
    {
        return BFSIterator<T>(nullptr);
    }

    // DFSIterator

    DFSIterator<T> begin_dfs_scan()
    {
        return DFSIterator<T>(_root);
    }

    DFSIterator<T> end_dfs_scan()
    {
        return DFSIterator<T>(nullptr);
    }

protected:
    Node<T> *_root;
};

// General k-nary tree
template <typename T, int N = 2>
class Tree : public AnyTree<T, N>
{
public:
    // InOrderIterator

    DFSIterator<T> begin_in_order()
    {
        return DFSIterator<T>(this->_root);
    }

    DFSIterator<T> end_in_order()
    {
        return DFSIterator<T>(nullptr);
    }

    // PreOrderIterator

    DFSIterator<T> begin_pre_order()
    {
        return DFSIterator<T>(this->_root);
    }

    DFSIterator<T> end_pre_order()
    {
        return DFSIterator<T>(nullptr);
    }

    // PostOrderIterator

    DFSIterator<T> begin_post_order()
    {
        return DFSIterator<T>(this->_root);
    }

    DFSIterator<T> end_post_order()
    {
        return DFSIterator<T>(nullptr);
    }
};

// Specialization for binary tree
template <typename T>
class Tree<T, 2> : public AnyTree<T, 2>
{
public:
    // InOrderIterator

    InOrderIterator<T> begin_in_order()
    {
        return InOrderIterator<T>(this->_root);
    }

    InOrderIterator<T> end_in_order()
    {
        return InOrderIterator<T>(nullptr);
    }

    // PreOrderIterator

    PreOrderIterator<T> begin_pre_order()
    {
        return PreOrderIterator<T>(this->_root);
    }

    PreOrderIterator<T> end_pre_order()
    {
        return PreOrderIterator<T>(nullptr);
    }

    // PostOrderIterator

    PostOrderIterator<T> begin_post_order()
    {
        return PostOrderIterator<T>(this->_root);
    }

    PostOrderIterator<T> end_post_order()
    {
        return PostOrderIterator<T>(nullptr);
    }

    // HeapIterator

    HeapIterator<T> begin_heap()
    {
        return HeapIterator<T>(this->_root);
    }

    HeapIterator<T> end_heap()
    {
        return HeapIterator<T>(nullptr);
    }

};