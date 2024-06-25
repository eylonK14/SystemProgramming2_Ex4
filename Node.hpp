// eylony1403@gmail.com

#pragma once

#include <iostream>
#include <vector>

template <typename T>
class Node
{

public:
#include "Node.hpp"

    Node(T data) : _data(data)
    {
    }

    ~Node()
    {
        for (auto child : _children)
        {
            delete child;
        }
    }

    void add_child(Node<T>child)
    {
        _children.push_back(child);
    }

    void remove_child(Node<T>child)
    {
        for (size_t i = 0; i < _children.size(); i++)
        {
            if (_children[i] == child)
            {
                long int index = static_cast<long int>(i);
                _children.erase(_children.begin() + index);
                return;
            }
        }
    }

    T get_value()
    {
        return _data;
    }

    Node<T> get_child(int index)
    {
        if (index < 0 || index >= _children.size())
        {
            throw std::out_of_range("Index out of range");
        }
        size_t i = static_cast<size_t>(index);
        return _children[i];
    }

    std::vector<Node<T>> get_children()
    {
        return _children;
    }

private:
    T _data;
    std::vector<Node<T>> _children;
};
