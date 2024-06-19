#include "Tree.hpp"

template <typename T, int N> Tree<T, N>::Tree() : _root(nullptr)
{
}

template <typename T, int N> Tree<T, N>::~Tree()
{
    delete this->_root;
}

template <typename T, int N> void Tree<T, N>::add_root(Node<T> root)
{
    _root = root;
}

template <typename T, int N> void Tree<T, N>::add_sub_root(Node<T> parent, Node<T> child)
{
    if (parent->get_children().size() >= N)
    {
        throw std::out_of_range("Parent has too many children");
    }

    parent->add_child(child);
}

template <typename T, int N> Node<T> Tree<T, N>::get_root()
{
    return _root;
}
