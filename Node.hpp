//@author eylony1403@gmail.com

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
        _children.clear();
    }

    void add_child(Node<T> *child)
    {
        if (std::find(child->_children.begin(), child->_children.end(), this) != child->_children.end())
        {
            throw std::invalid_argument("Child already has this parent");
        }
        _children.push_back(child);
    }

    void remove_child(Node<T> *child)
    {
        if (std::find(this->_children.begin(), this->_children.end(), child) == this->_children.end())
        {
            throw std::invalid_argument("Not contains that child");
        }

        for (size_t i = 0; i < _children.size(); i++)
        {
            if (_children[i]->get_value() == child->get_value())
            {
                long int index = static_cast<long int>(i);
                _children.erase(_children.begin() + index);
                return;
            }
        }
    }

    T &get_value()
    {
        return _data;
    }

    Node<T> *&get_child(int index)
    {
        if (index < 0 || index >= _children.size())
        {
            throw std::out_of_range("Index out of range");
        }
        size_t i = static_cast<size_t>(index);
        return _children[i];
    }

    std::vector<Node<T> *> &get_children()
    {
        return _children;
    }

private:
    T _data;
    std::vector<Node<T> *> _children;
};
